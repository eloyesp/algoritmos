#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LM 25
#define TF 15

/*
Declarar un tipo de dato Empleado que tiene como miembro una estructura
Persona, el salario y las horas trabajadas por semana.
Realizar un programa que declare un arreglo que contiene los datos de los
empleados de una empresa y definir las siguientes funcionalidades:
* Imprimir los datos del empleado que mayor salario tiene en la empresa.
* Dado un valor n, ingresado por teclado, imprimir un listado de todos los
empleados que trabajaron n o m�s horas en la semana.
* Calcular cuantas mujeres y cuantos varones trabajan en la empresa.
* Listar por rango de edad cual es el promedio de salario ej:
20-30 -> $ 2800.00 31-40 -> $ 3450.00 41-50 -> $ 4100.00 51-60 -> $ 3241.00
61-100 -> $ 2910.00
*/

struct fecha {
	int anio;
	int mes;
	int dia;
};
typedef struct fecha Fecha;

struct Persona {
	char nombre[LM];
	int documento;
	int edad;
	char sexo;
	Fecha fecha_nacimiento;
};
typedef struct Persona persona;

struct Empleado {
	persona miembro;
    int salario;
    int horas_por_semana;
};
typedef struct Empleado empleado;

/** Prototipos
*/

int cargar_empleados(empleado empleados[]);
empleado * empleado_con_mayor_salario(empleado empleados[]);
void mostrar_datos_empleado(const empleado * const e);
void listado_de_empleados_con_horas(const empleado empleados[], const int n);
void contar_mujeres_varones(empleado empleados[]);
void listar_promedio_salario_por_rango_de_edad(empleado empleados[]);

// main
int main(void) {
	empleado empleados[TF]; // Arreglo de los empleados de la empresa.
	int n, cantidad;
	char input[LM];
	
	cantidad = cargar_empleados(empleados);
	
	//mostrar_datos_empleado(empleado_con_mayor_salario(empleados));
	
	printf("\n\nIngrese un valor n: ");
	gets(input);
	while ((n = atoi(input)) < 1) {
		printf("Valor Incorrecto\nIngrese un valor n: ");
		gets(input);
	}
	
	//listado_de_empleados_con_horas(empleados, n);
	
	//contar_mujeres_varones(empleados);
	
	//listar_promedio_salario_por_rango_de_edad(empleados);
	
	printf("\nFIN\n");
	return 0;
}

void nuevo_empleado(empleado * e, char * nombre) {
	persona p = { "jorge", 3096148, 24, 'M', {2010, 5, 13}};
	e->miembro = p;
	e->salario = 1000;
	e->horas_por_semana = 4;
}

int cargar_empleados(empleado empleados[]) {
	int i = 0;
	
	nuevo_empleado(&empleados[0], "Jorge");
	printf("%s\n", empleados[0].miembro.nombre);
	
	return i;
}


Fecha new_fecha(const int anio, const int mes, const int dia)
	/* Retorna una nueva fecha.
	*/
{
	Fecha aux = {anio, mes, dia};
	return aux;
}

//fecha str_to_fecha(const char * const str)
//	/* Retorna una nueva fecha a partir de una cadena de la forma 'anio-mes-dia'
//	*/
//{
//	char cadena[LM];
//	char separador[] = "-";
//	fecha aux;
//	
//	strcpy(cadena, str);
//	
//	aux.anio = atoi(strtok( cadena, separador ));
//	aux.mes = atoi(strtok( NULL, separador ));
//	aux.dia = atoi(strtok( NULL, separador ));
//	
//	return aux;
//}
