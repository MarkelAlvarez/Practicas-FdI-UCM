package pr2.game.GameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.GameObjects.*;

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
		if(IExecuteRandomActions.canGenerateExplosiveShip(game))
		{
			int shipsBorder = getShipsOnBorder();
			game.addObject(new ExplosiveShip(game, x, y, live, cyclesToMove, move));
			setShipsOnBorder(shipsBorder);
			getDamage(live);
		}
	}

	@Override
	public String toString() {

		return RegularShip.icono + super.toString();
	}

	/*GETS y SETS*/

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		RegularShip.icono = icono;
	}
}