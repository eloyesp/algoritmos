#include <stdio.h>

int main() 
{
	int numero;
	
	printf("Ingrese un numeo entero: ");
	scanf("%i", &numero);
	
	if ( numero % 2  == 0 ) {
		printf("El numero es par\n");
	} else {
		printf("El numero es impar\n");
	}
	return 0;
}
