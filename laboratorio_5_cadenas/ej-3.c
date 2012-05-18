#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LM 25

char *read_line (char *buf, size_t length);

/*
Escribe un programa que lea una cadena que contiene una secuencia de
números enteros separados por coma y calcule e imprima la suma de dichos
números. (Ejemplo: cadena ingresada: "5,6,7,8" - suma: 26). Usa las funciones
strtok y atoi
*/

int main(int argc, char *argv[]) {
	char cadena[LM], separador[] = ",";
	char *ptr;
	int suma;
	
	printf("Ingrese una secuencia de numeros enteros separados por coma: (Ejemplo: '5,6,7,8'");
	read_line(cadena, LM);
		
	ptr = strtok(cadena, separador);    // Primera llamada => Primer token
	suma = atoi(ptr);
	while( (ptr = strtok( NULL, separador )) != NULL )    // Posteriores llamadas
		suma += atoi(ptr);
	
	
	//resultados
	printf("Suma = %i\n", suma);
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
