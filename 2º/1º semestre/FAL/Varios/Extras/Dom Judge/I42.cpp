/*#include <iostream>
#include <vector>

using namespace std;

bool algorithm(vector<int> v, int inicio, int final);

int main() {
	vector<int> v;
	int n, numero;
	int contador;

	while (cin >> n && n != 0) {

		v.push_back(n);
		contador = 1;
		while (cin >> numero && numero != 0) {
			v.push_back(numero);
			contador++;
		}
		if (algorithm(v, 0, contador)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		v.erase(v.begin(), v.end());
	}


	return 0;
}

bool algorithm(vector<int> v, int inicio, int final) {
	int min = v[inicio];
	int max = v[final - 1];


	for (int i = inicio; i < final - 1; i++) {
		if (i < (final + inicio) / 2) {
			if (v[i] < min) {
				min = v[i];
			}
		}
		else {
			if (v[i] < min) {
				return false;
			}
		}
		if (final - 1 - i >= (final + inicio) / 2){
			if (v[final - 1 - i] > max) {
				max = v[final - 1 - i];
			}
		}
		else {
			if (v[final - 1 - i] > max) {
				return false;
			}
		}
	}
	
	
		if (final - inicio == 2 || (algorithm(v, inicio, (final + inicio) / 2) && algorithm(v, (final + inicio) / 2, final))) {
			return true;
		}
		else {
			return false;
		}
}*/