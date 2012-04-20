#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TF 10

//Realiza un programa que tome dos vectores de enteros ordenados y que
//	con los elementos de ámbos complete un tercer vector, que también debe
//	mantenerse ordenado

int main( int argc, char *argv[] )
{
	int vector[2][TF], vector_union[TF*2], i, j, k;
	srand(time(NULL));
	//	aux, i, t_logico = 0;
	
	// Lleno los vectores ordenadamente con random
	for (i=0;i<=1;i++) {
		vector[i][0] = rand() % 30;
		j = 1;
		for (j=1; j < TF; j++) {
			vector[i][j] = rand() % 30 + vector[i][j-1];
		}
	}
	
	// convino en el tercer vector los elementos de ambos manteniendo el orden
	for (i=j=k=0; k <= 2*TF; k++) {
		if ( i >= TF )
			vector_union[k] = vector[1][j++];
		else if ( j >= TF )
			vector_union[k] = vector[0][i++];
		else if (vector[0][i] > vector[1][j])
			vector_union[k] = vector[1][j++];
		else
			vector_union[k] = vector[0][i++];
	}
	
	//muestro los vectores
	for (i=0;i<=1;i++) {
		printf("Vector[%d]: [9%d", i, vector[i][0]);
		for (j=1; j<TF; j++)
			printf(", %d", vector[i][j]);
		printf("]\n");
	}
	
	printf("Vector_Union: [%d", vector_union[0]);
	for (i=1; i<2*TF; i++)
		printf(", %d", vector_union[i]);
	printf("]\n");
		
	return 0;
}
