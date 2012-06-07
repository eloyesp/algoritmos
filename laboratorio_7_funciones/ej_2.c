// Escribir una función que reciba como primer argumento un arreglo de
//	enteros de 20 elementos y como segundo argumento un valor también entero,
//	que busque este valor dentro del arreglo y retorne la posición en la que está
//	ubicado, si no se encuentra que retorne -1. Hacer una llamada a la función
//	desde main() e imprimir el resultado.
//	
#include <stdio.h>
#include <stdlib.h>
#define TF 20

int buscar_elemento(const int vector[], const int n);

int main(void) {
	int vector[TF], i, n;
	
	printf("vector = [ ");
	for (i=0; i<TF; i++) {
		vector[i] = rand() % 25;
		printf("%2d ", vector[i]);
	}
	printf("]\n");
	
	n = rand() % 25;
	printf("\nbuscar_elemento(vector, %i) => %i", n, buscar_elemento(vector, n));

	return 0;
}

int buscar_elemento(const int vector[], const int n)
{
	int i = 0;
	
	while (i < 20 && vector[i] != n) {
		i++;
	}
	
	return (i == 20) ? -1 : i;
}
