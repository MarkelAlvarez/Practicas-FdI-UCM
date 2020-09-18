/*#include <iostream>
#include <vector>

using namespace std;

void MergeSort(int *data, int start, int end);
void merge(int *v, int a, int m, int b);

int main() {
	int numvec, numelem;
	int* v;
	cin >> numvec;
	for (int t = 0; t < numvec; t++) {
		cin >> numelem;
		v = new int[numelem];
		for (int i = 0; i < numelem; i++){
			cin >> v[i];
		}

		MergeSort(v, 0, numelem -1);

		for (int i = 0; i < numelem; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}




	return 0;
}


void MergeSort(int *data, int start, int end){
	if (start < end)
	{
		int middle = (start + end) / 2;

		
		MergeSort(data, start, middle);

		
		MergeSort(data, middle + 1, end);

		
		merge(data, start, middle, end);
	}
}

void merge(int *v, int a, int m, int b){

	int *u = new int[b - a + 1];
	int i, j, k;

	for (k = a; k <= b; k++) {
		u[k - a] = v[k];
	}
		
	i = 0;
	j = m - a + 1; 
	k = a;

	while ((i <= m - a) && (j <= b - a)) {
		if (u[i] <= u[j]) {
			v[k] = u[i];
			i = i + 1;
		}
		else {
			v[k] = u[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i <= m - a) {
		v[k] = u[i]; 
		i = i + 1; 
		k = k + 1;
	}
	while (j <= b - a) {
		v[k] = u[j]; 
		j = j + 1;
		k = k + 1;
	}
	delete[] u;
}*/