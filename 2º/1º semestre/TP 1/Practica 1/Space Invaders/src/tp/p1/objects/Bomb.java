package tp.p1.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

public class Bomb {

	private int damage;
	private int posX;
	private int posY;
	private int id;
	private String icono;
	
	/*Inicializa los atributos de la clase*/
	public Bomb(int x, int y, int ident) {

		damage = 1;
		posX = x;
		posY = y;
		id = ident;
		icono = "·";
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
	
	public int getDamage() {

		return damage;
	}
	
	public void setDamage(int damage) {

		this.damage = damage;
	}
	
	public int getId() {

		return id;
	}
	
	public void setId(int id) {

		this.id = id;
	}
	
	public String getIcono() {

		return icono;
	}
	
	public void setIcono(String icono) {

		this.icono = icono;
	}
}
