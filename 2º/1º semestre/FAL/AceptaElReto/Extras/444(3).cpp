#include <iostream>
using namespace std;

int main()
{
	int a, limite;

	while((scanf("%d%d", &a, &limite)) && ((a != 0) || (limite != 0)))
	{
		int arr[a], i = 0;

		while (i < a)
		{
			cin >> arr[i];
			i++;
		}

		int maximo = 0;
		int sum = 0, aux = 0, salir = 0;

		i = 0;

		while (i < a)
		{
			if(arr[i] == 1)
			{
				int j = i;

				while (j < a)
				{
					sum++;
					salir = j;

					if(arr[j] != 0)
					{
						aux = 0;
						maximo = max(maximo, sum);
					}
					if(arr[j] == 0) 
					{
						aux++;
					}
					if(aux > limite)
					{
						break;
					}

					j++;
				}
				
				i = salir;
				sum = 0;
				aux = 0;
			}
			i++;
		}
		
		printf("%d\n",maximo);
	}

	return 0;
}