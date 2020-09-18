public class EjemploVolatil3 {

	// Ejemplo del uso de volatile para que todas las hebras tengan la ultima
	// modificacion de una variable compartida. Si la var. contador no es
	// volatile, el programa puede no terminar porque cada hebra tiene la
	// variable cacheada en una cache distinta.
	// Si la variable es volatile, el programa siempre termina porque se
	// propaga el ultimo cambio a todas las hebras.
	//
	// De todas formas, el funcionamiento depende de la arquitectura hardware
	// y de la maq. virtual donde se ejecute: si la memoria cache es compartida
	// entre las hebras, es posible que funcione sin volatile, pero no se puede
	// generalizar a todas las instalaciones de la maquina virtual.

	private static volatile int contador = 0;

	static class Hilo1 extends Thread {

		@Override
		public void run() {

			int local = contador;

			while (local < 5)
			{
				if (local != contador)
				{
					System.out.println("Hilo1: Ha habido un cambio!!: " + contador);
					local = contador;
				}
			}
			System.out.println("Termina el hilo 1");
		}
	}

	static class Hilo2 extends Thread {

		@Override
		public void run() {

			int local = contador;

			while (contador < 5)
			{
				System.out.println("Hilo2: Vamos a incrementar a " + (local + 1));
				contador = ++local;

				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			System.out.println("Termina el hilo 2");
		}
	}

	public static void main(String[] args) {
		
		new Hilo1().start();
		new Hilo2().start();
	}
}