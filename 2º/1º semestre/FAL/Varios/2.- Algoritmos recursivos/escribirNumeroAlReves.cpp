#include <iostream>
using namespace std;

void alReves(int n);

int main()
{
	unsigned int n;

	//cin >> n;

	alReves(457);
	
	return 0;
}

void alReves(int n)
{
	cout << n % 10;
	
	if (n >= 10)
	{
		alReves(n / 10);	
	}
}