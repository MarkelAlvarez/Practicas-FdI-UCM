#include <iostream>
using namespace std;

int x[25], n, m;

int sol(int i,int j, int k);

int main()
{

	while((cin >> n >> m) && (n != 0 || m != 0))
	{
		for(int i = 0; i < m; i++)
		{
			cin >> x[i];
		}
		cout << sol(0, 0, 0) << endl;
	}

	return 0;
}

int sol(int i,int j, int k)
{
	if((k == 12) && (j <= n))
	{
		return 1;
	}

	if((i == m) || (j > n) || (k == 12))
	{
		return 0;
	}

	return (sol(i + 1, j + x[i], k + 1) + sol(i + 1, j, k));
}