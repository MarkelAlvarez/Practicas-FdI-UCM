package pr2.game.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

public class MyStringUtils {

	/*Repite el elemento*/
	public static String repetir(String elemento, int longitud) {
		
		int i;
		String resultado = "";

		for (i = 0; i < longitud; i++) {
			
			resultado += elemento;
		}

		return resultado;
	}

	/*Centra los objetos*/
	public static String centrar(String texto, int longitud) {

		String out = String.format("%"+ longitud + "s%s%" + longitud + "s", "", texto, "");
		float medio = (out.length()/2);
		float principio = medio - (longitud/2);
		float fin = principio + longitud;

		return out.substring((int)principio, (int)fin);
	} 
}