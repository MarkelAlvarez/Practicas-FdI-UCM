#include <stdio.h>
#include <iostream>
using namespace std;

typedef unsigned long long uint64;
uint64 seed;
uint64 state[2] = { seed, seed ^ 0x7263d9bd8409f526 };

uint64 xoroshiro128plus(uint64 s[2]) {
	uint64 s0 = s[0];
	uint64 s1 = s[1];
	uint64 result = s0 + s1;
	s1 ^= s0;
	s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
	s[1] = (s1 << 36) | (s1 >> 28);
	return result;
}

void initSystem(int seed) {
	state[0] = seed;
	state[1] = ((uint64)seed) ^ 0x7263d9bd8409f526;
}

int clave() {
	return xoroshiro128plus(state) % 100000;
}

bool haySietes(int n) {
	// TODO...
	bool ret = false;
	int aux = n;

	while (aux > 10 && !ret)
	{
		if (aux % 10 == 7)
		{
			ret = true;
		}
		aux /= 10;
	}

	if (aux % 10 == 7)
	{
		ret = true;
	}

	/*while ((n != 0) && (n % 10 == 7))
	{
		n /= 10;
	}*/

	return ret /*(n != 0*/;
}

int secuenciaMasLarga(int n) {
	
	int ret = 0, aux = 0, i = 0;

	while (i < n)
	{
		if (!haySietes(clave()))
		{
			aux++;
			if (aux > ret)
			{
				ret = aux;
			}
		}
		else
		{
			aux = 0;
		}
		i++;
	}

	return ret;
}

bool resuelve() {

	// Lectura
	int s, n;
	cin >> s >> n;
	if ((s == 0) && (n == 0))
		return false;

	initSystem(s);

	// Cálculo
	int r = secuenciaMasLarga(n);

	// Escritura
	cout << r << '\n';

	return true;

} // resuelve

int main() {

	// Resolvemos
	while (resuelve());

	return 0;

} // main