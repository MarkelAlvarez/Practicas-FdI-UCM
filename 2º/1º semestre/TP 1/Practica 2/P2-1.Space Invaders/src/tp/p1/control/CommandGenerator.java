package tp.p1.control;

import tp.p1.control.commands.*;

public class CommandGenerator {

	private static Command[] availableCommands = {
		new ListCommand("list", "L", "[L]ist", "Prints the list of available ships."),
		new HelpCommand("help", "H", "[H]elp", "Prints this help message."),
		new ResetCommand("reset", "R", "[R]eset", "Starts a new game."),
		new ExitCommand("exit", "E", "[E]xit", "Terminates the program."),
		new ShootCommand("shoot", "S", "[S]hoot", "UCM-Ship launches a missile."),
		new MoveCommand("move", "M", "[M]ove", "Moves UCM-Ship to the indicated direction."),
		new ShockwaveCommand("shockwave", "W", "Shock[W]ave", "UCM-Ship releases a shock wave."),
		new NoneCommand("none", "N", "[N]one", "Skips cycle.")
	};

	public static Command parseCommand(String[] commandWords) {

		int i = 0;

		while (i < getAvailableCommands().length)
		{
			if (getAvailableCommands()[i].parse(commandWords) != null)
			{
				return getAvailableCommands()[i];
			}
			i++;
		}

		return null;
	}

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

	public static Command[] getAvailableCommands() {
		return availableCommands;
	}

	public static void setAvailableCommands(Command[] availableCommands) {
		CommandGenerator.availableCommands = availableCommands;
	}

}
