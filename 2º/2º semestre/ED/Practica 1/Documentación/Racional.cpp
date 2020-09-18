#include "Racional.h"
#include <cmath>

//Metodos publicos
/*COMPLETAR*/
Racional::Racional()
{
	_numer = new long;
	_denom = new long;

	*_numer = 0;
	*_denom = 1;
	/*long aux = 1;
	this->_numer = 0;
	this->_denom = &aux;*/
}

Racional::Racional(long n, long d)
{
	if(d != 0)
	{
		_numer = new long;
		_denom = new long;

		*_numer = n;
		*_denom = d;

		reduce();
	}
	else
	{
		throw EDenominadorCero();
	}
}
	
Racional Racional::suma(const Racional aux)
{
	long base = 0;
	Racional res;

	if (_denom != aux._denom)
	{
		base = mcm(*_denom, *aux._denom);
		*_numer = base / *_denom;
		*aux._numer = base / *aux._denom;
	}
	 
	res._numer = Racional::_numer + *aux._numer;
	res._denom = &base;

	return res;
}

/*Racional divideYActualiza(const Racional aux)
{

}

Racional operator-(const Racional& f)
{

}

Racional operator*=(const Racional& f)
{

}

Racional operator==(const Racional& f)
{

}*/

long Racional::getNumer()
{
	return *_numer;
}

long Racional::getDenom()
{
	return *_denom;
}

long Racional::setNumer(long numer)
{
	*_numer = numer;

	return *_numer;
}
long Racional::setDenom(long denom)
{
	*_denom = denom;

	return *_denom;
}

// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f)
{
	out << *f._numer << "/" << *f._denom;
	return out;
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
