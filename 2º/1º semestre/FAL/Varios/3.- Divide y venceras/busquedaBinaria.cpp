#include <iostream>
using namespace std;

bool posible(int pos[], int n, int capSalto)
{
	//Se lo pedimos al alumno de primero
}

void resuelve()
{
	int a = 0, b = 1000000;

	while (!posible(pos, n, b))
	{
		a = b;
		b *= 2;
	}

	while (a < b)
	{
		int m = (a+b)/2; //m = punto medio
		if (posible(pos, n, m))
		{
			b = m;
		}
		else
		{
			a = m + 1;
		}
	}
}