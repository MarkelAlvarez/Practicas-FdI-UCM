#include <iostream>
#include <string.h>
using namespace std;

int cache[32][10];

int calc(int total, int fondo);

int main()
{
	int casos;

	cin >> casos;
	
	while(casos--)
	{
		int visible, fondo;

		cin >> visible >> fondo;

		memset(cache, -1, sizeof(cache));

		if(calc(visible, fondo))
		{
			cout << "GANA\n";
		}
		else
		{
			cout << "PIERDE\n";
		}
	}

	return 0;
}

int calc(int total, int fondo)
{
	int resultado;

	if(total >= 31)
	{
		return 1;
	}

	if(cache[total][fondo] != -1)
	{
		return cache[total][fondo];
	}
	else
	{
		if(fondo == 1)      resultado = !calc(total+2, 2) || !calc(total+3, 3) || !calc(total+4, 4) || !calc(total+7, 7);
		else if(fondo == 2) resultado = !calc(total+1, 1) || !calc(total+3, 3) || !calc(total+5, 5) || !calc(total+8, 8);
		else if(fondo == 3) resultado = !calc(total+1, 1) || !calc(total+2, 2) || !calc(total+6, 6) || !calc(total+9, 9);
		else if(fondo == 4) resultado = !calc(total+1, 1) || !calc(total+5, 5) || !calc(total+6, 6) || !calc(total+7, 7);
		else if(fondo == 5) resultado = !calc(total+2, 2) || !calc(total+4, 4) || !calc(total+6, 6) || !calc(total+8, 8);
		else if(fondo == 6) resultado = !calc(total+3, 3) || !calc(total+4, 4) || !calc(total+5, 5) || !calc(total+9, 9);
		else if(fondo == 7) resultado = !calc(total+1, 1) || !calc(total+4, 4) || !calc(total+8, 8) || !calc(total+9, 9);
		else if(fondo == 8) resultado = !calc(total+2, 2) || !calc(total+5, 5) || !calc(total+7, 7) || !calc(total+9, 9);
		else 				resultado = !calc(total+3, 3) || !calc(total+6, 6) || !calc(total+7, 7) || !calc(total+8, 8);
	}

	return cache[total][fondo] = resultado;
}