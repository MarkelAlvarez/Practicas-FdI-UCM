#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool esHoja(const Arbin<char>& a)
{
	return !a.esVacio() && a.hijoIz().esVacio() && a.hijoDer().esVacio();
}

int tiempoAyudaAux(const Arbin<char>& falda, int camino)
{
	int acum = 0;

	if(falda.esVacio())
	{
		return 0;
	}
	else
	{
		if(falda.raiz() == 'X')
		{
			acum += camino*2;
		}
		if(!esHoja(falda))
		{
			acum += tiempoAyudaAux(falda.hijoIz(), camino + 1);
			acum += tiempoAyudaAux(falda.hijoDer(), camino + 1);
		}
	}

	return acum;
}

int tiempoAyuda(const Arbin<char>& falda)
{
	int ret = 0;
	ret = tiempoAyudaAux(falda, 0);
	return ret;
}

Arbin<char> leeArbol(istream& in)
{
	char c;

	in >> c;

	switch (c)
	{
		case '#':
			return Arbin<char>();
		case '[':
		{
			char raiz;
			in >> raiz;
			in >> c;
			return Arbin<char>(raiz);
		}
		case '(':
		{
			Arbin<char> iz = leeArbol(in);
			char raiz;
			in >> raiz;
			Arbin<char> dr = leeArbol(in);
			in >> c;
			return Arbin<char>(iz, raiz, dr);
		}
		default:
			return Arbin<char>();
	}
}

int main()
{
	Arbin<char> falda;

	while (cin.peek() != EOF)
	{
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}

	return 0;
}