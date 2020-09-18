package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.MissileInFlightException;
import pr2.game.exceptions.NoShockwaveException;
import pr2.game.exceptions.OffWorldException;

public interface IPlayerController {
	
	// PLAYER ACTIONS
	public boolean move(int numCells) throws CommandExecuteException, OffWorldException;
	public boolean shootLaser() throws CommandExecuteException, MissileInFlightException;
	public boolean shockWave() throws CommandExecuteException, NoShockwaveException;
	
	// CALLBACKS
	public void receivePoints(int points);
	public void enableShockWave();
	public void enableMissile();
}