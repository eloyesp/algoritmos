#include <stdio.h>
#include <stdlib.h>

int menu(void);

int main (void) {
	int opcion = 1;
		
	while (opcion != 0) {
		opcion = menu();
		switch ( opcion ) {
			case 0 : 
				break; 
			default :
				puts("Error");
				break;
		}
	}
	
	return 0;
}


int menu(void)
{
	char input[20];
	
	printf("Menu (ingrese la opcion deseada)\n"
		"0 - Salir\n"
		"\nOpcion: ");
	gets(&input);
	
	return atoi(input);
}
