#include <iostream>
using namespace std;

int main()
{
	int ini, fin, n, k;

	while((cin >> ini >> fin >> n) && (ini != 0 && fin != 0 && n != 0))
	{
		cin >> k;

		for(int i = 0; i < k; i++)
		{
			int val;
			
			cin >> val;

			if (val < ini || val > fin)
			{
				continue;
			}
			if (val <= n)
			{
				ini = val;
			}
			else if (n < val)
			{
				fin = val - 1;
			}
		}
		
		if(ini == fin)
		{
			cout << "LO SABE\n";
		} 
		else
		{
			cout << "NO LO SABE\n";
		}  
	}

	return 0;
}