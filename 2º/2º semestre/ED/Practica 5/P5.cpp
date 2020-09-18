#include <iostream>
using namespace std;
#include <string>
#include "lista.h"

void invierteSecuenciasNoVocales(Lista<char>& mensaje)
{
	int b = mensaje.longitud();
	Lista<char>::Iterator iterador = mensaje.begin();
	Lista<char> aux;

	for (int i = 0; i < b; i++)
	{
		if (iterador.elem() != 'a' && iterador.elem() != 'e' && iterador.elem() != 'i' && iterador.elem() != 'o' && iterador.elem() != 'u' &&
			iterador.elem() != 'A' && iterador.elem() != 'E' && iterador.elem() != 'I' && iterador.elem() != 'O' && iterador.elem() != 'U')
		{
			aux.pon_ppio(iterador.elem());
			iterador = mensaje.eliminar(iterador);

			if (i == b-1)
			{
				while (!aux.esVacia())
				{
					mensaje.insertar(aux.primero(), iterador);
					aux.quita_ppio();
				}
				if (iterador != mensaje.end())
				{
					iterador.next();
				}
			}
		}
		else
		{
			while (!aux.esVacia())
			{
				mensaje.insertar(aux.primero(), iterador);
				aux.quita_ppio();
			}
			iterador.next();
		}
	}
}

// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l)
{
	l.print();
	cout << endl;
}

// Codifica el mensaje
void codifica(Lista<char>& mensaje)
{
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje)
{
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main()
{
	string linea;

	while(getline(cin, linea))
	{
	   Lista<char> mensaje;

	   construyeMensaje(linea, mensaje);
	   codifica(mensaje);
	   imprime(mensaje);
	}

	return 0;
}