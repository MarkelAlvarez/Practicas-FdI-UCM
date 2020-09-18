#include <iostream>
#include <math.h>
using namespace std;

void escribeTablero(int fila[], int n);
void escribeTodas(int solParcial[], int k, int n);
bool esPrometedora(int tablero[], int cuantas);
void esMejor(/*Descripcion del problema*/int tab[8][0], /*Solucion parcial*/int solParcial[], int k, /*Marcaje*/int gananciaActual, /*Mejor solucion*/int &mejorSolucion);

int main()
{
	int sol[100], consulta = 4;

	cout << "CON UN TABLERO DE " << consulta << "x" << consulta << "HAY" << cuantas(sol, 0, 4) << "SOLUCIONES."
	escribeTodas(sol, 0, 4);

	return 0;
}

void esMejor(/*Descripcion del problema*/int tab[8][0], /*Solucion parcial*/int solParcial[], int k, /*Marcaje*/int gananciaActual, /*Mejor solucion(in/out)*/int &mejorSolucion, int mejorColocacion[8])
{
	int ret = -1;
	
	if (k == 8)
	{
		if (mejorSolucion < gananciaActual)
		{
			mejorSolucion = gananciaActual;
			for (int i = 0; i < 8; ++i)
			{ 
				mejorColocacion[i] = solParcial[i];
			}
		}
		return;
	}

	for (int i = 0; i < 8; ++i)
	{
		solParcial[k] = i;
		if (esPrometedora(solParcial, k+1))
		{
			mejor(tab, solParcial, k, gananciaActual + tab[k][i], mejorSolucion);
		}
	}
}

void escribeTablero(int fila[], int n)
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (fila[y] == x)
			{
				cout << "X";
			}
			else
			{
				cout << ".";
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

void escribeTodas(int solParcial[], int k, int n)
{
	if (k == n)
	{
		escribeTablero(solParcial, n);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		solParcial[k] = i;
		if (esPrometedora(solParcial, k+1))
		{
			escribeTodas(solParcial, k+1, n);
		}
	}
}

void cuantas(int solParcial[], int k, int n)
{
	int ret = 0;

	if (k == n)
	{
		return 1;
	}

	for (int i = 0; i < n; ++i)
	{
		solParcial[k] = i;
		if (esPrometedora(solParcial, k+1))
		{
			ret += cuantas(solParcial, k+1, n);
		}
	}

	return ret;
}

bool esPrometedora(int tablero[], int cuantas)
{
	for (int i = 0; i < cuantas-1; ++i)
	{
		if (tablero[i] == tablero[cuantas-1])
		{
			return false;
		}

		if (abs(tablero[cuantas-1] - tablero[i]) == abs(cuantas - 1 - i))
		{
			return false;
		}
	}

	return true;
}

/*
UN VECTOR ES CUASIFIBONACCHI SI -> v[i+1]
							    -> v[i-1]+v[i-2]
*/