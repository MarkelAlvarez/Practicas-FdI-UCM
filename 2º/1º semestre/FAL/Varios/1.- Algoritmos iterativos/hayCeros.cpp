#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int masGrande(int v[], int n);

int main(int argc, char const *argv[])
{
	int v[128], n, ret;

	ret = hayCeros(v, n);
	cout << "\n" << ret;

	return 0;
}

bool hayCeros(int v[i], int n)
{
	int i = 0;

	//I: (0 <= i <= n)
	//	no hay ceros en v[0,...,i-1]
	while ((i < n) && (v[i] != 0))
	{
		i++;
	}

	return (i < n);
}