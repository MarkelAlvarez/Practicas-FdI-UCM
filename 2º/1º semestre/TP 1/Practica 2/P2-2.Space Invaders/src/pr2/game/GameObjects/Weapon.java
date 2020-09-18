package pr2.game.GameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.logic.Move;

public class Weapon extends GameObject {

	protected int damage;
	private Move move;

	public Weapon(Game game, int x, int y, int live, int damage, Move move) {
		
		super(game, x, y, live);
		this.damage = damage;
		this.move = move;
	}

	@Override
	public void computerAction() {
	}

	@Override
	public void onDelete() {
	}

	@Override
	public void move() {
		
		if (move == Move.UP)
		{
			x--;
		}
		else
		{
			x++;
		}
	}

	@Override
	public String toString() {
		
		return null;
	}
}