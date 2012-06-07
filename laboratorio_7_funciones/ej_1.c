//: Escribir una función que tenga un argumento de tipo entero y que devuelva
//	la letra P si el número es positivo, y la letra N si es cero o negativo. Hacer una
//	llamada a la función desde main() e imprimir el resultado.
#include <stdio.h>

char positivo(const int n);

int main(void) {
	int n;
	printf("Ingrese n: ");
	scanf("%i", &n);
	printf("positivo => %c", positivo(n));

	return 0;
}

char positivo(const int n)
{
	char value;
	
	if (n > 0) {
		value = 'P';
	} else {
		value = 'N';
	}
	
	return value;
}
