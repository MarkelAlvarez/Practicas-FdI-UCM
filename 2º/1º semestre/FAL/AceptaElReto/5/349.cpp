#include <iostream>
using namespace std;

int solucion();

int main()
{

	int casos, i = 0;

	cin >> casos;

	while(i < casos)
	{
		cout << solucion() <<'\n';
		i++;
	}
}

int solucion()
{
	char caracter, conversion = 0;

	cin >> caracter;

	conversion = caracter - '0';

	if ((conversion < 0) || (conversion > 9))
	{
		if(caracter == '+')
		{
			conversion = solucion() + solucion();
		}
		else if(caracter == '-')
		{
			conversion = solucion() - solucion();
		}
		else if(caracter == '*')
		{
			conversion = solucion() * solucion();
		}
		else if (caracter == '/')
		{
			conversion = solucion() / solucion();
		}
	}

	return conversion;
}