package tp.p1.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

public class RegularShip {

	private int posX;
	private int posY;
	private int resist;
	private int puntos;
	private String icono;
	
	/*Inicializa los atributos de la clase*/
	public RegularShip (int x, int y) {

		posX = x;
		posY = y;
		resist = 3;
		puntos = 5;
		icono = "C[" + resist + "]";
	}

	/*GETS y SETS*/
	
	public int getPosX() {

		return posX;
	}
	
	public void setPosX(int posX) {

		this.posX = posX;
	}
	
	public int getPosY() {

		return posY;
	}
	
	public void setPosY(int posY) {

		this.posY = posY;
	}
	
	public int getResist() {

		return resist;
	}
	
	public void setResist(int resist) {

		this.resist = resist;
	}
	
	public int getPuntos() {

		return puntos;
	}
	
	public void setPuntos(int puntos) {

		this.puntos = puntos;
	}
	
	public String getIcono() {
		
		icono = "C[" + resist + "]";
		
		return icono;
	}
	
	public void setIcono(String icono) {

		this.icono = icono;
	}
}