package tp.p1.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

import tp.p1.logic.MyStringUtils;

public class GamePrinter {
	
	int numRows; 
	int numCols;
	String[][] board;
	final String space = " ";
	
	/*Inicializa los atributos de la clase*/
	public GamePrinter(Game game, int rows, int cols) {

		this.numRows = rows;
		this.numCols = cols;	

		encodeGame(game);
	}
	
	/*Situa a las naves y objetos del juego en el tablero*/
	private void encodeGame(Game game) {

		board = new String[numRows][numCols];

		for(int i = 0; i < numRows; i++)
		{
			for(int j = 0; j < numCols; j++)
			{
				board[i][j] = game.toStringObjectAt(i, j);
			}
		}
	}
	
	/*Dibuja el tablero*/
	public String toString() {

		int cellSize = 7;
		int marginSize = 2;
		String vDelimiter = "|";
		String hDelimiter = "-";
		
		String rowDelimiter = MyStringUtils.repetir(hDelimiter, (numCols * (cellSize + 1)) - 1);
		String margin = MyStringUtils.repetir(space, marginSize);
		String lineDelimiter = String.format("%n%s%s%n", margin + space, rowDelimiter);
		
		StringBuilder str = new StringBuilder();
		
		str.append(lineDelimiter);
		
		for(int i = 0; i < numRows; i++)
		{
			str.append(margin).append(vDelimiter);

			for (int j = 0; j < numCols; j++)
			{
				str.append( MyStringUtils.centrar(board[i][j], cellSize)).append(vDelimiter); //center: centrar el string de i, j poniendolo en la mitad de la celda
			}

			str.append(lineDelimiter);
		}

		return str.toString();
	}
}