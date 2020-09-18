#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 60000;

int v1[MAX];
int v2[MAX];

long long int productoEscalar(int v1[], int v2[],int contadorNum);

int main(int argc, char const *argv[])
{
	int cont = 0;
	int i = 0;
	int n1, n2;
	int contadorNum = 0;


	while (cin >> n1)
	{
		cin >> n2;
		contadorNum = n1 + n2;

		while (cont < n1)
		{
			cin >> v1[i];
			i++;
			cin >> v1[i];
			i++;
			cont++;
		}

		cont = 0;
		i = 0;

		while (cont < n2)
		{
			cin >> v2[i];
			i++;
			cin >> v2[i];
			i++;
			cont++;
		}

		cont = 0;
		i = 0;

		cout << productoEscalar(v1, v2, contadorNum) << endl;
	}

	return 0;
}

long long int productoEscalar(int v1[], int v2[], int contadorNum)
{
	long long int res = 0, cont = 0, posA = 1, posB = 1, n1aux = 0;


	while (cont < contadorNum)
	{
		if (v1[posA - 1] < v2[posB - 1])
		{
			n1aux = v1[posA - 1];
		}
		else
		{
			n1aux = v2[posB - 1];
		}


		res += (v1[posA] * v2[posB])* n1aux;
		
		if (n1aux == v1[posA - 1] && n1aux == v2[posB - 1])
		{
			posA += 2;
			posB += 2;
			cont += 2;
		}
		else if (n1aux == v1[posA - 1])
		{
			posA += 2;
			v2[posB - 1] -= n1aux;
			cont++;
		}
		else
		{
			posB += 2;
			v1[posA - 1] -= n1aux;
			cont++;
		}
	}
	
	return res;
}