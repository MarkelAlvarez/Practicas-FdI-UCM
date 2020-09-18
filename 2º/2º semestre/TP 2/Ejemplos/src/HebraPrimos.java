// Calculo de numeros primos para EjemploPrimos1.java y EjemploPrimos2.java
public class HebraPrimos extends Thread {
	private int desde;
	private int hasta;
	private String nombre;

	public HebraPrimos(String nombre, int desde, int hasta) {
		this.nombre = nombre;
		this.desde = desde;
		this.hasta = hasta;
	}

	public void run() {
		for (int i = desde; i < hasta; i++) {
			System.out.println("hebra: " + this.nombre + " numero: " + i);
			esPrimo(i);
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
