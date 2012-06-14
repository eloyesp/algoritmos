# include <stdio.h>
# include <stdlib.h>
# define FILAS 6
# define COLUMNAS 8
# define SEED 5

void visualizar(int matriz[][FILAS], int cf, int cc) {
  int i, j;
  for (i=0; i < cf; i++) {
    printf("Fila %2i | ", i+1 );
    for (j=0; j < cc; j++)
      printf("%2d ", matriz[i][j]);
    printf("| \n");
  }
  printf("\n");
}

void visualizar_por_columnas(int matriz[][FILAS], int cf, int cc)
{
	int i, j;
	for (j=0; j < cc; j++) {
		printf("Columna %2i: ", j+1 );
		for (i=0; i < cf; i++)
			printf("%2d ", matriz[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main(void) {
  int matriz[COLUMNAS][FILAS], cf = FILAS, cc = COLUMNAS, i, j;
  srand(SEED);

  // lleno la matriz
  for (i=0; i < cc; i++) {
    for (j=0; j < cf; j++)
      matriz[i][j] = rand() % 100;
  }

  puts("Visualizando por filas\n"
	   "============ === =====");
  visualizar(matriz, cf, cc);

  puts("Visualizando por columnas\n"
	   "============ === ========");
  visualizar_por_columnas(matriz, cf, cc);

  return 0;
}

