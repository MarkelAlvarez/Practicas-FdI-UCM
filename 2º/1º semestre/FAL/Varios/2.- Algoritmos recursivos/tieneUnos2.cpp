#include <iostream>
using namespace std;

bool resuelve();
bool tieneUnos(long long n);
int cuantosSinUno(int n);

int main(int argc, char const *argv[])
{
	int ret;
	long long int n;

	while (resuelve())
	{
		ret = cuantosSinUno(n);
		cout << ret << endl;
	}
	
	return 0;
}

bool resuelve()
{
	long long n;

	cin >> n;

	if (!n)
	{
		ret = cuantosSinUno(n);
		cout << ret << endl;
	}

	return n;
}

bool tieneUnos(long long n)
{
	while((n != 0) && (n % 10 != 1))
	{
		n /= 10;
	}

	return n % 10 == 1;
}

int cuantosSinUno(int n)
{
	int ultDigito = n%10;
	long long int ret = 0, raiz = n/10;

	if (n == 0)
	{
		return 1;
	}

	for (int i = 0; i < ultDigito; i++)
	{
		if (!tieneUnos(10*raiz+i))
		{
			ret++;
		}
	}

	if (raiz)
	{
		ret += 9*cuantosSinUno(raiz-1);
	}

	return ret;
}

/*
a = 1, b = 10, k = 0
O(n^k*log(n))
*/