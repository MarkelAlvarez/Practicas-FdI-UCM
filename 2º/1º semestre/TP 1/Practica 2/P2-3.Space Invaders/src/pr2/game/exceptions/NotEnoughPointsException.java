package pr2.game.exceptions;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

/*
 * Aqui se gestionan todas las excepciones relacionadas con la compra de misiles
*/
public class NotEnoughPointsException extends Exception {

	private static final long serialVersionUID = 3576653426992805524L;

	public NotEnoughPointsException() {
	}

	public NotEnoughPointsException(String message) {
		super(message);
	}

	public NotEnoughPointsException(Throwable cause) {
		super(cause);
	}

	public NotEnoughPointsException(String message, Throwable cause) {
		super(message, cause);
	}

	public NotEnoughPointsException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
}