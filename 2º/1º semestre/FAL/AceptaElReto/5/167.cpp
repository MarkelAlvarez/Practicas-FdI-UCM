#include <iostream>
using namespace std;

int main() 
{
	int l;
	
	while (cin >> l) 
	{
		int s = 0, c = 1;
		
		while (l != 0) 
		{
			s += c*l;
			l /= 2;
			c *= 4;
		}

		cout << 4*s << endl;
	}

	return 0;
}