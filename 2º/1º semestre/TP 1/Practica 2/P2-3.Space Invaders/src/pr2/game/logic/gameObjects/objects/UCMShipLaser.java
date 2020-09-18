package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;
import pr2.game.logic.gameObjects.GameObject;
import pr2.game.logic.gameObjects.Weapon;

public class UCMShipLaser extends Weapon {

	static String icono = "oo";
	public static int damage = 1;

	/*Inicializa los atributos de la clase*/
	public UCMShipLaser(Game game, int x, int y, int damage) {

		super(game, x, y, 1, damage, Move.UP);
	}

	@Override
	public boolean performAttack(GameObject other) {
		
		boolean ret = false;
		
		if (other.isOnPosition(x, y))
		{
			ret = other.receiveMissileAttack(super.damage);
		}
		
		return ret;
	}

	@Override
	public boolean receiveBombAttack(int damage) {

		getDamage(damage);
		
		return true;
	}

	@Override
	public String toString() {

		return icono;
	}
	
	@Override
	public void onDelete() {
		
		game.enableMissile();
		game.remove(this);
	}
	
	public String toStringifier() {
		
		return "M: " + x + " " + y + "\n";
	}
	
	/*GETS y SETS*/
	
	public int getDamage() {

		return damage;
	}

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		UCMShipLaser.icono = icono;
	}
}