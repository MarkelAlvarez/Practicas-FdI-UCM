/*#include <iostream>

using namespace std;

void algorithm(int* v, int numnaves, int contador, int &movtotales);


int main() {
	int numnaves, movtotales;
	int *v;
	while (cin >> numnaves) {
		movtotales = 0;
		v = new int[numnaves];
		for (int i = 0; i < numnaves; i++) {
			cin >> v[i];
		}
		algorithm(v, numnaves, 0, movtotales);
		cout << movtotales << endl;
		
	}


	return 0;
}

void algorithm(int* v, int numnaves, int contador, int &movtotales) {
	if (contador < numnaves) {
		int x = v[contador];
		
		
		if (x != contador + 1) {
			int pos = 0;
			bool found = false;

			int i = contador + 1;
			while (i < numnaves && !found) {
				if (v[i] == contador + 1) {
					pos = i;
					found = true;
				}
				i++;
			}			
			movtotales += pos - contador;
			for (int i = pos; i > contador ; i--) {
				v[i] = v[i - 1];
			}
			v[contador] = contador + 1;
		}
		algorithm(v, numnaves, contador + 1, movtotales);
	}
	
}*/



