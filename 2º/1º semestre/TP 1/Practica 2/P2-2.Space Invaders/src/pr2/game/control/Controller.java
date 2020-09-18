package pr2.game.control;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import java.util.Scanner;
import pr2.game.Game;
import pr2.game.logic.GamePrinter;

public class Controller {

	private Game game;
	private Scanner in;
	private GamePrinter printer;
	final static int numF = 8;
	final static int numC = 9;

	String unknownCommandMsg = "Wrong input.\n";

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
		while (!game.isFinished())
		{
			draw();

			System.out.print("Command > ");
			String[] words = in.nextLine().toLowerCase().trim().split ("\\s+");

			Command command = CommandGenerator.parseCommand(words);

			if (command != null)
			{
				if (!command.execute(game))
				{
					System.out.format(unknownCommandMsg);
				}
			}
			else
			{
				System.out.format(unknownCommandMsg);
			}
		}
		
		draw();
		System.out.println(game.getWinnerMessage());
	}

	/*Te refleja la información de la partida y pinta el tableror*/
	public void draw() {

		System.out.println(game.infoToString());
		/*Pinta el tablero*/
		printer = new GamePrinter(game, numF, numC);

		System.out.println(printer.toString());
	}
}