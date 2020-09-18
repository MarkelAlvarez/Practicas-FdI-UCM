/*#include <iostream>

using namespace std;

bool algorithm(int* v, int numerorep, int elems);
bool pelos(int* v, int elems);
bool divertido(int* v, int numerorep, int elems);

int main() {
	int numerocasos, numerorep, elems;
	int *v;
	cin >> numerocasos;
	for (int i = 0; i < numerocasos; i++) {
		cin >> numerorep;
		cin >> elems;
		v = new int[elems];
		for (int j = 0; j < elems; j++) {
			cin >> v[j];
		}
		if (algorithm(v, numerorep, elems)) {
			cout << "SI"<< endl;
		}
		else {
			cout << "NO" << endl;
		}
		delete[] v;
	}
	return 0;
}

bool algorithm(int* v, int numerorep, int elems) {
	bool ambos = false;

	if(pelos(v,elems) && divertido(v,numerorep, elems)){
		ambos = true;
	}

	return ambos;
}

bool pelos(int* v, int elems) {
	bool uno = true;
	int counter = 1;
	
	while (counter < elems && uno) {
		if (v[counter] - v[counter - 1] > 1 || v[counter] - v[counter - 1] < 0){
			uno = false;
		}
		counter++;
	}
	return uno;
}

bool divertido(int* v, int numerorep, int elems) {
	bool divertidisimo = true;
	int i = 0, j = 0, counter, numero;


	while (i < elems && divertidisimo) {
		counter = 0;
		numero = v[i];
		if (numero != 0) {
			j = i;
			while (j < elems && divertidisimo) {
				if (v[j] == numero) {
					counter++;
					v[j] = 0;
				}
				if (counter > numerorep) {
					divertidisimo = false;
				}
				j++;
			}
		}		
		i++;
		counter = 0;
	}
	return divertidisimo;
}*/