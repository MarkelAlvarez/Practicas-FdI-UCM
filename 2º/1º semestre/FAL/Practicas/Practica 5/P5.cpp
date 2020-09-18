#include <iostream>
using namespace std;

long long int solve(long long int num, long long int cambiante, long long int &sol);

int main()
{
	static long long int num;
	//static long long int sol = 0;

	cin >> num;

	while (num != 0)
	{
		cout << cuantos(num) << endl;
		/*cout << solve(num, num, sol) << endl;

		sol = 0;*/
		cin >> num;
	}
}

/*long long int solve(long long int num, long long int cambiante, long long int &sol)
{
	if (num == 0)
		return sol;
	if (cambiante % 10 == 0)
	{
		solve(num, cambiante/ 10, sol);
	}
	else
	{
		if (cambiante / 10 == 0)
		{
			sol += cambiante%10;
			solve(num - 1, num-1, sol);
		}
	}

	return sol;
}*/

long long cuantos(long long n)
{
	if (n == 0)
	{
		return 0;
	}

	int ultDigito = n/10;
	long long raiz = n/10;

	return 45 * raiz + ultDigito*(ultDigito+1)/2 + cuantos(raiz);
}