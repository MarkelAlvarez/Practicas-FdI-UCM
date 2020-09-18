package pr2.game.exceptions;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

/*
 * Aqui se gestionan todas las excepciones relacionadas con la ejecucion de metodos
*/
public class CommandExecuteException extends Exception {

	private static final long serialVersionUID = -5466977732384133180L;

	public CommandExecuteException() {
	}

	public CommandExecuteException(String message) {
		super(message);
	}

	public CommandExecuteException(Throwable cause) {
		super(cause);
	}

	public CommandExecuteException(String message, Throwable cause) {
		super(message, cause);
	}

	public CommandExecuteException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
}