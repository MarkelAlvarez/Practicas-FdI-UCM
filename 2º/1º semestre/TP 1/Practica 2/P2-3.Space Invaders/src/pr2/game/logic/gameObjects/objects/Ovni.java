package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.gameObjects.EnemyShip;
import pr2.game.logic.gameObjects.IExecuteRandomActions;

public class Ovni extends EnemyShip implements IExecuteRandomActions{

	private Boolean active;
	private Boolean init = true;
	public static String icono = "O";
	public static int puntos = 25;
	public static int life = 1;

	/*Inicializa los atributos de la clase*/
	public Ovni(Game game, int x, int y) {

		super(game, x, y, life, puntos);
		setActive(false);
	}

	/*
	 * Cuando el ovni recibe daño se desactiva y pone el shockwave a true
	 */
	public boolean receiveMissileAttack(int damage) {

		getDamage(damage);
		
		return true;
	}

	@Override
	public void computerAction() {
		
		if(!active)
		{
			if(IExecuteRandomActions.canGenerateRandomOvni(game))
			{
				x = 0;
				y = Game.DIM_Y - 1;
				live = life;
				active = true;
				init = true;
			}
		}
	}
	
	public void deactivate() {
		
		active = false;
	}
	
	@Override
	public String toString() {
	
		if (active)
		{
			return Ovni.icono + super.toString();
		}
		
		return "";
	}
	
	@Override
	public void move() {
		
		if(isAlive() && !isOut() && !init)
		{
			y--;
			if (isOut())
			{
				deactivate();
			}
		}
		else
		{
			init = false;
		}
	}
	
	@Override
	public void onDelete() {

		super.onDelete();
		game.enableShockWave();
		deactivate();
	}
	
	@Override
	public String toStringifier() {
		
		return icono + ": " + x + " " + y + " " + live + "\n";
	}

	/*GETS y SETS*/

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		Ovni.icono = icono;
	}

	public Boolean getActive() {
		
		return active;
	}

	public void setActive(Boolean active) {
		
		this.active = active;
	}
}