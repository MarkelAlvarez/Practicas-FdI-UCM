#include "Racional.h"
#include <cmath>


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f)
{
	out << *f._numer << "/" << *f._denom;
	return out;
}

Racional::Racional()
{
	_numer = new long;
	*_numer = 0;
	_denom = new long;
	*_denom = 1;

}

Racional::Racional(long n, long d)
{
	if (d == 0)
	{
		throw Racional::EDenominadorCero();
	}
	else
	{
		_numer = new long;
		*_numer = n;
		_denom = new long;
		*_denom = d;

		reduce();
	}
}

Racional Racional::suma(const Racional& arg)
{
	long a = *_numer;
	long b = *_denom;
	long c = *arg._numer;
	long d = *arg._denom;
	
	long numerador, denominador;

	denominador = mcm(b, d);
	numerador = ((a * denominador / b) + (c * denominador / d));

	*_numer = numerador;
	*_denom = denominador;
	reduce();

	return *this;
}

Racional Racional:: operator - (const Racional& arg)
{
	long a = *_numer;
	long b = *_denom;
	long c = *arg._numer;
	long d = *arg._denom;

	long numerador, denominador;

	denominador = mcm(b, d);
	numerador = ((a * denominador / b) - (c * denominador / d));

	*_numer = numerador;
	*_denom = denominador;
	reduce();

	return *this;
}

Racional Racional::operator*=(const Racional& arg)
{
	long a = *_numer;
	long b = *_denom;
	long c = *arg._numer;
	long d = *arg._denom;

	*_numer = a*c;
	*_denom = b*d;
	reduce();

	return *this;
}

Racional Racional::divideYActualiza(const Racional& arg)
{
	long a = *_numer;
	long b = *_denom;
	long c = *arg._numer;
	long d = *arg._denom;

	if (c == 0 && d == 1)
	{
		throw Racional::EDivisionPorCero();
	}
	else
	{
		*_numer = a*d;
		*_denom = b*c;
	}
	reduce();

	return *this;
}

bool Racional::operator==(const Racional& arg) const
{
	long a = *_numer;
	long b = *_denom;
	long c = *arg._numer;
	long d = *arg._denom;

	return (a == c && b == d);
}

// Metodos privados
void Racional::reduce()
{
	// Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0)
	{
		*_numer = -(*_numer);
		*_denom = -(* _denom);
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

long Racional::mcd(long v1, long v2)
{
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);

	if (v1 < v2)
	{
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}

	while (v2 != 0)
	{
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}

	return v1;
}

long Racional::mcm(long v1, long v2)
{
	return v1*v2 / mcd(v1, v2);
}

