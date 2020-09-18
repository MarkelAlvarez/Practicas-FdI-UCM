#include <iostream>
using namespace std;

int n, m;

int solve(int c);

int main()
{
	while((scanf("%d%d", &n, &m) == 2) && (n != 0))
	{
		n *= 2;
		printf("%d\n", solve(m));
	}

	return 0;
}

int solve(int x)
{
	int ret = 0;
	
	if (x > n)
	{
		ret = 1 + solve(x/3) + solve(x-x/3);
	}
	else
	{
		ret = 0;
	}

	return ret;
}