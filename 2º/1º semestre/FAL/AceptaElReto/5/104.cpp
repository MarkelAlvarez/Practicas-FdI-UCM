#include <iostream>
using namespace std;

bool balanceado(int pi, int di, int pd, int dd, int &w)
{
	bool izq = true;

	if (pi == 0)
	{
		int pii, dii, pdi, ddi;

		scanf("%d%d%d%d",&pii,&dii,&pdi,&ddi);
		
		izq = balanceado(pii, dii, pdi, ddi, pi);
	}

	bool dch = true;

	if (pd == 0)
	{
		int pid, did, pdd, ddd;

		scanf("%d%d%d%d",&pid,&did,&pdd,&ddd);
		
		dch = balanceado(pid, did, pdd, ddd, pd);
	}

	w = pi + pd;

	return (izq && dch && (pi*di == pd*dd));
}

int main()
{
	int pd, pi, di, dd, w;
	bool ret = false;

	while((scanf("%d%d%d%d", &pi, &di, &pd, &dd) == 4) && (pi != 0 || pd != 0 || di != 0 || dd != 0))
	{
		ret = balanceado(pi, di, pd, dd, w);

		if(ret)
		{
			cout << "SI\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}