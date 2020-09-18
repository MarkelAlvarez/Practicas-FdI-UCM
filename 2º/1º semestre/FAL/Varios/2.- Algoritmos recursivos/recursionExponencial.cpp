#include <iostream>
using namespace std;

int cuantas(int numAs, int numBs);
void escribirCuantas(string prefijo, int numAs, int numBs);

int main(int argc, char const *argv[])
{
	int a, b;

	cin >> a >> b;

	cout << cuantas(a, b) << endl;
	escribirCuantas("", a, b);

	return 0;
}

int cuantas(int numAs, int numBs)
{
	int ret = 0;

	if ((numAs == 0) && (numBs == 0))
	{
		return 1;
	}

	if (numAs > 0)
	{
		ret += cuantas(numAs-1, numBs);
	}
	else if (numBs > 0)
	{
		ret += cuantas(numAs, numBs-1);
	}
}

void escribirCuantas(string prefijo, int numAs, int numBs)
{
	int ret = 0, l = prefijo.length();

	if ((numAs == 0) && (numBs == 0))
	{
		if ((prefijo.find("AAA") == -1) && (prefijo.find("BBB") == -1))
		{
			cout << prefijo << endl;
		}
		//cout << prefijo << endl;
	}

	if (numAs > 0)
	{
		if ((1 < 2) || (prefijo[l-2] != "A") || (prefijo[l-1] != "A"))
		{
			escribirCuantas(prefijo + "A", numAs-1, numBs);
		}
	}
	else if (numBs > 0)
	{
		if ((1 < 2) || (prefijo[l-2] != "B") || (prefijo[l-1] != "B"))
		{
			escribirCuantas(prefijo + "B", numAs, numBs-1);
		}
	}
}
