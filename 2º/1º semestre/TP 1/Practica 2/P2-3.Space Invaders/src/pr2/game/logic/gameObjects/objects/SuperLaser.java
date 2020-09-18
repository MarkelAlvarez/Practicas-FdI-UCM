package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;

public class SuperLaser extends UCMShipLaser {

	public static int cost = 20;
	public static int damage = 2;
	public static String icono = "^";

	public SuperLaser(Game game, int x, int y) {
		
		super(game, x, y, damage);
	}

	@Override
	public void onDelete() {

		game.remove(this);
	}

	public String toString() {

		return SuperLaser.icono;
	}
	
	public String toStringifier() {
		
		return "X: " + x + " " + y + "\n";
	}
}