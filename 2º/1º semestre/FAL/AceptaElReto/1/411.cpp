#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/*void comprobar(int x);

int main(int argc, char* argv[])
{
	int x;

	cin >> x;

	while (x != 0)
	{
		comprobar(x);

		cin >> x;
	}

	return 0;
}

void comprobar(int x)
{
	int num, sum = 0, i = 0;

	cin >> num;

	while (num != 0)
	{
		sum += num;

		if (sum <= x)
		{
			i++;
		}

		cin >> num;
	}
	cout << i << "\n";
}*/

int main()
{
    int casos, entrada, resultado = 0;

    cin >> casos;

    while(casos != 0)
    {
        cin >> entrada;
        
        while(entrada!=0)
        {
            casos -= entrada;
            if(casos >= 0)
            {
                resultado++;
            }
            cin >> entrada;
        }
        cout << resultado << endl;
        resultado = 0;
        cin >> casos;
    }
    
    return 0;
}