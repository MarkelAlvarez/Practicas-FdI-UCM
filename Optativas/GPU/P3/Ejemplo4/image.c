#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifdef _OPENACC
#include <openacc.h>
#endif

double get_time()
{
	static struct timeval 	tv0;
	double time_, time;

	gettimeofday(&tv0,(struct timezone*)0);
	time_=(double)((tv0.tv_usec + (tv0.tv_sec)*1000000));
	time = time_/1000000;
	return(time);
}

unsigned char *readBMP(char *file_name, char header[54], int *w, int *h)
{
	//Se abre el fichero en modo binario para lectura
	FILE *f=fopen(file_name, "rb");
	if (!f){
		perror(file_name); exit(1);
	}

	// Cabecera archivo imagen
	//***********************************
	//Devuelve cantidad de bytes leidos
	int n=fread(header, 1, 54, f);

	//Si no lee 54 bytes es que la imagen de entrada es demasiado pequenya
	if (n!=54)
		fprintf(stderr, "Entrada muy pequenia (%d bytes)\n", n), exit(1);

	//Si los dos primeros bytes no corresponden con los caracteres BM no es un fichero BMP
	if (header[0]!='B'|| header[1]!='M')
		fprintf(stderr, "No BMP\n"), exit(1);

	//El tamanyo de la imagen es el valor de la posicion 2 de la cabecera menos 54 bytes que ocupa esa cabecera
	int imagesize=*(int*)(header+2)-54;
	printf("Tamanio archivo = %d\n", imagesize);

	//Si la imagen tiene tamanyo negativo o es superior a 48MB la imagen se rechaza
	if (imagesize<=0|| imagesize > 0x3000000)
		fprintf(stderr, "Imagen muy grande: %d bytes\n", imagesize), exit(1);

	//Si la cabecera no tiene el tamanyo de 54 o el numero de bits por pixel es distinto de 24 la imagen se rechaza
	if (*(int*)(header+10)!=54|| *(short*)(header+28)!=24)
		fprintf(stderr, "No color 24-bit\n"), exit(1);
	
	//Cuando la posicion 30 del header no es 0, es que existe compresion por lo que la imagen no es valida
	if (*(int*)(header+30)!=0)
		fprintf(stderr, "Compresion no suportada\n"), exit(1);
	
	//Se recupera la altura y anchura de la cabecera
	int width=*(int*)(header+18);
	int height=*(int*)(header+22);
	//**************************************

	// Lectura de la imagen
	//*************************************
	unsigned char *image = (unsigned char*)malloc(imagesize+256+width*6); //Se reservan "imagesize+256+width*6" bytes y se devuelve un puntero a estos datos

	unsigned char *tmp;
	image+=128+width*3;
	if ((n=fread(image, 1, imagesize+1, f))!=imagesize)
		fprintf(stderr, "File size incorrect: %d bytes read insted of %d\n", n, imagesize), exit(1);

	fclose(f);
	printf("Image read correctly (width=%i height=%i, imagesize=%i).\n", width, height, imagesize);

	/* Output variables */
	*w = width;
	*h = height;

	return(image);
}

void writeBMP(float *imageFLOAT, char *file_name, char header[54], int width, int height)
{
	FILE *f;
	int i, n;

	int imagesize=*(int*)(header+2)-54;

	unsigned char *image = (unsigned char*)malloc(3*sizeof(unsigned char)*width*height);

	for (i=0;i<width*height;i++)
	{
		image[3*i]   = imageFLOAT[i]; //R 
		image[3*i+1] = imageFLOAT[i]; //G
		image[3*i+2] = imageFLOAT[i]; //B
	}

	f=fopen(file_name, "wb");		//Se abre el fichero en modo binario de escritura
	if (!f){
		perror(file_name); 
		exit(1);
	}

	n=fwrite(header, 1, 54, f);		//Primeramente se escribe la cabecera de la imagen
	n+=fwrite(image, 1, imagesize, f);	//Y despues se escribe el resto de la imagen
	if (n!=54+imagesize)			//Si se han escrito diferente cantidad de bytes que la suma de la cabecera y el tamanyo de la imagen. Ha habido error
		fprintf(stderr, "Escritos %d de %d bytes\n", n, imagesize+54);
	fclose(f);

	free(image);
}

float *RGB2BW(unsigned char *imageUCHAR, int width, int height)
{
	int i, j;
	float *imageBW = (float *)malloc(sizeof(float)*width*height);

	unsigned char R, B, G;

	for (i=0; i<height; i++)
		for (j=0; j<width; j++)
		{
			R = imageUCHAR[3*(i*width+j)];
			G = imageUCHAR[3*(i*width+j)+1];
			B = imageUCHAR[3*(i*width+j)+2];

			imageBW[i*width+j] = 0.2989 * R + 0.5870 * G + 0.1140 * B;
		}

	return(imageBW);
}


void border(float *im, float *image_out, int height, int width)
{
	int i, j, ii, jj;

	float filt[3*3];
	float tmp;
	int window_size = 3;
	int ws2 = (window_size-1)>>1; 

	//For time 
	double t0, t1;

	filt[0] =  0.0; filt[1] = -1.0; filt[2] =  0.0;
	filt[3] = -1.0; filt[4] =  4.0; filt[5] = -1.0;
	filt[6] =  0.0; filt[7] = -1.0; filt[8] =  0.0;

	#pragma acc data copyin(im[:height*width]) copyin(filt) copyout(image_out[:height*width])
	{

		t0 = get_time();

		#pragma acc parallel loop gang collapse(2)
		for(i=ws2; i<height-ws2; i++)
		{
			for(j=ws2; j<width-ws2; j++)
			{
				float tmp = 0.0;
				#pragma acc loop reduction(+:tmp) collapse(2)
				for (ii =-ws2; ii<=ws2; ii++)
				{
					for (jj =-ws2; jj<=ws2; jj++)
						tmp += im[(i+ii)*width + (j+jj)]*filt[(ii+ws2)*window_size + jj+ws2];
				}

				if (tmp>0.0 && tmp<255.0)
					image_out[i*width + j] = tmp;
				else if (tmp>255.0)
					image_out[i*width + j] = 255.0;
				else
					image_out[i*width + j] = 0.0;
			}
		}
		t1 = get_time();
		printf("Exection time %f ms.\n", t1-t0);
	}
}

void freeMemory(unsigned char *imageUCHAR, float *imageBW, float *imageOUT)
{
	//free(imageUCHAR);
	free(imageBW);
	free(imageOUT);
}	

int main(int argc, char **argv)
{
	int width, height;
	unsigned char *imageUCHAR;
	float *imageBW;
	char header[54];

	//Tener menos de 3 argumentos es incorrecto
	if (argc < 4)
	{
		fprintf(stderr, "Uso incorrecto de los parametros. exe  input.bmp output.bmp [cg]\n");
		exit(1);
	}

	// READ IMAGE & Convert image
	imageUCHAR = readBMP(argv[1], header, &width, &height);
	imageBW = RGB2BW(imageUCHAR, width, height);

	// Aux. memory
	float *imageOUT = (float *)malloc(sizeof(float)*width*height);

	////////////////
	// Filter     //
	////////////////
	switch (argv[3][0])
	{
		case 'c':
		case 'g':
			border(imageBW, imageOUT, height, width);
			break;
		default:
			printf("Not Implemented yet!!\n");
	}

	// WRITE IMAGE
	writeBMP(imageOUT, argv[2], header, width, height);

	freeMemory(imageUCHAR, imageBW, imageOUT);	
}