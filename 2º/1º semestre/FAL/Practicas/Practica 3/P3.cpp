#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
//dos girnaldas para juntar
int cuantasParejas(int v[], int n, int ancho);

int main(int argc, char const *argv[])
{
	int cuerdasGirnalda, dist, tamGuir[MAX], i = 0, x;

	do
	{
		cin >> cuerdasGirnalda;
		cin >> dist;
		if (cuerdasGirnalda != 0 && dist != 0)
		{
			do
			{
				cin >> x;
				if (x != 0)
				{
					tamGuir[i] = x;
					i++;
				}
			} while ((x != 0) && (i < cuerdasGirnalda));

			sort(tamGuir, tamGuir + cuerdasGirnalda);
			resolver(tamGuir, dist, cuerdasGirnalda);
		}
	} while (cuerdasGirnalda != 0 && dist != 0);

	return 0;
}

int cuantasParejas(int v[], int n, int ancho)
{
	int i = 0, j = 0, pareja = 0;

	while(i != ancho-1)
	{
		if ((v[i] + v[ancho-1]) == n)
		{
			pareja++;
			i++;
			ancho--;
		}
		else if ((v[i+1] + v[ancho-1]) == n)
		{
			i++;
			ancho--;
		}
	}
	
	cout << pareja << '\n';
}