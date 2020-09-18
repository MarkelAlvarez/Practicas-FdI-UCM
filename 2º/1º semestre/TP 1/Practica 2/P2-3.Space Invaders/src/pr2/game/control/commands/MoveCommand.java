package pr2.game.control.commands;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.Command;
import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.exceptions.OffWorldException;
import pr2.game.logic.Game;

public class MoveCommand extends Command {
	
	private String[] comando;
	
	public MoveCommand(String name, String shortcut, String details, String help) {
	
		super(name, shortcut, details, help);
	}

	@Override
	public boolean execute(Game game) throws CommandExecuteException, NumberFormatException {
		
		int foo; //inicializado por el try
		boolean ret = false;
		
		if (comando.length == 3)
		{
			/*Convierte el numero leido en un 'int'*/
			try {
				try {
					foo = Integer.parseInt(comando[2]);
				} catch (NumberFormatException e) {
					throw new NumberFormatException("Cause of Exception: \r\n" + 
							"\t pr2.exceptions.NumberFormatException: wrong parameter format: {move} {left | right} {1 | 2}");
				}
				/*Filtra los numeros para que tengan el rango adecuado*/
				if (foo > 2 || foo < 1)
				{
					throw new NumberFormatException("Cannot move given positions.");
				}
				else
				{
					/*Se mueve la nave segun lo que haya pedido el usuario*/
					if (comando[1].equals("left"))
					{
						ret = game.move(foo * (-1)); //le paso el numero en negativo para que se reste
					}
					else if (comando[1].equals("right"))
					{
						ret = game.move(foo);
					}
					else
					{
						System.out.println("Wrong direction parameter, check spelling.");
					}
				}
			} catch (OffWorldException owe) {
				throw new CommandExecuteException(owe.getMessage());
			}
		}
		else
		{
			throw new CommandExecuteException("Not enough parameters were entered.");
		}
		
		if(!game.isFinished())
		{
			game.update();
		}
		
		return ret;
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