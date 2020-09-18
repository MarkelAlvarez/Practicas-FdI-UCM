package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.Game;
import pr2.game.control.Command;

public class ShootCommand extends Command {

	private String[] comando;
	
	public ShootCommand(String name, String shortcut, String details, String help) {
		
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) {

		if (comando.length == 2)
		{
			if(comando[1].equals("supermissile") || comando[1].equals("superlaser"))
			{
				if (!game.superlaser())
				{
					System.out.println("No supermissiles avaiable\n");
				}
			}
		}
		else
		{
			game.shootLaser();
		}
		
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
			comando = commandWords;
			return this;
		}

		return null;
	}
}