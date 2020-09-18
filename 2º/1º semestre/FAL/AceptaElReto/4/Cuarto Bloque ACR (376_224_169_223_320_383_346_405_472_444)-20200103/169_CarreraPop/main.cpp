/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 169 Carrera Popular

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
#include <string>
using namespace std;

const string CADFIN= "====";

void casoDePrueba() {
	string aux_cad;
	vector <char> apellido, apellido_ant;
	int pos;
	bool hay_hermanos = false;
	long long int runners = 0, tot_hermanos = 0, parc_hermanos = 1;
	apellido_ant.clear();
	do {
		getline(cin,aux_cad);
		
		if (aux_cad != CADFIN) {
			++runners;
			pos = aux_cad.find_first_of(',');
			for (int i = 0; i < pos; ++i) {
				apellido.push_back(tolower(aux_cad[i]));
			}

			if (apellido == apellido_ant) {
				++parc_hermanos;
				hay_hermanos = true;
			}
			else if(hay_hermanos) {
				tot_hermanos = tot_hermanos + parc_hermanos;
				parc_hermanos = 1;
				hay_hermanos = false;
			}

			apellido_ant = apellido;
			apellido.clear();
			aux_cad.clear();
		}


	} while (aux_cad != CADFIN);
	if(hay_hermanos){ tot_hermanos = tot_hermanos + parc_hermanos; }

	cout << runners << " " << tot_hermanos << endl;
}



int main() {
	int numcasos;
	cin >> numcasos;
	cin.ignore();
	for (int i = 0; i < numcasos; ++i) {
		casoDePrueba();
	}
	return 0;
}

/*
   ACEPTA EL RETO. 169 Carrera Popular.

   Para el procesado de los apellidos tomamos la coordenada de la cadena
   donde está la coma (que solo puede haber una). Nos quedamos con el apellido,
   que va antes de la coma, previamente pasado por la función tolower()
   (que funciona proporcionando la minúscula de cualquier caracter) y así 
   nos libramos del inconveniente de comparar mayúsculas o minúsculas.

   Es importante entender que para llevar el conteo de los hermanos, sin sumar
   de más, tenemos que organizarlo por grupos una vez detectada una
   coincidencia. Cuando se acaba una lista de hermanos es ahí donde sumamos
   al contador total y no antes.

*/