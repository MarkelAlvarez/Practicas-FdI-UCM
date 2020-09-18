public class EjemploVolatil2 {

	// observar que con volatile si termina el bucle y sin volatile no

	static volatile boolean f = false;

	public static void main(String[] args) throws InterruptedException {

		new Thread() {

			public void run() {

				System.out.println("Thread is Starting");

				while (!f) {
					// no hace nada
				}

				System.out.println("Thread is Finishing");
			};

		}.start();
		
		Thread.sleep(2000);
		System.out.println("Setting f to 'true'");
		f = true;
		System.out.println("main terminado");
	}
}
