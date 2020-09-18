package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.control.Command;

public class ShockwaveCommand extends Command {

	public ShockwaveCommand(String name, String shortcut, String details, String help) {
		
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) {

		game.shockWave();
		
		if(!game.isFinished())
		{
			game.update();
		}
		
		return true;
	}

	@Override
	public Command parse(String[] commandWords) {

		if (matchCommandName(commandWords[0]))
		{
			return this;
		}

		return null;
	}
}