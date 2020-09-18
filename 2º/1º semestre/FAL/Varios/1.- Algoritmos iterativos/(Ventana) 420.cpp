#include <iostream>
using namespace std;

#define MAX 250000;
int v[MAX];

void resuelve();

int main()
{
	int nCasos, i;

	cin >> nCasos;

	for (i = 0; i < nCasos; i++)
	{
		resuelve();
	}

	return 0;
}

void resuelve()
{
	int x, zenbat = 0, y;
	char num[MAX], str[30];;

	cin >> x;

	do
	{
		cin >> y;

		if (y != 0)
		{
			num[zenbat] = y;
			zenbat++;
		}
	} while (y != 0);

	for (int i = 0; i < sizeof(num); ++i)
	{
		v[i] = num[i] - '0';
	}

	n = sizeof(num);

	//Cálculo
	cout << numSegementos(v, n, k) << endl;
}

int numSegementos(int v[], int n, int k) //importante
{
	int ret = 0, sumaVentana = /*suma de todos los elementos desde 'a' a 'b-1'*/, a = 0, b = 0;

	while (b < n)
	{
		if (sumaVentana < k)
		{
			sumaVentana += v[b];
			b++;
		}
		else
		{
			sumaVentana -= v[a];
			a++;
		}
		if (sumaVentana == k)
		{
			ret++;
		}
	}

	return ret;
}