#include <iostream>
#include <algorithm> // Para función abs().
using namespace std;

#define MAX_N 10
#define MAX_R 20

struct Restriccion {
  int a;
  int b;
  bool amigos; // true si son amigos (dist será la distancia máxima)
  int dist; // Siempre positivo (se quita el signo en la lectura)
};

// ... Añade otras funciones si las necesitas ...

int cuantas(// Descripción del problema
			int n, // Personas a sentar
			Restriccion restricciones[],
			int nRestricciones,
			// ... Añade otros parámetros si los necesitas ...
			)
{
  // ...
}


bool resuelve()
{
  Restriccion restricciones[MAX_R];
  // ... Añade otras declaraciones si las necesitas ...

  // Lectura
  int n, m;
  cin >> n >> m;

  if (!n && !m)
	 return false;

  for (int i = 0; i < m; ++i)
  {
	 cin >> restricciones[i].a >> restricciones[i].b >> restricciones[i].dist;
	 restricciones[i].amigos = restricciones[i].dist > 0;
	 restricciones[i].dist = abs(restricciones[i].dist);
  }

  int ret = cuantas(n, restricciones, m/*, ...*/);

  cout << ret << '\n';
  
  return true;

}

int main()
{

  while (resuelve());

  return 0;
}