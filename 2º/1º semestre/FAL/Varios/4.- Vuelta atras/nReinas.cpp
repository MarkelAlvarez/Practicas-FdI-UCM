#include <iostream>
using namespace std;

void escribeTablero(int fila[], int n);
void escribeTodas(int solParcial[], int k, int n);
bool esPrometedora(int tablero[], int cuantas);

int main()
{
	int sol[100], consulta = 4;

	cout << "CON UN TABLERO DE " << consulta << "x" << consulta << "HAY" << cuantas(sol, 0, 4) << "SOLUCIONES."
	escribeTodas(sol, 0, 4);

	return 0;
}

/*PSEUDOCODIGO DE LA SOLUCIÓN
void resuelveProblemas(Tupla &solucionParcial, int k) //cuantos elementos en la solución parcial
{
	if (esSolucion (solucionParcial, k)) //caso base
	{
		tratarSolucion(solucionParcial, k);
	}
	else //caso recursivo. Hay que probar todas las posibilidades
	{
		paraCadaCandidatosPosible
		{
			solucionParcial[k] = candidato;
			if (esPrometedora(solucionParcial, k+1))
			{
				resuelveProblemas(solucionParcial, k+1);
			}
		}
	}
}*/

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