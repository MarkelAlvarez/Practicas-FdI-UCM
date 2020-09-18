package pr2.game.GameObjects.objects;

import pr2.game.Game;

public class SuperLaser extends UCMShipLaser {

	public static int cost = 20;
	public static int damage = 2;
	public static String icono = "^";

	public SuperLaser(Game game, int x, int y) {
		
		super(game, x, y, damage);
	}

	@Override
	public void onDelete() {
	}

	public String toString() {

		return SuperLaser.icono;
	}
}