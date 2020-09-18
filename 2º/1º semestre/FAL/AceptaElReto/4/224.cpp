#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int casos, x[casos], res = 0, flag = 0, i, j, act = 0, aux1;

	while((scanf("%d", &casos) == 1) && (casos != 0))
	{
		for(i = 0; i < casos; i++)
		{
			cin >> x[i];
		}
		
		for(i = 0; i < casos; i++)
		{
			aux1 = x[i];

			for(j = i+1; j < casos; j++)
			{
				act += x[j];

				if(act > aux1)
				{
					break;
				}
			}

			if(act == aux1)
			{
				flag = 1; 
				res = i+1; 
				break;
			}
		}

		if(flag == 1)
		{
			cout << "SI " << res << endl;
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}