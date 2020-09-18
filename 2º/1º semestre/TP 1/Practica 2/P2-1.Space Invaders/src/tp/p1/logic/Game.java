package tp.p1.logic;

/*
* Juan Pablo Corella y Markel Alvarez (2ºB) 
*/

import tp.p1.objects.*;
import tp.p1.lists.*;

import java.util.Random;

public class Game {

	private Ovni Ovni;  
	private RegularShip RegularShip;
	private DestroyerShip DestroyerShip;
	private UCMShip UCMShip;
	private UCMShipLaser UCMShipLaser;
	private Bomb Bomb;
	
	private Boolean end;
	private Boolean sentido; //false = left / true = derecha
	private Boolean reset;
	private Boolean existOvni;
	private Level level;
	private Move move; 
	
	private RegularShipList rList;
	private DestroyerShipList dList;
	private BombList bList;
	
	private Random rand; 
	private int ciclos;
	private int puntuacion;
	
	/*Inicializa los atributos basicos de la clase*/
	public Game(Level level, Random rand) {

		this.level = level;
		this.rand = rand;
		end = false;
	}
	
	/*Inicializa los atributos y objetos que son necesarios para el funcionamiento del juego*/
	public void initGame() {

		RegularShip = new RegularShip(0, 0);	//inicializamos para tener un modelo para la lista y el toString
		DestroyerShip = new DestroyerShip(0, 0, 0);
		Ovni = new Ovni();
		Bomb = new Bomb(0, 0, 0);
		UCMShipLaser = new UCMShipLaser(0, 0);
		UCMShip = new UCMShip();

		rList = new RegularShipList(level.getNumRegularAliens());
		dList = new DestroyerShipList(level.getNumDestroyerAliens(), level.getLineDestroyer(), level.getColDestroyerAliens());
		bList = new BombList(level.getNumDestroyerAliens());
		
		ciclos = 0;
		puntuacion = 0;
		existOvni = false;
		sentido = false;
		reset = false;
	}
	
	/*USER COMMAND (Los siguientes metodos ejecutan los comandos introducidos)*/
	public void shoot() {

		if(UCMShip.getLaser())
		{
			System.out.println("Ya hay un laser en pantalla.");
		}
		else
		{
			/*Ubica el laser en las cordenadas de la nave y lo activa*/
			UCMShipLaser = new UCMShipLaser(UCMShip.getPosX(), UCMShip.getPosY());
			UCMShip.setLaser(true);
		}
	}
	
	public void shockwave() {
		
		if (UCMShip.getShockwave())
		{
			/*
			* Busca en la lista de naves y resta el daño de shockwave a las naves.
			* Si la vida se queda a 0 elimina la/las nave(s) con 0 de vida.
			*/
			for (int i = 0; i < rList.getContador(); i++)
			{
				/*Resta la vida a la nave*/
				rList.getList()[i].setResist(rList.getList()[i].getResist() - 1);
	
				if (rList.getList()[i].getResist() == 0)
				{
					/*Si la vida es 0 elimina la nave y vuelve a leer la posicion por si hay otra nave*/
					rList.deleteRegular(rList.getList()[i].getPosX(), rList.getList()[i].getPosY());
					--i; //tenemos que volver a comprobar de nuevo esta posicion
				}
			}
			
			/*
			* Busca en la lista de naves y resta el daño de shockwave a las naves.
			* Si la vida se queda a 0 elimina la/las nave(s) con 0 de vida.
			*/
			for (int i = 0; i < dList.getContador(); i++)
			{	
				/*Resta la vida a la nave*/
				dList.getList()[i].setResist(dList.getList()[i].getResist() - 1);
				
				if (dList.getList()[i].getResist() == 0)
				{
					/*Si la vida es 0 elimina la nave y vuelve a leer la posicion por si hay otra nave*/
					dList.deleteDestroyer(dList.getList()[i].getPosX(), dList.getList()[i].getPosY());
					--i; //tenemos que volver a comprobar de nuevo esta posicion
				}
			}
			
			UCMShip.setShockwave(false);
		}
		
		else 
		{
			System.out.println("No hay shockwave disponible.");
		}
	}
	
	public void reset(){

		setReset(true);
	}
	
	public void help() {
		
		System.out.println("move <left|right><1|2>: Moves UCM-Ship to the indicated direction.\r\n" + 
				"shoot: UCM-Ship launches a missile.\r\n" + 
				"shockWave: UCM-Ship releases a shock wave.\r\n" + 
				"list: Prints the list of available ships.\r\n" + 
				"reset: Starts a new game.\r\n" + 
				"help: Prints this help message.\r\n" +
				"exit: Terminates the program.\r\n"+
				"[none]: Skips one cycle.");
	}

	/*Proporciona dinamicamente la información sobre los objetos del juego*/	
	public void list() {

		System.out.print("[R]egular ship: Points: " + RegularShip.getPuntos() + " - Harm: 0 - Shield: " + RegularShip.getResist() + "\n");
		System.out.print("[D]estroyer ship: Points: " + DestroyerShip.getPuntos() + " - Harm: " + Bomb.getDamage() + " - Shield: " + DestroyerShip.getResist() + "\n");
		System.out.print("[O]vni: Points: " + Ovni.getPuntos() + " - Harm: 0 - Shield: " + Ovni.getResist() + "\n");
		System.out.print(UCMShip.getIcono() + ": Harm: " + UCMShipLaser.getDamage() + " - Shield: " + UCMShip.getResist() + "\n\n");	
	}

	public void exit() {

		setEnd(true);
	}
	
	/*COMPUTER ACTION*/
	public void computerAction() {

		int i = 0;

		/*Comprueba la dificultad del juego*/
		if ((ciclos % level.getSpeed()) == 0)
		{
			/*Para Regular y Destroyer*/
			if (!sentido) //Si el sentido es hacia la izquierda
			{
				move = Move.LEFT;
				/*Si la nave ha llegado a uno de los bordes 'move' se iguala a 'DOWN' para asi moverla hacia abajo*/
				while (i < rList.getContador())
				{
					if (rList.getList()[i].getPosY() == 0)
					{
						move = Move.DOWN;
						i = rList.getContador();
					}
					i++;
				}

				i = 0;
				/*Si la nave ha llegado a uno de los bordes 'move' se iguala a 'DOWN' para asi moverla hacia abajo*/
				while (i < dList.getContador())
				{
					if (dList.getList()[i].getPosY() == 0)
					{
						move = Move.DOWN;
						i = dList.getContador();
					}
					i++;
				}
			}
			else
			{
				move = Move.RIGHT;
				/*Si la nave ha llegado a uno de los bordes 'move' se iguala a 'DOWN' para asi moverla hacia abajo*/
				while (i < rList.getContador())
				{
					if (rList.getList()[i].getPosY() == 8)
					{
						move = Move.DOWN;
						i = rList.getContador();
					}
					i++;
				}

				i = 0;
				/*Si la nave ha llegado a uno de los bordes 'move' se iguala a 'DOWN' para asi moverla hacia abajo*/
				while (i < dList.getContador()) 
				{
					if (dList.getList()[i].getPosY() == 8)
					{
						move = Move.DOWN;
						i = dList.getContador();
					}
					i++;
				}
			}

			/*Depende de que valor tenga 'move' los aliens se moverán a un lado o a otro*/
			switch(move)
			{
				case LEFT:
					moveAliensLeft();
					break;
				case RIGHT:
					moveAliensRight();
					break;
				case DOWN:
					moveAliensDown();
					break;
				default:
					break;
			}
		}

		/*Movemos el ovni*/
		if (existOvni)
		{
			moveOvni(Ovni);
		}
		else
		{
			if(rand.nextDouble() < level.getFrecOvni())
			{
				existOvni = true;
				Ovni = new Ovni();
			}
		}

		/*Disparar*/
		for (int j = 0; j < dList.getContador(); j++)
		{
			/*Si la destroyer ship puede lanzar una bomba y la propababilidad lo permite se dispara*/
			if((!dList.getList()[j].getBomb()) && (rand.nextDouble() < level.getShootFrec()))
			{
				/*Se añade una bomba a la destroyer y se actualiza el estado de la bomba*/
				bList.addBomb(dList.getList()[j].getPosX(), dList.getList()[j].getPosY(), dList.getList()[j].getId());
				dList.updateBomb(dList.getList()[j].getId(), true);
			}
		}
	}
	
	/*UPDATE*/
	public void update() {

		int i = 0, j;

		/*Se comprueba la colisión entre objetos del juego*/
		colisiones();
		
		/*Se comprueba si tanto destroyer como regular ship han llegado a la altura de UCMShip*/
		while((!end) && (i < 9))
		{
			end = rList.isFound(7, i);
			i++;
		}

		i = 0;
		
		while((!end) && (i < 9))
		{
			end = dList.isFound(7, i);
			i++;
		}
		/*Si no se acaba el juego se ejecuta la siguinte...*/
		if (!end)
		{
			if  (Ovni.getPosY() < 0)
			{
				existOvni = false; 
			}

			/*
			* Si hay un laser en el tablero se mueve y se comprueba que no se sale del tablero.
			* Si no sale del tablero se comprueban las colisiones con los objetos del tablero.
			*/
			if (UCMShip.getLaser()) 
			{
				moveLaser(UCMShipLaser);

				if (UCMShipLaser.getPosX() < 0) //Comprueba si se va a salir del tablero
				{	
					UCMShip.setLaser(false);
				}
				else 
				{
					colisiones();
				}
			}

			/*Se mueve la bomba y si se sale del tablero se elimina*/
			for (j = 0; j < bList.getContador(); j++) 
			{
				moveBomb(bList.getList()[j]);

				/*Comprueba si se va a salir del tablero*/
				if (bList.getList()[j].getPosX() > 7)
				{
					bList.deleteBomb(bList.getList()[j].getPosX(), bList.getList()[j].getPosY(), dList);
					j--; //Se vuelve a comprobar esta posicion en la siguiente vuelta
				}
			}

			/*Se comprueba la colisión entre objetos del juego*/
			colisiones();
		}	
	}
	
	public void colisiones() {
		
		/*Colisión de laser con bomba*/
		if (UCMShip.getLaser() && bList.deleteBomb(UCMShipLaser.getPosX(), UCMShipLaser.getPosY(), dList)) 
		{
			UCMShip.setLaser(false);
		}
		
		/*Colisión de nave con bomba*/
		if(bList.deleteBomb(UCMShip.getPosX(), UCMShip.getPosY(), dList)) 
		{
			UCMShip.setResist(UCMShip.getResist() - 1);

			if (UCMShip.getResist() == 0) 
			{
				end = true;
				UCMShip.setIcono(UCMShip.getDeath());
			}
		}
		
		if (!end)
		{
			/*Colisión de laser con destroyer*/
			if (UCMShip.getLaser() && dList.isFound(UCMShipLaser.getPosX(), UCMShipLaser.getPosY())) 
			{
				dList.decreaseLife(UCMShipLaser.getPosX(), UCMShipLaser.getPosY(), UCMShipLaser.getDamage());
				UCMShip.setLaser(false);

				for (int i = 0; i < dList.getContador(); i++)
				{
					/*Si está muerto, se suman puntos*/
					if(dList.getList()[i].getResist() <= 0)
					{
						puntuacion += DestroyerShip.getPuntos();
						dList.deleteDestroyer(UCMShipLaser.getPosX(), UCMShipLaser.getPosY());
					}
				}
			}
			/*Colisión de laser con regular*/
			else if(UCMShip.getLaser() && rList.isFound(UCMShipLaser.getPosX(), UCMShipLaser.getPosY()))
			{
				rList.decreaseLife(UCMShipLaser.getPosX(), UCMShipLaser.getPosY(), UCMShipLaser.getDamage());
				UCMShip.setLaser(false);

				for (int i = 0; i < rList.getContador(); i++) 
				{
					/*Si está muerto, se suman puntos*/
					if(rList.getList()[i].getResist() <= 0) 
					{
						puntuacion += RegularShip.getPuntos();
						rList.deleteRegular(UCMShipLaser.getPosX(), UCMShipLaser.getPosY());
					}
				}
			}
			/*Colisión de laser con ovni*/
			else if (UCMShip.getLaser() && existOvni)
			{	
				if ((Ovni.getPosX() == UCMShipLaser.getPosX()) && (Ovni.getPosY() == UCMShipLaser.getPosY()))
				{
					Ovni.decreaseLife(UCMShipLaser.getDamage());
					UCMShip.setLaser(false);

					/*Si está muerto, suman puntos*/
					if(Ovni.getResist() <= 0)
					{
						puntuacion += Ovni.getPuntos();
						existOvni = false;
						UCMShip.setShockwave(true);
					}
				}
			}
		}
		
		if((rList.getContador() == 0) && (dList.getContador() == 0))
		{	
			end = true;
		}
	}
	
	/*Coloca objetos en tablero*/
	public String toStringObjectAt(int i, int j) {

		if((UCMShip.getPosX() == i) && (UCMShip.getPosY() == j))
		{
			return UCMShip.getIcono();
		}
		else if(rList.isFound(i, j))
		{
			return rList.iconFrom(i, j);
		}
		else if(dList.isFound(i, j))
		{
			return dList.iconFrom(i, j);
		}
		else if(bList.isFound(i, j))
		{
			return Bomb.getIcono();
		}
		else if(existOvni && (Ovni.getPosX() == i) && (Ovni.getPosY() == j))
		{
			return Ovni.getIcono();
		}
		else if(UCMShip.getLaser() && (UCMShipLaser.getPosX() == i) && (UCMShipLaser.getPosY() == j))
		{
			return UCMShipLaser.getIcono();
		}	
		else
		{
			return "";
		}
	}
	
	/*Mueve el ovni una posición*/
	public void moveOvni(Ovni ovni) {

		ovni.setPosY(ovni.getPosY() - 1);
	}
	
	/*Mueve los aliens a la izquierda*/
	public void moveAliensLeft(){
		
		for (int i = 0; i < rList.getContador(); i++)
		{
			rList.getList()[i].setPosY(rList.getList()[i].getPosY() - 1);
		}

		for (int i = 0; i < dList.getContador(); i++)
		{
			dList.getList()[i].setPosY(dList.getList()[i].getPosY() - 1);
		}
	}
	
	/*Mueve los aliens a la derecha*/
	public void moveAliensRight() {
		
		for (int i = 0; i < rList.getContador(); i++)
		{
			rList.getList()[i].setPosY(rList.getList()[i].getPosY() + 1);
		}

		for (int i = 0; i < dList.getContador(); i++)
		{
			dList.getList()[i].setPosY(dList.getList()[i].getPosY() + 1);
		}
	}
	
	/*Mueve los aliens hacia abajo*/
	public void moveAliensDown() {
		
		for (int i = 0; i < rList.getContador(); i++)
		{
			rList.getList()[i].setPosX(rList.getList()[i].getPosX() + 1);
		}

		for (int i = 0; i < dList.getContador(); i++)
		{
			dList.getList()[i].setPosX(dList.getList()[i].getPosX() + 1);
		}
		
		if(getSentido())
		{
			setSentido(false);
		}
		else
		{
			setSentido(true);
		}
	}
	
	/*Mueve UCMShip hacia la izquierda 'cantidad' pasos*/
	public void moveShipLeft(int pasos) {
		
		UCMShip.setPosY(UCMShip.getPosY() - pasos);
		
		if (UCMShip.getPosY() < 0)
		{
			UCMShip.setPosY(0);
		}
	}

	/*Mueve UCMShip hacia la derecha 'cantidad' pasos*/
	public void moveShipRight (int pasos) {

		UCMShip.setPosY(UCMShip.getPosY() + pasos);
		
		if (UCMShip.getPosY() > 8)
		{
			UCMShip.setPosY(8);
		}
	}
	
	/*Mueve la bomba hacia abajo*/
	public void moveBomb(Bomb bomb) {

		bomb.setPosX(bomb.getPosX() + 1);		
	}
	
	/*Mueve el laser de UCMShip hacia arriba*/
	public void moveLaser(UCMShipLaser laser) {

		laser.setPosX(laser.getPosX() - 1);
	}

	/*GETS y SETS*/
	
	public UCMShip getUCMShip() {

		return UCMShip;
	}
	
	public Boolean getEnd() {

		return end;
	}
	
	public void setEnd(Boolean end) {

		this.end = end;
	}
	
	public Boolean getSentido() {

		return sentido;
	}
	
	public void setSentido(Boolean sentido) {

		this.sentido = sentido;
	}
	
	public RegularShipList getrList() {

		return rList;
	}

	public DestroyerShipList getdList() {

		return dList;
	}
	
	public BombList getbList() {

		return bList;
	}

	public int getCiclos() {

		return ciclos;
	}
	
	public void setCiclos(int ciclos) {

		this.ciclos = ciclos;
	}
	
	public int getPuntuacion() {

		return puntuacion;
	}
	
	public void setPuntuacion(int puntuacion) {

		this.puntuacion = puntuacion;
	}
	
	public Boolean getReset() {

		return reset;
	}
	
	public void setReset(Boolean reset) {

		this.reset = reset;
	}
	
	public Boolean getExistOvni() {

		return existOvni;
	}
	
	public void setExistOvni(Boolean existOvni) {

		this.existOvni = existOvni;
	}

}
