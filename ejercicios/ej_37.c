#include <stdio.h>

int main() 
{
	int numero1, numero2;
	printf("ingrese el primer numero: ");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero: ");
	scanf("%d", &numero2);
	
	numero1 = numero1*numero1;
	
	if (numero1 == numero2)
		printf("El segundo es el cuadrado exacto del primero\n");
	else if (numero1 < numero2)
		printf("El segundo es mayor que el cuadrado del primero\n");
	else if (numero1 > numero2)
		printf ("El segundo es menor que el cuadrado del primero\n");
	
	return 0;
}
