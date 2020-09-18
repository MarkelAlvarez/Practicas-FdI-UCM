/**
  @file diccionario.h

  Implementación dinámica del TAD Diccionario utilizando
  árboles de búsqueda.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Marco Antonio Gómez Martín, 2012;  Mercedes Gómez y José Luis Sierra, 2017
*/

#ifndef __DICCIO_H
#define __DICCIO_H

#include <fstream>
#include <cstddef>
#include "pila.h" // Usado internamente por los iteradores
using namespace std;


/**
 Implementación dinámica del TAD Diccionario utilizando 
 árboles de búsqueda (no auto-balanceados).

 Las operaciones son:

 - diccionarioVacio: operación generadora que construye
 un diccionario vacío.

 - inserta(clave, valor): modificadora que añade una 
 nueva pareja (clave, valor) al diccionario. Si la
 clave ya estaba se sustituye el valor.

 - borra(clave): operación modificadora. Elimina la
 clave del diccionario.  Si la clave no está,
 la operación no tiene efecto.

 - valorDe(clave): operación observadora que devuelve
 el valor asociado a una clave. Es un error preguntar
 por una clave que no existe.

 - contiene(clave): operación observadora. Sirve para
 averiguar si se ha introducido una clave en el diccionario.

 - esVacio(): operacion observadora que indica si
 el diccionario tiene alguna clave introducida.

 @author Marco Antonio Gómez Martín ( con ligeras adaptaciones de Mercedes Gómez y José Luis Sierra)
 */



/// Excepciones generadas por algunos métodos
class EClaveErronea {};

class EAccesoNoValido{};


template <class tClave, class tValor>
class Diccionario {
private:
	/**
	Clase nodo que almacena internamente la pareja (clave, valor)
	y los punteros al hijo izquierdo y al hijo derecho.
	*/
	class Nodo {
	public:
		Nodo() : _iz(NULL), _dr(NULL) {}
		Nodo(const tClave &clave, const tValor &valor)
			: _clave(clave), _valor(valor), _iz(NULL), _dr(NULL) {}
		Nodo(Nodo *iz, const tClave &clave, const tValor &valor, Nodo *dr)
			: _clave(clave), _valor(valor), _iz(iz), _dr(dr) {}

		tClave _clave;
		tValor _valor;
		Nodo *_iz;
		Nodo *_dr;
	};

	/**
	Elimina todos los nodos de una estructura arbórea
	que comienza con el puntero ra.
	Se admite que el nodo sea NULL (no habrá nada que
	liberar).
	*/
	static void libera(Nodo *ra) {
		if (ra != NULL) {
			libera(ra->_iz);
			libera(ra->_dr);
			delete ra;
		}
	}

	/**
	Copia la estructura jerárquica de nodos pasada
	como parámetro (puntero a su raiz) y devuelve un
	puntero a una nueva estructura jerárquica, copia
	de anterior.
	*/
	static Nodo *copia(Nodo *ra) {
		if (ra == NULL)
			return NULL;
		else
			return new Nodo(copia(ra->_iz),	ra->_clave, ra->_valor,	copia(ra->_dr));
	}

	/**
	Busca una clave en la estructura jerárquica de
	nodos cuya raíz se pasa como parámetro, y devuelve
	el nodo en la que se encuentra (o NULL si no está).
	@param p Puntero a la raíz de la estructura de nodos
	@param clave Clave a buscar
	*/
	static Nodo *buscaAux(Nodo *p, const tClave &clave) {

		if (p == NULL)
			return NULL;
		else if (p->_clave == clave)
			return p;
		else if (clave < p->_clave)
			return buscaAux(p->_iz, clave);
		else
			return buscaAux(p->_dr, clave);
	}

	/**
	Inserta una pareja (clave, valor) en la estructura
	jerárquica que comienza en el puntero pasado como parámetro.
	Ese puntero se admite que sea NULL, por lo que se creará
	un nuevo nodo que pasará a ser la nueva raíz de esa
	estructura jerárquica. El método devuelve un puntero a la
	raíz de la estructura modificada. En condiciones normales
	coincidirá con el parámetro recibido; sólo cambiará si
	la estructura era vacía.
	@param clave Clave a insertar. Si ya aparecía en la
	estructura de nodos, se sobreescribe el valor.
	@param valor Valor a insertar.
	@param p Puntero al nodo raíz donde insertar la pareja.
	@return Nueva raíz (o p si no cambia).
	*/
	static Nodo *insertaAux(const tClave &clave, const tValor &valor, Nodo *p)
	{
		if (p == NULL)
		{
			return new Nodo(clave, valor);
		}
		else if (p->_clave == clave)
		{
			p->_valor = valor;
			return p;
		}
		else if (clave < p->_clave)
		{
			p->_iz = insertaAux(clave, valor, p->_iz);
			return p;
		}
		else
		{ // (clave > p->_clave)
			p->_dr = insertaAux(clave, valor, p->_dr);
			return p;
		}
	}

	/**
	Elimina (si existe) la clave/valor de la estructura jerárquica
	de nodos apuntada por p. Si la clave aparecía en la propia raíz,
	ésta cambiará, por lo que se devuelve la nueva raíz. Si no cambia
	se devuelve p.

	@param p Raíz de la estructura jerárquica donde borrar la clave.
	@param clave Clave a borrar.
	@return Nueva raíz de la estructura, tras el borrado. Si la raíz
	no cambia, se devuelve el propio p.
	*/
	static Nodo *borraAux(Nodo *p, const tClave &clave)
	{
		if (p == NULL)
			return NULL;
		else
			if (clave == p->_clave)
				return borraRaiz(p);
			else
				if (clave < p->_clave)
				{
					p->_iz = borraAux(p->_iz, clave);
					return p;
				}
				else
				{ // clave > p->_clave
					p->_dr = borraAux(p->_dr, clave);
					return p;
				}
	}

	/**
	Borra la raíz de la estructura jerárquica de nodos
	y devuelve el puntero a la nueva raíz que garantiza
	que la estructura sigue siendo válida para un árbol de
	búsqueda (claves ordenadas).
	*/
	static Nodo *borraRaiz(Nodo *p)
	{
		Nodo *aux;

		if (p->_iz == NULL)
		{ // Si no hay hijo izquierdo, la raíz pasa a ser el hijo derecho
			aux = p->_dr;
			delete p;
			return aux;
		}
		else
			if (p->_dr == NULL)
			{ // Si no hay hijo derecho, la raíz pasa a ser el hijo izquierdo
				aux = p->_iz;
				delete p;
				return aux;
			}
			else
			{ // La nueva raíz es el elemento más pequeño del hijo derecho (sucesor de la actual raíz)
				return mueveMinYBorra(p);
			}
	}

	/**
	Método auxiliar para el borrado; recibe un puntero a la
	raíz a borrar. Busca el elemento más pequeño del hijo derecho
	que se convertirá en la raíz (que devolverá), borra la antigua
	raíz (p) y "cose" todos los punteros, de forma que ahora:

	- El mínimo pasa a ser la raíz, cuyo hijo izquierdo y
	derecho eran los hijos izquierdo y derecho de la raíz
	antigua.
	- El hijo izquierdo del padre del elemento más pequeño
	pasa a ser el antiguo hijo derecho de ese mínimo.
	*/
	static Nodo *mueveMinYBorra(Nodo *p)
	{
		// Vamos bajando hasta que encontramos el elemento
		// más pequeño (aquel que no tiene hijo izquierdo).
		// Vamos guardando también el padre (que será null
		// si el hijo derecho es directamente el elemento
		// más pequeño).
		Nodo *padre = NULL;
		Nodo *aux = p->_dr;

		while (aux->_iz != NULL)
		{
			padre = aux;
			aux = aux->_iz;
		}

		// aux apunta al elemento más pequeño.
		// padre apunta a su padre (si el nodo es hijo izquierdo)

		// Dos casos dependiendo de si el sucesor es la raíz
		// del hijo derecho del nodo a borrar (=> padre == NULL) o no (=> padre != NULL)
		// 
		if (padre != NULL){  // el sucesor no es la raíz del subarbol derecho sino un nodo más profundo
			padre->_iz = aux->_dr; // el hijo derecho del sucesor pasa a ser el nuevo izquierdo de su padre
								   // el sucesor ocupa el puesto del que hay que borrar...
			aux->_iz = p->_iz; //... su hijo izdo (que antes era null) pasa a ser el izquierdo del que borras
			aux->_dr = p->_dr; // ... su hijo dcho pasa a ser el derecho del que borras
		}
		else { // el sucesor es la raíz del subarbol derecho de la clave a borrar
			aux->_iz = p->_iz;
		}

		delete p; // eliminamos el nodo con la clave a borrar
		return aux; // devolvemos la nueva raíz
	}

	/**
	Puntero a la raíz de la estructura jerárquica
	de nodos.
	*/
	Nodo *_ra;

public:
	/** Constructor; operacion diccionarioVacio */
	Diccionario() : _ra(NULL) {
	}

	/** Destructor; elimina la estructura jerárquica de nodos. */
	~Diccionario() {
		//libera();
		libera(_ra);
		_ra = NULL;
	}


	/** Constructor copia */
	Diccionario(const Diccionario<tClave, tValor> &other) : _ra(NULL) {
		_ra = copia(other._ra);
	}

	/** Operador de asignación */
	Diccionario<tClave, tValor> &operator=(const Diccionario<tClave, tValor> &other) {
		if (this != &other) {
			libera(_ra);
			_ra = copia(other._ra);
		}
		return *this;
	}

	/**
	 Operación observadora que devuelve si el diccionario es vacío 
	 (no contiene elementos) o no.
	 */
	bool esVacio() const {
		return _ra == NULL;
	}

	/**
	 Operación observadora que permite averiguar si una clave
	 determinada está o no en el diccionario.

	 @param clave Clave por la que se pregunta.
	 @return true si el diccionario contiene un valor asociado
	 a esa clave.
	 */
	bool contiene(const tClave &clave) const { 
		return (buscaAux(_ra, clave) != NULL) ? true : false; 
	}

	
	/**
	 Operación observadora que devuelve el valor asociado
	 a una clave dada.

	 @param clave Clave por la que se pregunta.
	 */
	const tValor& valorPara(const tClave &clave) const { 
		Nodo *p = buscaAux(_ra, clave); 
		if (p == NULL)
			throw EClaveErronea();
		return p->_valor;
	}

	
	/**
	 Operación mutadora que añade una nueva clave/valor
	 a un diccionario.
	 @param clave Clave nueva.
	 @param valor Valor asociado a esa clave. Si la clave
	 ya se había insertado previamente, sustituimos el valor
	 viejo por el nuevo.
	 */
	void inserta(const tClave &clave, const tValor &valor) {
		_ra = insertaAux(clave, valor, _ra);
	}

	/**
	 Operación modificadora que elimina una clave del diccionario.
	 Si la clave no existía la operación no tiene efecto.
	 @param clave Clave a eliminar.
	 */
	void borra(const tClave &clave) {
		_ra = borraAux(_ra, clave);
	}     

	  // //
	  // ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	  // //

	  /**
	  Clase interna que implementa un iterador que permite recorrer el 
	  árbol en inorden pero no permite modificarlo.
	  */
	  class ConstIterator {
	  public:
		  void next() {
			  if (_act == NULL) throw EAccesoNoValido();

			  // Si hay hijo derecho, saltamos al primero
			  // en inorden del hijo derecho
			  if (_act->_dr != NULL)
				  _act = primeroInOrden(_act->_dr);
			  else {
				  // Si no, vamos al primer ascendiente
				  // no visitado. Para eso consultamos
				  // la pila; si ya está vacía, no quedan
				  // ascendientes por visitar
				  if (_ascendientes.esVacia())
					  _act = NULL;
				  else {
					  _act = _ascendientes.cima();
					  _ascendientes.desapila();
				  }
			  }
		  }

		  const tClave &clave() const {
			  if (_act == NULL) throw EAccesoNoValido();
			  return _act->_clave;
		  }

		  const tValor &valor() const {
			  if (_act == NULL) throw EAccesoNoValido();
			  return _act->_valor;
		  }

		  bool operator==(const ConstIterator &other) const {
			  return _act == other._act;
		  }

		  bool operator!=(const ConstIterator &other) const {
			  return !(this->operator==(other));
		  }

	  protected:
		  // Para que pueda construir objetos del
		  // tipo iterador
		  friend class Diccionario;

		  ConstIterator() : _act(NULL) {}
		  ConstIterator(Nodo *act) {
			  _act = primeroInOrden(act);
		  }

		  /**
		  Busca el primer elemento en inorden de
		  la estructura jerárquica de nodos pasada
		  como parámetro; va apilando sus ascendientes
		  para poder "ir hacia atrás" cuando sea necesario.
		  @param p Puntero a la raíz de la subestructura.
		  */
		  Nodo *primeroInOrden(Nodo *p) {
			  if (p == NULL)
				  return NULL;

			  while (p->_iz != NULL) {
				  _ascendientes.apila(p);
				  p = p->_iz;
			  }
			  return p;
		  }

		  // Puntero al nodo actual del recorrido
		  // NULL si hemos llegado al final.
		  Nodo *_act;

		  // Ascendientes del nodo actual
		  // aún por visitar
		  Pila<Nodo*> _ascendientes;
	  };

	  /**
	  Devuelve el iterador constante al principio del
	  diccionario (clave más pequeña).
	  @return iterador al principio del recorrido;
	  coincidirá con cend() si el diccionario está vacío.
	  */
	  ConstIterator cbegin() const {
		  return ConstIterator(_ra);
	  }

	  /**
	  @return Devuelve un iterador al final del recorrido
	  (fuera de éste).
	  */
	  ConstIterator cend() const {
		  return ConstIterator(NULL);
	  }

	  ConstIterator cbusca(const tClave &c) const {
		  Pila<Nodo*> ascendientes;
		  Nodo *p = _ra;
		  while ((p != NULL) && (p->_clave != c)) {
			  if (p->_clave > c) {
				  ascendientes.apila(p);
				  p = p->_iz;
			  }
			  else
				  p = p->_dr;
		  }
		  ConstIterator ret;
		  ret._act = p;
		  if (p != NULL)
			  ret._ascendientes = ascendientes;
		  return ret;
	  }

	  // //
	  // ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	  // //

	  /**
	  Clase interna que implementa un iterador sobre
	  la árbol de búsqueda que permite recorrer la lista e incluso
	  alterar el valor de sus elementos.
	  */
	  class Iterator {
	  public:
		  void next() {
			  if (_act == NULL) throw EAccesoNoValido();

			  // Si hay hijo derecho, saltamos al primero
			  // en inorden del hijo derecho
			  if (_act->_dr != NULL)
				  _act = primeroInOrden(_act->_dr);
			  else {
				  // Si no, vamos al primer ascendiente
				  // no visitado. Para eso consultamos
				  // la pila; si ya está vacía, no quedan
				  // ascendientes por visitar
				  if (_ascendientes.esVacia())
					  _act = NULL;
				  else {
					  _act = _ascendientes.cima();
					  _ascendientes.desapila();
				  }
			  }
		  }

		  const tClave &clave() const {
			  if (_act == NULL) throw EAccesoNoValido();
			  return _act->_clave;
		  }

		  tValor &valor() const {  
			  if (_act == NULL) throw EAccesoNoValido();
			  return _act->_valor;
		  }

		  void setVal(const tValor& valor) {
			  if (_act == NULL) throw EAccesoNoValido();
			  _act->_valor = valor;
		  }

		  bool operator==(const Iterator &other) const {
			  return _act == other._act;
		  }

		  bool operator!=(const Iterator &other) const {
			  return !(this->operator==(other));
		  }

	  protected:
		  // Para que pueda construir objetos del
		  // tipo iterador
		  friend class Diccionario;

		  Iterator() : _act(NULL) {}
		  Iterator(Nodo *act) {
			  _act = primeroInOrden(act);
		  }

		  /**
		  Busca el primer elemento en inorden de
		  la estructura jerárquica de nodos pasada
		  como parámetro; va apilando sus ascendientes
		  para poder "ir hacia atrás" cuando sea necesario.
		  @param p Puntero a la raíz de la subestructura.
		  */
		  Nodo *primeroInOrden(Nodo *p) {
			  if (p == NULL)
				  return NULL;

			  while (p->_iz != NULL) {
				  _ascendientes.apila(p);
				  p = p->_iz;
			  }
			  return p;
		  }

		  // Puntero al nodo actual del recorrido
		  // NULL si hemos llegado al final.
		  Nodo *_act;

		  // Ascendientes del nodo actual
		  // aún por visitar
		  Pila<Nodo*> _ascendientes;
	  };

	  /**
	  Devuelve el iterador al principio del recorrido.
	  @return iterador al principio del recorrido;
	  coincidirá con final() si el recorrido está vacío.
	  */
	  Iterator begin() {
		  return Iterator(_ra);
	  }

	  /**
	  @return Devuelve un iterador al final del recorrido
	  (fuera de éste).
	  */
	  Iterator end() const {
		  return Iterator(NULL);
	  }

	  Iterator busca(const tClave &c) {
		  Pila<Nodo*> ascendientes;
		  Nodo *p = _ra;
		  while ((p != NULL) && (p->_clave != c)) {
			  if (p->_clave > c) {
				  ascendientes.apila(p);
				  p = p->_iz;
			  }
			  else
				  p = p->_dr;
		  }
		  Iterator ret;
		  ret._act = p;
		  if (p != NULL)
			  ret._ascendientes = ascendientes;
		  return ret;
	  }	
};

#endif // __DICCIO_H
