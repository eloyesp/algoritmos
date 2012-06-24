#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#define PAUSE while (getchar() != '\n');
int menu(void);
char * read_line (char * buf, size_t length);
void reinicializar_matriz(matriz * const m);
void cargar_valor_matriz(matriz * const m);
void leer_valor_matriz(const matriz * const m);

int main (void) {
	int opcion = 0;
  matriz m;
  matriz_inicializar(&m, 2, 2);

	while (opcion != 5) {
		opcion = menu();
		switch ( opcion ) {
      case 1 :
        puts("=================\n"
             "Mostrar matriz");
        matriz_mostrar(&m);
        PAUSE
        break;
      case 2 :
        puts("=================\n"
             "Reinicializar matriz");
        reinicializar_matriz(&m);
        matriz_mostrar(&m);
        PAUSE
        break;
      case 3 :
        puts("=================\n"
             "Cargar valor en Matriz");
        cargar_valor_matriz(&m);
        matriz_mostrar(&m);
        PAUSE
        break;
      case 4 :
        puts("=================\n"
             "Leer valor de la matriz");
        leer_valor_matriz(&m);
        matriz_mostrar(&m);
        PAUSE
        break;
			case 5 : 
        puts ("Bye");
				break;
			default :
				puts("Error");
        PAUSE
				break;
		}
	}
	
	return 0;
}

void reinicializar_matriz(matriz * const m) {
  char input[20];
  int  filas, columnas;
  
  printf("Ingrese la cantidad de filas (<=20): ");
  read_line(input, 20);
  filas = atoi(input);
  while (filas < 1 || filas > 20) {
    puts("ERROR (el numero de filas debe estar entre 1 y 20)");
    printf("Ingrese la cantidad de filas (<=20): ");
    read_line(input, 20);
    filas = atoi(input);
  }
  printf("Ingrese la cantidad de columnas (<=20): ");
  read_line(input, 20);
  columnas = atoi(input);
  while (columnas < 1 || columnas > 20) {
    puts("ERROR (el numero de columnas debe estar entre 1 y 20)");
    printf("Ingrese la cantidad de columnas (<=20): ");
    read_line(input, 20);
    columnas = atoi(input);
  }
  matriz_inicializar(m, filas, columnas);
}
void cargar_valor_matriz(matriz * const m){
  
}
void leer_valor_matriz(const matriz * const m){
  
}


int menu(void)
{
	char input[20];
  system("cls");
	
	printf("Menu (ingrese la opcion deseada)\n"
    "1 - Mostrar matriz\n"
    "2 - Reinicializar Matriz\n"
    "3 - Cargar valor en la matriz\n"
    "4 - Leer valor de la matriz\n"
		"5 - Salir\n"
		"\nOpcion: ");
	read_line(input, 20);
	
	return atoi(input);
}

char * read_line (char * buf, size_t length) {
  /**** Copyright de home.datacomm.ch/t_wolf/tw/c/getting_input.html#skip
  Read at most 'length'-1 characters from the file 'f' into
  'buf' and zero-terminate this character sequence. If the
  line contains more characters, discard the rest.
  */
  
  char *p;
  
  if ((p = fgets (buf, length, stdin))) {
    size_t last = strlen (buf) - 1;
    
    if (buf[last] == '\n') {
      /**** Discard the trailing newline */
      buf[last] = '\0';
    } else {
      /**** There's no newline in the buffer, therefore there must be
      more characters on that line: discard them!
      */
      fscanf (stdin, "%*[^\n]");
      /**** And also discard the newline... */
      (void) fgetc (stdin);
    } /* end if */
  } /* end if */
  return p;
} /* end read_line */
