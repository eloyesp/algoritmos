#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void descartar_resto(void) {
	while (getchar() != '\n');
}

void pause(void) {
	if (getchar() != '\n')
		descartar_resto();
}

int buscar_elemento( const int elementos[], const int t_logico, const int aux) {
	int i = 0, valor = -1;
	while	(valor == -1 && i < t_logico) {
		if (aux == elementos[i])
			valor = i;
		else
			i++;
	}
	return valor;
}

void eliminar_pos(int vector[], int * tl, const int pos) {
	int i;
	if (*tl > pos) {
		for (i = pos; i < *tl - 1; i++) {
			vector[i] = vector[i+1];
		}
		*tl = *tl - 1; // ahora el vector es mas chico
		printf ("El elemento fue eliminado\n");
	} else {
		printf ("No se puede eliminar ese elemento\n");
	}
}

int main( int argc, char *argv[] )
{
	char opcion = 0;
	int elementos[TAM], aux, i, t_logico = 0;
	
	/*Menú de opciones*/
	printf("Ingrese la opcion deseada:\n");
	printf("a: Insertar elemento\n");
	printf("b: Eliminar elemento\n");
	printf("c: Eliminar posicion\n");
	printf("d: Buscar elemento\n");
	printf("e: Mostrar vector\n");
	printf("s: Salir\n");
	opcion = getchar(); /* lee un caracter*/
	descartar_resto();
	do{
		printf("\e[1;1H\e[2J");
		switch (opcion) {
		case 'a': /* Inserta un elemento */
			printf("Ingrese elemento a insertar: ");
			scanf("%d", &aux);
			descartar_resto();
			if (t_logico < TAM)
				t_logico++;
			
			// Muevo para adelante hasta llegar al primero || a la posicion donde insertar el elemento
			i = t_logico;
			while (i > 0 && elementos[i-1] > aux ) {
				//reordeno
				elementos[i] = elementos[i-1];
				i--;
			}
			elementos[i] = aux;
			break;
			
		case 'b': /* Busca un elemento y lo elimina*/
			printf("Ingrese elemento a eliminar: ");
			scanf("%d",&aux);
			descartar_resto();
			// busco el primer elemento que sea igual a aux
			aux = buscar_elemento(elementos, t_logico, aux);
			if (aux == -1) {
				printf ("El elemento no esta en el arreglo");
			} else {
				// y lo elimino.
				eliminar_pos(elementos, &t_logico, aux);
				printf ("El elemento ha %d sido eliminado", aux + 1);
			}
			pause();
			break;
			
		case 'c': /* Elimina el elemento de la posición seleccionada*/
			printf("Ingrese posicion de elemento a eliminar: ");
			scanf("%d",&aux);
			descartar_resto();
			eliminar_pos(elementos, &t_logico, aux);
			pause();
			break;
		case 'd': /* Busca un elemento y muestra en que posición se encuentra */
			printf("Ingrese elemento a buscar: ");
			scanf("%d",&aux);
			descartar_resto();
			aux = buscar_elemento(elementos, t_logico, aux);
			if ( aux != -1 )
				printf("el elemento buscado esta en la posicion %d\n", aux + 1);
			else
				printf("El elemento no se encuentra en el arreglo\n");
			pause();
			break;
		case 'e': /* Muestra vector */
			if (t_logico > 0) {
				for (i = 0; i < t_logico; i++)
					printf("%d ", elementos[i]);
				printf ("\n");
			} else {
				printf("El array esta vacio\n");
			}
			pause();
			break;
			
		case 's': /* Salir */
			break;
		default: printf("opcion equivocada!\n");
			pause();
		}
		printf("\e[1;1H\e[2J"); /* limplio la pantalla*/
		/*Menú de opciones*/
		printf("Ingrese la opcion deseada:\n");
		printf("a: Insertar elemento\n");
		printf("b: Eliminar elemento\n");
		printf("c: Eliminar posicion\n");
		printf("d: Buscar elemento\n");
		printf("e: Mostrar vector\n");
		printf("s: Salir\n");
		opcion = getchar(); /* lee un caracter*/
		descartar_resto();
	} while (opcion != 's');
	printf("\nChau!\n");
	return 0;
}
