#include <iostream>
using namespace std;

#define MODULO 46337

void multiplicar(long long int m1[2][2], long long int m2[2][2]);
void potencia(long long int m1[2][2], int n);
int fibonacci(long long int n);

int main()
{
	long long int n;

	while((cin >> n) && (n != 0))
	{
		cout << fibonacci(n) << endl;
	}

	return 0;
}

int fibonacci(long long int n)
{
	long long int m1[2][2] = {{1,1},{1,0}};

	if (n == 0)
	{
		return 0;
	}

	potencia(m1, n-1);

	return m1[0][0];
}

void potencia(long long int m1[2][2], int n)
{
	long long int m2[2][2] = {{1,1}, {1,0}};

	if( n == 0 || n == 1)
	{
		return;
	}
	
	potencia(m1, n/2);
	multiplicar(m1, m1);

	if (n % 2 != 0)
	{
		multiplicar(m1, m2);
	}
}

void multiplicar(long long int m1[2][2], long long int m2[2][2])
{
	int x = ( (m1[0][0]*m2[0][0]) + (m1[0][1]*m2[1][0]) ) % MODULO;
	int y = ( (m1[0][0]*m2[0][1]) + (m1[0][1]*m2[1][1]) ) % MODULO;
	int z = ( (m1[1][0]*m2[0][0]) + (m1[1][1]*m2[1][0]) ) % MODULO;
	int w = ( (m1[1][0]*m2[0][1]) + (m1[1][1]*m2[1][1]) ) % MODULO;
	
	m1[0][0] = x;
	m1[0][1] = y;
	m1[1][0] = z;
	m1[1][1] = w;
}


