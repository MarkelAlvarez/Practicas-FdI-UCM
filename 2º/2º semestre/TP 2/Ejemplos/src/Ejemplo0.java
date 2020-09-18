public class Ejemplo0 {

	// Ejemplo minimo de hebras, sin swing.
	// Uso de la herencia de Thread y del metodo start().

	private static class MiThread extends Thread {
		private int num;

		public MiThread(int constante) {
			this.num = constante;
		}

		public void run() {
			while (true) {
				System.out.println("hebra: " + num +"!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			}

		}
	}

	public static void main(String[] args) {

		MiThread th0 = new MiThread(0);
		//th0.run(); //asi seria para ejecutarlo en la hebra ppal
		th0.start(); // Ejecucion CONCURRENTE
		int i;
		for (i = 0; i < 10000000; i++) {
			System.out.println("estoy en el main--------------------------- ");

		}
	}
}
