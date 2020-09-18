#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int ret;
	long long int n;

	cin >> n;

	ret = cuantosSinUno(n);
	cout << ret << endl;
	
	return 0;
}

bool tieneUnos(long long n)
{
	if (n < 10)
	{
		if (n == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int cuantosSinUno(int n)
{
	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		if (!tieneUnos(i))
		{
			ret++;
		}
	}

	return ret;
}