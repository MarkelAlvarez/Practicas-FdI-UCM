/*#include <iostream>

using namespace std;

int main() {
	int numcuadrantes, dim, numpeces, suma;
	int **v;
	int **resultados;

	while (cin >> numcuadrantes) {
		cin >> dim;
		numpeces = 0;
		v = new int*[numcuadrantes];
		for (int i = 0; i < numcuadrantes; i++) {
			v[i] = new int[numcuadrantes];
			for (int j = 0; j < numcuadrantes; j++) {
				cin >> v[i][j];
			}
		}
		resultados = new int*[numcuadrantes];
		for (int i = 0; i < numcuadrantes; i++) {

			resultados[i] = new int[numcuadrantes - dim + 1];
			for (int k = 0; k < numcuadrantes - dim + 1; k++) {
				suma = 0;
				for (int j = k; j < k + dim; j++) {
					suma += v[i][j];
				}		
				resultados[i][k] = suma;
			}
		}

		
		for (int i = 0; i < numcuadrantes - dim + 1; i++) {

			for (int k = 0; k < numcuadrantes - dim + 1; k++) {
				suma = 0;
				for (int j = k; j < k + dim; j++) {
					suma += resultados[j][i];
				}
				if (suma > numpeces) {
					numpeces = suma;
				}
				
			}
		}

		cout << numpeces << endl;

	}



	return 0;
}*/