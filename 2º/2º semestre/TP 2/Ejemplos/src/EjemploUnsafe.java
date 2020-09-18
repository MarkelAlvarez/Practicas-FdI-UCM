// Ejemplo de programacion "thread-UNsafe"
// Simulacion de contabilidad de clientes de una tienda online. 
// El total de la contabilidad y el total por clientes debera coincidir siempre. 
// Si se ejecutan secuencialmente, coinciden los totales.
// ¿Que ocurre si se ejecutan concurrentemente?

import java.util.Random;

public class EjemploUnsafe {

	public static final int NUM = 1000;

	static class ItemImporte {

		private int importe;
		private ItemImporte next;

		public ItemImporte(int imp) {

			importe = imp;
			next = null;
		}
	}

	static class Contabilidad {

		private ItemImporte primero = null;
		private ItemImporte ultimo = null;
		
		public synchronized void add(int importe) {

			if (primero == null)
			{
				primero = new ItemImporte(importe);
				ultimo = primero;
			}
			else
			{
				ItemImporte nuevo = new ItemImporte(importe);
				ultimo.next = nuevo;
				ultimo = nuevo;
			}
		}

		public int calcTotal()
		{
			int total = 0;
			ItemImporte item = primero;

			while (item != null)
			{
				total = total + item.importe;
				item = item.next;
			}

			return total;
		}
	}

	static class ClienteOnline extends Thread {

		private String id;
		private Contabilidad ct;
		private int acumulado = 0;

		public ClienteOnline(String id, Contabilidad s) {

			this.id = id;
			ct = s;
		}

		public void run() {

			Random rnd = new Random();

			for (int i = 0; i < NUM; i++)
			{
				int importe = rnd.nextInt(100);
				ct.add(importe);
				acumulado = acumulado + importe;
			}
		}

		public int getAcumulado() {

			return acumulado;
		}
	}

	public static void main(String[] args) throws InterruptedException {

		Contabilidad contab = new Contabilidad();
		ClienteOnline cli1 = new ClienteOnline("cliente 1", contab);
		ClienteOnline cli2 = new ClienteOnline("cliente 2", contab);

		cli1.start();
		cli2.start();
		cli1.join();
		cli2.join();

		int totalPorClientes = cli1.getAcumulado() + cli2.getAcumulado();

		System.out.println("Total por clientes   : " + totalPorClientes);
		System.out.println("Total en contabilidad: " + contab.calcTotal());
	}
}
