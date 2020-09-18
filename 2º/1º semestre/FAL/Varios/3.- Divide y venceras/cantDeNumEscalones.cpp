#include <iostream>
using namespace std;

int numEscalones(int v[], int a, int b)
{
	if (v[a] == v[b])
	{
		return 1;
	}

	int m = (a+b)/2;

	int izq = numEscalones(v, a, m);
	int der = numEscalones(v, m+1, b);

	if (v[m] != v[m+1])
	{
		return izq + der;
	}
	else
	{
		return izq + der - 1;
	}
}

int numEscalones(int v[], int n)
{
	return numEscalones(v, 0, n-1);
}
/*
POST:

COMPLEJIDAD
a = , b = , k = 
O()
*/