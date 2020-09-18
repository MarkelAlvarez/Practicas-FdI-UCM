package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import java.io.IOException;
import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.exceptions.FileContentsException;
import pr2.game.logic.Game;

public class LoadCommand extends Command {

	String[] comando;
	String nFichero;
	
	public LoadCommand(String name, String shortcut, String details, String help) {
		
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException {

		if (comando.length == 2)
		{
			/*
			 * Comprueba si el comando introducido tiene la extensión del fichero,
			 * en el caso de que no lo tenga se lo añade.
			*/
			if (!comando[1].contains(".dat"))
			{
				nFichero = comando[1] + ".dat";
			}
			else
			{
				nFichero = comando[1];
			}
			
			//TODO Load from file (a las bombas sin nave crearles una fuera de la lista)
			System.out.println("This funtionality is currently unavailable.");
			/*try {
				game.readFile(nFichero);
				System.out.println("Game successfully from file " + nFichero + ".");
			} catch (IOException | FileContentsException e) {
				System.out.println(e);
			}*/
		}
		else
		{
			System.out.println("Please input a file name");
		}
		
		return false;
	}

	@Override
	public Command parse(String[] commandWords) throws CommandParseException {

		if (matchCommandName(commandWords[0]))
		{
			comando = commandWords;
			return this;
		}
		
		return null;
	}
}