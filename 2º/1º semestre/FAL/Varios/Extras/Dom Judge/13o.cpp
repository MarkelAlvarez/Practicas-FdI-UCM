/*#include <iostream>
#include <string>

using namespace std;

void algorithm(string** v, int fila, int columnas, int filas);

int main() {
	int filas, columnas;
	string **v;

	while (cin >> filas && cin >> columnas) {
		v = new string*[columnas];
		for (int i = 0; i < filas; i++) {
			v[i] = new string[columnas];
			for (int j = 0; j < columnas; j++) {
				cin >> v[i][j];
			}
		}
		algorithm(v, 0,columnas, filas); 
	}


	return 0;
}

void algorithm(string** v, int fila, int columnas, int filas) {
	int inicio = 0, final = -1, iniciotemp;
	bool erablanco = false;

	for (int j = 0; j < columnas; j++) {
		if (v[fila][j] != "FFFFFF" && erablanco) {
			if (j - 1 - iniciotemp > inicio - final) {
				final = j - 1;
				erablanco = false;
			}
			
		}
		if (v[fila][j] == "FFFFFF" && !erablanco) {
			erablanco = true;
			iniciotemp = j;
		}
	}

	cout << inicio << " " << final << endl;
	if (fila < filas - 1) {
		algorithm(v, fila + 1, columnas, filas);
	}
}*/