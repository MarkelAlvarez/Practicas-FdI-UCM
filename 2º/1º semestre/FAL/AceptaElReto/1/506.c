#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define	MAX 30

int leer();
void comprobar(int max, int min, int i);

int main(int argc, char* argv[])
{
	int nCasos, i, max, min;
	char str[MAX];

	nCasos = leer();

	for (i = 1; i <= nCasos; i++)
	{
		//printf("\n Introduce los datos: ");
		fgets(str, MAX, stdin);
		sscanf(str, "%d / %d", &max, &min);

		comprobar(max, min, i);
	}

	return 0;
}

int leer()
{
	int x;
	char str[MAX];

	//printf("\n Numero de casos a registrar: ");
	fgets(str, MAX, stdin);
	sscanf(str, "%d", &x);

	return x;
}

void comprobar(int max, int min, int i)
{
	if ((max > min) || (max == min))
	{
		printf("BIEN\n");
	}
	else
	{
		printf("MAL\n");
	}
}