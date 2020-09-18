#include <iostream>
using namespace std;

void convertir(int num)
{
	if (num > 0)
	{
		convertir(num/6);
		cout << num % 6;
	}

}

int main()
{
	int casos;

	cin >> casos;

	while(casos != 0)
	{
		int num;

		cin >> num;

		if(num == 0)
		{
			cout << "0";
		}
		else
		{
			convertir(num);
		}

		casos--;
		cout << "\n";
	}
}