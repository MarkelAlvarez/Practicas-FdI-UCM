package tp.p1.control;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

import java.util.Scanner;

import tp.p1.logic.Game;
import tp.p1.logic.GamePrinter;

public class Controller {

	private Game game;
	private Scanner in;
	private GamePrinter printer;
	final static int numF = 8;
	final static int numC = 9;
	
	/*Inicializa los atributos de la clase e initGame()*/
	public Controller(Game game, Scanner scanner) {
		
		this.game = game;
		in = scanner;
		game.initGame();
	}

	public void run() {

		/*
		* Mientras que no se acabe el juego ni se ejecute la opcion 'reset'
		* el juego hara un ciclo (draw, user command, computer action y update)
		*/
		while ((game.getEnd() == false) && (game.getReset() == false))
		{
			draw();
			game.userCommand(comandoMenu());
			
			if(game.getEnd() == false)
			{
				game.computerAction();
				game.update();
				game.setCiclos(game.getCiclos() + 1);
			}
		}

		/*
		* Cuando se ejecuta la opcion 'reset' se inicia el juego de nuevo volviendo
		* a ejecutar initGame(). Si getEnd es true se ejecuta 'draw' y te muestra un
		* texto dependiendo de como haya terminado el juego.
		*/
		if (game.getReset())
		{
			game.initGame();
			run();
		}
		else if (game.getEnd())
		{
			draw();

			if (game.getdList().getContador() + game.getrList().getContador() == 0)
			{
				System.out.println("YOU WIN! POINTS OBTAINED: " + game.getPuntuacion());
			}
			else
			{
				System.out.println("GAME OVER");
			}
		}
	}

	/*Te refleja la información de la partida y pinta el tableror*/
	public void draw() {
		
		System.out.println("Life: " + game.getUCMShip().getResist());
		System.out.println("Number of cycles: " + game.getCiclos());
		System.out.println("Points: " + game.getPuntuacion());
		System.out.println("Remaining aliens: " + (game.getdList().getContador() + game.getrList().getContador()));
		
		if (game.getUCMShip().getShockwave())
		{
			System.out.println("Shockwave: YES");
		}
		else
		{
			System.out.println("Shockwave: NO");
		}
		/*Pinta el tablero*/
		printer = new GamePrinter(game, numF, numC);
		
		System.out.println(printer.toString());
	}
	
	/*Lee el comando introducido por el usuario*/
	public String comandoMenu()
	{
		String comando;
		
		System.out.print("Command > ");
		comando = this.in.nextLine();
		System.out.println();

		return comando;
	}
}
