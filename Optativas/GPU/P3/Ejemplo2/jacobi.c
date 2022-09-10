#include <math.h>
#include <string.h>
#include <stdio.h>
#include "timer.h"

#ifdef _OPENACC
#include <openacc.h>
#endif

double *A;
double *Anew;

int main(int argc, char** argv)
{
	const int iter_max = 1000;
	int n, m;

	const double tol = 1.0e-6;
	double error     = 1.0;

	// For time
	double runtime;

	if (argc==3)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}
	else
	{
		n = 4096;
		m = 4096;
	}

	A    = (double *)malloc(n*m*sizeof(double));
	Anew = (double *)malloc(n*m*sizeof(double));

	// Init A and Anew
	for( int j = 0; j < n; j++)
	{
		A[j*m+0]    = 1.0;
		Anew[j*m+0] = 1.0;

		for( int i = 1; i < m; i++)
		{
			A[j*m+i]    = 0.0;
			Anew[j*m+i] = 0.0;
		}
	}

	printf("Jacobi relaxation Calculation: %d x %d mesh\n", n, m);

	int iter = 0;

	#pragma acc data copy(A[:m*n]) create(Anew[:m*n])
	{
		StartTimer();

		while ( error > tol && iter < iter_max )
		{
			error = 0.0;

			#pragma acc parallel loop reduction(max:error)
			for( int j = 1; j < n-1; j++)
			{
				#pragma acc loop reduction(max:error)
				for( int i = 1; i < m-1; i++ )
				{
					Anew[j*m+i] = 0.25 * ( A[j*m+i+1] + A[j*m+i-1]
						+ A[(j-1)*m+i] + A[(j+1)*m+i]);
					error = fmax( error, fabs(Anew[j*m+i] - A[j*m+i]));
				}
			}

			#pragma acc parallel loop
			for( int j = 1; j < n-1; j++)
			{
				#pragma acc loop
				for( int i = 1; i < m-1; i++ )
				{
					A[j*m+i] = Anew[j*m+i];    
				}
			}

			if(iter % 10 == 0)
			{
				printf("%5d, %0.6f\n", iter, error);
			}

			iter++;
		}
		
		runtime = GetTimer();
	}

	printf(" total: %f s\n", runtime / 1000);
}
