#include <stdio.h>

int main (void)
{
	int cantIBlancos = 9;
	int cantIAsteriscos = 1;
	int i, j, k;
	/* el for se ejecuta 10 veces */
	for (k = 1; k <= 10; k++)
	{
		for (i = 1; i <= cantIBlancos; i++)
			printf ("-");
		for (j = 1; j <= cantIAsteriscos; j++)
			printf ("*");
		printf ("\n");
		cantIAsteriscos++;
		cantIBlancos--;
	}
	
	printf ("\n");
	return 0;
}
