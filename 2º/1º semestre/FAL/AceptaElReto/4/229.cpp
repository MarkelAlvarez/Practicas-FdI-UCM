#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, s1, s2, cnt, x, i;

	while ((scanf("%d", &n)) && (n != 0))
	{
		s2 = 0;
		vector<int> v;

		while (n--) 
		{
			cin >> x;
			v.push_back(x);
			s2 += x;
		}

		s1 = 0;
		cnt = 0;

		if (s1 == s2)
		{
			cnt++;
		}

		for (i = 0; i < v.size(); i++) 
		{
			s1 += v[i];
			s2 -= v[i];

			if (s1 == s2)
			{
				cnt++;
			}
		}
		
		cout << cnt << '\n';
	}

	return 0;
}