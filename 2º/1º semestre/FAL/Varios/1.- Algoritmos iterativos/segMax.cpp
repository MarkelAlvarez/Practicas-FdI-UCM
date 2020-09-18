#include <iostream>
using namespace std;

//Pre: 0 < n <= longitud(v) ^ ord(v, n)
int segMax(int v[], int n, int p)
{
	int a, b = 1, ret = 0 /*Numero de elementos en [a, b)*/;
	//INVARIANTE: La diferencia entre el primero (a) y el ultimo (b-1) tiene que ser menos que p
	while (b < n)
	{
		if (v[b] - v[a] < p)
		{
			b++;
		}
		else
		{
			a++;
		}
		ret = max(ret, b-a);
	}	

	return ret;
}
//Post: ret = max i, j: (0 <= i <= j < n) ^ //sin acabar

//ord(v, n) = para todo i: 0 <= i <= n-1, v[i] <= v[i+1]