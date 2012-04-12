#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main( int argc, char *argv[] )
{
	char opcion = 0;
	int elementos[TAM], aux, i, ultimo = 0;
	
	/*Menú de opciones*/
	printf("Ingrese la opcion deseada:\n");
	printf("a: Insertar elemento\n");
	printf("b: Eliminar elemento\n");
	printf("c: Eliminar posicion\n");
	printf("d: Buscar elemento\n");
	printf("e: Mostrar vector\n");
	printf("s: Salir:\n");
	opcion = getchar(); /* lee un caracter*/
	do{
		switch (opcion) {
		case 'a': /* Inserta un elemento */
			printf("Ingrese elemento a insertar: ");
			scanf("%d", &aux);
			if (ultimo < TAM)
				ultimo++;
			for (i = ultimo; i > 0; i--) {
				elementos[i] = elementos[i-1];
			}
			elementos[0] = aux;
			break;
		case 'b': /* Busca un elemento y lo elimina*/
			printf("Ingrese elemento a eliminar: ");
			scanf("%d",&aux);
			break;
		case 'c': /* Elimina el elemento de la posición seleccionada*/
			printf("Ingrese posicion de elemento a eliminar: ");
			scanf("%d",&aux);
			break;
		case 'd': /* Busca un elemento y muestra en posición se encuentra */
			printf("Ingrese elemento a buscar: ");
			scanf("%d",&aux);
			break;
		case 'e': /* Muestra vector */
			for (i = 0; i < ultimo; i++)
				printf("%d ", elementos[i]);
			printf("\n");
			break;
		case 's': /* Salir */
			break;
		default: printf("opcion equivocada!\n");
		}
		printf("---------------\n");
		/*Menú de opciones*/
		printf("Ingrese la opcion deseada:\n");
		printf("a: Insertar elemento\n");
		printf("b: Eliminar elemento\n");
		printf("c: Eliminar posicion\n");
		printf("d: Buscar elemento\n");
		printf("e: Mostrar vector\n");
		printf("s: Salir:\n");
		fflush(stdin); /* limpia el buffer de entrada */
		opcion = getchar(); /* lee un caracter*/
	} while (opcion != 's');
	
	return 0;
}