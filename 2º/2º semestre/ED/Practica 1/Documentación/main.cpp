#include "Racional.h"

   // Codigo de prueba
   // Procesa un archivo de entrada que incluye 0 o mas comandos de las siguiente formas: 
   //      + f1 f2
   //      - f1 f2
   //      * f1 f2
   //      / f1 f2
   //      == f1 f2
   // donde f1 y f2 son fracciones. Los numeradores y denominadores siempre estan en el
   // rango de 'long', pero no se garantiza que las fracciones sean validas (puede
   // haber fracciones con 0 en el denominador), ni que sean irreducibles.
   // Los comandos se procesan, en orden de aparicion, como sigue:
   //         (1) "+ f1 f1", "- f1 f1" y "* f1 f2" realiza la operacion con
   //             las fracciones indicadas y escriben el resultado. 
   //         (2) "/ f1 f2" se comporta igual, salvo que, si se detecta division por 0,
   //             se escribe DIVISION_POR_CERO.
   //         (4) "== f1 f2" compara f1 con f2 y escribe el resultado
   //  Si durante el proceso se encuentra una fraccion no valida, se escribe
   //       ERROR_EN_ARGUMENTO

    
   // Lee una fraccion de la entrada estandar
Racional leeFraccion()
{
	long numer, denom;
	char sdiv;

	cin >> numer >> sdiv >> denom;
	
	return Racional(numer, denom);
}

int main()
{
	string comando;
	cout << boolalpha;
	  // Se ejecutan los comandos
	  while (cin >> comando)
	  {
		try {  
		  // En 'comando' estara el comando leido
		  Racional arg1 = leeFraccion();
		  Racional arg2 = leeFraccion();
	      // Se ejecuta el comando
	      switch (comando[0]) {
			  case '+':
				  cout << arg1.suma(arg2) << endl;
				  break;
			  /*case '-':
				  cout << arg1 - arg2 << endl;
				  break;
			  case '*':
				  arg1 *= arg2;
				  cout << arg1 << endl;
				  break;
			  case '/':
			      arg1.divideYActualiza(arg2);
			      cout << arg1 << endl;
				  break;
			  case '=':
				  cout << (arg1 == arg2) << endl;
				  break;*/
			  }
		  }
		  catch(Racional::EDenominadorCero) {
			 cout <<  "ERROR_EN_ARGUMENTO" << endl;
			 string resto_linea;
			 getline(cin,resto_linea);
		  }
		  catch(Racional::EDivisionPorCero) {
			 cout << "DIVISION_POR_CERO" << endl;
		  }
	  }

	  return 0;
}



