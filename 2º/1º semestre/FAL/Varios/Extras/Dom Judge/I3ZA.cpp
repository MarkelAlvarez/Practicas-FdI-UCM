/*#include <iostream>
#include <vector>

using namespace std;

int main() {
	int dim, numero, pares, aux, pos;
	vector<int> mivector;
	bool changed = false;

	while (cin >> dim) {
		pares = 0;
		for (int i = 0; i < dim; i++) {
			cin >> numero;
			if (numero % 2 == 0) {
				pares++;
			}
			mivector.push_back(numero);
		}
		if (pares > dim - pares) {
			pos = (dim - pares) * 2;
		}
		else {
			pos = pares * 2;
		}

		for (int i = 0; i < pos; i++) {
			if (mivector[i] % 2 != i % 2) {
				int j = i + 1;
				while (j < dim && !changed) {
					if (mivector[j] % 2 != j % 2 && j % 2 == mivector[i] % 2) {
						aux = mivector[i];
						mivector[i] = mivector[j];
						mivector[j] = aux;
						changed = true;
					}
					j++;
				}				
				changed = false;
			}
			cout << mivector[i] << " ";
		}
		//esto va comentado
		 mivector.resize(pos);
		for (int y = 0; y <pos; y++ ){
			cout << mivector[y] << " ";
		}//hasta aqui
		mivector.clear();
		cout << endl;
	}



	return 0;
}*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int dim, numero, pares, aux, pos;
	vector<int> mivector;
	bool changed = false;

	while (cin >> dim) {
		pares = 0;
		for (int i = 0; i < dim; i++) {
			cin >> numero;
			if (numero == 0) {
				pares++;
			}
			mivector.push_back(numero);
		}
		if (pares > dim - pares) {
			pos = (dim - pares) * 2;
		}
		else {
			pos = pares * 2;
		}

		for (int i = 0; i < pos; i++) {
			if (mivector[i] != i % 2) {
				int j = i + 1;
				while (j < dim && !changed) {
					if (mivector[j] != mivector[i]) {
						mivector[i] = j % 2;
						mivector[j] =  i % 2;
						changed = true;
					}
					j += 2;
				}
				changed = false;
			}
			cout << mivector[i] << " ";
		}

		/*mivector.resize(pos);
		for (int y = 0; y <pos; y++) {
			cout << mivector[y] << " ";
		}*/
		/*mivector.clear();
		cout << endl;
	}



	return 0;
}*/