package pr2.game.logic.gameObjects.lists;

/*
* Juan Pablo Corella y Markel Alvarez (2ÂºB)
*/

import pr2.game.logic.gameObjects.*;

public class GameObjectBoard {

	private GameObject[] objects;
	private int currentObjects;

	/*
	 * Inicializaciï¿½n del tablero
	*/
	public GameObjectBoard (int width, int height)
	{
		objects = new GameObject[width * height];

		for (int i = 0; i < width * height; i++)
		{
			objects[i] = null;
		}
		currentObjects = 0;
	}

	private int getCurrentObjects () {

		return currentObjects;
	}

	/*
	 * Añade nuevos objetos a la lista
	*/
	public void add (GameObject object) {

		objects[currentObjects] = object;
		currentObjects++;
	}

	/*
	 * Obtiene el objeto que hay en unas coordenadas
	*/
	private GameObject getObjectInPosition (int x, int y) {

		int i = 0;

		while (i < currentObjects)
		{
			if (objects[i].isOnPosition(x, y))
			{
				return objects[i];
			}
			i++;
		}

		return null;
	}

	private int getIndex(int x, int y) {

		int i = 0;

		while (i < currentObjects)
		{
			if (objects[i].isOnPosition(x, y))
			{
				return i;
			}
			i++;
		}

		return -1;
	}

	/*
	 * Aquí se actualiza el estado de juego. Primero se comprueban si hay colision,
	 * si es afirmativo se eliminara(n) de la lista. Despues se repite la operación
	 * pero moviendo los objetos y volviendo a comprobar las colisiones para luego
	 * eliminar todo aquello que no tenga vida de la lista
	*/
	public void update() {
		
		for (int i = 0; i < currentObjects; i++)
		{
			if (objects[i].isAlive()) 
			{
				objects[i].move();
				checkAttacks(objects[i]);
			}
		}
		
		removeDead();
	}

	/*
	 * Aqui se comprueban las colisiones de los proyectiles con los elementos del juego
	*/
	private void checkAttacks(GameObject object) {
		
		int i = 0;
			
		while (i < currentObjects)
		{
			for (int j = 0; j < currentObjects; j++)
			{
				if (objects[j].isAlive())
				{
					if(object.performAttack(objects[j]))
					{
						object.getDamage(object.getLive());
						i = currentObjects;
					}
				}
			}
			i++;
		}
	}
	
	/*
	 * Este metodo se encarga de gestionar la explosion de la ExplosiveShip
	*/
	public void explosion(int x, int y, int damage) {
		
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if(!(i == 0 && j == 0))
				{
					GameObject aux = getObjectInPosition(x + i, y + j);
					if(aux != null)
					{
						aux.receiveExplosiveAttack(damage);
					}
				}
			}
		}
	}

	/*
	 * Se mueven los objetos del juego despues de haber hecho todas las comprobaciones
	 * correspondientes
	*/
	public void computerAction() {
		
		for (int i = 0; i < currentObjects; i++)
		{
			objects[i].computerAction();
		}
	}

	/*
	 * Aquí se eliminan los elementos del juego sin vida
	*/
	private void removeDead() {
		
		for (int i = currentObjects-1; i >= 0; i--)
		{
			if (!objects[i].isAlive())
			{
				objects[i].onDelete();
			}
		}
	}

	/*
	 * Este algoritmo complementa al anterior en la eliminación de los objectos en la lista
	*/
	public void remove(GameObject object) {

		int i = 0;

		while (i < currentObjects)
		{
			if (objects[i] == object)
			{
				for (int j = i + 1; j < currentObjects; j++)
				{
					objects[i] = objects[j];
					i++;
				}
				objects[currentObjects - 1] = null;
				currentObjects--;
				i = currentObjects;
			}
			i++;
		}
	}

	public String toString(int i, int j) {

		for (int aux = 0; aux < currentObjects; aux++)
		{
			if (objects[aux].isOnPosition(i, j))
			{
				return objects[aux].toString();
			}
		}

		return "";
	}

	/*
	 * Recibe la información de los objetos en modo texto
	*/
	public String toStringifier() {
		
		String str = "";
		
		for (int i = 0; i < currentObjects; i++)
		{
			str += objects[i].toStringifier();
		}
		
		return str;
	}
}