// Ejemplo de uso de join().
// Calculo de numeros primos en tres hebras distintas.
// La hebra de main espera a la finalizacion de las tres.

public class EjemploPrimos1 {

	public static final int NUM = 500;

	public static void main(String[] args) {

		long startTime = System.currentTimeMillis();
		HebraPrimos hebra1 = new HebraPrimos("uno ", 1, NUM);
		HebraPrimos hebra2 = new HebraPrimos("dos ", NUM + 1, 2 * NUM);
		HebraPrimos hebra3 = new HebraPrimos("tres", 2 * NUM + 1, 3 * NUM);
		
		hebra1.start();
		hebra2.start();
		hebra3.start();

		try {
			hebra1.join();
			System.out.println("Ha terminado la hebra 1.");
			hebra2.join(); 
			System.out.println("Ha terminado la hebra 2.");
			hebra3.join();
			System.out.println("Han terminado todas las hebras.");
		} catch (InterruptedException e) {
		}

		long endTime = System.currentTimeMillis();
		System.out.println("Tiempo total: " + (endTime - startTime) + " ms.------------");
	}
}
