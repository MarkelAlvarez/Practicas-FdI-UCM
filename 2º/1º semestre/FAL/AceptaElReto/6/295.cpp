#include <iostream>
using namespace std;

int potencia(int x, int n);

int main()
{
	int x, n;

	while( (cin >> x >> n) && (x != 0 || n != 0) )
	{
			cout << potencia(x, n) << endl;
	}
	
	return 0;
}

int potencia(int x, int n) 
{
	if (n == 0)
	{
		return 1;
	}

	if (n % 2 == 0)
	{
		int x1 = potencia(x, n/2);

		return (x1 * x1) % 31543;
	}
	else
	{
		int x1 = potencia(x, (n-1)/2);
		
		return (((x1 * x1) % 31543) * (x % 31543)) % 31543;
	}
}