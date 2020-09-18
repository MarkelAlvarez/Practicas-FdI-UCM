/*
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> torre, int azul, int rojo, int verde);
void algo(vector<int> torre,int azul,int rojo, int verde, int pos, vector<int> puestos, bool &tratado);
bool isValidSolution(vector<int> torre, vector<int> puestos, int pos, int azul, int rojo, int verde);
bool isSolution(vector<int> torre, vector<int> puestos, int pos);
void treatSolution(vector<int> torre);


int main() {
	int altura, azul, rojo, verde;

	while (cin >> altura && cin >> azul && cin >> rojo && cin >> verde && altura != 0) {
		vector<int> torre(altura, -1);
		backtracking(torre, azul, rojo, verde);
		cout << endl;
	}

	return 0;
}

void backtracking(vector<int> torre, int azul, int rojo, int verde) {
	vector<int> puestos(3, 0);
	bool tratado = false;

	if (rojo > 0) {
		torre[0] = 1; //rojo
		puestos[1]++;
		algo(torre, azul, rojo, verde, 1, puestos, tratado);
		if (tratado == false) {
			cout << "SIN SOLUCION" << endl;
		}
	}
	else cout << "SIN SOLUCION" << endl;

}

void algo(vector<int> torre, int azul, int rojo, int verde, int pos, vector<int> puestos, bool &tratado) {
	int color = 0;
	while (color < 3 && pos < torre.size()) {
		torre[pos] = color;
		puestos[color] += 1;
		if (isValidSolution(torre, puestos, pos, azul, rojo, verde)) {
			if (isSolution(torre, puestos, pos)) {
				treatSolution(torre);
				tratado = true;
			}
			else {
				algo(torre, azul, rojo, verde, pos + 1, puestos, tratado);
			}
		}
		puestos[color] -= 1;
		color++;
	}
}

bool isValidSolution(vector<int> torre, vector<int> puestos, int pos, int azul, int rojo, int verde) {
	if (puestos[0] > azul) {
		return false;
	}
	else if (puestos[1] > rojo) {
		return false;
	}
	else if (puestos[2] > verde) {
		return false;
	}
	else if(torre[pos] == 2 && torre[pos - 1] == 2){
		return false;
	}
	else if(puestos[2] > puestos[0]){
		return false;
	}
	else {
		return true;
	}
}

bool isSolution(vector<int> torre, vector<int> puestos, int pos) {
	if (pos < torre.size() - 1) {
		return false;
	}

	else if (puestos[1] <= puestos[0] + puestos[2]) {
		return false;
	}
	else {
		return true;
	}	
}

void treatSolution(vector<int> torre) {//esto a lo mejor va mal pr hacer print del espacio al final
	for (int i = 0; i < torre.size(); i++) {
		if (torre[i] == 0) {
			cout << "azul" << " ";
		}
		else if (torre[i] == 1) {
			cout << "rojo" << " ";
		}
		else {
			cout << "verde" << " ";
		}
	}
	cout << endl;
}*/