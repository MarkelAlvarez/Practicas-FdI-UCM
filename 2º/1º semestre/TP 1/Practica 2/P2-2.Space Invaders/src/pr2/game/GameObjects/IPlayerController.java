package pr2.game.GameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

public interface IPlayerController {
	
	// PLAYER ACTIONS
	public boolean move (int numCells);
	public boolean shootLaser();
	public boolean shockWave();
	
	// CALLBACKS
	public void receivePoints(int points);
	public void enableShockWave();
	public void enableMissile();
}