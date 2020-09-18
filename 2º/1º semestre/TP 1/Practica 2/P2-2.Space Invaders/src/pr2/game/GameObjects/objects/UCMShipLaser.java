package pr2.game.GameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.GameObjects.GameObject;
import pr2.game.GameObjects.Weapon;
import pr2.game.logic.Move;

public class UCMShipLaser extends Weapon {

	static String icono = "oo";
	public static int damage = 1;

	/*Inicializa los atributos de la clase*/
	public UCMShipLaser(Game game, int x, int y, int damage) {

		super(game, x, y, 1, damage, Move.UP);
	}

	@Override
	public boolean performAttack(GameObject other) {

		return other.receiveMissileAttack(super.damage);
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