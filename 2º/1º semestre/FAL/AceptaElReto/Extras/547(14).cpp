#include <iostream>
using namespace std;

void solucion(int nLuces, int intervalo1, int intervalo2);

int main()
{
	int nLuces, intervalo1, intervalo2;

	cin >> nLuces >> intervalo1 >> intervalo2;

	while(nLuces != 0 && nLuces >= 0 && nLuces <= 4)
	{
		solucion(nLuces, intervalo1, intervalo2);
		cin >> nLuces >> intervalo1 >> intervalo2;
	}

	return 0;
}

void solucion(int nLuces, int intervalo1, int intervalo2)
{
	int nSegundos = 0;

	cout << nSegundos << endl;
}