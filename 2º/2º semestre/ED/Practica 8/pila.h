/**
  @file Pila.h

  Implementación del TAD Pila utilizando una
  lista enlazada simple de nodos.

  Estructura de Datos y Algoritmos
  Facultad de Informática
  Universidad Complutense de Madrid

 (c) Marco Antonio Gómez Martín, 2012  Mercedes Gómez Albarrán, 2016
*/
#ifndef __PILA_LISTA_ENLAZADA_H
#define __PILA_LISTA_ENLAZADA_H
#include <cstddef>

/// Excepciones generadas por algunos métodos
class EPilaVacia {};

/**
 Implementación del TAD Pila utilizando una lista enlazada de nodos.

 Las operaciones son:

 - PilaVacia: -> Pila. Generadora implementada en el
   constructor sin parámetros.
 - apila: Pila, Elem -> Pila. Generadora
 - desapila: Pila - -> Pila. Modificadora parcial.
 - cima: Pila - -> Elem. Observadora parcial.
 - esVacia: Pila -> Bool. Observadora.

 @author Marco Antonio Gómez Martín  Mercedes Gómez Albarrán
 */
template <class T>
class Pila {
public:

	/** Constructor; operación PilaVacia */
	Pila() : _cima(NULL) {
	}
	
	/**
	 Apila un elemento. Operación generadora.

	 @param elem Elemento a apilar.
	*/
	void apila(const T &elem) {
		_cima = new Nodo(elem, _cima);
	}
	
	/**
	 Desapila un elemento. Operación modificadora parcial.

	 error: falla si la pila está vacía
	*/
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		Nodo *aBorrar = _cima;
		_cima = _cima->_sig;
		delete aBorrar;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operación
	 observadora parcial.

	 error: falla si la pila está vacía.
	 @return Elemento en la cima de la pila.
	 */
	const T &cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _cima->_elem;
	}

	/**
	 Devuelve true si la pila no tiene ningún elemento.

	 @return true si la pila no tiene ningún elemento.
	 */
	bool esVacia() const {
		return _cima == NULL;
	}

	/** Destructor; elimina la lista enlazada. */
	~Pila() {
		libera();
		_cima = NULL;
	}

	/** Constructor copia */
	Pila(const Pila<T> &other) {
		copia(other);
	}

	/** Operador de asignación */
	Pila<T> &operator=(const Pila<T> &other) {
		if (this != &other) { // no se intenta copiar una pila sobre sí misma
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const Pila<T> &rhs) const {
		Nodo *cima1 = _cima;
		Nodo *cima2 = rhs._cima;
		while ((cima1 != NULL) && (cima2 != NULL) && (cima1->_elem == cima2->_elem)) {
			cima1 = cima1->_sig;
			cima2 = cima2->_sig;
		}
		return (cima1 == NULL) && (cima2 == NULL);
	}

	bool operator!=(const Pila<T> &rhs) const {
		return !(*this == rhs);
	}

private:
	
	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que podría ser NULL si
	 el nodo es el último de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) : 
		    _elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	/**
	Elimina todos los nodos de la lista enlazada que soporta la pila. 
	*/
	void libera() {
		while (_cima != NULL) {
			Nodo *aBorrar = _cima;
			_cima = _cima->_sig;
			delete aBorrar;
		}
	}

	/**
	Genera una copia de other en la pila receptora
	*/
	void copia(const Pila &other) {
		if (other.esVacia()) 
			_cima = NULL;
		else {
			Nodo *puntAOrigen = other._cima; 
			Nodo *ultimo; 
			_cima = new Nodo(puntAOrigen->_elem); 
			ultimo = _cima; 
			while (puntAOrigen->_sig != NULL) { 
				puntAOrigen = puntAOrigen->_sig; 
				ultimo->_sig = new Nodo(puntAOrigen->_elem); 
				ultimo = ultimo->_sig; 
			}
		}
	}


	/** Puntero al primer elemento */
	Nodo *_cima;

};

#endif // __PILA_LISTA_ENLAZADA_H
