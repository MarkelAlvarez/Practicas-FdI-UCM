/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 245 Los Dalton.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
using namespace std;

bool casoDePrueba() {
	long long int nhecos, alt1, alt2, i;
	bool sonasc = true;
	bool sondesc = true;
	cin >> nhecos;
	if (nhecos == 0) {
		return false;
	}
	else {
		cin >> alt1;
		i = 1;
		while (i < nhecos) {
			cin >> alt2;
			sonasc = sonasc && (alt2 > alt1);
			sondesc = sondesc && (alt2 < alt1);
			++i;
			alt1 = alt2;
		}

		if (sonasc || sondesc) {
			cout << "DALTON" << endl;
		}
		else {
			cout << "DESCONOCIDOS" << endl;
		}

		return true;
	}
}
int main() {
	while (casoDePrueba()) {
	}
	return 0;
}
/*
   ACEPTA EL RETO. 245 Los Dalton.

   Para empezar podemos comprobar como si queremos adquirir todos los elementos
   del array de alturas nos da MLE. Por lo tanto debemos intentar procesar los datos
   según entran por consola.

   No queda demasiado claro si la secuencia de DALTON debe ser ascendente o también
   puede ser una secuencia descendente. Tampoco si los hermanos pueden tener alturas
   no consecutivas siempre que mantengan la tendencia.
   Tras hacer las pertienentes pruebas la conclusión es:

   -->La foto es válida siempre que todas las alturas sean diferentes y estén ordenadas
   de forma creciente estricta o decreciente estricta.

   La siguiente complicación de este problema es que evaluar toda la secuencia con 
   While->IF-ELSE se nos va de tiempo, TLE. Por lo tanto debemos idear una forma de 
   saber si es una secuencia estricta con operadores lógicos que tienen un coste
   computacional menor. El orden de complejidad seguirá siendo O(n), sin embargo
   la exigencia nos obliga a afinar más, porque no es lo mismo (8n) que (20n)
   aunque sean del mismo orden asintótico.

   Nótese que en la solución propuesta no se abandona el bucle aunque la foto resulta
   falsa a mitad de camino. Esto puede parecer ineficiente, pero por el contrario para 
   secuencias muy largas el no incluir condiciones acaba siendo mejor opción.

*/