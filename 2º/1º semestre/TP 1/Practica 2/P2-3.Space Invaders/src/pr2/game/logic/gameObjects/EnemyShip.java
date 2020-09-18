package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;

public class EnemyShip extends Ship {

	protected Move move;
	protected int points;

	public EnemyShip(Game game, int x, int y, int live, int points) {

		super(game, x, y, live);
		this.move = Move.LEFT;
		this.points = points;
	}

	@Override
	public void computerAction() {
	}

	@Override
	public void onDelete() {
		
		game.receivePoints(points);
	}

	@Override
	public void move() {
		
		if (move == Move.LEFT)
		{
			y--;
		}
		else if (move == Move.RIGHT)
		{
			y++;
		}
	}

	@Override
	public String toString() {

		return "[" + live + "]";
	}
}