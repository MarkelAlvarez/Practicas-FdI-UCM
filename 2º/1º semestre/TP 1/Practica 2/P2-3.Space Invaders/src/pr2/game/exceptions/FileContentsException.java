package pr2.game.exceptions;

/*
 * Juan Pablo Corella y Markel Alvarez (2ºB)
*/

/*
 * Aqui se gestionan todas las excepciones relacionadas los ficheros 
*/
public class FileContentsException extends Exception {

	private static final long serialVersionUID = 1224929816548215556L;

	public FileContentsException() {
	}

	public FileContentsException(String message) {
		super(message);
	}

	public FileContentsException(Throwable cause) {
		super(cause);
	}

	public FileContentsException(String message, Throwable cause) {
		super(message, cause);
	}

	public FileContentsException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
}