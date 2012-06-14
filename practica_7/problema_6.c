#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 8
#define SEED 8
#define MAX 25

void visualizar(int matriz[][N], int cf, int cc) {
  int i, j;
  for (i=0; i < cf; i++) {
    printf("| ");
    for (j=0; j < cc; j++)
      printf("%2i  ", matriz[i][j]);
    printf("| \n");
  }
}

int main(void) {
  int matriz[M][N], vector[N][2], minimo;
  int i, j;
  srand(time(NULL));

  // lleno la matriz
  for (i=0; i < M; i++) {
    for (j=0; j < N; j++) {
      matriz[i][j] = rand() % MAX;
    }
  }

  // Calculo los minimos de cada columna
  for (j=0; j<N; j++) {
    // primero tiro un supuesto minimo (el primer elemento)
    minimo = matriz[0][j];
    // Despues ajusto lo que sea necesario
    for (i=1; i<M; i++) {
      if (minimo > matriz[i][j]) {
        minimo = matriz[i][j];
      }
    }
    // minimo es el minimo de la columna j+1
    // Ubico el minimo en el vector
    i = j;
    while (i > 0 && vector[i-1][0] > minimo ) {
			// Muevo para adelante
			vector[i][0] = vector[i-1][0];
			vector[i][1] = vector[i-1][1];
			i--;
		}
	vector[i][0] = minimo;
	vector[i][1] = j;
  }

  puts("");
  visualizar(matriz, M, N);
  puts("");
  for (j=0; j<N; j++)
    printf("%2i (minimo de la columna %d)\n",
      vector[j][0], vector[j][1] + 1);

  return 0;
}

