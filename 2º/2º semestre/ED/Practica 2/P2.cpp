#include <iostream>
#include <string>
#include "Pila.h" 
using namespace std;

bool esEquilibrada(const string& cadena)
{
    unsigned int i = 0;
    bool equi = true;
    Pila<char> pila;

    while (equi && i < cadena.length())
    {
        if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{')
        {
            pila.apila(cadena[i]);
        }
        else if (!pila.esVacia())
        {
            if (cadena[i] == '}')
            {
                if (pila.cima() == '{')
                {
                    pila.desapila();
                }
                else
                {
                    equi = false;
                }
            }
            else if (cadena[i] == ']')
            {
                if (pila.cima() == '[')
                {
                    pila.desapila();
                }
                else
                {
                    equi = false;
                }
            }
            else if (cadena[i] == ')')
            {
                if (pila.cima() == '(')
                {
                    pila.desapila();
                }
                else
                {
                    equi = false;
                }
            }
        }
        else
        {
            if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}')
            {
                equi = false;
            }
        }
        i++;
    }

    if (!pila.esVacia())
    {
        equi = false;
    }

    return equi;
}

int main() 
{    
	string cadena;

    while(getline(cin, cadena))
    {
        if(esEquilibrada(cadena))
            cout << "EQUILIBRADA" << endl;
        else
            cout << "NO_EQUILIBRADA" << endl;		  
	}

	return 0;
}	
