package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.exceptions.NoShockwaveException;
import pr2.game.logic.Game;

public class ShockwaveCommand extends Command {

	public ShockwaveCommand(String name, String shortcut, String details, String help) {
		
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException {

		try {
			game.shockWave();
		} catch (NoShockwaveException e) {
			throw new CommandExecuteException(e.getMessage());
		}
		
		if(!game.isFinished())
		{
			game.update();
		}
		
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