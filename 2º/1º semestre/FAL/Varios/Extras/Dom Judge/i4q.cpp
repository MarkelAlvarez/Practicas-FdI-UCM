/*#include <iostream>

using namespace std;

bool algorithm(int*v, int diferencia, int inicio, int final);

int main() {
	int nnums, diferencia;
	int* v;

	while (cin >> nnums && cin >> diferencia) {
		v = new int[nnums];
		for (int i = 0; i < nnums; i++) {
			cin >> v[i];
		}
		if (algorithm(v,diferencia,0,nnums)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}




	return 0;
}

bool algorithm(int*v, int diferencia, int inicio, int final) {
	int x = v[inicio] - v[final - 1];
	if (x < 0) {
		x *= (-1);
	}
	if (x < diferencia) {
		return false;
	}
	else {
		if (final - inicio == 2) {
			return true;
		}
		else {
			if (algorithm(v, diferencia, inicio, (final + inicio) / 2) && algorithm(v, diferencia, (final + inicio) / 2, final)) {
				return true;
			}
			else {
				return false;
			}
		}
	}





}*/
