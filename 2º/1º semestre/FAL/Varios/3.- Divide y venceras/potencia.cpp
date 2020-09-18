#include <iostream>
using namespace std;

#define PRIME 1000007

int main()
{
	return 0;
}

int potencia(int k, int n)
{
	if(n == 0)
	{
		return 1;
	}

	int aux = potencia(k, n/2);
	int ret = aux*aux;
	ret %= PRIME;

	if (n%2 == 1)
	{
		ret *= k;
		ret = ret % PRIME;
	}
}
/*
POST: ret = (k^n)%PRIME

COMPLEJIDAD
a = 1, b = 2, k = 0
O(n^k*log(n))
*/