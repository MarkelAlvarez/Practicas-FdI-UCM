#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char const *argv[])
{
	long long paises, estudiantes[100000], parejas, sum, i;

	while(1)
	{
		scanf("%lld", &paises);
		if (paises == 0)
		{
			return 0;
		}

		sum = 0;
	
		for(i = 0; i < paises; i++)
		{
			scanf("%lld", &estudiantes[i]);
			sum += estudiantes[i]; 
		}

		parejas = 0;
	
		for(i = 0; i < paises; i++)
		{
			sum -= estudiantes[i];
			parejas += sum * estudiantes[i];
		}

		printf("%lld\n", parejas);
	}
	return 0;
}