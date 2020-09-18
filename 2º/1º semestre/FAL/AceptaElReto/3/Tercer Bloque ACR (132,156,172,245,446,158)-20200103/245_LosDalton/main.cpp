/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 245 Los Dalton.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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
   seg�n entran por consola.

   No queda demasiado claro si la secuencia de DALTON debe ser ascendente o tambi�n
   puede ser una secuencia descendente. Tampoco si los hermanos pueden tener alturas
   no consecutivas siempre que mantengan la tendencia.
   Tras hacer las pertienentes pruebas la conclusi�n es:

   -->La foto es v�lida siempre que todas las alturas sean diferentes y est�n ordenadas
   de forma creciente estricta o decreciente estricta.

   La siguiente complicaci�n de este problema es que evaluar toda la secuencia con 
   While->IF-ELSE se nos va de tiempo, TLE. Por lo tanto debemos idear una forma de 
   saber si es una secuencia estricta con operadores l�gicos que tienen un coste
   computacional menor. El orden de complejidad seguir� siendo O(n), sin embargo
   la exigencia nos obliga a afinar m�s, porque no es lo mismo (8n) que (20n)
   aunque sean del mismo orden asint�tico.

   N�tese que en la soluci�n propuesta no se abandona el bucle aunque la foto resulta
   falsa a mitad de camino. Esto puede parecer ineficiente, pero por el contrario para 
   secuencias muy largas el no incluir condiciones acaba siendo mejor opci�n.

*/