#include "cola.h"
#include <iostream>
using namespace std;

// A IMPLEMENTAR
void supervivientes(int n, Cola<int>& cola)
{
	unsigned int aQuitar = 2;

	if (n < 2)
	{
		throw EColaVacia();
	}

	for (int i = 1; i <= n; i++)
	{
		cola.pon(i);
	}

	while (cola.longitud() >= aQuitar)
	{
		unsigned int n = cola.longitud();
		for (unsigned int i = 0; i < n; i++)
		{
			if (i != 0 && i % aQuitar != 0)
			{
				cola.pon(cola.primero());
			}
			cola.quita();
		}
		aQuitar++;
	}
}

int main() {
	
	int n;
	Cola<int> cola;

	cin >> n;
	while (n != 0){

		supervivientes(n, cola);

		cout << n << ":";
		while (!cola.esVacia())
		{
			cout << " " << cola.primero();
			cola.quita();
		}
		cout << endl;
		
		cin >> n;	
	}
		
	return 0;
}