/*#include <iostream>

using namespace std;

int main() {
	int numcaso, cant, contador;
	int *v;
	cin >> numcaso;

	for (int i = 0; i < numcaso; i++) {
		cin >> cant;
		contador = 0;
		v = new int[cant];
		for (int j = 0; j < cant; j++) {
			cin >> v[j];
		}
		for (int j = 0; j < cant - 1; j++) {
			if (v[j] > v[j + 1]) {
				contador += 1;
			}
		}
		cout << contador << endl;
	}



	return 0;
}*/