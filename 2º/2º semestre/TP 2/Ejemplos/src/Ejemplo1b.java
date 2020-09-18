// Ejemplo minimo de hebras, sin swing.
// Creacion de varias hebras a partir de una misma clase.

public class Ejemplo1b {

	private static class MiThread extends Thread {

		private int num;

		public MiThread(int constante) {

			this.num = constante;
		}

		public void run() {

			int i;

			for (i = 0; i < 10; i++)
			{
				System.out.println("estoy en la hebra: " + num);
			}
		}
	}

	public static void main(String[] args) {

		MiThread th0 = new MiThread(0);
		MiThread th1 = new MiThread(1);
		MiThread th2 = new MiThread(2);
		MiThread th3 = new MiThread(3);
		
		th0.start();
		th1.start();
		th2.start();
		th3.run(); // OJO: en el thread principal del programa!

		System.out.println("!!!!!!!!!!!!!!!!!!!!!!");
	}
}