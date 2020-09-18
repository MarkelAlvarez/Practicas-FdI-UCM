#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, res = 0, KM, res1 = 0, cont = 0, m = 0, cur = 0;
	bool prim=false;

	cin >> n;
	
	while(n != -1)
	{
		while(m != -1)
		{
			cin >> m;

			if(m == n)
			{
				res++;

				if(res1 < res)
				{
					res1 = res;
					if(!prim)
					{
						KM = cur;
						prim = true;
					}
				}

				n = m;
				cont++;
			}
			else
			{
				prim = false;
				res = 0;
				n = m;
				cont++;
				cur = cont;
			}
		}
		if(res1 != 0)
		{
			cout << KM << " " << res1 << endl;
		}
		else
		{
			cout << "HOY NO COMEN" << endl;
		}
		
		res = 0; cont = 0; m = 0; res = 0; prim = false; res1 = 0; KM = 0; cur = 0;
		cin >> n;
	}

	return 0;
}