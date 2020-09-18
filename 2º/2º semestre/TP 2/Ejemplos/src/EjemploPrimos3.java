// Ejemplo de uso de sleep(), interrupt() e isInterrupted().
// Calculo de numeros primos en tres hebras distintas.
// La hebra de main espera 1000ms e interrumpe las tres hebras.

public class EjemploPrimos3 {

	public final static int NUM = 5000000;

	public static void main(String[] args) throws InterruptedException {

		long startTime = System.currentTimeMillis();

		HebraPrimos3 hebra1 = new HebraPrimos3("uno ", 1, NUM);
		HebraPrimos3 hebra2 = new HebraPrimos3("dos ", NUM + 1, 2 * NUM);
		HebraPrimos3 hebra3 = new HebraPrimos3("tres", 2 * NUM + 1, 3 * NUM);

		hebra1.start();
		hebra2.start();
		hebra3.start();
		Thread.sleep(1000);
		hebra1.interrupt();
		hebra2.interrupt();
		hebra3.interrupt();

		long endTime = System.currentTimeMillis();
		System.out.println("Tiempo total: " + (endTime - startTime) + " ms.");
	}

	public static class HebraPrimos3 extends Thread {
		
		private int desde;
		private int hasta;
		private String nombre;

		public HebraPrimos3(String nombre, int desde, int hasta) {
			this.nombre = nombre;
			this.desde = desde;
			this.hasta = hasta;
		}

		public void run() {
			for (int i = desde; i < hasta && !isInterrupted(); i++) {
				if (esPrimo(i))
					System.out.println("Hebra: " + nombre + " numero: " + i);
			}
		}

		private boolean esPrimo(int n) {
			if (n <= 3) {
				return true;
			} else {
				if (n % 2 == 0) {
					return false;
				} else {
					boolean primo = true;
					for (int i = 3; i * i < n && primo; i += 2)
						if (n % i == 0)
							primo = false;
					return primo;
				}
			}
		}
	}

}
