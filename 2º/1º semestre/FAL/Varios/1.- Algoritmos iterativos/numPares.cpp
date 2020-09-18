#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int numPares(int v[], int n);

int main(int argc, char const *argv[])
{
	int v[128], n, ret;

	ret = numPares(v, n)
	cout << "\n" << ret; 

	return 0;
}

int numPares(int v[], int n)
{
	int ret, i;
	// I: (0 <= i <= n) ^
	while (i < n)
	{
		//I ^ (i < n)
		if (v[i] % 2 == 0)
		{
			ret += v[i];
		}
		i++;
		//I
	}

	return ret;
}

//ret = Sum j : 0 <= j < n : v[j];

