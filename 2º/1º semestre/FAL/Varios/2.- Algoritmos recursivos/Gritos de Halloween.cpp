#include <iostream>
using namespace std;

void numCopias(string v[], int a, int b,/*out*/ int &libro,/*out*/ int &primerLibro,/*out*/ int &ultimoLibro);;

int main(int argc, char const *argv[])
{
	
	return 0;
}

void longitudGrito(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return 2 * longitudGrito(n-1) + n + 2;
}

char letraGrito(int n, long long p)
{
	if () //si p apunta al primer bloque
	{
		return letraGrito(n-1, p);
	}
	if () //si p apunta al central
	{
		if () // si p apunta al primero
		{
			return 'B';
		}
		if () // si p apunta al ultimo
		{
			return 'H';
		}

		return 'U';
	}

	if () //si p apunta al ultimo
	{
		return letraGrito(n-1, p adaptado);
	}
}