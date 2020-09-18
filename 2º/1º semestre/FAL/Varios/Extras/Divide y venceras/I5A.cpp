/*#include <iostream>

using namespace std;

bool elemento_situado(int *v, int ini, int fin);

int main() {
	int numvect,totalpos;
	int *v;
	cin >> numvect;
	for (int i = 0; i < numvect; i++) {
		cin >> totalpos;
		if (totalpos != 0) {
			v = new int[totalpos];
			for (int j = 0; j < totalpos; j++) {
				cin >> v[j];
			}
			if (elemento_situado(v, 0, totalpos - 1)) {
				cout << "SI" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
		
	}




	return 0;
}

bool elemento_situado(int *v, int ini, int fin) {
	int x = (ini + fin) / 2;
	if (x != ini) {
		if (v[x] == x) {
			return true;
		}
		else if (v[x] < x) {
			return elemento_situado(v, x + 1, fin);
		}
		else {
			return elemento_situado(v, ini, x - 1);
		}
	}
	else {
		if (v[x] == x) {
			return true;
		}
		else {
			return false;
		}
	}
	

}*/