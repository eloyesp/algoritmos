#include <stdio.h>

int main (void)
{
	int cantIBlancos = 9;
	int cantIAsteriscos = 1;
	int i, j, k = 1;
	
	/* el while se ejecuta 10 veces */
	while ( 10 >= k++ ) {
		/* cada repeticion disminuye la cantidad de asteriscos de 10 a 1 */
		j = i = 1;
		while (j++ <= cantIAsteriscos)
			printf ("*");
		/* cada repeticion aumenta la cantidad de guiones de 1 a 10 */
		while (i++ <= cantIBlancos)
			printf ("-");
		printf ("\n");
		cantIAsteriscos++;
		cantIBlancos--;
	}
	
	printf ("\n");
	return 0;
}
