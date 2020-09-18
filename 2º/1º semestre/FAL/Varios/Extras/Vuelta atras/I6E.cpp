/*#include <iostream>
#include <vector>

using namespace std;

void backtracking(int **v, bool **marcas, int numfuncionarios);
void algo(int **v, bool **marcas, int pos, int &tiempominimo, int numfuncionarios, int *sol);
bool isSolution(int *sol, int tiempominimo, int pos, int numfuncionarios);
void treatSolution(int *sol, int &tiempominimo, int numfuncionarios);


int main() {
	int numfuncionarios;
	int **v;
	bool **marcas;
	while (cin >> numfuncionarios && numfuncionarios != 0) {
		
		v = new int*[numfuncionarios];
		marcas = new bool*[numfuncionarios];
		for (int i = 0; i < numfuncionarios; i++) {
			v[i] = new int[numfuncionarios];
			marcas[i] = new bool[numfuncionarios];
			for (int j = 0; j < numfuncionarios; j++) {
				cin >> v[i][j];
				marcas[i][j] = true;
			}
		}
		backtracking(v,marcas, numfuncionarios);
		cout << endl;
	}

	return 0;
}

void backtracking(int **v, bool **marcas, int numfuncionarios) {
	int tiempominimo = 10000 * numfuncionarios;
	int *sol = new int[numfuncionarios];
		algo(v,marcas, 0, tiempominimo, numfuncionarios, sol);
		cout << tiempominimo << endl;
	
	
}

void algo(int **v, bool **marcas, int pos, int &tiempominimo, int numfuncionarios, int *sol) {
	int j = 0;
	while (j < numfuncionarios && pos < numfuncionarios) {
		sol[pos] = v[j][pos];
		if (marcas[j][pos]) {
			if (isSolution(sol,tiempominimo, pos, numfuncionarios)) {
				treatSolution(sol, tiempominimo, numfuncionarios);
				
			}
			else {
				for (int m = 0; m < numfuncionarios; m++) {
					marcas[j][m] = false;
				}
				algo(v,marcas, pos + 1, tiempominimo, numfuncionarios, sol);
				for (int m = 0; m < numfuncionarios; m++) {
					
					marcas[j][m] = true;
				}
			}
		}
		
		j++;
	}
}

bool isSolution(int *sol, int tiempominimo, int pos, int numfuncionarios) {
	if (pos == numfuncionarios - 1) {
		return true;
	}
	else {
		return false;
	}
}

void treatSolution(int *sol, int &tiempominimo, int numfuncionarios) {//esto a lo mejor va mal pr hacer print del espacio al final
	int suma = 0;
	for (int i = 0; i < numfuncionarios; i++) {
		suma += sol[i];
	}
	if (suma < tiempominimo) {
		tiempominimo = suma;
	}
}*/