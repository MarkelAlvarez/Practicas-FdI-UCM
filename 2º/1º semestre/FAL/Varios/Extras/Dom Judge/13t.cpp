/*#include <iostream>

using namespace std;

typedef enum  piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

int main() {
	int numpiedras; int numtipo1, numtipo2; 
	piedrasPreciosas tipo1, tipo2;

	cin >> numpiedras >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
	std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
		char num;
		entrada >> num;
		switch (num) {
		case ’d’: p = diamante; break;
		case ’r’: p = rubi; break;
		case ’e’: p = esmeralda; break;
		case ’z’: p = zafiro; break;
		case ’j’: p = jade; break;
		}
		return entrada;
	}


	return 0;
}*/