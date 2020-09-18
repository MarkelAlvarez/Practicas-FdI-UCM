/*#include <iostream>

using namespace std;
void algorithm(int *v, int &racha, int &veces, int &ultimospart, int n);

int main() {
	int n, racha = 0, veces = 0, ultimospart= 0;
	int *v;


	while (cin >> n) {
		v = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		algorithm(v, racha, veces, ultimospart, n);

		cout << racha << " " << veces << " " << ultimospart << endl;
		racha = 0;
		veces = 0;
		ultimospart = 0;
	}
	return 0;
}

void algorithm(int *v, int &racha, int &veces, int &ultimospart, int n) {
	int rachatemp = 0;

	for (int i = 0; i < n; i++) {
		ultimospart++;
		if (i != n - 1) {
			if (v[i] > 0) {
				rachatemp++;
			}
			else if (rachatemp != 0) {
				if (rachatemp > racha) {
					racha = rachatemp;
					ultimospart = 1;
					rachatemp = 0;
					veces = 1;
				}
				else if (rachatemp == racha) {
					rachatemp = 0;
					ultimospart = 1;
					veces++;
				}
			}
		}
		else {
					
			if (rachatemp > racha) {
				racha = rachatemp;
				ultimospart = 0;
				veces = 1;
			}
			else if (rachatemp == racha && rachatemp != 0) {
				ultimospart = 0;
				veces++;
			}
			

		}
		
	}

}*/