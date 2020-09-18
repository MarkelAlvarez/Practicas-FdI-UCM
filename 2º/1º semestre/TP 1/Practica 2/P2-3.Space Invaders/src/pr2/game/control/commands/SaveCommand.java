package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import java.io.IOException;

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;

public class SaveCommand extends Command {
	
	String[] comando;
	String nFichero;
	
	public SaveCommand(String name, String shortcut, String details, String help) {
		
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
			
			try {
				game.writeFile(nFichero);
				System.out.println("Game successfully saved in file " + nFichero + ". Use the load command to reload it.");
			} catch (IOException e) {
				System.out.println(e);
			}	
		}
		else
		{
			System.out.println("Please input a file name.");
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