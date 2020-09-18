#include <iostream>
using namespace std;


const int MAX_OBRAS = 10000;

// Indica la complejidad.
// Puedes implementar funciones auxiliares
int minCarga(int v[], int n, int maxViajes) {

  // ... TU CODIGO AQUÍ ...
}


bool resuelve() {
  int n, maxViajes;
  int pesos[MAX_OBRAS];

  // Lectura
  cin >> n >> maxViajes;
  if (!n && !maxViajes)
	 return false;

  for (int i = 0; i < n; ++i)
	 cin >> pesos[i];

  // Cálculo
  int ret = minCarga(pesos, n, maxViajes);

  // Escritura
  cout << ret << '\n';

  return true;
}

int main() {
  while (resuelve())
	 ;
  return 0;
}