package pr2.game.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import java.io.*;
import java.util.Random;

import pr2.game.exceptions.*;
import pr2.game.logic.gameObjects.*;
import pr2.game.logic.gameObjects.lists.GameObjectBoard;
import pr2.game.logic.gameObjects.objects.*;

public class Game implements IPlayerController {

	public final static int DIM_X = 8;
	public final static int DIM_Y = 9;
	private int currentCycle;
	private boolean doExit;
	private Random rand;
	private Level level;
	private UCMShip player;
	private BoardInitializer initializer ;
	GameObjectBoard board;

	public Game (Level level, Random random) {

		this.rand = random;
		this.level = level;
		initializer = new BoardInitializer();
	}

	public void initGame () {

		currentCycle = 0;
		board = initializer.initialize(this, level);
		player = new UCMShip(this, DIM_X - 1, DIM_Y/2);
		board.add(player);
	}

	public Random getRandom() {
		return rand;
	}

	public Level getLevel() {
		return level;
	}

	public void reset() {

		initGame();
	}

	public void addObject(GameObject object) {

		board.add(object);
	}

	public String positionToString(int x, int y) {

		return board.toString(x, y);
	}
	
	public void explosion(int x, int y, int damage) {
		
		board.explosion(x, y, damage);
	}

	public boolean isFinished() {

		return ((playerWin()) || (aliensWin()) || (doExit));
	}

	public boolean aliensWin() {

		return ( (!player.isAlive ()) || (AlienShip.haveLanded()) );
	}

	private boolean playerWin () {

		return AlienShip.allDead();
	}

	/*
	 * Proporciona dinamicamente la informaci�n sobre los objetos del juego
	*/
	public void list() {

		System.out.print("[R]egular ship: Points: " + RegularShip.puntos + " - Harm: 0 - Shield: " + RegularShip.life + "\n");
		System.out.print("[D]estroyer ship: Points: " + DestroyerShip.puntos + " - Harm: " + Bomb.damage + " - Shield: " + DestroyerShip.life + "\n");
		System.out.print("[O]vni: Points: " + Ovni.puntos + " - Harm: 0 - Shield: " + Ovni.life + "\n");
		System.out.print(UCMShip.icono + ": Harm: " + UCMShipLaser.damage + " - Shield: " + UCMShip.life + "\n\n");
	}
	
	public void update() {

		board.computerAction();
		board.update();
		currentCycle += 1;
	}

	/* 
	 * Comprueba si está dentro del tablero
	*/
	public boolean isOnBoard(int x, int y) {

		return ( (x >= 0) && (y >= 0) && (x < DIM_X) && (y < DIM_Y) );
	}

	public void exit() {

		doExit = true;
	}

	/*
	 * A�ade en un string la información basica del juego que despues será mostrada
	*/
	public String infoToString() {

		String chain = "Life: " + player.getLive() + "\n" + "Cycles: " + currentCycle + "\n" + player.stateToString()
		+ "Remaining aliens: " + (AlienShip.getRemainingAliens()) + "\n"
		+ "SuperLasers: " + (player.getPoints() / SuperLaser.cost + "\n");

		if (player.getShockwave())
		{
			chain += "Shockwave: YES\n";
		}
		else
		{
			chain += "Shockwave: NO\n";
		}

		return chain;
	}

	/*
	 * Dependiendo de como haya terminado la partida muestra un mensaje u otro
	*/
	public String getWinnerMessage () {

		if (playerWin()) return "Player win! Points obtained: " + player.getPoints();
		else if (aliensWin()) return "Aliens win!";
		else if (doExit) return "Player exits the game";
		else return "This should not happen";
	}
	
	public boolean move(int numCells) throws CommandExecuteException, OffWorldException {

		return player.move(numCells);
	}
	
	public boolean shootLaser() throws CommandExecuteException, MissileInFlightException {

		return player.shootLaser();
	}
	
	public boolean superlaser() throws CommandExecuteException, NotEnoughPointsException {
		
		return player.buy();
	}
	
	public boolean shockWave() throws CommandExecuteException, NoShockwaveException {
		
		return player.shockwave();
	}
	
	public void receivePoints(int points) {
		
		player.receivePoints(points);
	}

	public void enableShockWave() {

		if (player.getShockwave())
		{
			player.setShockwave(false);
		}
		else
		{
			player.setShockwave(true);
		}
	}
	
	public void enableMissile() {
		
		if (player.getLaser())
		{
			player.setLaser(false);
		}
		else
		{
			player.setLaser(true);
		}
	}

	public String stringifier() {
		
		String ret = "";
		
		return ret += "-- Space Invaders v2.0 --\n\n"
					+ "Game: " + currentCycle + "\n"
					+ "Level: " + level.getLevelString() + "\n"
					+ board.toStringifier();	
	}
	
	public void remove(GameObject object) {

		board.remove(object);
	}

	/*
	 * Escribe en un fichero el estado del juego
	*/
	public void writeFile(String nFichero) throws IOException {

		BufferedWriter write = new BufferedWriter(new FileWriter(new File(nFichero)));
		write.write(stringifier());
		write.close();
	}
	
	/*
	 * Carga de un fichero el estado del juego
	*/
	/*public void readFile(String nFichero) throws IOException, FileContentsException {
		
		BufferedReader read = new BufferedReader(new FileReader(new File(nFichero)));
		read.readLine();
		read.close();
		load(read);
	}
	
	public void load(BufferedReader inStream) throws IOException, FileContentsException {
		
		boolean loading = false;
		String line = inStream.readLine().trim();
		FileContentsVerifier verifier = new FileContentsVerifier();
		
		while( line != null && !line.isEmpty() )
		{
			GameObject gameObject = GameObjectGenerator.parse(line, this, verifier);
			
			if (gameObject == null)
			{
				throw new FileContentsException("invalid file, " + "unrecognised line prefix");
			}
			
			board.add(gameObject);
			line = inStream.readLine().trim();
		}
	}*/
}