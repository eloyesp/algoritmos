#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int menu(void);
char * read_line (char * buf, size_t length);

int main (void) {
	int opcion = 0;
  matriz m;
  matriz_inicializar(&m, 2, 2);

	while (opcion != 5) {
		opcion = menu();
		switch ( opcion ) {
      case 1 :
        puts("Mostrar matriz");
        matriz_mostrar(&m);
        while (getchar() != '\n');
        
			case 5 : 
        puts ("Bye");
				break;
			default :
				puts("Error");
        while (getchar() != '\n');
				break;
		}
	}
	
	return 0;
}


int menu(void)
{
	char input[20];
  system("cls");
	
	printf("Menu (ingrese la opcion deseada)\n"
    "1 - Matrices\n"
		"5 - Salir\n"
		"\nOpcion: ");
	read_line(&input, 20);
	
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
