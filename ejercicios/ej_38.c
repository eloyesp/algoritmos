#include <stdio.h>

int main() 
{
	float a, b, x;
	printf("ingrese el valor de a: ");
	scanf("%f", &a);
	printf("ingrese el valor de b: ");
	scanf("%f", &b);
	
	printf("La ecuacion %f x + %f = 0 : ", a, b);
	
	x = -b/a;
	
	if ( a == 0 ) {
		if ( b == 0 )
			printf("es indeterminada\n");
		else 
			printf("no tiene solucion\n"); }
	else 
		printf("tiene solucion x = %f \n", x);
	
	return 0;
}
