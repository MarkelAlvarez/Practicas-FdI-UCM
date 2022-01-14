#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>	// srand, rand
#include <ctime>	// Aleatorios
#include <cstdlib>	// Convertir string a entero
#include <ctype.h>
#include <unistd.h>

using namespace std;

struct Pregunta {
	string enunciado = "";
	string respuestaA = "";
	string respuestaB = "";
	string respuestaC = "";
	char respuestaSeleccionada;
	char respuestaCorrecta;
} pregunta;

int  menu()
{
	int opcion;

	cout << "------------------------MENU---------------------------" << endl;
	cout << "	¡Vamos a aprobar ASOR!" << endl;											
	cout << "	1 - Estudiar todo (todas las preguntas)" << endl;
	cout << "	2 - Examen de 10 preguntas aleatorias" << endl;
	cout << "	0 - Salir" << endl;
	cout << "	Elige una opción: ";
	cin >> opcion;
	cout << endl;

	return opcion;
}

int  menuParte()
{
	int opcion;

	cout << "------------------------MENU---------------------------" << endl;
	cout << "	1 - Examen de redes" << endl;
	cout << "	2 - Examen de sistemas operativos" << endl;
	cout << "	3 - Examen de todo" << endl;
	cout << "	0 - Atras" << endl;
	cout << "	Elige una opción: ";
	cin >> opcion;
	cout << endl;

	return opcion;
}

int  menuRedes()
{
	int opcion;

	cout << "------------------------MENU---------------------------" << endl;
	cout << "	1 - Revisión del protocolo IPv4. DHCP" << endl;
	cout << "	2 - Conceptos avanzados del protocolo TCP" << endl;
	cout << "	3 - Servicios de red" << endl;
	cout << "	4 - Internet de nueva generación: IPv6" << endl;
	cout << "	5 - Encaminamiento en Internet" << endl;
	cout << "	6 - Todo" << endl;
	cout << "	0 - Atras" << endl;
	cout << "	Elige una opción: ";
	cin >> opcion;
	cout << endl;

	return opcion;
}

int  menuSO()
{
	int opcion;

	cout << "------------------------MENU---------------------------" << endl;
	cout << "	1 - Introducción a la programación de sistemas" << endl;
	cout << "	2 - Sistema de ficheros" << endl;
	cout << "	3 - Gestión de procesos" << endl;
	cout << "	4 - Programación con sockets" << endl;
	cout << "	5 - Todo" << endl;
	cout << "	0 - Atras" << endl;
	cout << "	Elige una opción: ";
	cin >> opcion;
	cout << endl;

	return opcion;
}

int main()
{
	setlocale(LC_ALL, ""); // Tildes

	int opcion, preguntasTotales = -1;
	int acertadas = 0, falladas = 0;
	string lineaFichero;
	char respuesta;

	opcion = menu();
	
	while (opcion != 0)
	{
		ifstream ficheroPreguntas;
		string linea;
		// Creamos un array con las preguntas
		struct Pregunta arrayPreguntas[9999];
		int contadorArray = 0;
		int opcionParte, opcionTema;

		struct Pregunta arrayPreguntasFalladas[9999]; // Array donde guardaremos las falladas para luego mostrar los resultados.
		int contadorFalladas = 0;

		opcionParte = menuParte();
		
		if (opcionParte == 1)
		{
			opcionTema = menuRedes();
			if (opcionTema == 1)
			{
				ficheroPreguntas.open("preguntas/preguntasT1Redes.txt");
			}
			else if (opcionTema == 2)
			{
				ficheroPreguntas.open("preguntas/preguntasT2Redes.txt");
			}
			else if (opcionTema == 3)
			{
				ficheroPreguntas.open("preguntas/preguntasT3Redes.txt");
			}
			else if (opcionTema == 4)
			{
				ficheroPreguntas.open("preguntas/preguntasT4Redes.txt");
			}
			else if (opcionTema == 5)
			{
				ficheroPreguntas.open("preguntas/preguntasT5Redes.txt");
			}
			else if (opcionTema == 6)
			{
				ficheroPreguntas.open("preguntas/preguntasTodoRedes.txt");
			}
			else if (opcionTema == 0)
			{
				opcionParte = menuParte();
				continue;
			}
		}
		else if (opcionParte == 2)
		{
			opcionTema = menuSO();
			if (opcionTema == 1)
			{
				ficheroPreguntas.open("preguntas/preguntasT1SO.txt");
			}
			else if (opcionTema == 2)
			{
				ficheroPreguntas.open("preguntas/preguntasT2SO.txt");
			}
			else if (opcionTema == 3)
			{
				ficheroPreguntas.open("preguntas/preguntasT3SO.txt");
			}
			else if (opcionTema == 4)
			{
				ficheroPreguntas.open("preguntas/preguntasT4SO.txt");
			}
			else if (opcionTema == 5)
			{
				ficheroPreguntas.open("preguntas/preguntasTodoSO.txt");
			}
			else if (opcionTema == 0)
			{
				opcionParte = menuParte();
				continue;
			}
		}
		else if (opcionParte == 3)
		{
			ficheroPreguntas.open("preguntas/preguntasTodo.txt");
		}
		else if (opcionParte == 0)
		{
			opcion = menu();
			continue;
		}
		else
		{
			cout << "No has elegido ninguna parte" << endl;
			opcionParte = menuParte();
		}

		while (!ficheroPreguntas.eof())
		{
			getline(ficheroPreguntas, pregunta.enunciado);
			getline(ficheroPreguntas, pregunta.respuestaA);
			getline(ficheroPreguntas, pregunta.respuestaB);
			getline(ficheroPreguntas, pregunta.respuestaC);
			getline(ficheroPreguntas, linea);
			pregunta.respuestaCorrecta = linea[0]; // Leemos la letra de la respuesta correcta

			arrayPreguntas[contadorArray] = pregunta;
			contadorArray++;
		}

		contadorArray = contadorArray - 1;
		preguntasTotales = contadorArray;

		ficheroPreguntas.close();

		system("clear");
		cout << "Total preguntas del fichero: " << preguntasTotales << endl << endl;
		
		// Estudiar todo
		if (opcion == 1)
		{
			for (int i = 0; i < preguntasTotales; i++)
			{
				// Nos miestra la pregunta aleatoria
				cout << i + 1 << ".- " << arrayPreguntas[i].enunciado << endl;
				cout << "	" << arrayPreguntas[i].respuestaA << endl;
				cout << "	" << arrayPreguntas[i].respuestaB << endl;
				cout << "	" << arrayPreguntas[i].respuestaC << endl;
				cout << "	Elige la respuesta correcta (a, b, c): ";
				cin >> respuesta;
				cout << endl << "------------------------------------------------------------------------------------" << endl;
				cout << endl;

				// convertir respuesta a minúscula
				respuesta = tolower(respuesta);
				
				// Comparamos con la respuesta, si no es correcta además de añadirla al contador de falladas, la añadimos al array de falladas que mostraremos al final del examen.
				if (respuesta == arrayPreguntas[i].respuestaCorrecta)
				{ // RESPUESTA ACERTADA
					acertadas++;
				}
				else
				{ // RESPUESTA FALLADA
					falladas++;
					arrayPreguntasFalladas[contadorFalladas] = arrayPreguntas[i];
					arrayPreguntasFalladas[contadorFalladas].respuestaSeleccionada = respuesta;
					contadorFalladas++;
				}
			}

			// MOSTRAMOS RESULTADOS
			cout << "	Preguntas acertadas = " << acertadas << endl;
			cout << "	Preguntas falladas = " << falladas << endl;

			// Calculamos si hemos aprobado o no el examen, cada fallo resta el 50%, osea por cada respuesta bien se pueden tener dos mal y se queda en 0
			// Pregunta correcta 1 punto, pregunta incorrecta -0.5 puntos
			double totalPuntuacion = ((acertadas * 1) - (falladas * 0.5));

			if (totalPuntuacion >= double(preguntasTotales/2)) cout << "	Has aprobado!!!" << endl;
			else cout << "	Game Over, vuelve a intentarlo" << endl;
			
		}
		// Test 10 preguntas aleatorias
		else if (opcion == 2)
		{
			/***NUMaleatorias****/
			int numPreguntasTest = 10;
			// Creamos un número aleatorio entre 0 y el total de las preguntas
			for (int i = 0; i < numPreguntasTest; i++)
			{
				srand(time(NULL));
			
				int aleatorio, DESDE = 0, HASTA = preguntasTotales - 1;
				aleatorio = rand() % (HASTA - DESDE + 1) + DESDE;

				// Nos miestra la pregunta aleatoria
				cout << i + 1 << ".- " << arrayPreguntas[aleatorio].enunciado << endl;
				cout << "	" << arrayPreguntas[aleatorio].respuestaA << endl;
				cout << "	" << arrayPreguntas[aleatorio].respuestaB << endl;
				cout << "	" << arrayPreguntas[aleatorio].respuestaC << endl;
				cout << "	Elige la respuesta correcta (a, b, c): ";
				cin >> respuesta;
				cout << endl << "------------------------------------------------------------------------------------" << endl;
				cout << endl;

				if (respuesta == arrayPreguntas[aleatorio].respuestaCorrecta)
				{ // RESPUESTA ACERTADA
					acertadas++;
				}
				else
				{ // RESPUESTA FALLADA
					falladas++;
					arrayPreguntasFalladas[contadorFalladas] = arrayPreguntas[aleatorio];
					arrayPreguntasFalladas[contadorFalladas].respuestaSeleccionada = respuesta;
					contadorFalladas++;
				}
			}

			// MOSTRAMOS RESULTADOS
			cout << "	Preguntas acertadas = " << acertadas << endl;
			cout << "	Preguntas falladas = " << falladas << endl;

			// Calculamos si hemos aprobado o no el examen, cada fallo resta el 50%, osea por cada respuesta bien se pueden tener dos mal y se queda en 0
			// Pregunta correcta 1 punto, pregunta incorrecta -0.5 puntos
			double totalPuntuacion = ((acertadas * 1) - (falladas * 0.5));

			if (totalPuntuacion >= double(numPreguntasTest/2)) cout << "	Has aprobado!!!" << endl;
			else cout << "	Game Over, vuelve a intentarlo" << endl;
		}

		if (falladas > 0)
		{
			sleep(3);
			system("clear");
			cout << endl << "********************************************************************" << endl;
			cout << "		HAS FALLADO EN ESTAS PREGUNTAS			" << endl;
			cout << "********************************************************************" << endl << endl;

			for (int i = 0; i < contadorFalladas; i++)
			{
				cout << i + 1 << ".- " << arrayPreguntasFalladas[i].enunciado << endl;
				cout << "	" << arrayPreguntasFalladas[i].respuestaA << endl;
				cout << "	" << arrayPreguntasFalladas[i].respuestaB << endl;
				cout << "	" << arrayPreguntasFalladas[i].respuestaC << endl;
				cout << "	La solución es la opción " << arrayPreguntasFalladas[i].respuestaCorrecta << " no la opción " << arrayPreguntasFalladas[i].respuestaSeleccionada << endl;
				cout << endl << "------------------------------------------------------------------------------------" << endl;
				cout << endl;
			}
		}

		// Reiniciamos resultados
		acertadas = 0;
		falladas = 0;

		cout << endl;
		opcion = menu();
	}

	return 0;
}