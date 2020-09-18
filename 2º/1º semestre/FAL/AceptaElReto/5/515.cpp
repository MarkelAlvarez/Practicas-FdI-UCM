// ^ significa y
#include <iostream>
using namespace std;

int numViajesSiEmpezarPeque(int n);
int numViajesSiEmpezarMayor(int n);

int main(int argc, char const *argv[])
{
	int n, nd;
	
	do
	{
		cin >> n;
		if (n != 0)
		{
			cout << numViajesSiEmpezarPeque(n) << endl;
		}
	} while (n != 0);
	
	return 0;
}

int numViajesSiEmpezarPeque(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return 1 + numViajesSiEmpezarMayor(n-1);
}

int numViajesSiEmpezarMayor(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n % 2 == 0)
	{
		return 1 + numViajesSiEmpezarPeque(n-2);
	}
	else
	{
		return 1 + numViajesSiEmpezarPeque(n-1);
	}
}