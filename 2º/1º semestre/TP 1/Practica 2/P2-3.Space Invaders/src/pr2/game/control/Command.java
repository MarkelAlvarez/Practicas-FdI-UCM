package pr2.game.control;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB)
*/

import pr2.game.exceptions.CommandExecuteException;
import pr2.game.exceptions.CommandParseException;
import pr2.game.logic.Game;

public abstract class Command {

	protected final String name;
	protected final String shortcut;
	private final String details ;
	private final String help;

	protected static final String incorrectNumArgsMsg = "Incorrect number of arguments";
	protected static final String incorrectArgsMsg = "Incorrect argument format";

	/*
	 * Se pasan en la constructora los valores necesarios de los atributos
	*/
	public Command(String name, String shortcut, String details, String help) {

		this.name = name;
		this.shortcut = shortcut;
		this.details = details;
		this.help = help;
	}

	/*
	 * Se declaran los metros que van a heredar las subclases
	*/
	public abstract boolean execute(Game game) throws CommandExecuteException;

	public abstract Command parse(String[] commandWords) throws CommandParseException;

	protected boolean matchCommandName(String name) {
		
		return (this.shortcut.equalsIgnoreCase(name) || this.name.equalsIgnoreCase(name));
	}

	public String helpText() {

		return details + " : " + help + "\n";
	}
	
	/*GETS & SETS*/
	
	public String getName() {
		return name;
	}

	public String getShortcut() {
		return shortcut;
	}

	public String getDetails() {
		return details;
	}

	public String getHelp() {
		return help;
	}

	public static String getIncorrectnumargsmsg() {
		return incorrectNumArgsMsg;
	}

	public static String getIncorrectargsmsg() {
		return incorrectArgsMsg;
	}
}