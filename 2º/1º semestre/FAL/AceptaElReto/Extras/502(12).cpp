#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solucion(int casos);

int main()
{
	int casos;

	while(cin >> casos)
	{
		solucion(casos);
	}

	return 0;
}

void solucion(int casos)
{
	int i, n;
    vector<int> v;
	
	for(i = 0; i < casos; i++)
	{
		cin >> n;
		
		auto x = upper_bound(v.begin(), v.end(), n);

		if(x == v.end())
		{
			v.push_back(n);
		}
		else
		{
			*x = n;
		}
	}

	cout << v.size() << endl;	
}