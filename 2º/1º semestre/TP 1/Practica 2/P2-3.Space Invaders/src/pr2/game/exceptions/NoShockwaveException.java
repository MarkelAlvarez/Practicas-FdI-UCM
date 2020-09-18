package pr2.game.exceptions;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

/*
 * Aqui se gestionan todas las excepciones relacionadas con el shockwave
*/
public class NoShockwaveException extends Exception {

	private static final long serialVersionUID = -3286753536717731372L;

	public NoShockwaveException() {
	}

	public NoShockwaveException(String message) {
		super(message);
	}

	public NoShockwaveException(Throwable cause) {
		super(cause);
	}

	public NoShockwaveException(String message, Throwable cause) {
		super(message, cause);
	}

	public NoShockwaveException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
}