# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# define MAX 30
# define REPETICIONES 800

int main(void) {
	int i, vector[MAX], n = 0;
	srand(time(NULL));
	
	while (n < 1 || n > 30) {
		printf ("Ingrese n entre 1 y 30: ");
		scanf ("%d", &n);
	}
	n += 1;
	
	for (i=0; i < n; i++) {
		vector[i] = 0;
	}
	
	for (i=0; i < REPETICIONES; i++) {
		vector[(rand() % n)]++;
	}
	printf("\n");
	printf("-------------------------------------\n");
	printf("| Numero | Apariciones | Porcentaje |\n");
	printf("-------------------------------------\n");
	for (i=0; i < n; i++) {
		printf("| %6d | %11d | %8.2f % |\n", i, vector[i], (float) vector[i] / (float) 8);
	}
	printf("-------------------------------------\n");
	
	return 0;
}
