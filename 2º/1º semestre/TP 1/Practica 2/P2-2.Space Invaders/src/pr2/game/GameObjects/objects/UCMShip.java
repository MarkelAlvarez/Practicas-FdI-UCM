package pr2.game.GameObjects.objects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.GameObjects.*;

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

	public boolean receiveBombAttack(int damage) {

		getDamage(damage);
		
		return true;
	}
	
	public boolean shootLaser() {
		
		if(canShootLaser)
		{
			game.addObject(new UCMShipLaser(game, x, y, UCMShipLaser.damage));
			game.enableMissile();
			
			return true;
		}
		
		return false;
	}
	
	public boolean shockwave() {
		
		if(hasShockwave)
		{
			game.addObject(new ShockWave(game));
			
			return true;
		}
		
		return false;
	}
	
	public boolean buy() {
		
		if(points > SuperLaser.cost)
		{
			game.addObject(new SuperLaser(game, x, y));
			game.receivePoints(-SuperLaser.cost);
			
			return true;
		}
		
		return false;
	}
	
	public void receivePoints(int points) {
		
		this.points += points;
	}
	
	public boolean move(int cells) {
		
		y += cells;
		
		if (y < 0)
		{
			y = 0;
		}
		else if (y >= Game.DIM_Y)
		{
			y = Game.DIM_Y - 1;
		}
			
		return true;
	}
	
	@Override
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