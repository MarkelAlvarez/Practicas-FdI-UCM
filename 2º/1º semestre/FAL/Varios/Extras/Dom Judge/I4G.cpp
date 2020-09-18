/*#include <iostream>

using namespace std;

void algorithm(int* v, int nnums, int contador, int &min);

int main() {
	int nnums, min;
	while (cin >> nnums) {
		int*v = new int[nnums];
		for (int i = 0; i < nnums; i++) {
			cin >> v[i];
		}
		min = v[0];
		algorithm(v, nnums, 1, min);
		cout << min << endl;
	}
	return 0;
}

void algorithm(int* v, int nnums, int contador, int &min) {
	if (v[contador] < min && contador < nnums) {
		min = v[contador];
		
			algorithm(v, nnums, contador + 1, min);
			
	}
}*/