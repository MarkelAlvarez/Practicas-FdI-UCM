#include <iostream>
using namespace std;

bool crecimientoPorLosPelos(int v[], int a, int b)
{
	if (v[b] - v[a] <= 1)
	{
		return true;
	}

	if (v[b] - v[a] > b - a)
	{
		return false;
	}
	
	int m = (a+b)/2;

	if ((v[m+1] - v[m] <= 1) && crecimientoPorLosPelos(v, a, m) && crecimientoPorLosPelos(v, m+1, b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int numEscalones(int v[], int n)
{
	return numEscalones(v, 0, n-1);
}

/*
POST:

COMPLEJIDAD
linela
a = , b = , k = 
O()
*/