package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
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
		
		if(move != Move.NONE)
		{	
			if (move == Move.UP)
			{
				x--;
			}
			else
			{
				x++;
			}
			
			if(isOut())
			{
				live = 0;
			}
		}
	}

	@Override
	public String toString() {
		
		return null;
	}
}