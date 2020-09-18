package pr2.game.GameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;

public interface IExecuteRandomActions {

	static boolean canGenerateRandomOvni(Game game) {
	
		return ( (game.getRandom().nextDouble()) < (game.getLevel().getOvniFrequency()) );
	}
	
	static boolean canGenerateRandomBomb(Game game) {
	
		return ( (game.getRandom().nextDouble()) < (game.getLevel().getShootFrequency()) );
	}
	
	static boolean canGenerateExplosiveShip(Game game) {
		
		return ( (game.getRandom().nextDouble()) < 0.05 );
	}
}