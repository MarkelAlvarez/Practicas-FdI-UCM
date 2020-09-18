//tortuga.bat 170 250 0 casas.java

	public void paint() {

		figura(170, 7);
	}

	public void figura(int longitud, int nivel) { 

		if (nivel == 0)
		{
			return;	
		}
		else
		{
			advanceAndPaint(longitud);
			figura(longitud/2, nivel-1);
			rotate(-90);
			advanceAndPaint(longitud);
			rotate(-90);
			advanceAndPaint(longitud);
			rotate(-90);
			advanceAndPaint(longitud);
			rotate(-90);
			advanceAndPaint((-longitud)/2);
			figura(longitud/2, nivel-1);
			advanceAndPaint(longitud/2);
		}		
	}