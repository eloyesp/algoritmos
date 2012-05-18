#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define LM 25

char *read_line (char *buf, size_t length);

int main(int argc, char *argv[]) {
	char cadena[LM], copia[LM], c;
	int i;
	printf("ingrese una palabra: ");
	read_line(cadena, LM);
	
	strcpy(copia, cadena);
	i = 0;
	while(copia[i] != '\0') {
		copia[i] = tolower(copia[i]);
		i++;
	}
	
	//resultados
	printf("Cadena ingresada: %s\n"
	       "Copia: %s\n", cadena, copia);
	return 0;
}

char *read_line (char *buf, size_t length)
	/**** Read at most 'length'-1 characters from the file 'f' into
	'buf' and zero-terminate this character sequence. If the
	line contains more characters, discard the rest.
	*/
{
	char *p;
	
	if (p = fgets (buf, length, stdin)) {
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
