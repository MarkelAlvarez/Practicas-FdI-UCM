#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mytar.h"

extern char *use;

/** Copy nBytes bytes from the origin file to the destination file.
 *
 * origin: pointer to the FILE descriptor associated with the origin file
 * destination:  pointer to the FILE descriptor associated with the destination file
 * nBytes: number of bytes to copy
 *
 * Returns the number of bytes actually copied or -1 if an error occured.
 */
int copynFile(FILE * origin, FILE * destination, int nBytes)
{
	int caracter, cont = 0;

	while ((cont < nBytes) && ((caracter = getc(origin)) != EOF))
	{
		putc(caracter, destination);
		cont++;
	}

	return cont;
}

/** Loads a string from a file.
 *
 * file: pointer to the FILE descriptor
 *
 * The loadstr() function must allocate memory from the heap to store
 * the contents of the string read from the FILE.
 * Once the string has been properly built in memory, the function returns
 * the starting address of the string (pointer returned by malloc())
 *
 * Returns: !=NULL if success, NULL if error
 */
char* loadstr(FILE * file)
{
	int i = 0, caracter;
	char *str;

	if ((str = (char *) malloc(PATH_MAX * sizeof(char))) == NULL)
	{
		perror("No se puede añadir el nombre del fichero a la memoria");
		return NULL;
	}

	do {
		caracter = getc(file);
		str[i]= (char)caracter;
		i++;

	} while ((caracter != EOF) && ((char)caracter != '\0'));

	str[i] = '\0';

	return str;
}

/** Read tarball header and store it in memory.
 *
 * tarFile: pointer to the tarball's FILE descriptor
 * nFiles: output parameter. Used to return the number
 * of files stored in the tarball archive (first 4 bytes of the header).
 *
 * On success it returns the starting memory address of an array that stores
 * the (name,size) pairs read from the tar file. Upon failure, the function returns NULL.
 */
stHeaderEntry* readHeader(FILE * tarFile, int *nFiles)
{
	stHeaderEntry* cabecera = NULL;

	// Lee la cantidad de ficheros dentro del mytar
	fread(nFiles,sizeof (int), 1,tarFile);

	// Creamos la memoria dinamica para la cabecera
	if ((cabecera = malloc(sizeof(stHeaderEntry)* (*nFiles))) == NULL)
	{
		perror("El fichero es demasiado grande para guardarlo en memoria");
		fclose(tarFile);
	}
	else
	{
		for (int i = 0; i < *nFiles; i++)
		{
			if ((cabecera[i].name = loadstr(tarFile)) == NULL)
			{
				for (int j = 0; j < i; j++)
				{
					free(cabecera[j].name);
				}
				fclose(tarFile);

				return NULL;
			}

			fread(&cabecera[i].size, sizeof(unsigned int), 1, tarFile);
		}
	}

	return cabecera;
}

/** Creates a tarball archive
 *
 * nfiles: number of files to be stored in the tarball
 * filenames: array with the path names of the files to be included in the tarball
 * tarname: name of the tarball archive
 *
 * On success, it returns EXIT_SUCCESS; upon error it returns EXIT_FAILURE.
 * (macros defined in stdlib.h).
 *
 * HINTS: First reserve room in the file to store the tarball header.
 * Move the file's position indicator to the data section (skip the header)
 * and dump the contents of the source files (one by one) in the tarball archive.
 * At the same time, build the representation of the tarball header in memory.
 * Finally, rewind the file's position indicator, write the number of files as well as
 * the (file name,file size) pairs in the tar archive.
 *
 * Important reminder: to calculate the room needed for the header, a simple sizeof
 * of stHeaderEntry will not work. Bear in mind that, on disk, file names found in (name,size)
 * pairs occupy strlen(name)+1 bytes.
 *
 */
int createTar(int nFiles, char *fileNames[], char tarName[])
{
	int tamCabecera = 0;
	FILE *archivoTar, *in;
	stHeaderEntry *cabecera;

	// Añadir la cabecera a memoria
	if ((cabecera = malloc(sizeof(stHeaderEntry) * nFiles)) == NULL)
	{
		perror("No se puede guardar en memoria la cabecera");
		return EXIT_FAILURE;
	}

	// Creamos el archivo Mytar
	if ((archivoTar = fopen(tarName, "w")) == NULL)
	{
		perror("No se ha podido crear el archivo Mytar");
		return EXIT_FAILURE;
	}

	// Calculamos el tamaño en memoria de la cabecera
	for (int i = 0; i < nFiles; i++)
	{
		tamCabecera = tamCabecera + strlen(fileNames[i]) + 1;
	}

	tamCabecera = sizeof(char) * tamCabecera + sizeof(int) + nFiles * sizeof(unsigned int);

	// Apuntamos al final del archivo
	fseek(archivoTar, tamCabecera, SEEK_SET);

	for (int i = 0; i < nFiles; i++)
	{
		// Añadimos a la memoria el nombre del archivo
		cabecera[i].name = (char*) malloc(strlen(fileNames[i]) + 1);

		if ((in = fopen(fileNames[i], "r")) == NULL)
		{
			free(cabecera);
			fclose(archivoTar);
			return EXIT_FAILURE;
		}
		// Copiamos el nombre del archivo que vamos a incluir en el Mytar
		strcpy(cabecera[i].name, fileNames[i]);
		// Copiamos la información
		cabecera[i].size = copynFile(in, archivoTar, INT_MAX);

		fclose(in);
	}

	// Apuntamos al byte 0 del archivo
	rewind(archivoTar);
	// Escribimos la cantidad de archivos a incluir en el Mytar
	fwrite(&nFiles, sizeof(int), 1, archivoTar);

	// Escribimos la cabecera
	for (int i = 0; i < nFiles; ++i)
	{
		fwrite(cabecera[i].name, sizeof(char), strlen(fileNames[i]), archivoTar);
		putc('\0', archivoTar);
		fwrite(&cabecera[i].size, sizeof(unsigned int), 1, archivoTar);
	}

	fprintf(stdout, "¡%s creado!\n", tarName);

	free(cabecera);
	fclose(archivoTar);

	return EXIT_SUCCESS;
}

/** Extract files stored in a tarball archive
 *
 * tarName: tarball's pathname
 *
 * On success, it returns EXIT_SUCCESS; upon error it returns EXIT_FAILURE.
 * (macros defined in stdlib.h).
 *
 * HINTS: First load the tarball's header into memory.
 * After reading the header, the file position indicator will be located at the
 * tarball's data section. By using information from the
 * header --number of files and (file name, file size) pairs--, extract files
 * stored in the data section of the tarball.
 *
 */
int extractTar(char tarName[])
{
	int nFiles;
	stHeaderEntry *header;
	FILE *tarFile, *output;

	if ((tarFile = fopen(tarName, "r")) == NULL)
	{
		perror("No se ha podido abrir el archivo Mytar");
		return EXIT_FAILURE;
	}

	// Creamos la cabecera
	header = readHeader(tarFile, &nFiles);
	// Creamos y escribimos los archivos con la información
	for (int i = 0; i < nFiles; i++)
	{
		output = fopen(header[i].name, "w");
		copynFile(tarFile, output, header[i].size);
		fclose(output);
		fprintf(stdout, "[%d] %s extraido\n", i+1, header[i].name);
	}

	fprintf(stdout, "¡%s extraido!\n", tarName);

	free(header);
	fclose(tarFile);

	return EXIT_SUCCESS;
}
