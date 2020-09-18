#include "cola.h"
#include <iostream>
using namespace std;


// A IMPLEMENTAR
void supervivientes(int n, Cola<int>& cola) {

}

int main() {
	
	int n;
	Cola<int> cola;

	cin >> n;
	while (n != 0){

		supervivientes(n, cola);

		cout << n << ":";
		while (!cola.esVacia()) {
			cout << " " << cola.primero();
			cola.quita();
		}
		cout << endl;
		
		cin >> n;	
	}
		
	return 0;
}
