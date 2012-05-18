#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LM 25

/*
Declarar un tipo de dato Persona que tiene como miembro: nombre,
documento, edad, sexo (‘F’ o ‘M’), y fecha de nacimiento, que es del tipo
definido en la actividad anterior. Declarar e inicializar una variable del tipo
Persona y Luego imprimir los datos en pantalla.
*/

struct Fecha {
	int anio;
	int mes;
	int dia;
};
typedef struct Fecha fecha;

struct Persona {
	char nombre[LM];
	int documento;
	int edad;
	char sexo;
	fecha fecha_nacimiento;
};
typedef struct Persona persona;

char *read_line (char *buf, size_t length);
int fecha_compare ( const fecha fecha_1, const fecha fecha_2);
fecha str_to_fecha( const char *str );

int main(void) {
	persona gonzalo={ "Gonzalo", 25798425, 24, 'M', str_to_fecha("1986-7-14") };

	printf("Datos Personales:\n  Nombre: %s\n  DNI: %i\n  Edad:%i\n"
		"  Sexo: '%c'\n  Fecha de Nacimiento: %i - %i - %i",
		gonzalo.nombre, gonzalo.documento, gonzalo.edad, gonzalo.sexo,
		gonzalo.fecha_nacimiento.dia, gonzalo.fecha_nacimiento.mes,
		gonzalo.fecha_nacimiento.anio);
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
