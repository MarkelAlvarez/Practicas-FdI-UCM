/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 104 Móviles

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

struct packMovil {
	long long int peso;
	bool equilibrado;
};


packMovil mov_recursivo(long long int pesoI, long long int distI, long long int pesoD, long long int distD) {
	packMovil mi_movilI, mi_movilD;
	long long int local_pi, local_di, local_pd, local_dd;

	if ((pesoI != 0) && (pesoD != 0)) {//Caso Base, sin alambres colgantes.
		mi_movilI.equilibrado = ((pesoI *distI) == (pesoD * distD));
		mi_movilI.peso = pesoI + pesoD;
	}
	else {// Caso recursivo, tiene alambres en algún lateral. Mirar primero izquierda.

		cin >> local_pi >> local_di >> local_pd >> local_dd; // Recogida de los valores de mi móvil actual.

		if ((pesoI==0) && (pesoD==0)) { // Con dos alambres

			mi_movilI = mov_recursivo(local_pi, local_di, local_pd, local_dd); //Primero Izquierda

			cin >> local_pi >> local_di >> local_pd >> local_dd;
			mi_movilD = mov_recursivo(local_pi, local_di, local_pd, local_dd); //Después derecha

			mi_movilI.equilibrado = mi_movilI.equilibrado && mi_movilD.equilibrado;
			mi_movilI.equilibrado = mi_movilI.equilibrado && ((mi_movilI.peso * distI) == (mi_movilD.peso * distD));
			mi_movilI.peso = mi_movilI.peso + mi_movilD.peso;
			
		}
		else if (pesoI == 0) { // Con alambre a la izquierda
			mi_movilI = mov_recursivo(local_pi, local_di, local_pd, local_dd);

			mi_movilI.equilibrado = mi_movilI.equilibrado && ((mi_movilI.peso * distI) == (pesoD * distD));
			mi_movilI.peso = mi_movilI.peso + pesoD;
		}
		else { // Con alambre a la derecha
			mi_movilD = mov_recursivo(local_pi, local_di, local_pd, local_dd);

			mi_movilI.equilibrado = mi_movilD.equilibrado && ((pesoI * distI) == (mi_movilD.peso * distD));
			mi_movilI.peso = pesoI + mi_movilD.peso;
		}
	}
	return mi_movilI;
}

bool resuelveCaso() {
	long long int pesoI, distI, pesoD, distD;

	cin >> pesoI >> distI >> pesoD >> distD;

	if ((distI + distD + pesoD + pesoI) == 0) {
		return false;
	}
	else {

		if (mov_recursivo(pesoI,distI,pesoD,distD).equilibrado) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
		return true;
	}

}

int main() {

	while (resuelveCaso()) {
	}

	return 0;
}

/*
   ACEPTA EL RETO. 104 Móviles

   En este ejercicio hacemos un árbol de recursión que puede tener una llamada, dos o ninguna
   (en función del número de ceros que encontremos en PesoIzq y PesoDer). En caso de encontrar 
   en los dos lados, siempre pedimos primero el izquierdo porque así entran por consola. Si 
   no tiene ninguno es que la rama ha terminado, es una "hoja" (caso Base).

   Una de las cosas que no sabemos en este ejercicio es cuándo acaba. No sabemos cuántas ramas
   tendrá y cómo serán de profundas, así que vamos tomando por consola a medida que la recursión
   se hace más profunda, no lo podemos tomar todo al comenzar el caso. En un determinado momento 
   dejarán de entrar ramificaciones y se acabará el caso.

   Para poder hacer comprobaciones de si los móviles están equilibrados o no además de devolver
   un booleano devolvemos en un struct el peso total del móvil (con todas sus ramas anteriores)
   así se puede calcular el nuevo peso fácilmente y realizar el (piXdi=pdXdd).

*/