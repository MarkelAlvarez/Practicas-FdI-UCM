/*#include <iostream>
#include <string>

using namespace std;

void algorithm(string* v, int columnas);

int main() {
	int filas, columnas;
	string **v;

	while (cin >> filas && cin >> columnas) {
		v = new string*[filas];
		for (int i = 0; i < filas; i++) {
			v[i] = new string[columnas];
			for (int j = 0; j < columnas; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < filas; i++) {
			algorithm(v[i], columnas);
		}
		
	}
}

void algorithm(string* v, int columnas) {
	int inicio = 0, final = -1;
	int iniciot;

	for (int i = 0; i < columnas; i++) {
		if (v[i] == "FFFFFF") {
			iniciot = i;
		}
	}


}*/