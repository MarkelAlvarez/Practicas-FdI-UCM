package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;

public interface IExecuteRandomActions {

	/*
	 * Comprueba si es posible generar un ovni
	*/
	static boolean canGenerateRandomOvni(Game game) {
	
		return ( (game.getRandom().nextDouble()) < (game.getLevel().getOvniFrequency()) );
	}
	
	/*
	 * Comprueba si es posible generar una bomba
	*/
	static boolean canGenerateRandomBomb(Game game) {
	
		return ( (game.getRandom().nextDouble()) < (game.getLevel().getShootFrequency()) );
	}
	
	/*
	 * Comprueba si es posible generar una ExplosiveShip
	*/
	static boolean canGenerateExplosiveShip(Game game) {
		
		return ( (game.getRandom().nextDouble()) < 0.05 );
	}
}