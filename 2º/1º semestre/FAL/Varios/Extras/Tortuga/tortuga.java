//public class Tortuga {

	double longitudInicial = 500;
	double puntoCorte = 0.8;

	int cuantas = 18;

	double alpha = Math.toDegrees(Math.asin((1-puntoCorte) / puntoCorte));
	double ratio = Math.sqrt(puntoCorte*puntoCorte + (1-puntoCorte)*(1-puntoCorte));

	public void paint() {

		figura(cuantas, longitudInicial);
	}

	public void figura(int n, double longitud) { //de manera recursiva
		
		if (n == 0)
		{
			return 0;
		}

		advanceAndPaint((1-puntoCorte)*longitud);

		rotate(alpha);
		figura(n-1, longitud*ratio);

		advanceAndPaint(longitud);
		rotate(90);
		advanceAndPaint(longitud);
		rotate(90);
		advanceAndPaint(longitud);
		rotate(90);
	}

	/*public figura(int n, double longitud) {
		//Primer bucle: segmentos de longitud de 20% del lado
		int i = 0;

		while(i < n)
		{
			advanceAndPaint((1-puntoCorte)*longitud);
			rotate(alpha);
			longitud *= ratio;
			i++;
		}

		i = 0;

		while(i < n)
		{
			rotate(-alpha);
			longitud /= ratio;
			advanceAndPaint(puntoCorte*longitud);
			rotate(90);
			advanceAndPaint(longitud);
			rotate(90);
			advanceAndPaint(longitud);
			rotate(90);
			advanceAndPaint(longitud);
			i++;
		}
	}*/

//}