//#include <stdio.h>
#include "trafo.h"
#include "types.h"
#include "lena128.h"

pixelRGB imagenRGB[N][M];
unsigned char imagenGris[N][M];
unsigned char imagenBinaria[N][M];
unsigned char blancosPorFila[N];

void initRGB(pixelRGB m[N][M]) {
    int i,j;

    for (i=0;i<N;i++)
        for (j=0; j<M; j++) {
            m[i][j].R = lena128[(i*M + j)*3];
            m[i][j].G = lena128[(i*M + j)*3 + 1];
            m[i][j].B = lena128[(i*M + j)*3 + 2];
        }
}

int main(void) {
    // 1. Crear una matriz NxM a partir del array lena128
    initRGB(imagenRGB);

    // 2. Transformar la matriz RGB a una matriz de grises
    RGB2GrayMatrix(imagenRGB,imagenGris);

    // 3. Transformar la matriz de grises a una matriz en blanco y negro
    Gray2BinaryMatrix(imagenGris,imagenBinaria);

    // 4. Contar los blancos que aparecen por filas en imagenBinaria
    contarBlancos(imagenBinaria,blancosPorFila);

    return 0;
}
