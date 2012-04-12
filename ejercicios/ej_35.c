#include <stdio.h>
#include <math.h>

int main() 
{
	float radio, perimetro, area;
	printf("Ingrese el radio: ");
	scanf("%f", &radio);
	
	perimetro= M_PI*radio*2;
	area= M_PI*radio*radio;
	
	printf("El perimetro es: %f \n", perimetro);
	printf("El area es: %f \n", area);
	
	return 0;
}
