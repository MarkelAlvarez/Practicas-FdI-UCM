package tp.p1.control.commands;

import tp.p1.control.Command;
import tp.p1.logic.Game;

public class MoveCommand extends Command {
	
	private String[] comando;
	public MoveCommand(String name, String shortcut, String details, String help) {
		super(name, shortcut, details, help);
		// TODO Auto-generated constructor stub
	}

	@Override
	public boolean execute(Game game) {
		
		int foo;
		boolean ret = false;
		
		if (comando.length == 3)
		{
			/*Convierte el numero leido en un 'int'*/
			foo = Integer.parseInt(comando[2]);
			/*Filtra los numeros para que tengan el rango adecuado*/
			if (foo > 2)
			{
				foo = 2;
			}
			else if (foo < 1)
			{
				foo = 1;
			}
			/*Se mueve la nave segun lo que haya pedido el usuario*/
			if (comando[1].equals("left"))
			{
				game.moveShipLeft(foo);
			}
			else if (comando[1].equals("right"))
			{
				game.moveShipRight(foo);
			}
			ret = true;
		}
		
		if(game.getEnd() == false)
		{
			game.computerAction();
			game.update();
			game.setCiclos(game.getCiclos() + 1);
		}
		
		return ret;
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
