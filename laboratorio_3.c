#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int i, numero;
	int bandera = 0;

	printf ("Ingrese un numero entero: ");
	scanf ("%i", &numero);

	for (i = 2; i < numero; i++)
		if ((numero % i) == 0)
			bandera++;

	printf ("\n");

	if ( bandera > 0 )
		printf("El numero ingresado NO es primo");
	else printf("El numero ingresado ES primo");

	return 0;
}
