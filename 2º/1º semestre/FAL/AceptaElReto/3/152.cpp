#include <iostream>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
	int i, casos, num, maxi = -INF, res=0;

	while((scanf("%d",&casos)==1) && (casos!=0))
	{
		map<int,int> M;
		for (i = 0; i < casos;i++)
		{
			cin >> num;
			M[num]++;
		}
		map<int,int>::iterator it = M.begin();
		
		for (it = M.begin(); it != M.end(); it++)
		{
			if(maxi < it->second)
			{
				maxi = it->second;
				res = it->first;
			}
		}
		cout << res << endl;
	}
	return 0;
}