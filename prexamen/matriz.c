#include "matriz.h"
#include <stdio.h>

void matriz_inicializar(matriz * const m, const int filas, const int columnas) {
  int i, j;
  for (i=0; i<filas; i++) {
    for (j=0; j<columnas; j++) {
      m->valores[i][j] = 0;
    }
  }
  m->columnas = columnas;
  m->filas = filas;
}

void matriz_mostrar(const matriz * const m) {
  int i, j;
  printf("\n");
  for (i=0; i < m->filas; i++) {
    printf("|");
    for (j=0; j < m->columnas; j++) {
      printf(" %2d", m->valores[i][j]);
    }
    printf(" |\n");
  }
}
