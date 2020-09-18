/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 320 Palmeras en la Nieve.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/



#include <iostream>
#include <vector>
using namespace std;

void casoDePrueba() {
	int numelements, aux, peso_nieve, max_tramo = 0, palmeras = 0, ancho1, ancho2;
	vector <int> vec_palmeras;

	cin >> peso_nieve;
	cin >> numelements;
	if (numelements < 6) {
		cout << numelements << endl;
		cin.ignore();
		cin.ignore(2000000, '\n'); //Con esto ignoramos las palmeras de la fila con 5 o menos elementos
	}
	else {
		while (max_tramo < numelements) { // bucle de obtención inicial, hasta 5 palmeras vivas
			cin >> aux;
			if (aux >= peso_nieve) {
				vec_palmeras.push_back(max_tramo);
				++palmeras;
				if (palmeras == 5) {
					++max_tramo;
					break;
				}
			}
			++max_tramo;
		}
		ancho2 = max_tramo;
		for (int k = max_tramo; k < numelements; ++k) { //bucle de recorrido
			cin >> aux;
			if (aux >= peso_nieve) {
				vec_palmeras.push_back(k);
				ancho1 = k - vec_palmeras[palmeras-5];
				++palmeras;
				if (ancho1 > max_tramo) {
					max_tramo = ancho1;
				}
				ancho2 = ancho1;
			}
			else {
				++ancho2;
				if (ancho2 > max_tramo) {
					max_tramo = ancho2;
				}
			}

		}

		cout << max_tramo << endl;
	}


}

int main() {
	int numcasos;

	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		casoDePrueba();
	}

	return 0;
}
/*
   ACEPTA EL RETO. 320 Palmeras en la Nieve.

   Este problema que es bastante intuitivo tiene una cierta complejidad
   a la hora de evaluar computacionalmente el mayor tramo requerido.

   Para poder llevar la cuenta de las palmeras sobrevivientes a la 
   nevada tenemos que evaluar y contar cuándo aparece una 6ª palmera
   (palmera no caída) y desplazar la "ventana" de tramo con 5 palmeras.
   La complicación que surge reside en que el desplazamiento de esa
   ventana es irregular dependiendo del número de agujeros que haya
   abandonando el tramo y además habrá que sumarle los agujeros nuevos
   hasta que encontremos otra vez la 6ª palmera. Si esto supera el tramo
   máximo tomaremos nota de ello.

   Para solventar este problema he considerado crear un vector de enteros
   donde voy anotando en qué posiciones se encuentran las palmeras que 
   han sobrevivido (adquiriendo el peso con CIN y comparando con la nevada).

   OXOOOXOXXOXOOXOX  -> [0,2,3,4,6] Estas son las 5 primeras palmeras (las X son caídas, O son palmeras)
   OXOOOXO||XXOXOOXOX

   Una vez tengo creado este array inicial (con el while que ejecuta un break)
   pasamos a ir incorporando el resto de palmeras procesando el contenido restante en el for:

   OXOOOXOXXOXOOXOX  -> [0,2,3,4,6,9,11,12,14] 

   Cada vez que aparece una nueva palmera resto la diferencia entre el valor
   de la 6ª palmera y el inicio del tramo (que al principio es la componente [0])
   para crear el comienzo de un nuevo tramo.
   El primer tramo con 5 palmeras en pie tiene 9 de ancho [0-8] que se computa con
   los 7 iniciales del while más 2 huecos encontrados después con X.

   El segundo tramo ya comienza con ancho 9 (que es 9-0) y después consigue un aumento
   al tener una X adicional en la posición [10].

   Tramo 1 = 9                   (Array inicial de 7 más 2X)
   OXOOOXOXX    OXOOXOX

      Tramo 2 = 10               (Sacado de 9 menos 0 más 1X)
   O  XOOOXOXXOX   OOXOX

		 Tramo 3 = 9             (Sacado de 11 menos 2)
   OXO  OOXOXXOXO     OXOX

		 Tramo 4 = 10            (Sacado de 12 menos 3 más 1X)
   OXOO   OXOXXOXOOX     OX

		    Tramo 5 = 11         (Sacado de 14 menos 4 más 1X)
   OXOOO    XOXXOXOOXOX


   **El máximo es 11**.
*/