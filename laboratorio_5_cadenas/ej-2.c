#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define LM 25

char *read_line (char *buf, size_t length);

/*
Diseña un programa en C que lea dos cadena e informe si la cadena de
menor longitud se encuentra contenida en la cadena de mayor longitud. Las
cadenas pueden contener espacios en blanco. Usar las funciones strstr y gets
*/

int main(int argc, char *argv[]) {
	char cadena[2][LM];
	char *match;

	printf("ingrese una palabra: ");
	read_line(cadena[0], LM);
	
	printf("ingrese otra palabra: ");
	read_line(cadena[1], LM);
	
	if (strlen(cadena[0]) > strlen(cadena[1]))
		match = strstr(cadena[0], cadena[1]);
	else 
		match = strstr(cadena[1], cadena[0]);
	
	if (match == NULL)
		printf("La cadena mayor no contiene a la menor :-(\n");
	else
		printf("La cadena mayor contiene a la menor.  :-)\n");
	
	//resultados
	printf("Cadena 1: %s\n"
	       "Cadena 2: %s\n", cadena[0], cadena[1]);
	return 0;
}

char *read_line (char *buf, size_t length)
	/**** Read at most 'length'-1 characters from the file 'f' into
	'buf' and zero-terminate this character sequence. If the
	line contains more characters, discard the rest.
	*/
{
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
