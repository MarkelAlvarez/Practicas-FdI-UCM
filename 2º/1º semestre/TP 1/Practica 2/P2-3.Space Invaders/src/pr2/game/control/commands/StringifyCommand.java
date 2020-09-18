package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;
import pr2.game.view.GamePrinter;
import pr2.game.view.PrinterTypes;

public class StringifyCommand extends Command {
	
	public StringifyCommand(String name, String shortcut, String details, String help) {

		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException {
		
		/*
		 * Se le pasa a printer las caracteristicas de STRINGIFIER para
		 * luego poder mostrarlo en pantalla
		 */
		GamePrinter printer = PrinterTypes.STRINGIFIER.getObject();
		
		System.out.println(printer.toString(game));

		return false;
	}

	@Override
	public Command parse(String[] commandWords) throws CommandParseException {

		if (matchCommandName(commandWords[0]))
		{
			return this;
		}

		return null;
	}
}