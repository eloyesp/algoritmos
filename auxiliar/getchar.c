#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  char c, d, e;

  //ingreso
	while (c != 's') {
		printf ("Ingrese un caracter: (s para salir) ");
		c = getchar();
		while (getchar() != '\n' );
		printf("Ingreso: %c\n", c);
	}	
	
  return 0;
}


