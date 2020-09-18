package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.logic.Game;
import pr2.game.logic.Move;
import pr2.game.logic.gameObjects.*;

public class DestroyerShip extends AlienShip implements IExecuteRandomActions{

	private Boolean bomb;
	public static String icono = "D";
	public static int puntos = 10;
	public static int life = 1;
	private int id;

	/*Inicializa los atributos de la clase*/
	public DestroyerShip(Game game, int x, int y, int live, int id) {

		super(game, x, y, live, puntos);
		bomb = true;
		this.setId(id+1);
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
	public void computerAction() {
		
		if(bomb && IExecuteRandomActions.canGenerateRandomBomb(game))
		{
			game.addObject(new Bomb(game, x, y, this));
			bomb = false;
		}
	}
	
	@Override
	public String toString() {

		return DestroyerShip.icono + super.toString();
	}
	
	public String toStringifier() {
		
		return icono + ": " + x + " " + y + " " + live + " " + cyclesToMove + " " + Move.toString(move) + " " + id + "\n";
	}
	
	@Override
	public void onDelete() {

		super.onDelete();
		game.remove(this);
	}

	/*GETS y SETS*/

	public Boolean canShootBomb() {

		return bomb;
	}

	public void setBomb(Boolean bomb) {

		this.bomb = bomb;
	}

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		DestroyerShip.icono = icono;
	}

	public int getId() {
		
		return id;
	}

	public void setId(int id) {
		
		this.id = id;
	}
}