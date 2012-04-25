# include <stdio.h>
# define TF 5
# define SEED 5

void visualizar(int matriz[][TF], int cf, int cc) {
  int i, j;
  for (i=0; i < cf; i++) {
    printf("| ");
    for (j=0; j < cc; j++)
      printf("%2d ", matriz[i][j]);
    printf("| \n");
  }
}

void visualizar_por_columnas(int matriz[][TF], int cf, int cc)
{
  int i, j;
  for (j=0; j < cc; j++) {
    for (i=0; i < cf; i++)
      printf("%d ", matriz[i][j]);
  }
  printf("\n");
}

int main(void) {
  int matriz[TF][TF], cf = TF, cc = TF, i, j;
  srand(SEED);

  // lleno la matriz
  for (i=0; i < cc; i++) {
    for (j=0; j < cf; j++)
      matriz[i][j] = rand() % 100;
  }

  puts("");
  visualizar(matriz, cf, cc);

  puts("");
  visualizar_por_columnas(matriz, cf, cc);

  return 0;
}

