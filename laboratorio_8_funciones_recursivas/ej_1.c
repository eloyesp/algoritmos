#include <stdio.h>

unsigned int factorial (const unsigned int n)
{
	if (n<=1)
		return 1;
	else
		return n * factorial ( n-1 );
}
int main(void)
{
	int valor;
	printf ("Ingrese un numero entero positivo: ");
	scanf ("%d", &valor);
	printf ("El factorial de %d vale: %d\n", valor, factorial(valor));
	return 0;
}
