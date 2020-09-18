#include <iostream>
using namespace std;

int k;
int arr[5];

bool sol(int x, int y);

int main()
{
	while(cin >> k)
	{
		for(int i = 0; i < 5; i++)
		{
			cin >> arr[i];
		}

		if(sol(arr[0], 1))
		{
			cout << "SI\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}

bool sol(int x, int y)
{
	bool comprobar = false;

	if((x == k) && (y == 5))
	{
		return true;
	}
	if(y == 5)
	{
		return false;
	}
	if((arr[y] != 0) && (x % arr[y] == 0))
	{
		comprobar = sol(x/arr[y], y + 1);
	}

	return (comprobar || sol(x + arr[y], y + 1) || sol(x * arr[y], y + 1) || sol(x - arr[y], y + 1));
}