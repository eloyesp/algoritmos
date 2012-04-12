# include <stdio.h>

# define MAX 10

int duplicado(int const vector[], int last);

int main(void) {
	int i, vector[MAX];
	
	for (i = 0; i < MAX; i++) {
		printf ("ingrese el valor: ");
		scanf ("%d", &vector[i]);
		while (duplicado(vector, i)) {
			printf ("Ese numero ya esta, ingrese otro: ");
			scanf ("%d", &vector[i]);
		}
	}
	
	printf("\n");
	
	for (i=0; i < MAX; i++)
		printf("%d ", vector[i]); 
	return 0;
}


int duplicado(int const vector[], int last_i) {
	int duplicado = 0, i = 0, j;
	
	while (!duplicado && i < last_i) {
		j = i+1;
		while (!duplicado && j <= last_i) {
			duplicado = (vector[j] == vector[i]);
			j++;
		}
		i++;
	}

	return duplicado;
}
