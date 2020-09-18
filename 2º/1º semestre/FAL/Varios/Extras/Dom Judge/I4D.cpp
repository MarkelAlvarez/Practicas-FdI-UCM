/*#include <iostream>

using namespace std;

char algorithm(char* v, int contador, char x, char final);

int main() {
	int numcasos;
	char* v;
	char inicial, final;
	cin >> numcasos;

	for (int i = 0; i < numcasos; i++) {
		cin >> inicial >> final;
		v = new char[final - inicial];
		for (int j = 0; j < final - inicial; j++) {
			cin >> v[j];
		}
		cout << algorithm(v, final - inicial, inicial, final) << endl;
	}
	return 0;
}

char algorithm(char* v, int contador, char x, char final) {
	bool found = false;
	if (x == final) {
		return final;
	}
	else {
		for (int i = 0; i < contador; i++) {
			if (v[i] == x) {
				found = true;
			}
		}
		if (found) {
			return algorithm(v, contador, x + 1, final);
		}
		else {
			return x;
		}
	}
	
}*/