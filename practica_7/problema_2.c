#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TF 8
#define COLUMNAS 3
#define SEED 8
#define MAX 25

void visualizar(float matriz[][3], int cf, int cc) {
  int i, j;
  for (i=0; i < cf; i++) {
    printf("| ");
    for (j=0; j < cc; j++)
      if (j == 2)
        printf("%.3f  ", matriz[i][j]);
      else
        printf("%3d  ", (int) matriz[i][j]);
    printf("| \n");
  }
}

int main(void) {
	float matriz[TF][COLUMNAS];
	int cf = TF, i;
	srand(SEED);

	for (i=0; i < cf; i++) {
		// lleno la primera columna de la matriz
		matriz[i][0] = rand() % MAX;
		// lleno la segunda columna de la matriz
		matriz[i][1] = matriz[i][0] * matriz[i][0];
		// lleno la tercera columna de la matriz
		matriz[i][2] = sqrt(matriz[i][0]);
	}

	puts("");
	visualizar(matriz, cf, COLUMNAS);

	return 0;
}

