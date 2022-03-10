#include <stdio.h>

#define N1 800
#define N2 800
#define N3 800

double A[N1][N2];
double B[N2][N3];
double C[N1][N3];

int main ()
{
  int i, j, k;
  double sum;

  for (i = 0; i<N1; i++) {
    for (j = 0; j<N2; j++) {
      A[i][j] = (double) i;
    }
  }

  for (j = 0; j<N2; j++) {
    for (k = 0; k<N3; k++) {
      B[j][k] = (double) j;
    }
  }

  for (i = 0; i<N1; i++) {
    for (k = 0; k<N3; k++) {
      sum = 0.0;
      for (j = 0; j<N2; j++) {
        sum += A[i][j] * B[j][k];
      }
      C[i][k] = sum;
    }
  }

  printf("Result: %f\n", C[N1/2][N3/2]);

  return 0;
}
