package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;

public abstract class GameObject implements IAttack {

	protected int x;
	protected int y;
	protected int live;
	protected Game game;

	public GameObject( Game game, int x, int y, int live) {

		this.x = x;
		this.y = y;
		this.game = game;
		this.live = live;
	}

	public boolean isAlive() {
		
		return this.live > 0;
	}
	
	public boolean isOnPosition(int x, int y) {
		
		return ((this.x == x) && (this.y == y));
	}

	/*
	 * Comprueba si se encuentra fuera del tablero
	*/
	public boolean isOut() {
		
		return !game.isOnBoard(x, y);
	}
	
	public boolean receiveExplosiveAttack(int damage) {
		
		getDamage(damage);
		
		return true;
	}

	public abstract void computerAction();
	public abstract void onDelete();
	public abstract void move();
	public abstract String toString();
	
	/*GETS & SETS*/
	
	public void getDamage (int damage) {
		
		this.live = damage >= this.live ? 0 : this.live - damage;
	}
	
	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public int getLive() {
		return this.live;
	}

	public String toStringifier() {
		
		return null;
	}
}