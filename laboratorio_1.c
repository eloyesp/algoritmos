#include <stdio.h>

int main (void)
{
	int cantIBlancos = 9;
	int cantIAsteriscos = 1;
	int i, j, k;
	/* el for se ejecuta 10 veces */
	for (k = 1; k <= 10; k++)
	{
		/* cada repeticion disminuye la cantidad de asteriscos de 10 a 1 */
		for (j = 1; j <= cantIAsteriscos; j++)
			printf ("*");
		/* cada repeticion aumenta la cantidad de guiones de 1 a 10 */
		for (i = 1; i <= cantIBlancos; i++)
			printf ("-");
		printf ("\n");
		cantIAsteriscos++;
		cantIBlancos--;
	}
	
	printf ("\n");
	return 0;
}
