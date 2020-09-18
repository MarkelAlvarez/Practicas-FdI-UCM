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
	
	public static String toString(Move move) {
		
		if (move.equals(LEFT))
		{
			return "LEFT";
		}
		else if (move.equals(RIGHT))
		{
			return "RIGHT";
		}
		else if (move.equals(DOWN))
		{
			return "DOWN";
		}
		else if (move.equals(UP))
		{
			return "UP";
		}
		else
		{
			return "NONE";
		}
	}
}
