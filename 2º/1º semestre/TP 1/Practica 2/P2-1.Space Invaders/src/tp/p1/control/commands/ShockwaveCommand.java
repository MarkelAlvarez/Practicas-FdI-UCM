package tp.p1.control.commands;

import tp.p1.control.Command;
import tp.p1.logic.Game;

public class ShockwaveCommand extends Command {

	public ShockwaveCommand(String name, String shortcut, String details, String help) {
		super(name, shortcut, details, help);
		// TODO Auto-generated constructor stub
	}

	@Override
	public boolean execute(Game game) {

		game.shockwave();
		
		if(game.getEnd() == false)
		{
			game.computerAction();
			game.update();
			game.setCiclos(game.getCiclos() + 1);
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
