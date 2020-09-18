package tp.p1.lists;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

import tp.p1.objects.RegularShip;

public class RegularShipList { 

	private RegularShip[] list;
	private int contador;
	
	/*Inicializa la lista de destroyer ships y el contador de las mismas*/
	public RegularShipList(int naves) {

		list = new RegularShip[naves];
		contador = 0;
		
		for (int i = 0; i < 4; i++)
		{
			/*Añade una regula ship*/
			addRegular(1, i + 3);
		}

		if (naves == 8)
		{
			for (int i = 0; i < 4; i++)
			{
				/*Añade una regula ship*/
				addRegular(2, i + 3);
			}
		}
	}
	
	/*Añande una regular ship a la lista*/
	public void addRegular(int x, int y) {

		list[contador] = new RegularShip(x, y);
		contador++;
	}
	
	/*Quita una regular ship de la lista si la encuentra y devuelve si se ha eliminado ya que solo tiene 1 de vida*/
	public void deleteRegular(int x, int y) {
		
		int i = 0, j;
		/*Realiza la busqueda de naves*/
		while (i < contador)
		{
			/*Busca la nave a eliminar en las cordenadas pasadas al metodo*/
			if((list[i].getPosX() == x) && (list[i].getPosY() == y))
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
	
	/*Indica a toStringObjectAt() si se ha encontrado la regular ship*/
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

	/*Obtiene el icono de la regular ship*/
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
	
	public RegularShip[] getList() {
		
		return list;
	}
	
	public void setList(RegularShip[] rList) {
		
		this.list = rList;
	}
	
	public int getContador() {
		
		return contador;
	}
	
	public void setContador(int contador) {
		
		this.contador = contador;
	}

}
