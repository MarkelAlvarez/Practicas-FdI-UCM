package tp.p1.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

public enum Level {

	EASY, HARD, INSANE;

	/*Cantidad de regular ships dependiento de la dificultad elegida*/
	public int getNumRegularAliens() {

		int num = 0;

		if (this == EASY)
		{
			num = 4;
		}
		else if (this == HARD)
		{
			num = 8;
		}
		else if (this == INSANE)
		{
			num = 8;
		}
		
		return num;
	}

	/*Cantidad de destroyer ships dependiento de la dificultad elegida*/
	public int getNumDestroyerAliens() {

		int num = 0;

		if (this == EASY)
		{
			num = 2;
		}
		else if (this == HARD)
		{
			num = 2;
		}
		else if (this == INSANE)
		{
			num = 4;
		}
		
		return num;
	}
	
	/*Frecuencia de tiro dependiento de la dificultad elegida*/
	public double getShootFrec() {

		double freq = 0;

		if (this == EASY)
		{
			freq = 0.1;
		}
		else if (this == HARD)
		{
			freq = 0.3;
		}
		else if (this == INSANE)
		{
			freq = 0.5;
		}
		
		return freq;
	}
	
	/*Velocidad de movimiento dependiento de la dificultad elegida*/
	public int getSpeed() {

		int ciclos = 0;

		if (this == EASY)
		{
			ciclos = 3;
		}
		else if (this == HARD)
		{
			ciclos = 2;
		}
		else if (this == INSANE)
		{
			ciclos = 1;
		}
		
		return ciclos;
	}
	
	/*Frecuencia de aparicieón del ovni dependiento de la dificultad elegida*/
	public double getFrecOvni() {

		double freq = 0;

		if (this == EASY)
		{
			freq = 0.5;
		}
		else if (this == HARD)
		{
			freq = 0.2;
		}
		else if (this == INSANE)
		{
			freq = 0.1;
		}
		
		return freq;
	}

	/*Posicion de la destroyer en la fila dependiento de la dificultad elegida*/
	public int getLineDestroyer() {
		
		int num;

		if (this == EASY)
		{
			num = 2;
		}
		else if(this == HARD || this == INSANE)
		{
			num = 3;
		}
		else
		{
			num = 0;
		}

		return num;
	}

	/*Posicion de la destroyer en la columna dependiento de la dificultad elegida*/
	public int getColDestroyerAliens() {
		
		int num;
		
		if (this == EASY || this == HARD)
		{
			num = 4;
		}
		else if (this == INSANE)
		{
			num = 3;
		}
		else
		{
			num = 0;
		}
		
		return num;
	}
}
