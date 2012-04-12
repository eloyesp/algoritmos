#include <stdio.h>

int main (void)
{
	int cantIBlancos = 0;
	int cantIAsteriscos = 10;
	int i, j, k;
	/* el for se ejecuta 10 veces */
	for (k = 10; k >= 1; k--)
	{
		for (j = 1; j <= cantIAsteriscos; j++)
		  printf ("*");
		for (i = 1; i <= cantIBlancos; i++)
			printf ("-");
		
		printf ("\n");
		cantIAsteriscos--;
		cantIBlancos++;
	}
	
	printf ("\n");
	return 0;
}
