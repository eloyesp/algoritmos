#include <stdio.h>
#include <stdlib.h>
/* Directrices de Sustitucion para el Precompilador. Definicion de constantes */
#define VENDEDORES 5
#define ARTICULOS 20

/* Declaracion y Definicion de Varibles Globales */
float precios[ARTICULOS];
int ventas[VENDEDORES][ARTICULOS];
float costos [ARTICULOS];

int main (void)
{
	int i, j;
	int opcion = -1;
	float acumulador;
	
	while (opcion != 0)
	{
		/* MENU */
		/*system ("cls");*/ /* WINDOWS */
		system ("clear"); /* LINUX */
		printf ("Ingrese la opcion y presione enter:\n\n");
		printf (" 1 - Cargar Precios de Articulos al Publico.\n");
		printf (" 2 - Cargar Costos de Articulos.\n");
		printf (" 3 - Cargar Ventas de los Vendedores.\n");
		printf (" 4 - Carga Automatica de Datos Ficticios.\n");
		printf (" 5 - Reporte: Total de Ventas por Vendedor ($).\n");
		printf (" 6 - Reporte: Total de Ganancias por Articulo ($).\n");
		printf ("\n 0 - Salir.\n\n");
		printf ("Opcion: ");
		scanf ("%d", &opcion);
		switch (opcion)
		{
		case 1:
			/* Cargar Precios Articulos */
			printf("Ingrese numero de articulo:");
			scanf("%d", &i);
			if (i>=0 && i<20) {
				printf("ingrese precio del articulo:");
				scanf("%f", &precios[i]);
			} else {
				puts("Ese no es un articulo valido");
			}
			break;
		case 2:
			/* Cargar Costos Articulos */
			printf("Ingrese numero de articulo:");
			scanf("%d", &i);
			if (i>=0 && i<20) {
				printf("ingrese costo del articulo:");
				scanf("%f", &costos[i]);
			} else {
				puts("Ese no es un articulo valido");
			}
			break;
		case 3:
			/* Cargar Ventas Vendedores */
			i=0;
			while (i != -1) {
				printf("Ingrese codigo de vendedor:");
				scanf("%d", &i);
				if (i<5 && i>0) {
					printf("ingrese codigo del articulo:");
					scanf("%d", &j);
					if (i>=0 && i<20) {
						printf("ingrese cantidad vendida en unidades:");
						scanf("%d", &ventas[i][j]);
					} else {
						puts("Ese no es un articulo valido");
					}
				} else if (i != -1) {
					puts ("vendedor invalido!!");
				}
			} 	
			break;
		case 4:
			/* Carga Automatica de Datos Ficticios */
			for (i = 0; i < VENDEDORES; i++)
				for (j = 0; j < ARTICULOS; j++)
					ventas[i][j] = rand () % 11;
			for (j = 0; j < ARTICULOS; j++)
				precios[j] = ((rand () % 1000) + 1)/(10.0);
			for (j = 0; j < ARTICULOS; j++)
				costos[j] = precios[j] * 0.3;
			
			printf("DATOS CARGADOS:\n\n");
			for (i = 0; i < VENDEDORES; i++){
				for (j = 0; j < ARTICULOS; j++){
					printf("%3d", ventas[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			for (j = 0; j < ARTICULOS; j++){
				printf("%.2f ", precios[j]);
			}
			printf("\n\n");
			for (j = 0; j < ARTICULOS; j++){
				printf("%.2f ", costos[j]);
			}
			printf("\n\n");
			break;
		case 5:
			/* Reporte: Total de Ventas por Vendedor ($) */
			for (i = 0; i < VENDEDORES; i++) {
				acumulador = 0;
				for (j = 0; j < ARTICULOS; j++) {
					acumulador += ventas[i][j] * precios[j];
				}
				printf("Total de ventas del vendedor %d: $ %8.2f\n", i, acumulador);
			}
			break;
		case 6:
			/* Reporte: Total de Ganancias por Articulo ($) */
			for (i = 0; i < ARTICULOS; i++) {
				acumulador = 0;
				for (j = 0; j < VENDEDORES; j++) {
					acumulador += ventas[j][i] * (precios[i]-costos[i]);
				}
				printf("Total de ganancias del articulo %d: $ %8.2f\n", i, acumulador);
			}
			break;
		};
		getchar(); /* lee el enter ingresado al elegir la opcion */
		printf("Presiona Enter para continuar... ");
		getchar();
	};

	return 0;
}
