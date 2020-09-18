/*#include <iostream>
#include <vector>

using namespace std;

void solucion(int numero,vector<int> &v, int &contador);

int main() {
	int numero, contador;
	vector<int> v;

	while (cin >> numero) {
		contador = 0;
		solucion(numero, v, contador);
		
		for (int i = 0; i < contador; i++) {	
			if (!(i == 0 && v[i] == 0 && contador != 1)) {
				cout << v[i];
			}
			//cout << v[i];			
		}
		cout << endl;
		v.erase(v.begin(), v.end());
	}


	return 0;
}

void solucion(int numero, vector<int> &v, int &contador) {
	int modulo = numero % 10;
	int numeronew = numero / 10;
	v.push_back(modulo);
	contador++;
	if (numeronew != 0){
		solucion(numeronew, v, contador);
	}
}*/