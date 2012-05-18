#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LM 25

/*
Declare un tipo de estructura para representar una fecha. Realizar un
programa que lea por teclado 2 variables del tipo fecha, que las compare e
imprima en pantalla ordenadas cronológicamente.
*/

struct Fecha {
	int anio;
	int mes;
	int dia;
};
typedef struct Fecha fecha;

char *read_line (char *buf, size_t length);
int fecha_compare ( const fecha fecha_1, const fecha fecha_2);
fecha str_to_fecha( const char *str );

int main(void) {
	int aux, i;
	char cadena[LM];
	fecha fecha_1, fecha_2;
	fecha *ordenadas[2];

	printf("ingrese una fecha (ej: '1985-07-16'): ");
	read_line(cadena, LM);
	fecha_1 = str_to_fecha(cadena);

	printf("ingrese otra fecha: ");
	read_line(cadena, LM);
	fecha_2 = str_to_fecha(cadena);

	//resultados
	printf("Fecha: %i - %i - %i\n", fecha_1.anio, fecha_1.mes, fecha_1.dia );
	printf("Fecha: %i - %i - %i\n", fecha_2.anio, fecha_2.mes, fecha_2.dia );

	aux = fecha_compare(fecha_1, fecha_2);
	if (aux > 0) {
		printf("La primera es mayor que la segunda\n");
		ordenadas[1] = &fecha_1;
		ordenadas[0] = &fecha_2;
	} else if (aux < 0) {
		printf("La segunda es mayor que la primera\n");
		ordenadas[0] = &fecha_1;
		ordenadas[1] = &fecha_2;
	} else {
		printf("Ambas fechas son iguales\n");
		ordenadas[0] = ordenadas[1] = &fecha_1;
	}
	puts("\nOrdenadas Cronologicamente:\n");
	for (i=0; i<2; i++) {
		printf("%i - %i - %i\n",
			ordenadas[i] -> anio, ordenadas[i] -> mes, ordenadas[i] -> dia);
	}

	return 0;
}


fecha str_to_fecha(const char *str) {
	char cadena[LM];
	char separador[] = "-";
	fecha aux;

	strcpy(cadena, str);

	aux.anio = atoi(strtok( cadena, separador )); // Primera llamada => Primer token
	aux.mes = atoi(strtok( NULL, separador ));
	aux.dia = atoi(strtok( NULL, separador ));

	return aux;
}

int fecha_compare ( const fecha fecha_1, const fecha fecha_2)
	/* Compara las fechas y retorna un numero >, < o = a 0 segun cual es
	anterior.
	*/
{
	int diff;

	diff = fecha_1.anio - fecha_2.anio;
	if (diff == 0) {
		diff = fecha_1.mes - fecha_2.mes;
		if (diff == 0)
			diff = fecha_1.dia - fecha_2.dia;
	}

	return diff;
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
