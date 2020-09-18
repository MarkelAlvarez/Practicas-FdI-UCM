package pr2.game.logic.gameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.MissileInFlightException;
import pr2.game.exceptions.NoShockwaveException;
import pr2.game.exceptions.NotEnoughPointsException;
import pr2.game.exceptions.OffWorldException;
import pr2.game.logic.Game;
import pr2.game.logic.gameObjects.Ship;

public class UCMShip extends Ship{
	
	private int points;
	private boolean hasShockwave;
	private boolean canShootLaser;
	public static String icono = "^__^";
	public static String death = "!xx!";
	public static int life = 3;

	/*Inicializa los atributos de la clase*/
	public UCMShip(Game game, int x, int y) {

		super(game, x, y , life); //el 3 es la vida
		hasShockwave = false;
		canShootLaser = true;
		points = 0;
	}

	/*
	 * Recibe el da�o de una nave
	*/
	public boolean receiveBombAttack(int damage) {

		getDamage(damage);
		
		return true;
	}
	
	public boolean shootLaser() throws MissileInFlightException {
		
		/*
		 * Si no es posible disparar se lanza una excepcion explicando que ocurre.
		 * Si es posible lanzar un laser se agrega el objeto y el misil
		*/
		if(canShootLaser)
		{
			game.addObject(new UCMShipLaser(game, x, y, UCMShipLaser.damage));
			game.enableMissile();
			
			return true;
		}
		
		System.out.println("Failed to shoot");
		throw new MissileInFlightException("Cause of Exception:\r\n" + 
				"	pr2.exceptions.MissileInFlightException: Cannot fire missile: missile already exists on board");
	}
	
	public boolean shockwave() throws NoShockwaveException {
		
		/*
		 * Si no es posible disparar se lanza una excepcion explicando que ocurre.
		 * Si es posible lanzar un shockwave se a�ade a la lista y luego se desactiva
		 * para que no puedan ser lanzados de manera infinita
		*/
		if(hasShockwave)
		{
			game.addObject(new ShockWave(game));
			hasShockwave = false;
			
			return true;
		}
		System.out.println("Failed to shoot");
		throw new NoShockwaveException("Cause of Exception:\r\n" + 
				"	pr2.exceptions.NoShockwaveException: Cannot release shockwave: no shockwave available");
	}
	
	/*
	 * Se comprueban con la cantidad de puntos que se tienen cuantas naves pueden comprarse.
	 * Si no es posible comprar ninguna se lanza una excepci�n explicando lo ocurrido
	*/
	public boolean buy() throws NotEnoughPointsException {
		
		if(points >= SuperLaser.cost)
		{
			game.addObject(new SuperLaser(game, x, y));
			game.receivePoints(-SuperLaser.cost);
			
			return true;
		}
		System.out.println("Failed to shoot");
		throw new NotEnoughPointsException("Cause of Exception:\r\n" + 
				"	pr2.exceptions.NotEnoughPoints: Cannot fire superlaser: there are not enough points.");
	}
	
	public void receivePoints(int points) {
		
		this.points += points;
	}
	
	/*
	 * Mueve la nave de izquierda a derecha y viceversa hasta que no se puede mover
	 * m�s debido a que UCMShip se encuentra en el borde y se lanza una excepci�n
	 * explicando que ocurre
	*/
	public boolean move(int cells) throws CommandExecuteException, OffWorldException {
		
		y += cells;
		
		if (y < 0)
		{
			y = 0;
			System.out.println("Failed to move");
			throw new OffWorldException("Cause of Exception:\r\n" + 
					"	pr2.exceptions.OffWorldException: Cannot perform move: ship too near border", new OffWorldException());
		}
		else if (y >= Game.DIM_Y)
		{
			y = Game.DIM_Y - 1;
			System.out.println("Failed to move");
			throw new OffWorldException("Cause of Exception:\r\n" + 
					"	pr2.exceptions.OffWorldException: Cannot perform move: ship too near border");
		}
			
		return true;
	}
	
	@Override
	/*
	 * Dependiendo de si UCMShip tiene vida o no se da un icono u otro
	*/
	public String toString() {
		
		if (isAlive())
		{
			return getIcono();
		}
		
		return getDeath();
	}

	public String stateToString() {
		
		return "Points: " + points + "\n";
	}
	
	@Override
	public void onDelete() {
	}
	
	public String toStringifier() {
		
		return "P: " + x + " " + y + " " + live + " " + points + " " + hasShockwave + " " + (points / SuperLaser.cost) + "\n";
	}

	/*GETS & SETS*/
	
	public void setState(int points) {
		
		this.points += points;
	}

	public boolean getLaser() {

		return canShootLaser;
	}

	public void setLaser(boolean laser) {

		this.canShootLaser = laser;
	}

	public boolean getShockwave() {

		return hasShockwave;
	}

	public void setShockwave(boolean shockwave) {

		this.hasShockwave = shockwave;
	}

	public String getDeath() {

		return death;
	}

	public void setDeath(String death) {

		UCMShip.death = death;
	}

	public String getIcono() {

		return icono;
	}

	public void setIcono(String icono) {

		UCMShip.icono = icono;
	}
	
	public int getPoints() {
		
		return points;
	}
}