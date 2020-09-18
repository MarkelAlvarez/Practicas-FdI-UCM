/*#include <iostream>
#include <string>

using namespace std;

void contar(int *v, int numelem, int contador, long long int &inversiones);

int main() {
	int numcasos, numelem;
	long long inversiones;
	int *v;
	cin >> numcasos;
	for (int t = 0; t < numcasos; t++){
		inversiones = 0;
		cin >> numelem;
		if (numelem > 0) {
			v = new int[numelem];
			for (int i = 0; i < numelem; i++) {
				cin >> v[i];
			}
			if (numelem > 1) {
				contar(v, numelem, 0, inversiones);
			}
		}		
		cout << inversiones << endl;
	}

	return 0;
}

void contar(int *v, int numelem, int contador, long long int &inversiones) {
	int x;
	
		x = v[contador];
		for (int j = contador + 1; j < numelem; j++) {
			if (x > v[j]) {
				inversiones += 1;
			}
		}
	
	if (contador < numelem - 2) {
		contador += 1;
		contar(v, numelem, contador, inversiones);
	}
}*/