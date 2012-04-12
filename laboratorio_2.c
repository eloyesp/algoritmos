# include <stdlib.h>
# include <math.h>
# include <stdio.h>

int main (void)
{
	int digito_max = 0, cifras = 0;
	long n;
	
	printf ("Escriba un nro: ");
	scanf ("%ld", &n);
	printf("\n");
	n = abs(n);
	
	do {
		if (digito_max < (n % 10)) digito_max = n % 10;
		n = n / 10;
		cifras++;
	} while (n != 0);
	
	printf("El numero tiene %d cifras y la mayor es %d", cifras, digito_max);
	printf ("\n");
	return 0;
}
