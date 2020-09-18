package pr2.game.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

public enum Move {
	
	LEFT, RIGHT, UP, DOWN, NONE;
	
	public Move flip() {
		
		if(this == LEFT)
		{
			return RIGHT;
		}
		else if(this == RIGHT)
		{
			return LEFT;
		}
		
		return this;
	}
}
