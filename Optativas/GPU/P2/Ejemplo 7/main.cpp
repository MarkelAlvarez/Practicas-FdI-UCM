#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <CL/sycl.hpp>
#include "kernels.hpp"

#include <sys/time.h>
#include <sys/resource.h>

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
	if (!f)
	{
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

void RGB2BW(float *imageBW, unsigned char *imageUCHAR, int width, int height)
{
	int i, j;

	unsigned char R, B, G;

	for (i=0; i<height; i++)
		for (j=0; j<width; j++)
		{
			R = imageUCHAR[3*(i*width+j)];
			G = imageUCHAR[3*(i*width+j)+1];
			B = imageUCHAR[3*(i*width+j)+2];

			imageBW[i*width+j] = 0.2989 * R + 0.5870 * G + 0.1140 * B;
		}
}

#define MAX_WINDOW_SIZE 5*5

void mergeSort(float arr[],int low,int mid,int high)
{
	int i,m,k,l;
	float temp[MAX_WINDOW_SIZE];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		 for(k=m;k<=high;k++){
			 temp[i]=arr[k];
			 i++;
		 }
	}
	else{
		 for(k=l;k<=mid;k++){
			 temp[i]=arr[k];
			 i++;
		 }
	}
   
	for(k=low;k<=high;k++){
		 arr[k]=temp[k];
	}
}

void buble_sort(float array[], int size)
{
	int i, j;
	float tmp;

	for (i=1; i<size; i++)
		for (j=0 ; j<size - i; j++)
			if (array[j] > array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}

void remove_noise(float *im, float *image_out, float thredshold, int window_size, int height, int width)
{
	int i, j, ii, jj;

	float window[MAX_WINDOW_SIZE];
	float median;
	int ws2 = (window_size-1)>>1; 

	for(i=ws2; i<height-ws2; i++)
	{
		for(j=ws2; j<width-ws2; j++)
		{
			for (ii =-ws2; ii<=ws2; ii++)
				for (jj =-ws2; jj<=ws2; jj++)
					window[(ii+ws2)*window_size + jj+ws2] = im[(i+ii)*width + j+jj];

			// SORT
			buble_sort(window, window_size*window_size);
			median = window[(window_size*window_size-1)>>1];

			if (fabsf((median-im[i*width+j])/median) <=thredshold)
				image_out[i*width + j] = im[i*width+j];
			else
				image_out[i*width + j] = median;
		}
	}
}

int main(int argc, char **argv)
{
	int width, height;
	unsigned char *imageUCHAR;
	char header[54];

	//Variables para calcular el tiempo
	double t0, t1;
	double cpu_time_used = 0.0;

	//Tener menos de 3 argumentos es incorrecto
	if (argc < 4)
	{
		fprintf(stderr, "Uso incorrecto de los parametros. exec input.bmp output.bmp [hcg]\n");
		exit(1);
	}

	// READ IMAGE & Convert image
	imageUCHAR = readBMP(argv[1], header, &width, &height);

	// Select device
	sycl::device dev;

	if (argv[3][0]=='h')
		dev = sycl::device(sycl::host_selector());
	else if (argv[3][0]=='c')
		dev = sycl::device(sycl::cpu_selector());
	else if (argv[3][0]=='g')
		dev = sycl::device(sycl::gpu_selector());

	sycl::queue Q(dev);
	std::cout << "Running on " << Q.get_device().get_info<sycl::info::device::name>() << std::endl;

	// imageBE in USM
	float *imageBW = malloc_shared<float>(width*height, Q);
	float *imageOUT = malloc_shared<float>(width*height, Q);

	RGB2BW(imageBW, imageUCHAR, width, height);

	//////////////////
	// Remove noise //
	//////////////////
	switch (argv[3][0])
	{
		case 'h':
			t0 = get_time();
			remove_noise(imageBW, imageOUT, 0.1, 3, height, width);
			t1 = get_time();
			printf("CPU Exection time %f ms.\n", t1-t0);
			break;
		case 'c':
		case 'g':
			t0 = get_time();
			remove_noise_SYCL(Q, imageBW, imageOUT, 0.1, 3, height, width);
			t1 = get_time();
			printf("SYCL Exection time %f ms.\n", t1-t0);
			break;
		default:
			printf("Not Implemented yet!!\n");
	}

	// WRITE IMAGE
	writeBMP(imageOUT, argv[2], header, width, height);

	free(imageBW, Q);
	free(imageOUT, Q);
}