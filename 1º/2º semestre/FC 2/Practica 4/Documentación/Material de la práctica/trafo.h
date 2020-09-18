#ifndef _TRAFO_H
#define _TRAFO_H

#include "types.h"

void RGB2GrayMatrix(pixelRGB orig[N][M], unsigned char dest[N][M]);

void Gray2BinaryMatrix(unsigned char orig[N][M], unsigned char dest[N][M]);

int rgb2gray(int R, int G, int B);

void contarBlancos(unsigned char mat[N][M], unsigned char vector[N]);

#endif
