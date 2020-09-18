package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;
import pr2.game.logic.gameObjects.*;

public class Bomb extends Weapon{

	private DestroyerShip ship;
	private String icono = ".";
	public static int damage = 1;

	/*Inicializa los atributos de la clase*/
	public Bomb(Game game, int x, int y, DestroyerShip ship) {

		super(game, x, y, 1, damage, Move.DOWN);
		this.ship = ship;
	}

	@Override
	public boolean performAttack(GameObject other) {
		
		boolean ret = false;
		
		if (other.isOnPosition(x, y))
		{
			ret = other.receiveBombAttack(super.damage);
		}
		
		return ret;
	}

	@Override
	public boolean receiveMissileAttack(int damage) {

		getDamage(damage);
		
		return true;
	}

	@Override
	public void onDelete() {
		
		ship.setBomb(true);
		game.remove(this);
	}

	public String toStringifier() {
		
		return "B: " + x + " " + y + " " + ship.getId() + "\n";
	}
	
	/*GETS y SETS*/

	@Override
	public String toString() {
		
		return icono;
	}

	public int getDamage() {

		return damage;
	}

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		this.icono = icono;
	}
}