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
fecha str_to_fecha( char *str );

int main(int argc, char *argv[]) {
	int aux;
	char cadena[LM];
	fecha fecha_1;
	fecha fecha_2;
	fecha *mayor;
	fecha *menor;
	
	printf("ingrese una fecha (ej: '1985-07-16'): ");
	//read_line(cadena, LM);
	puts("2008-07-16");
	fecha_1 = str_to_fecha("2008-07-16");
	
	printf("ingrese otra fecha: ");
	read_line(cadena, LM);
	//puts("2008-07-15");
	fecha_2 = str_to_fecha(cadena);
	
	//resultados
	printf("Fecha: %i - %i - %i\n", fecha_1.anio, fecha_1.mes, fecha_1.dia );
	printf("Fecha: %i - %i - %i\n", fecha_2.anio, fecha_2.mes, fecha_2.dia );
	
	aux = fecha_compare(fecha_1, fecha_2);
	if (aux > 0) {
		printf("La primera es mayor que la segunda\n");
		mayor = &fecha_1;
		menor = &fecha_2;
	} else if (aux < 0) {
		printf("La segunda es mayor que la primera\n");
		mayor = &fecha_2;
		menor = &fecha_1;
	} else {
		printf("Ambas fechas son iguales\n");
		mayor = menor = &fecha_2;
		
	}
	
	printf("Mayor: %i - %i - %i\n"
		   "Menor: %i - %i - %i\n",
			mayor -> anio, mayor -> mes, mayor -> dia,
			menor -> anio, menor -> mes, menor -> dia);
	
	return 0;
}


fecha str_to_fecha(char *str) {
	char cadena[LM];
	char separador[] = "-";
	fecha aux;

	strcpy(cadena, str);

	aux.anio = atoi(strtok( cadena, separador )); // Primera llamada => Primer token
	aux.mes = atoi(strtok( NULL, separador ));
	aux.dia = atoi(strtok( NULL, separador ));
	
	return aux;
}

int fecha_compare ( fecha const fecha_1, fecha const fecha_2)
	/**** Compara las fechas y retorna un numero >, < o = a 0 segun cual es
	anterior.
	*/
{
	int diff;
	
	diff = fecha_1.anio - fecha_2.anio;
	if (diff != 0)
		return diff;
	else if ((diff = fecha_1.mes - fecha_2.mes) != 0)
		return diff;
	else {
		diff = fecha_1.dia - fecha_2.dia;
		return diff;
	}
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
