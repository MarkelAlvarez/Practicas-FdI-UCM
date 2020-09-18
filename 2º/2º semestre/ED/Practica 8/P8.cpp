#include <iostream>
#include <string>
#include "lista.h"
#include "diccionario.h"
using namespace std;

// Clase Puntuacion. Sirve para representar la puntuacion final (nota) obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado)
{
	// A IMPLEMENTAR
	Diccionario<string, int> refs;
	
	if (!bien.esVacia())
	{
		Lista<string>::ConstIterator it_bien(bien.cbegin());
		refs.inserta(it_bien.elem(), 1);
		it_bien.next();

		while (it_bien != bien.cend())
		{
			Diccionario<string, int>::Iterator p = refs.busca(it_bien.elem());
			if (p == refs.end())
			{
				refs.inserta(it_bien.elem(), 1);
			}
			else
			{
				p.setVal(p.valor() + 1);
			}
			it_bien.next();
		}
	}

	if (!mal.esVacia())
	{
		Lista<string>::ConstIterator it_mal(mal.cbegin());

		while (it_mal != mal.cend())
		{
			Diccionario<string, int>::Iterator p = refs.busca(it_mal.elem());
			if (p == refs.end())
			{
				refs.inserta(it_mal.elem(), -1);
			}
			else
			{
				p.setVal(p.valor() - 1);
			}
			it_mal.next();
		}
	}

	Diccionario<string, int>::Iterator p(refs.begin());
	while (p != refs.end())
	{
		if(p.valor() != 0)
		{
			Puntuacion punt = Puntuacion(p.clave(), p.valor());
			listado.pon_ppio(punt);
		}
		p.next();
	}
}

void imprimePuntuaciones(Lista<Puntuacion>& listado)
{
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
  
	while (i != e)
	{
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}  
	
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal)
{
	string nombre;

	do {
		cin >> nombre;
		if (nombre != "#")
		{
			string resultado;
			cin >> resultado;

			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main()
{
	string comienzo;
	
	while (cin >> comienzo)
	{
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal,listado);
		imprimePuntuaciones(listado);
	}
	
	return 0;   
}