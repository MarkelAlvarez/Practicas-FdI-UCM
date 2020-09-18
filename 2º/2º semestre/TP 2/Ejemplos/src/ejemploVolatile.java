//tanto si lo hago con volatil como si no siempre actualizadas
//por el synchronized

public class ejemploVolatile {
	
	private static int comun = 8;

	private static class MiThread extends Thread {

		private int num;

		public MiThread(int constante) {

			this.num = constante;
		}

		public void run() {

			int i;

			for (i = 0; i < 10; i++)
			{
				incrementa(num);

				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					return;
				}
			}
		}

		private synchronized static void incrementa(int num) {

			comun = comun + 1;
			System.out.println("estoy en la hebra: " + num + "; y comun vale: "	+ comun);
		}
	}

	public static void main(String[] args) {

		MiThread th0 = new MiThread(0);
		MiThread th1 = new MiThread(1);
		
		th0.start();
		th1.start();
	}
}
