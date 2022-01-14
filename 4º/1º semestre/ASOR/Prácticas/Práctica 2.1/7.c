#include <stdio.h>
#include <unistd.h>

int main()
{
	const char *path = "/home/markel/Desktop/ASOR/Práctica 2.1";

	printf("Número máximo de enlaces: %ld\n", pathconf(path, _PC_LINK_MAX));
	printf("Tamaño máximo de una ruta: %ld\n", pathconf(path, _PC_PATH_MAX));
	printf("Tamaño máximo de un nombre de fichero: %ld\n", pathconf(path, _PC_NAME_MAX));
	
	return 0;
}