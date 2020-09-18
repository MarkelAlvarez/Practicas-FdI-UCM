#include <iostream>
using namespace std;

void solucion(int nTramos, int nParadas);

int main()
{
	int nTramos, nParadas;

	while(cin >> nTramos && cin >> nParadas)
	{
		nParadas++;
		solucion(nTramos, nParadas);
	}

	return 0;
}

void solucion(int nTramos, int nParadas)
{
	int total = 0, maximo = 0, tramo[nTramos];
	
	for(int i = 0; i < nTramos; i++)
	{
		cin >> tramo[i];
		total += tramo[i];
		maximo = max(maximo, tramo[i]);
	}

	while(maximo < total)
	{
		int mitad = 0, suma = 0, nedesidad = 1;

		mitad = maximo + (total-maximo)/2;

		for(int i = 0; i < nTramos; i++)
		{
			if(suma + tramo[i] > mitad)
			{
				suma = tramo[i];
				nedesidad++;
				if(nedesidad > nParadas)
				{
					i = nTramos;
				}
			}
			else
			{
				suma += tramo[i];
			}
		}

		if(nedesidad <= nParadas)
		{
			total = mitad;
		}
		else
		{
			maximo = mitad + 1;
		}
	}

	cout << maximo << endl;
}