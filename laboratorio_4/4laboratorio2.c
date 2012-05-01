#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Directrices de Sustitucion para el Precompilador. Definicion de constantes */
#define M 5
#define N 8
#define MAX_VALUE 8

int main (void)
{
	int matriz[M][N], i, j, falta;
	srand(time(NULL));

	// Cargo la Matriz
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			matriz[i][j]=rand() % MAX_VALUE;
		}
	}

	// Muestro la matriz

  puts("La matriz a analizar es:");
	for(i=0; i<M; i++) {
	  printf("  | ");
		for(j=0; j<N; j++) {
			printf("%2d ", matriz[i][j]);
		}
		printf(" |\n");
	}

// Existe algún cero en la matriz.
  falta = 1;
  i = 0;
  while (falta && i < M) {
    j = 0;
    while (falta && j < N) {
      if (matriz[i][j] == 0)
        falta = 0;
      j++;
    }
    i++;
  }

  puts(""); //separador

  if (falta)
    puts("No hay ceros en la matriz");
  else
    puts("Hay ceros en la matriz");


// Hay mas de 5 ceros en la matriz.

  falta = 5;
  i = 0;
  while (falta && i < M) {
    j = 0;
    while (falta && j < N) {
      if (matriz[i][j] == 0)
        falta--;
      j++;
    }
    i++;
  }

  puts(""); //separador

  if (falta)
    puts("No hay cinco (5) ceros en la matriz");
  else
    puts("Hay, al menos cinco ceros en la matriz");

// Cuantas veces aparece el número cero.
  falta = 0;
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
      if (matriz[i][j] == 0)
        falta++;
		}
	}
	printf("\nLa cantidad de ceros es: %d\n", falta);


	puts ("\nTambien se puede acceder a los datos como un vector grande, haciendo un poco de trampa, de forma que se harian mas facil los ejercicios: ");

	// a ver:
	for(i=0; i < M * N; i++)
	  printf("%d ", matriz[0][i]);
  printf("\n");
	return 0;
}

