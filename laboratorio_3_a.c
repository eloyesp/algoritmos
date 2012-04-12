#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int i, numero=0;
	int bandera = 0;
  
	do {
	printf ("Ingrese un numero entero mayor que uno: ");
	scanf ("%i", &numero);
  } while (numero < 2);
	
	for (i = 2; i < numero; i++)
		if ((numero % i) == 0)
			bandera++;

	printf ("\n");

	if ( bandera > 0 )
		printf("El numero ingresado NO es primo");
	else printf("El numero ingresado ES primo");

	return 0;
}
