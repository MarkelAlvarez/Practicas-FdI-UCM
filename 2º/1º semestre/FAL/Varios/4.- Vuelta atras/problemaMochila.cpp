#include <iostream>
using namespace std;

void mochila(/*Información del problema*/float peso[], float beneficio[], int n, float capacidad,/*Solucion parcial*/bool productos[], int k,/*Marcaje*/float pesoAcumulado, float beneficioAcumulado,/*Poda*/float maximoBeneficioPendiente,/*Mejor solucion*/float &maximoBeneficio, bool mejorSolucion[]);

int main()
{
	int ;
	bool ;
	float ;

	mochila();

	return 0;
}

void mochila(/*Información del problema*/float peso[], float beneficio[], int n, float capacidad,/*Solucion parcial*/bool productos[], int k,/*Marcaje*/float pesoAcumulado, float beneficioAcumulado,/*Poda*/float maximoBeneficioPendiente,/*Mejor solucion*/float &maximoBeneficio, bool mejorSolucion[])
{
	if (k == n)
	{
		if (beneficioAcumulado > maximoBeneficio)
		{
			for (int i = 0; i < n; ++i)
			{
				mejorSolucion[i] = productos[i];
			}
		}
		return;
	}
	
	//Caso recursivo
	//Opcion 1: no cogemos el producto
	if (maximoBeneficio < (beneficioAcumulado + maximoBeneficioPendiente - beneficio[k]))
	{
		producto[k] = false; //si se pone este no hace falta poner el de abajo y viceversa
		mochila(peso, beneficio, n, capacidad, productos, k+1, pesoAcumulado, beneficioAcumulado, maximoBeneficioPendiente-beneficio[k], maximoBeneficio, mejorSolucion);
	}
	//Opcion 2: cogemos el producto
	if (pesoAcumulado+peso[k] <= capacidad)
	{
		productos[k] = true;
		mochila(peso, beneficio, n, capacidad, productos, k+1, pesoAcumulado+peso[k], beneficioAcumulado+beneficio[k], maximoBeneficioPendiente-beneficio[k], maximoBeneficio, mejorSolucion);
		//productos[k] = false;
	}
}