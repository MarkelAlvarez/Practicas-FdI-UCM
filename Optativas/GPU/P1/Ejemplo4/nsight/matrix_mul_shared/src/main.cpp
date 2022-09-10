/*
 * Copyright 1993-2014 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "matrix_mul.h"


void init_matrix(float *M, int hM, int wM, float k)
{
	int i,j;

	for (i=0; i<hM; i++)
		for (j=0; j<wM; j++)
			if (i==j)
				M[i*wM+j] = k*1.0f;
			else
				M[i*wM+j] = 0.0f;
}

void print_matrix(float *M, int hM, int wM)
{
	int i,j;

	for (i=0; i<hM; i++){
//		printf("Line %i: ", i);
		for (j=0; j<wM; j++)
			printf("%4.1f ", M[i*wM+j]);
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	// Matrix variables
	float *A, *B, *C;
	int hA, wA, hB, wB;

	setbuf(stdout, NULL);

	if (argc!=4){
		printf("./exec hA hB/WA wB\n");
		exit(-1);
	}

	hA = atoi(argv[1]);
	hB = wA = atoi(argv[2]);
	wB = atoi(argv[3]);

	// Init A and B, malloc C
	int size_A = wA * hA;
	A = (float*)malloc(size_A*sizeof(float));
	init_matrix(A, hA, wA,2.0);

	int size_B = wB * hB;
	B = (float*)malloc(size_B*sizeof(float));
	init_matrix(B, hB, wB,1.0);

	int size_C = wB * hA;
	C = (float*)malloc(size_C*sizeof(float));

	Mul(A, B, hA, wA, wB, C);

	// print Matrix
	//printf("\n\nMATRIX A\n");print_matrix(A, hA, wA);
	//printf("\n\nMATRIX B\n");print_matrix(B, hB, wB);
	//printf("\n\nMATRIX C\n");print_matrix(C, hA, wB);

	return (1);
}


