/*#include <iostream>

using namespace std;

int alone(int *v, int ini, int fin);

int main() {
	int casos, num;
	cin >> casos;
	while (casos > 0){

		cin >> num;
		int *v = new int[num];
		for (int i = 0; i < num; i++){
			cin >> v[i];
		}
		cout << alone(v, 0, num) << "\n";
		delete[] v;
		casos--;

	}
	return 0;
}

int alone(int *v, int ini, int fin) {
	int mid = (ini + fin - 1) / 2;

	if (mid % 2 == 0) {
		if (ini == mid) return ini;
		if (v[mid] == v[mid + 1]) return alone(v, mid, fin);
		else return alone(v, ini, mid + 1);
	}
	else {
		if (ini == mid) return fin - 1;
		if (v[mid] == v[mid + 1]) return alone(v, ini, mid + 1);
		else return alone(v, mid, fin);
	}
}*/

