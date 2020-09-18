package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;
import pr2.game.logic.gameObjects.*;

public class RegularShip extends AlienShip {

	public static int life = 3;
	public static int puntos = 5;
	public static String icono = "C";

	/*Inicializa los atributos de la clase*/
	public RegularShip (Game game, int x, int y, int live) {

		super(game, x, y, live, puntos);
	}

	@Override
	public boolean receiveMissileAttack(int damage) {

		getDamage(damage);

		return true;
	}

	@Override
	public boolean receiveShockWaveAttack(int damage) {

		getDamage(damage);

		return true;
	}

	@Override
	public void computerAction()
	{
		/*
		 * Si la probabilidad lo permite esta RegularShip pasa a
		 * ser una ExplosiveShip
		 */
		if(IExecuteRandomActions.canGenerateExplosiveShip(game))
		{
			int shipsBorder = getShipsOnBorder();
			game.addObject(new ExplosiveShip(game, x, y, live, cyclesToMove, move));
			setShipsOnBorder(shipsBorder);
			getDamage(live);
			game.receivePoints(-points); //Para que el jugador no gane puntos cuando se convierta en explosive
		}
	}

	@Override
	public String toString() {

		return RegularShip.icono + super.toString();
	}
	
	public String toStringifier() {
		
		return "R: " + x + " " + y + " " + live + " " + cyclesToMove + " " + Move.toString(move) + "\n";
	}
	
	@Override
	public void onDelete() {

		super.onDelete();
		game.remove(this);
	}

	/*GETS y SETS*/

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		RegularShip.icono = icono;
	}
}