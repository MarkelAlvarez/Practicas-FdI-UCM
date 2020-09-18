#include <iostream>
using namespace std;

int main()
{
	long int vel = 0,velocidad, casos, i;

	while(1)
	{
		if(scanf("%ld",&casos)!=EOF)
		{
			for(i = 0;i < casos;i++)
			{
				cin >> velocidad;
				if(velocidad > vel)
				{
					vel = velocidad;
				}
			}
			cout << vel << "\n";
			vel = 0;
		}
		else
		{
			break;
		}
	}
	return 0;
}