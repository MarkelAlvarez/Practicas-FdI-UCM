#include<iostream>
#include<string>

using namespace std;

const int MAX_SECCION = 300000;

int v[MAX_SECCION];

void resuelve();
int posEscondite(int v[], int n, int ancho);

int main() {
	int ncasos, contador=0;

	cin >> ncasos;

	while (contador < ncasos)
	{
		resuelve();
		contador++;
	}

	return 0;
}

void resuelve()
{
	int K, N, ret, i;

	cin >> N;
	cin >> K;
	
	for (i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	ret = posEscondite(v, N, K);

	cout << ret << endl;
}

int posEscondite(int v[], int n, int ancho)
{
	int ini = 0, i = ini, ret = 0, fin = ancho-1, max = 0, pos = 0;

	while (fin < n)
	{
		while (i < fin + 1)
		{
			ret += v[i];
			i++;
		}
		if (ret > max)
		{
			max = ret;
			pos = ini;
		}
		ini++;
		i = ini;
		ret = 0;
		fin++;
	}
	return pos;
}