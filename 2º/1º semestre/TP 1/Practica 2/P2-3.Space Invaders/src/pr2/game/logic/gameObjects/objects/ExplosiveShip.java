package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;

public class ExplosiveShip extends RegularShip {

	public static String icono = "E";
	private int damage = 1;
	private boolean explode;

	public ExplosiveShip(Game game, int x, int y, int live, int cycles, Move move) {
		
		super(game, x, y, live);
		cyclesToMove = cycles;
		this.move = move;
		explode = false;
	}
	
	@Override
	public boolean receiveMissileAttack(int damage) {

		super.getDamage(damage);
		
		if(!isAlive() && !explode)
		{
			game.explosion(x, y, damage);	
			explode = true;
		}
		
		return true;
	}

	@Override
	public boolean receiveShockWaveAttack(int damage) {

		super.getDamage(damage);
		
		if(!isAlive() && !explode)
		{
			game.explosion(x, y, damage);	
			explode = true;
		}
		
		return true;
	}

	@Override
	public void onDelete() {
		
		super.onDelete();
	}

	@Override
	public void computerAction() {
	}

	@Override
	public String toString() {

		return ExplosiveShip.icono + "[" + live + "]";
	}
	
	@Override
	public String toStringifier() {
		
		return icono + ": " + x + " " + y + " " + live + " " + cyclesToMove + " " + Move.toString(move) + "\n";
	}
}