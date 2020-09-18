#include <iostream>
using namespace std;

int main()
{
	int v[128], a, b;

	ordena(v, a, b);

	return 0;
}

void ordena(int v[], int a, int b)
{
	int m;

	if (a < b)
	{
		m = (a+b)/2;
		ordena(v, a, m-1);
		ordena(v, m, b);

		mezcla(v, a, m, b);
	}
}

void ordena(int v[], int a, int b) //QuickSort O(n*log(n))
{
	int p;

	if (a < b)
	{
		p = particion(v, a, b);
		ordena(v, a, p-1);
		ordena(v, p, b);
	}
}

void ordena(int v[], int n)
{
	ordena(v, 0, n-1);
}