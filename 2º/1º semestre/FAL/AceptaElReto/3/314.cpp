#include <iostream>
using namespace std;

int main()
{
	int t, m, valles=0, picos=0, anterior, cont=0, medio,k;

	cin >>t;

	while(t--)
	{
		cin >> k;

		while(k--)
		{
			cin >> m;

			if(cont == 1)
			{
			 medio = m;
			}
			else if(cont == 0)
			{
				anterior = m;
			}
			else
			{
				if((anterior > medio) && (m > medio))
				{
					picos++;
				}
				else if((anterior < medio) && (m < medio))
				{
					valles++;
				}
				anterior = medio;
				medio = m;

			}
			cont++;
		}
		cout << valles << " " << picos << endl;
	}
	return 0;
}