#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int i, numero = 2;
	int bandera = 0;
  
	printf("Numeros primos entre 2 y 1000: \n");
	do { 
		for (i = 2; i < numero; i++)
			if ((numero % i) == 0)
				bandera++;
		if ( bandera == 0 )
			printf("%d ", numero);
		
		// hago un salto de linea cada tanto para que los numeros no se corten
		if (numero % 100 == 0)
			printf("\n");
		numero++;
		bandera = 0;
  } while (numero < 1000);
	
	printf ("\n");

	return 0;
}
