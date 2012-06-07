//	Implementar funciones no implementadas:
//  - calcular la diferencia de días entre dos fecha.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT 5

struct fecha {
	int anio;
	int mes;
	int dia;
};
typedef struct fecha Fecha;

char *read_line (char *buf, size_t length);
Fecha fecha_leer_por_teclado(Fecha * fecha);
void fecha_mostrar_corta(const Fecha * const fecha);
void fecha_mostrar_larga(const Fecha * const fecha);
int fecha_compare ( const Fecha * const fecha_1, const Fecha * const fecha_2);
int fecha_bisiesto(const Fecha * const fecha);
int fecha_comparar( const Fecha * const fecha_1, const Fecha * const fecha_2);
int fecha_existe(const Fecha * const fecha);
int fecha_diferencia(const Fecha * const fecha_1, const Fecha * const fecha_2);
int existe_elemento(const int vector[], const int tl, const int n);

int main(void) {
	Fecha fecha, otra_fecha;
	int diff;
	
	fecha_leer_por_teclado(&fecha);
	fecha_mostrar_corta(&fecha);
	fecha_mostrar_larga(&fecha);
	
	if (fecha_bisiesto(&fecha)) {
		puts("Es bisiesto !!");
	} else {
		puts("NO es bisiesto :(");
	}
	
	if (fecha_existe(&fecha)) {
		puts("Existe !!");
	} else {
		puts("NO existe :(");
	}
	
	fecha_leer_por_teclado(&otra_fecha);

	diff = fecha_comparar(&fecha, &otra_fecha);
	
	printf("\nLa ultima fecha ingresada es ");
	
	if (diff == 0)
		puts("la misma que la anterior");
	else if (diff < 0)
		puts("posterior a la anterior");
	else
		puts("anterior a la anterior");	
	
	return 0;
}

Fecha fecha_leer_por_teclado(Fecha * fecha)
	/** Leer una fecha por teclado
	*/
{
	char input[INPUT];
	
	printf("Ingrese el dia: ");
	fecha->dia = atoi(read_line(input, INPUT));
	printf("Ingrese el mes: ");
	fecha->mes = atoi(read_line(input, INPUT));
	printf("Ingrese el anio: ");
	fecha->anio = atoi(read_line(input, INPUT));
	
	if (!fecha_existe(fecha)) {
		printf("La fecha ingresada no es valida, vuelva a ingresarla.\n");
		*fecha = fecha_leer_por_teclado(fecha);
	}
	return *fecha;
}

void fecha_mostrar_corta(const Fecha * const fecha)
	/** Mostrar una fecha por pantalla con formato dd /mm/aaaa (por ejemplo,
		el 7 de junio de 2001 se muestra así 07/06/2001)
	*/
{
	printf("%2d/%2d/%04d\n", fecha->dia, fecha->mes, fecha->anio);
}

void fecha_mostrar_larga(const Fecha * const fecha)
	/** Mostrar una fecha por pantalla como texto (por ejemplo, 7 de junio de
		2001)
	*/
{
	const char * const NOMBRE_MESES[] = { "Enero", "Febrero", "Marzo", "Abril",
		"Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
		"Noviembre", "Diciembre" };
	
	if (fecha->mes > 0 && fecha->mes <= 12 ) {
		printf("Fecha larga: %i de %s de %i\n", fecha->dia, NOMBRE_MESES[fecha->mes - 1],
			fecha->anio);
	}
}

int fecha_bisiesto(const Fecha * const fecha)
	/** Averiguar si una fecha cae en año bisiesto
		Robado de wikipedia:
		- http://es.wikipedia.org/wiki/A%C3%B1o_bisiesto#Algoritmo_computacional
	*/
{
	const int anio = fecha->anio;
	int bisiesto = !(anio%4) && ( anio%100  || !(anio%400) );
	
	return bisiesto;
}

int fecha_existe(const Fecha * const fecha)
	/** comprobar si una fecha existe (por ejemplo, el 29 de febrero de 2002 no
		existe)
	*/
{
	int existe = 1;
	const int mes = fecha->mes;
	const int de_30[] = { 4, 6, 9, 11};
	int dias;
	
	if (fecha->anio == 0) {
		existe = 0;
	} else if (mes < 1 || mes > 12) {
		existe = 0;
	} else if (fecha->dia < 1) {
		existe = 0;
	} else {
		if ( mes == 2 ) {
			dias = fecha_bisiesto(fecha) ? 29 : 28;
		} else if (existe_elemento(de_30, 4 , fecha->mes)) {
			dias = 30;
		} else {
			dias = 31;
		}
		if (fecha->dia > dias)
			existe = 0;
	}
	
	return existe;
}

int fecha_comparar ( const Fecha * const fecha_1, const Fecha * const fecha_2)
	/** Averiguar si una fecha es anterior, igual o posterior a otra, devolviendo
		valores positivos, 0 o negativos respectivamente;
	*/
{
	int diff;
	
	diff = fecha_1->anio - fecha_2->anio;
	if (diff == 0) {
		diff = fecha_1->mes - fecha_2->mes;
		if (diff == 0)
			diff = fecha_1->dia - fecha_2->dia;
	}
	
	return diff;
}

int existe_elemento(const int vector[], const int tl, const int n)
{
	int i = 0;
	
	while (i < tl && vector[i] != n) {
		i++;
	}
	
	return (i == tl) ? 0 : 1;
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
