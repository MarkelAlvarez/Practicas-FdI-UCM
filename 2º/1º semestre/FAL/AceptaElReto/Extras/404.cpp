#include <iostream>
#include <string>
using namespace std;

int main()
{

	
	return 0;
}

int sol(char numero[], int pos)
{
	if (numero[pos] == 'I')
	{
		if (numero[pos-1] == 'I')
		{
			num += sol(numero, pos-2);
			if (numero[pos-2] == 'I')
			{
				num += sol(numero, pos-2);
				if (numero[pos-1] == 'I')
				{
					num += sol(numero, pos-2);
				}
			}
		}
	}
	else if (numero[pos] == 'V')
	{
		/* code */
	}
	else if (numero[pos] == 'X')
	{
		/* code */
	}
}