package pr2.game.control;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import java.util.Scanner;

import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;
import pr2.game.view.GamePrinter;
import pr2.game.view.PrinterTypes;

public class Controller {

	final static int numF = 8;
	final static int numC = 9;
	private Game game;
	private Scanner in;
	GamePrinter printer;
	private String unknownCommandMsg = "Wrong input.\n";
	
	/*Inicializa los atributos de la clase e initGame()*/
	public Controller(Game game, Scanner scanner) {

		this.game = game;
		in = scanner;
		game.initGame();
		printer = PrinterTypes.BOARDPRINTER.getObject();
	}

	public void run() {
		
		boolean printMe = true;
		/*
		* Mientras que no se acabe el juego ni se ejecute la opcion 'reset'
		* el juego hara un ciclo (draw (si se ha pedido el tablero), user command, computer action y update).
		* Tambien se gestionan las excepciones lanzadas por los metodos que son llamados desde aqui.
		*/
		while (!game.isFinished())
		{
			if(printMe)
			{
				draw();
			}
			
			printMe = true;
			
			System.out.print("Command > ");
			String[] words = in.nextLine().toLowerCase().trim().split("\\s+");

			try {
				Command command = CommandGenerator.parseCommand(words);

				if (command != null)
				{
					if (!command.execute(game))
					{
						printMe = false;
					}
				}
				else
				{
					System.out.format(unknownCommandMsg);
					printMe = false;
				}
			} catch (CommandParseException | CommandExecuteException | NumberFormatException ex) {
				System.out.format(ex.getMessage() + " %n %n");
			}
		}
		
		draw();
		System.out.println(game.getWinnerMessage());
	}

	/*Te refleja la informacion de la partida y pinta el tableror*/
	public void draw() {

		System.out.println(game.infoToString());
		
		/*Pinta el tablero*/
		System.out.println(printer.toString(game));
	}
}