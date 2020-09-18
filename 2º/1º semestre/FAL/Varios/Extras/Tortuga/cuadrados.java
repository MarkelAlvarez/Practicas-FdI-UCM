//public class Tortuga {

	double longitudInicial = 500;
	double puntoCorte = 0.8;

	int cuantas = 50;

	double alpha = Math.toDegrees(Math.asin((1-puntoCorte) / puntoCorte));
	double ratio = Math.sqrt(puntoCorte*puntoCorte + (1-puntoCorte)*(1-puntoCorte));

	public void paint() {

		for(int i = 0; i < 4; i++)
		{
			advanceAndPaint(50);
			rotate(90);
		}
	}

//}