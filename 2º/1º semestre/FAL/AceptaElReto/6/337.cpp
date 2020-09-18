#include <iostream>
using namespace std;

void sol(int casos);

int main()
{
	int casos;

	cin >> casos;

	sol(casos);

	return 0;
}

void sol(int casos)
{
	int suma, j = 0;
	bool comprobar = false;

	while(j < casos)
	{
		int caninos[6], incisivos[6];

		for(int i = 0; i < 6; i++)
		{
			cin >> caninos[i];
		}
		for(int i = 0; i < 6; i++)
		{
			cin >> incisivos[i];
		}

		suma = caninos[0] + incisivos[0];

		for(int p = 0; p < 6; p++)
		{
			if(suma != (caninos[p] + incisivos[p]))
			{
				comprobar = true;
			}
		}

		if(comprobar)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "SI\n";
		}

		comprobar = false;

		j++;
	}
}