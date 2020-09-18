#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int masGrande(int v[], int n);

int main(int argc, char const *argv[])
{
	int v[128], n, ret;

	ret = masGrande(v, n);
	cout << "\n" << ret;

	return 0;
}

//Solo funciona si n >= 1 (Precondición)
int masGrande(int v[], int n)
{
	int ret, i = 1;
	
	while (i < n)
	{
		if (ret < v[i])
		{
			ret = v[i]
		}
		i++;
	}

	return ret;
}

// ret = Max j : 0 <= j < n : v[j] (Postcondicion)

//------------------------------------------------
int masGrande(int v[], int n)
{
	int ret, i = 1;
	
	while (i < n)
	{
		if (ret < v[i])
		{
			ret = v[i]
		}
		i++;
	}

	return ret;
}