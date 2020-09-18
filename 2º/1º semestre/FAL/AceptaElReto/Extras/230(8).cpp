#include <iostream>
using namespace std;

long long int _mergeSort(int x[], int tmp[], int izq, int dch);
long long int mergeSort(int x[], int tamX);
long long int merge(int x[], int tmp[], int izq, int medio, int dch);

int main()
{
	int n;

	while((cin >> n) && (n != 0))
	{
		int x[n], i;

		for(i = 0; i < n; i++)
		{
			cin >> x[i];
		}

		cout << mergeSort(x, n) << endl;
	}

	return 0;
}

long long int mergeSort(int x[], int tamX)
{
	int* tmp = (int*)malloc(sizeof(int)*tamX);

	return _mergeSort(x, tmp, 0, tamX - 1);
}

long long int _mergeSort(int x[], int tmp[], int izq, int dch)
{
	long long int medio, cont = 0;

	if (dch > izq)
	{
		medio = (dch + izq) / 2;

		cont = _mergeSort(x, tmp, izq, medio);
		cont += _mergeSort(x, tmp, medio + 1, dch);
		cont += merge(x, tmp, izq, medio + 1, dch);
	}

	return cont;
}

long long int merge(int x[], int tmp[], int izq, int medio, int dch)
{
	int i, j, k;
	long long int cont = 0;

	i = izq;
	j = medio;
	k = izq;

	while ((i <= medio - 1) && (j <= dch))
	{
		if (x[i] <= x[j])
		{
			tmp[k++] = x[i++];
		}
		else
		{
			tmp[k++] = x[j++];
			cont = cont + (medio - i);
		}
	}

	while (i <= (medio - 1))
	{
		tmp[k++] = x[i++];
	}

	while (j <= dch)
	{
		tmp[k++] = x[j++];
	}

	for (i = izq; i <= dch; i++)
	{
		x[i] = tmp[i];
	}

	return cont;
}