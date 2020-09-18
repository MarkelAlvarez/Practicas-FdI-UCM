package pr2.game.view;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;

public class Stringifier extends GamePrinter {
	
	public Stringifier() {
	}

	public String toString(Game game) {
				
		System.out.print(game.stringifier());
		
		return "";
	}
}