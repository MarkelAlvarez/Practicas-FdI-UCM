#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2) {
		perror("Error: debe especificar la ruta del fichero o directorio como argumento del programa.");

		return -1;
	}

	struct stat st;
	stat(argv[1], &st);

	if (S_ISREG(st.st_mode))
	{
		string linkName = string(argv[1]) + ".hard";
		string symlinkName = string(argv[1]) + ".sym";

		if (symlink(argv[1], symlinkName.c_str()) == 0)
		{
			printf("El fichero %s ha sido creado como un enlace simbolico en %s\n", argv[1], symlinkName.c_str());
		}
		else
		{
			perror("Error: no se ha podido crear el enlace simbolico\n");
		}
		
		if (link(argv[1], linkName.c_str()) == 0)
		{
			printf("El fichero %s ha sido creado como un enlace en %s\n", argv[1], linkName.c_str());
		}
		else
		{
			perror("Error: no se ha podido crear el enlace rigido\n");
		}
	}
	else
	{
		perror("Error: el path no es un fichero\n");
	}
}