package tp.p1.control;

import tp.p1.logic.Game;

public abstract class Command {

	protected final String name;
	protected final String shortcut;
	private final String details ;
	private final String help;

	protected static final String incorrectNumArgsMsg = "Incorrect number of arguments";
	protected static final String incorrectArgsMsg = "Incorrect argument format";

	public Command(String name, String shortcut, String details, String help) {

		this.name = name;
		this.shortcut = shortcut;
		this.details = details;
		this.help = help;
	}

	public abstract boolean execute(Game game);

	public abstract Command parse(String[] commandWords);

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
