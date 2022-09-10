#include <stdio.h>
#include <stdlib.h>

/* Time */
#include <sys/time.h>
#include <sys/resource.h>

static struct timeval tv0;

double getMicroSeconds()
{
	double t;
	gettimeofday(&tv0, (struct timezone*)0);
	t = ((tv0.tv_usec) + (tv0.tv_sec)*1000000);

	return (t);
}

void init_seed()
{
	FILE *fd;
	int seedi=1;

	/* Generated random values between 0.00 - 1.00 */
	fd = fopen("/dev/urandom", "r");
	fread(&seedi, sizeof(int), 1, fd);
	fclose(fd);
	srand(seedi);
}

void init2Drand(float **buffer, int n)
{
	int i, j;

	for (i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			buffer[i][j] = 500.0*((float)(rand())/RAND_MAX)-500.0; /* [-500 500]*/
		}
	}
		
}

float *getmemory1D( int nx )
{
	int i,j;
	float *buffer;

	if((buffer=(float *)malloc(nx*sizeof(float *)))== NULL)
	{
		fprintf(stderr, "ERROR in memory allocation\n");
		
		return(NULL);
	}

	for(i=0; i<nx; i++)
	{
		buffer[i] = 0.0;
	}

	return(buffer);
}


float **getmemory2D(int nx, int ny)
{
	int i,j;
	float **buffer;

	if((buffer=(float **)malloc(nx*sizeof(float *)))== NULL)
	{
		fprintf(stderr, "ERROR in memory allocation\n");

		return(NULL);
	}

	if((buffer[0]=(float *)malloc(nx*ny*sizeof(float)))==NULL)
	{
		fprintf(stderr, "ERROR in memory allocation\n");
		free(buffer);

		return(NULL);
	}

	for( i=1; i<nx; i++)
	{
		buffer[i] = buffer[i-1] + ny;
	}

	for( i=0; i<nx; i++)
	{
		for( j=0; j<ny; j++ )
		{
			buffer[i][j] = 0.0;
		}
	}

	return(buffer);
}

/********************************************************************************/
/********************************************************************************/

/*
 * Traspose 2D version
 */
void transpose2D(float **in, float **out, int n)
{
	int i, j;

	#pragma omp parallel for
	for(j=0; j < n; j++)
	{
		#pragma omp parallel for
		for(i=0; i < n; i++)
		{
			out[j][i] = in[i][j];
		}		
	}
}

/*
 * Traspose 1D version
 */
void transpose1D(float *in, float *out, int n)
{
	int i, j;

	#pragma omp parallel for 
	for(j=0; j < n; j++)
	{
		for(i=0; i < n; i++)
		{
			out[j*n+i] = in[i*n+j]; 
		}
	}
		
}


int main(int argc, char **argv)
{
	int n;
	double t0;
	float **array2D, **array2D_trans;
	float *array1D,  *array1D_trans;

	if (argc==2)
	{
		n = atoi(argv[1]);
	}
	else
	{
		n = 4096;
		printf("./exec n (by default n=%i)\n", n);
	}
	
	/* Initizalization */
	init_seed();
	array2D       = getmemory2D(n,n);
	array2D_trans = getmemory2D(n,n);
	array1D       = array2D[0];
	array1D_trans = array2D_trans[0];
	init2Drand(array2D, n);


	/* Transpose 2D version */
	t0 = getMicroSeconds();
	transpose2D(array2D, array2D_trans, n);
	printf("Transpose version 2D: %f MB/s\n", n*n*sizeof(float)/((getMicroSeconds()-t0)/1000000)/1024/1024);

	/* Transpose 1D version */
	t0 = getMicroSeconds();
	transpose1D(array1D, array1D_trans, n);
	printf("Transpose version 1D: %f MB/s\n", n*n*sizeof(float)/((getMicroSeconds()-t0)/1000000)/1024/1024);

	return(1);
}