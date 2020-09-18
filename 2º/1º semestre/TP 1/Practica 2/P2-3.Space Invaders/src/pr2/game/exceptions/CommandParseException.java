package pr2.game.exceptions;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

/*
 * Aqui se gestionan todas las excepciones relacionadas con el parse de los datos introducidos 
*/
public class CommandParseException extends Exception {

	private static final long serialVersionUID = 2076404981021992986L;

	public CommandParseException() {
	}

	public CommandParseException(String message) {
		super(message);
	}

	public CommandParseException(Throwable cause) {
		super(cause);
	}

	public CommandParseException(String message, Throwable cause) {
		super(message, cause);
	}

	public CommandParseException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
}