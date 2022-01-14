#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Longitud máxima de argumentos: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Número máximo de hijos: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Número máximo de ficheros: %ld\n", sysconf(_SC_OPEN_MAX));
	
	return 0;
}