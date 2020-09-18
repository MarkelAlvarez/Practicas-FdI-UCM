package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;

public class ResetCommand extends Command {
	
	public ResetCommand(String name, String shortcut, String details, String help) {
		
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException {

		game.reset();
		
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