#include <stdio.h>

float x_a_la_n (const float x, const int n)
{
	if (n == 0)
		return 1;
	else if (n > 0)
		return x * x_a_la_n(x, n-1);
}
int main(void)
{
	int n;
	float x;
	
	printf ("Ingrese un numero real: ");
	scanf ("%f", &x);
	
	printf ("Ingrese un numero entero positivo: ");
	scanf ("%d", &n);
	printf ("%f a la %d vale: %f\n", x, n, x_a_la_n(x, n));
	return 0;
}
