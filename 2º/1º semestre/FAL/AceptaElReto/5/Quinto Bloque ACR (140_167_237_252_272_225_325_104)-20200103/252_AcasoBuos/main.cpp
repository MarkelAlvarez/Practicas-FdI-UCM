/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 252 ¿Acaso hubo búhos acá?

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool palindromo(const vector <char>& v, int ini, int fin) {
	bool palin = false; 

	if ((fin-ini) < 1) { // Caso base. No quedan letras o queda solo una.
		palin = true;
	}
	else { // Caso recursivo. Quedan letras por procesar
		if (v[ini] == v[fin]) {
			palin = palindromo(v, ini+1, fin-1); //Quitamos los extremos modificando los "punteros"
		} 
	}
	return palin; 
}


bool resuelveCaso() {

	int pos, tam;
	string cad;
	vector <char> v;
	getline(cin, cad);

	if (cad!="XXX") {
		tam = cad.length();
		for (int i = 0; i < tam; ++i) {
			if (cad.at(i) == ' ') {
				cad.erase(i, 1); // Eliminación de espacios.
				--i;
				--tam;
			}
			else {
				v.push_back(tolower(cad.at(i))); //Guardado en vector minúsculas.
			}
		}

		if (palindromo(v, 0, v.size()-1)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
		return true;
	}
	else {
		return false;
	}

}


int main() {

	while (resuelveCaso()) {

	}

	return 0;
}
/*
   ACEPTA EL RETO. 252 ¿Acaso hubo búhos acá?

   Siempre devuelve false a menos que sean todos las recursiones true, si falla se corta la recursión.
   Es una especie de algoritmo de recursión final, pero con truncamiento.

   Respecto a la preparación de la cadena de caracteres, vamos eliminando los espacios desde un string
   y después guardándolo en un vector de CHAR ya en minúsculas. Así las comparaciones son directas.

*/