/*#include <iostream>

using namespace std;

bool algorithm(int &pit, int dit, int &pdt, int ddt);

int main() {
	int numcasos;
	int pit, dit, pdt, ddt;

	cin >> numcasos;

	for (int i = 0; i < numcasos; i++) {
		cin >> pit >> dit >> pdt >> ddt;
		if (algorithm(pit,dit,pdt,ddt)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}

bool algorithm(int &pit, int dit, int &pdt, int ddt) {
	int pi, di, pd, dd;
	pi = pit;
	di = dit;
	pd = pdt;
	dd = ddt;

	if (pi == 0) {
		cin >> pi >> di >> pd >> dd;
		if (algorithm(pi,di,pd,dd)) {
			pit += pi + pd;
		}
	}
	else  if (pd == 0) {
		cin >> pi >> di >> pd >> dd;
		if (algorithm(pi, di, pd, dd)) {
			pdt += pd + pi;
		}
	}

	if (pi * di == pd * dd) {
		return true;
	}
	else {
		return false;
	}

}*/
