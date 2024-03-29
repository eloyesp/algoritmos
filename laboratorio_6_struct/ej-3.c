#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
empleado * empleado_con_mayor_salario(empleado empleados[], int const n);
void mostrar_datos_empleado(const empleado * const e);
void listado_de_empleados_con_horas(const empleado empleados[], const int n, const int min_horas);
void contar_mujeres_varones(empleado empleados[], const int n);
void listar_promedio_salario_por_rango_de_edad(empleado empleados[], const int n);
Fecha new_fecha(const int anio, const int mes, const int dia);
	
// main
int main(void) {
	empleado empleados[TF]; // Arreglo de los empleados de la empresa.
	int n, cantidad;
	char input[LM];
	
	cantidad = cargar_empleados(empleados);
	printf("%i empleados cargados", cantidad);
	
	mostrar_datos_empleado(empleado_con_mayor_salario(empleados, cantidad));
	
	printf("\n\nIngrese un valor n: ");
	gets(input);
	while ((n = atoi(input)) < 1) {
		printf("Valor Incorrecto\nIngrese un valor n: ");
		gets(input);
	}
	
	listado_de_empleados_con_horas(empleados, cantidad, n);
	
	contar_mujeres_varones(empleados, cantidad);
	
	listar_promedio_salario_por_rango_de_edad(empleados, cantidad);
	
	printf("\n\nFIN\n");
	return 0;
}

void nueva_persona(persona * p, char * nombre) {
	strcpy(p->nombre, nombre);
	p->documento = rand() % 10000000;
	p->edad = rand()%50 + 20;
	p->sexo = (rand()%2) ? 'M' : 'F';
	p->fecha_nacimiento = new_fecha(2012 - p->edad, rand()%12+1, rand()%30+1);
}

void nuevo_empleado(empleado * e, char * nombre) {
	nueva_persona(&e->miembro, nombre);
	e->salario = rand()%100000;
	e->horas_por_semana = rand()%50;	
}

int cargar_empleados(empleado empleados[]) {
	int i = 0;
	char *nombres[10] = { "Jorge", "Adrian", "Miriam", "Adriana", "Raquel"};
	
	for (i=0; i<5; i++) {
		nuevo_empleado(&empleados[i], nombres[i]);
	}
	printf("%s\n", empleados[i-1].miembro.nombre);
	
	return i;
}


Fecha new_fecha(const int anio, const int mes, const int dia)
	/* Retorna una nueva fecha.
	*/
{
	Fecha aux = {anio, mes, dia};
	return aux;
}

empleado * empleado_con_mayor_salario(empleado empleados[], const int n) {
	int i, max = empleados[0].salario;
	empleado * mejor = &empleados[0];
	
	for (i=1; i<n; i++) {
		if (max < empleados[i].salario) {
			max = empleados[i].salario;
			mejor = &empleados[i];
		}
	}

	return mejor;
}

void mostrar_datos_empleado(const empleado * const e) {
	
	printf("\nDatos del empleado:\n"
		"Nombre: %s\n"
		"Documento: %i\n"
		"Fecha de nacimiento: %i-%i-%i (%i anios)\n"
		"Salario: %i\n"
		"Horas de trabajo: %i\n"
		"Sueldo por hora: %.2f\n\n",
		e->miembro.nombre, e->miembro.documento, e->miembro.fecha_nacimiento.dia,
		e->miembro.fecha_nacimiento.mes, e->miembro.fecha_nacimiento.anio,
		e->miembro.edad, e->salario, e->horas_por_semana,
		(float) e->salario / e->horas_por_semana / 4);
}

void listado_de_empleados_con_horas(const empleado empleados[], const int n, const int min_horas) {
	int i;
	printf ("Los empleados que trabajan mas de %i horas son: ", min_horas);
	for (i=0; i<n; i++) {
		if (empleados[i].horas_por_semana >= min_horas)
			printf("%s ", empleados[i].miembro.nombre);
	}
	printf("\n");
}

void contar_mujeres_varones(empleado empleados[], const int n) {
	int mujeres, varones, i;
	mujeres = varones = 0;
	for (i=0; i<n; i++) {
		if (empleados[i].miembro.sexo == 'M')
			varones++;
		else
			mujeres++;
	}
	
	printf("La cantidad de mujeres es: %i y la cantidad de varones es: %i\n", mujeres, varones);
}

void listar_promedio_salario_por_rango_de_edad(empleado empleados[], const int n) {
	int matriz[2][5], i, aux;
	for (i=0; i<5; i++) {
		matriz[0][i] = matriz[1][i] = 0;
	}
	for (i=0; i<n; i++) {
		aux = empleados[i].miembro.edad / 10;
		if (aux > 6) 
			aux = 6;
		aux -= 2; // las categorias empiezan en 20 anios
		matriz[0][aux] += empleados[i].salario;
		matriz[1][aux]++;
	}
	
	printf("\nPromedios de sueldo por rango de edad:\n");
	for (i=0; i<4; i++) {
		if (matriz[1][i] > 0)
			printf("%i-%i -> $ %.2f ", (i+2)*10, (i+3)*10, (float) matriz[0][i] / matriz[1][i]);
	}
	printf("60-100 -> $ %f ", (float) matriz[0][i] / matriz[1][i]);
	
	
}
