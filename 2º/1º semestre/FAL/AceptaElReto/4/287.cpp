#include <iostream>
using namespace std;

int main()
{
	int ini, n, h, res, i;
	long long int mul;

	while(scanf("%d%d", &ini, &n) == 2)
	{
		res = 0;
		mul = 1;

		for(i = 0; i < n; i++)
		{
			scanf("%d", &h);

			if(n%2 == 0)
			{
				if(i == n/2)
				{
					mul = 78787 - (26262*mul) % 78787;
					res = (res + (ini*h*mul) % 78787) % 78787;
					mul = 78787 - (26262*mul) % 78787;
				}
				else if(i < n/2)
				{
					res = (res + (ini*h*mul)%78787) % 78787;
					mul = (mul*3) % 78787;
				}
				else
				{
					res = (res + (ini*h*mul) % 78787) % 78787;
					mul = 78787 - (26262*mul) % 78787;
				}
			}
			else
			{
				if(i < n/2)
				{
					res = (res + (ini*h*mul) % 78787) % 78787;
					mul = (mul*3) % 78787;
				}
				else
				{
					res = (res + (ini*h*mul) % 78787) % 78787;
					mul = 78787 - (26262*mul) % 78787;
				}
			}
		}

		printf("%d\n", res);
	}
	return 0;
}