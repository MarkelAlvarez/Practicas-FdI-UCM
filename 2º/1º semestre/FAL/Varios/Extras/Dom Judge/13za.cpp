/*#include <iostream>

using namespace std;
int algorithm(int *v, int n);

int main() {
	int n;
	int *v;

	while (cin >> n) {
		v = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < algorithm(v, n); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}


	return 0;
}

int algorithm(int *v, int n) {
	bool found = false;
	int j, indice = n, numero, temp;
	for (int i = 0; i < n; i++) {
		numero = v[i];
		if (numero % 2 != i % 2) {
			j = i + 1;
			while (!found && j < n) {
				if (numero % 2 == j % 2 && v[j] % 2 == i % 2) {
					temp = v[j];
					v[j] = numero;
					v[i] = temp;
				}
				j++;
			}
			if (!found) {
				indice = j;
			}
		}
	}
	return indice;
}*/