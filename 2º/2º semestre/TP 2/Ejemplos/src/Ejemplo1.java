// Ejemplo minimo de hebras, sin swing.
// Uso de la herencia de Thread y del metodo start().

public class Ejemplo1  {
	private static class MiThread extends Thread {
		private int num;

		public MiThread(int constante) {
			this.num = constante;
		}

		public void run() {
			int i;
			for (i = 0; i < 1000; i++) {
				System.out.println("estoy en la hebra: " + num);
			}
		}
	}

	public static void main(String[] args) {

		MiThread th0 = new MiThread(0);
		//th0.run(); //se ejecuta el metodo run en la hebra ppal
		th0.start(); // Ejecucion CONCURRENTE 
		int i;
		for (i = 0; i < 1000; i++) {
			System.out.println("estoy en el main");

		}
	}
}
