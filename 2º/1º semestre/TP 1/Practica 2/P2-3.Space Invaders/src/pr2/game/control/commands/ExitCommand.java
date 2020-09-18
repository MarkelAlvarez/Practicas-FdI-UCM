package pr2.game.control.commands;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;

public class ExitCommand extends Command {

	public ExitCommand(String name, String shortcut, String details, String help) {
	
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException {

		game.exit();
		
		return true;
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