#include <chrono> // Requiere C++11
#include <iostream>
#include <stdlib.h> // rand
#include <algorithm>

using namespace std;
using namespace std::chrono;

#define MAX_SEGUIDAS 3
#define MAX_TIME 2000

void seleccion(int v[], int n);
void rellenaVectorAleatorio(int v[], int n);

int v[50000];

int main()
{
	int tamInicial = 1000, tamFinal = 100000, incremento = 1000, numSeguidas = 0;
	
	for (int n = tamInicial; (n <= tamFinal) && (numSeguidas < MAX_SEGUIDAS); n += incremento)
	{
		rellenaVectorAleatorio(v, n);
		
		// Medición
		high_resolution_clock::time_point inicio = high_resolution_clock::now();
		//seleccion(v, n);
		sort(v, v + n);
		high_resolution_clock::time_point fin = high_resolution_clock::now();
		
		// Escribimos en la salida estándar
		auto duracion = duration_cast<milliseconds>(fin - inicio).count();

		cout << n << " " << duracion << "\n";
	}
	return 0;
}void rellenaVectorAleatorio(int v[], int n)
{
	for (int i = 0; i < n; ++i)
		v[i] = rand();
}

void seleccion(int v[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int pmin = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (v[j] < v[pmin])
				pmin = j;
			int temp = v[i];
			v[i] = v[pmin];
			v[pmin] = temp;
		}
	}
}