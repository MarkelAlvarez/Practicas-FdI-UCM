#include <iostream>
#include <algorithm>
using namespace std;
/* Vector de n elementos y en la primera posicion hay un datos. Dos partes , 1) <250 2)>250 y en 1) la primera posicion sera para el numero mas grande*/
int main(int argc, char const *argv[])
{
	int v[50000], n;

	distribuir(v, n);

	return 0;
}

void particion(/*inout*/int v[], int n)
{
	int a = 0, b = n, p = v[0];

	while (a < b)
	{
		if (v[a] <= p) //si puede crecer en la parte de izquierda
		{
			a++;
		}
		else if (v[a] > p) //si puede crecer en la parte de derecha
		{
			b--;
		}
		else
		{
			swap(v[a], v[b]);
			a++;
			b--;
		}
	}
}

/* Nos dan dos vectores con el mismo tamaño n, tambien hay un vector de tamaño n+n con los elementos de los otros dos vectores ordenados*/
void mezcla(int v[], int w[], /*out*/int x[], int n)
{
	int i = 0, j = 0, k = 0;

	while (k < 2*n)
	{
		if (v[i] <= w[j])
		{
			x[k] = v[i];
			i++;
		}
		else
		{
			x[k] = w[j];
			j++;
		}
		k++;
	}

	while (i < n)
	{
		x[k] = v[i];
		i++;
		k++;
	}

	while (j < n)
	{
		x[k] = w[j];
		j++;
		k++;
	}
}

