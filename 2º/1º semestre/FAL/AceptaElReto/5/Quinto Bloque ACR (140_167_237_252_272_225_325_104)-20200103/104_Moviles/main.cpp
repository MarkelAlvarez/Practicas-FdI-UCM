/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 104 M�viles

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
	else {// Caso recursivo, tiene alambres en alg�n lateral. Mirar primero izquierda.

		cin >> local_pi >> local_di >> local_pd >> local_dd; // Recogida de los valores de mi m�vil actual.

		if ((pesoI==0) && (pesoD==0)) { // Con dos alambres

			mi_movilI = mov_recursivo(local_pi, local_di, local_pd, local_dd); //Primero Izquierda

			cin >> local_pi >> local_di >> local_pd >> local_dd;
			mi_movilD = mov_recursivo(local_pi, local_di, local_pd, local_dd); //Despu�s derecha

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
   ACEPTA EL RETO. 104 M�viles

   En este ejercicio hacemos un �rbol de recursi�n que puede tener una llamada, dos o ninguna
   (en funci�n del n�mero de ceros que encontremos en PesoIzq y PesoDer). En caso de encontrar 
   en los dos lados, siempre pedimos primero el izquierdo porque as� entran por consola. Si 
   no tiene ninguno es que la rama ha terminado, es una "hoja" (caso Base).

   Una de las cosas que no sabemos en este ejercicio es cu�ndo acaba. No sabemos cu�ntas ramas
   tendr� y c�mo ser�n de profundas, as� que vamos tomando por consola a medida que la recursi�n
   se hace m�s profunda, no lo podemos tomar todo al comenzar el caso. En un determinado momento 
   dejar�n de entrar ramificaciones y se acabar� el caso.

   Para poder hacer comprobaciones de si los m�viles est�n equilibrados o no adem�s de devolver
   un booleano devolvemos en un struct el peso total del m�vil (con todas sus ramas anteriores)
   as� se puede calcular el nuevo peso f�cilmente y realizar el (piXdi=pdXdd).

*/