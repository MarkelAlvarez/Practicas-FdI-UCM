#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, total = 0, res = sqrt(n);

	while ((scanf("%d",&n)==1) && (n != 0))
	{
		while(n > 3)
		{
			n -= (res*res);
			total += (((res*2+(res-2)*2)*2+4)+(res-2)*(res-2));
		}
		if(n!=0)
		{
			total+=(n*5);
		}
		cout << total << '\n';
	}
	return 0;
}