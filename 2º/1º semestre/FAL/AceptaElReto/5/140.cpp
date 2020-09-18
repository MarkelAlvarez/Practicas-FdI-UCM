#include <iostream>
using namespace std;

int main()
{
	int resultado = 0;
	string numero;

	while(1)
	{
		cin >> numero;

		if(numero[0] > 47)
		{
			int i = 0;

			while(i < numero.length())
			{
				resultado += numero[i] - 48;

				if(i != numero.length()-1)
				{
					cout << numero[i] << " + ";
				}
				else
				{
					cout << numero[i] << " ";
				}

				i++;
			}

			cout << "= " << resultado << "\n";
			resultado = 0;
		}
		else
		{
			break;
		}
	}

	return 0;
}