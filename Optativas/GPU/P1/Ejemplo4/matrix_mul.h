#ifndef MATRIX_MUL_H
#define MATRIX_MUL_H

#ifdef __cplusplus
extern "C"
#endif
void Mul(float* A, float* B, int hA, int wA, int wB,
	float* C);
#endif
