package pr2.game.GameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.GameObjects.*;
import pr2.game.logic.Move;

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
		
		return other.receiveBombAttack(damage);
	}

	@Override
	public boolean receiveMissileAttack(int damage) {

		getDamage(damage);
		
		return true;
	}

	@Override
	public void onDelete() {
		
		ship.setBomb(true);
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