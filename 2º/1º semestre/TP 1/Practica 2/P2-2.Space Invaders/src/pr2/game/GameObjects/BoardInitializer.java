package pr2.game.GameObjects;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.*;
import pr2.game.GameObjects.Lists.GameObjectBoard;
import pr2.game.GameObjects.objects.*;

public class BoardInitializer {
	
	private Level level ;
	private GameObjectBoard board;
	private Game game;
	
	public GameObjectBoard initialize(Game game, Level level) {
		
		this.level = level;
		this.game = game;
		board = new GameObjectBoard(Game.DIM_X, Game.DIM_Y);
		initializeOvni();
		initializeRegularAliens();
		initializeDestroyerAliens();
		
		return board;
	}
	
	private void initializeOvni () {
		
		board.add(new Ovni(game, 0, Game.DIM_Y - 1));
	}
	
	private void initializeRegularAliens () {
		
		int fila = 1;
		int inic = Game.DIM_Y/2 - level.getNumRegularAliensPerRow()/2 + 1; //mismo numero de naves en cada lado
		
		while (fila <= level.getNumRowsOfRegularAliens())
		{
			for (int i = 0; i < level.getNumRegularAliensPerRow(); i++)
			{
				board.add(new RegularShip(game, fila, inic + i, RegularShip.life));
			}
			fila ++;
		}
	}
	
	private void initializeDestroyerAliens () {
		
		int inic = Game.DIM_Y/2 - level.getNumDestroyerAliensPerRow()/2 + 1; //mismo numero de naves en cada lado
		
		for (int i = 0; i < level.getNumDestroyerAliensPerRow(); i++)
		{
			board.add(new DestroyerShip(game, level.getNumRowsOfRegularAliens() + 1, inic + i, DestroyerShip.life));
		}
	}
}