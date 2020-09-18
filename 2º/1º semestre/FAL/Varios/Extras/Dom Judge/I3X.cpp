#include <iostream>

using namespace std;

int main() {
	int numcasos, numelem,segtot, segt;
	int *v;
	bool sigue = false;

	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) {
		cin >> numelem;
		
		v = new int[numelem];
		for (int j = 0; j < numelem; j++) {
			cin >> v[j];
		}
		if (numelem > 2) {
			segtot = 2; segt = 2;
			for (int j = 2; j < numelem; j++) {
				if (v[j] == v[j - 1] + v[j - 2]) {
					segt += 1;
					sigue = true;
				}
				else {
					if (sigue) {
						sigue = false;
						if (segt > segtot) {
							segtot = segt;
						}
						segt = 0;
					}
				}
			}
			cout << segtot << endl;
		}
		else {
			cout << numelem << endl;
		}
		
	}





	return 0;
}