/*#include <iostream>
#include <string>

using namespace std;

void algorithm(int numjugadores, int* numcanicas, string* nombres);

int main() {
	int numjugadores;
	int* numcanicas;
	string* nombres;

	while (cin >> numjugadores) {
		
		numcanicas = new int[numjugadores];
		nombres = new string[numjugadores];
		for (int i = 0; i < numjugadores; i++) {
			cin >> nombres[i] >> numcanicas[i];
		}
		algorithm(numjugadores, numcanicas, nombres);
	}

	return 0;
}

void algorithm(int numjugadores, int* numcanicas, string* nombres) {
	int* numerocanicas = new int[numjugadores / 2];
	string* nombresjug = new string[numjugadores / 2];
	int contador = 0;
	
		for (int i = 0; i < numjugadores/2; i ++) {
			if (numcanicas[2*i] >= numcanicas[(2*i) + 1]) {
				nombresjug[contador] = nombres[2*i];
				numerocanicas[contador] = numcanicas[2*i] + (numcanicas[(2*i) + 1] / 2);
				contador++;
			}
			else {
				nombresjug[contador] = nombres[2*i + 1];
				numerocanicas[contador] = numcanicas[2*i + 1] + (numcanicas[2*i] / 2);
				contador++;
			}
		}
		if (contador > 1) {
			algorithm(numjugadores / 2, numerocanicas, nombresjug);
		}
		else {
			cout << nombresjug[0] << " " << numerocanicas[0] << endl;
		}
	
}*/