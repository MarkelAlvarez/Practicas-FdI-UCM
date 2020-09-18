package pr2.game.logic.gameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

public interface IAttack {
	
	default boolean performAttack(GameObject other) {return false;};
	
	default boolean receiveMissileAttack(int damage) {return false;};
	default boolean receiveBombAttack(int damage) {return false;};
	default boolean receiveShockWaveAttack(int damage) {return false;};
	default boolean receiveExplosiveAttack(int damage) {return false;};
}