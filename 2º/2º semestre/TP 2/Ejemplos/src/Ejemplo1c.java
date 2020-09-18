// Ejemplo minimo de hebras, sin swing.
// Un thread se arranca en un objeto de una clase, pero
// pueden ejecutarse metodos de ese mismo objeto en distintas hebras.

public class Ejemplo1c {
	private static class MiThread extends Thread {
		private int num;

		public MiThread(int constante) {
			
			this.num = constante;
		}

		public void run() {

			mirun(num);
		}

		public void mirun(int n) {

			int i;
			
			for (i = 0; i < 1000 ; i++)
			{
				System.out.println(n);
			}
		}
	}

	public static void main(String[] args) {

		MiThread th0 = new MiThread(0);
		th0.start(); // Ejecucion CONCURRENTE
		th0.mirun(2);// Ejecucion de un metodo del mismo objeto th0 pero en la hebra ppal.
	}
}
