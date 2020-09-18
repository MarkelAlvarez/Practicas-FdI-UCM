package tp.p1.lists;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

import tp.p1.objects.DestroyerShip;

public class DestroyerShipList {

	private DestroyerShip[] list;
	private int contador;
	
	/*Inicializa la lista de destroyer ships y el contador de las mismas*/
	public DestroyerShipList(int naves, int fila, int col) {

		list = new DestroyerShip[naves];
		contador = 0;
		
		for (int i = 0; i < naves; i++)
		{
			addDestroyer(fila, i + col);
		}
	}
	
	/*Añade una destroyer ship a la lista*/
	public void addDestroyer(int x, int y) {

		list[contador] = new DestroyerShip(x, y, contador);
		contador++;
	}

	/*Quita una destroyer ship de la lista si la encuentra y devuelve si se ha eliminado ya que solo tiene 1 de vida*/
	public void deleteDestroyer(int x, int y) {

		int i = 0, j;
		/*Realiza la busqueda de naves*/
		while (i < contador)
		{
			if(list[i].getPosX() == x && list[i].getPosY() == y)
			{
				for (j = i + 1; j < contador; j++)
				{
					list[i] = list[j];
					i++;
				}
				contador--;
			}
			i++;
		}
	}

	/*Indica a toStringObjectAt() si se ha encontrado la destroyer*/
	public Boolean isFound(int x, int y) {

		int i = 0;
		Boolean found = false;
		
		while((i < contador) && (!found))
		{
			if((list[i].getPosX() == x) && (list[i].getPosY() == y))
			{
				found = true;
			}
			i++;
		}

		return found;
	}

	/*Reduce la vida de la nave por la cantidad que le paseamos a 'damage'*/
	public void decreaseLife(int x, int y, int damage) {

		int i = 0;
		
		while (i < contador)
		{
			if((list[i].getPosX() == x) && (list[i].getPosY() == y))
			{
				list[i].setResist(list[i].getResist() - damage);
				i = contador;
			}
			i++;
		}
	} 

	/*Actualiza el estado de la bomba de la nave*/
	public void updateBomb(int id, Boolean active) {

		int i = 0;

		while(i < contador)
		{
			if(list[i].getId() == id)
			{
				list[i].setBomb(active);
				i = contador;
			}
			
			i++;
		}
	}
	
	/*Obtiene el icono de la destroyer*/
	public String iconFrom(int x, int y) {

		int i = 0;
		String icon = "";
		
		while (i < contador)
		{
			if((list[i].getPosX() == x) && (list[i].getPosY() == y))
			{
				icon = list[i].getIcono();
				i = contador;
			}
			i++;
		}
		
		return icon;
	}

	/*GETS y SETS*/
	
	public DestroyerShip[] getList() {
		
		return list;
	}
	
	public void setList(DestroyerShip[] list) {
		
		this.list = list;
	}
	
	public int getContador() {
		
		return contador;
	}
	
	public void setContador(int contador) {
		
		this.contador = contador;
	}
	
}
