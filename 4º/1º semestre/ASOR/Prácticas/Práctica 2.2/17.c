#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error: debe especificar la ruta del fichero o directorio como argumento del programa.");
		return -1;
	}

	DIR *dir = opendir(argv[1]);
	if (dir == NULL)
	{
		perror("Error: no se pudo abrir el directorio.");
		return -1;
	}

	struct stat entry_info;
	off_t total_size = 0;

	struct dirent * current;
	while((current = readdir(dir)) != NULL)
	{
		size_t abs_path_len = sizeof(char) * (strlen(argv[1]) + strlen(current->d_name) + 3);
		char *abs_path = (char *) malloc(abs_path_len);
		sprintf(abs_path, "%s/%s", argv[1], current->d_name);

		if (stat(abs_path, &entry_info) == -1)
		{
			perror("Error: no se pudo obtener la información de una de las entradas del directorio.");
			closedir(dir);
			return -1;
		}
		
		if (current->d_type == DT_LNK)
		{
			long path_max_size = pathconf("/", _PC_NAME_MAX);

			char * link_name = (char *) malloc(path_max_size + 1);
			readlink(abs_path, link_name, path_max_size + 1);

			printf("Enlace: %s -> %s\n", current->d_name, link_name);
		}
		else if (current->d_type == DT_REG)
		{
			printf("Fichero normal: %s", current->d_name);

			// Comprobamos si alguien tiene permisos de ejecución.
			if ((entry_info.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) > 0)
			{
				printf(" *");
			}

			total_size += entry_info.st_size;

			printf(" (%ld bytes)\n", entry_info.st_size);
		}
		else if (current->d_type == DT_DIR)
		{
			printf("Directorio: %s/\n", current->d_name);
		}
		
		free(abs_path);
	}

	closedir(dir);

	float total_size_kb = total_size / 1000;
	printf("Tamaño total de ficheros regulares: %.2f kilobytes\n", total_size_kb);

	return 0;
}