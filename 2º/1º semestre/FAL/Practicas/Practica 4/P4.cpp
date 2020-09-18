/*#include <iostream>
using namespace std;

void fractal(int cx, int cy, int px, int py, int mitadLado, /*out*/ int &numCuadrados, /*out*/ int &longLados)
{
	/*numCuadrados = 0;
	longLados = 0;

	if (cx + mitadLado >= px || cx - mitadLado <= px)
	{
		if ((cy + mitadLado >= py) && (cy - mitadLado <= py))
		{
			if (mitadLado >= 2)
			{
				fractal(cx + mitadLado / 2, cy + mitadLado / 2, px, py, mitadLado / 2, numCuadrados, longLados);
				fractal(cx + mitadLado / 2, cy - mitadLado / 2, px, py, mitadLado / 2, numCuadrados, longLados);
				fractal(cx - mitadLado / 2, cy + mitadLado / 2, px, py, mitadLado / 2, numCuadrados, longLados);
				fractal(cx - mitadLado / 2, cy - mitadLado / 2, px, py, mitadLado / 2, numCuadrados, longLados);
				
				numCuadrados++;
				
				longLados = longLados + 8*mitadLado;
			}
		}
	}
}

int main()
{
	int cx, cy, px, py, mitadLado, numCuadrados, longLados;

	cin >> cx;
	cin >> cy;
	cin >> px;
	cin >> py;
	cin >> mitadLado;

	fractal(cx, cy, px, py, mitadLado, numCuadrados, longLados);

	cout << numCuadrados << " " << longLados << endl;

	return 0;
}*/

#include <iostream>
#include <cmath>
using namespace std;

void fractal(int cx, int cy, int px, int py, int mitadLado, /*out*/ int& numCuadrados, /*out*/ int& longLados);
bool leecasos();

int main() 
{
	while (leecasos());

	return 0;
}

bool leecasos()
{
	int cx, cy, px, py, mitad;

	if (!(cin >> cx))
	{
		return false;
	}

	cin >> cy;
	cin >> px;
	cin >> py;
	cin >> mitad;

	int num_L = 0, Long = 0;

	fractal(cx, cy, px, py, mitad, num_L, Long);

	cout << num_L << " " << Long << endl;

	return true;
}

void fractal(int cx, int cy, int px, int py, int mitadLado, /*out*/ int& numCuadrados, /*out*/ int& longLados)
{
	if (px <= cx + mitadLado && px >= cx - mitadLado && py <= cy + mitadLado && py >= cy - mitadLado) 
	{
		numCuadrados++;
		longLados += 8 * mitadLado;
	}

	if(mitadLado >= 2)
	{
		fractal(cx + mitadLado, cy + mitadLado, px, py, mitadLado/2, /*out*/numCuadrados, /*out*/longLados);
		fractal(cx + mitadLado, cy - mitadLado, px, py, mitadLado/2, /*out*/numCuadrados, /*out*/longLados);
		fractal(cx - mitadLado, cy + mitadLado, px, py, mitadLado/2, /*out*/numCuadrados, /*out*/longLados);
		fractal(cx - mitadLado, cy - mitadLado, px, py, mitadLado/2, /*out*/numCuadrados, /*out*/longLados);
	}
}

