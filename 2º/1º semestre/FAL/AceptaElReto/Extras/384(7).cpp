#include <iostream>
using namespace std;

void solucion(int n);

int main()
{
	int n;

	while (cin >> n)
	{
		solucion(n);
	}

	return 0;
}

void solucion(int n)
{
	int x[n], tmp, flag = 0, aux = 1;
	
	cin >> tmp;

	x[0] = x[1] = tmp;
	n--;
	
	while(n != 0)
	{
		n--;
		cin >> tmp;

		for (int i = aux; ( (i > 0) && (x[i - 1] < tmp) && (flag == 0) ); i -= 2)
		{
			if (x[i - 1] < tmp && x[i] > tmp)
			{
				flag = 1;
			}
		}

		if (flag)
		{
			break;
		}

		if (x[aux - 1] < tmp)
		{
			x[aux] = tmp;
		}
		else if (x[aux - 1] == x[aux])
		{
			x[aux - 1] = x[aux] = tmp;
		}
		else
		{
			aux += 2;
			x[aux - 1] = x[aux] = tmp;
		}
	}

	while(n != 0)
	{
		n--;
		cin >> tmp;
	}

	if (flag)
	{
		printf("ELEGIR OTRA\n");
	}
	else
	{
		printf("SIEMPRE PREMIO\n");
	}
}