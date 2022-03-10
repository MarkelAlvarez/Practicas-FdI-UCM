#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* argv[])
{
    double *A, *B, *C;
    long i, N;

    if (argc != 2) {
        printf("Debes introducir el tamaño de la memoria en MB\n");
        exit(1);
    }

    N = atol(argv[1]) * 1024 * 1024 / 3 / sizeof(double);
    
    /* Reserva de Memoria de las matrices */
    
    A = (double *) malloc(N*sizeof(double));
    B = (double *) malloc(N*sizeof(double));    
    C = (double *) malloc(N*sizeof(double));        
    
    if (A == NULL || B == NULL || C == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    /* Bucle de Calculo */
    
    for (i=0; i<N; i++)
    {
        A[i] = sin(i*M_PI/180.0);
        B[i] = cos(i*M_PI/180.0);
    };
    
    for (i=0; i<N; i++)
        C[i] = A[i]*B[i]+exp(A[i]+B[i]);
    
    free(A);
    free(B);
    free(C);    
}        
    
