package pr2.game.control;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.control.commands.*;
import pr2.game.exceptions.CommandParseException;

public class CommandGenerator {

	/*
	 * En el array se crean instancias de los comandos del programa con su informacion y caracteristicas
	*/
	private static Command[] availableCommands = {
			
		new ListCommand("list", "L", "[L]ist", "Prints the list of available ships."),
		new HelpCommand("help", "H", "[H]elp", "Prints this help message."),
		new ResetCommand("reset", "R", "[R]eset", "Starts a new game."),
		new ExitCommand("exit", "E", "[E]xit", "Terminates the program."),
		new ShootCommand("shoot", "S", "[S]hoot", "UCM-Ship launches a missile."),
		new MoveCommand("move", "M", "[M]ove", "Moves UCM-Ship to the indicated direction."),
		new ShockwaveCommand("shockwave", "W", "Shock[W]ave", "UCM-Ship releases a shock wave."),
		new StringifyCommand("stringify", "G", "Strin[g]ify", "Stringify all objects."),
		new ListPrintersCommand("listPrinters", "P", "List [P]rinters", "Shows available printers."),
		new SaveCommand("save", "V", "Sa[V]e", "Save progress into a file."),
		new LoadCommand("load", "D", "Loa[D]", "Load progress from a file."),
		new NoneCommand("none", "N", "[N]one", "Skips cycle.")
	};

	/*
	 * Se hace la busqueda en el array del comando introducido
	*/
	public static Command parseCommand(String[] commandWords) throws CommandParseException {

		int i = 0;

		while (i < getAvailableCommands().length)
		{
			if (getAvailableCommands()[i].parse(commandWords) != null)
			{
				return getAvailableCommands()[i];
			}
			i++;
		}
		
		throw new CommandParseException("Cause of Exception:\n" + 
				"\t pr2.exceptions.CommandParseException: Wrong command: no such command is available.");
	}

	/*
	 * Se muestra en pantalla la ayuda de los comandos
	*/
	public static String commandHelp() {

		String help = "";

		for (int i = 0; i < getAvailableCommands().length; i++)
		{
			if (getAvailableCommands()[i].getHelp() != null)
			{
				help += getAvailableCommands()[i].helpText();
			}
		}

		return help;
	}

	// GETS & SETS
	
	public static Command[] getAvailableCommands() {
		
		return availableCommands;
	}

	public static void setAvailableCommands(Command[] availableCommands) {
		
		CommandGenerator.availableCommands = availableCommands;
	}
}