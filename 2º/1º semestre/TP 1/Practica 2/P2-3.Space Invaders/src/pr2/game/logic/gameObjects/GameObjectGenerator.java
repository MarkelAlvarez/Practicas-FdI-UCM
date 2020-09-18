/*package pr2.game.logic.gameObjects;

import pr2.game.exceptions.FileContentsException;
import pr2.game.logic.*;
import pr2.game.logic.gameObjects.objects.*;

public class GameObjectGenerator {
	
	private static GameObject[] availableGameObjects = {
		new UCMShip(null, 0, 0),
		new Ovni(null, 0, 0),
		new RegularShip(null, 0, 0, 0),
		new DestroyerShip(null, 0, 0, 0, 0),
		new ExplosiveShip(null, 0, 0, 0, 0, null),
		new ShockWave(null),
		new Bomb(null, 0, 0, null),
		new UCMShipLaser(null, 0, 0, 0),
		new SuperLaser(null, 0, 0)
	};
	
	public static GameObject parse(String stringFromFile, Game game, FileContentsVerifier verifier) throws FileContentsException {
		
		GameObject gameObject = null;
		
		for (GameObject go: availableGameObjects)
		{
			gameObject = go.parse(stringFromFile, game, verifier);
			
			if (gameObject != null)
			{
				break;
			}
		}
		
		return gameObject;
	}
}*/