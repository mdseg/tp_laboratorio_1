/*
 ============================================================================
 Name        : TP1.c
 Author      : Marcos Seghesio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnFuncionesCalculadora.h"
#include "utnFuncionesGenericas.h"

#define TRUE 1
#define FALSE 0
#define BANNER_GENERIC "-----------------------------------------------------------------------------------------\n"
#define MAIN_MENU "--------Calculadora--------------------\nSeleccione alguna de las opciones:\n1-Ingresar primer operando.\n2-Ingresar segundo operando.\n3-Calcular todas las funciones.\n4-Informar los resultados.\n5-Salir\n"
#define MAIN_MENU_INPUT_ERROR "Por favor, ingrese una opcion válida"
#define INPUT_PRIMER_OPERANDO "Ingrese el valor del primer operando:\n"
#define INPUT_PRIMER_OPERANDO_ERROR "Hubo problemas al ingresar el primer operando.\n"
#define INPUT_SEGUNDO_OPERANDO_ERROR "Hubo problemas al ingresar el segundo operando.\n"
#define INPUT_SEGUNDO_OPERANDO "Ingrese el valor del segundo operando:\n"
#define INPUT_ERROR "Por, favor ingrese un valor numérico valido"
#define INPUT_PRIMER_OPERANDO_SUCCESS "Primer operando cargado correctamente.\n"
#define INPUT_SEGUNDO_OPERANDO_SUCCESS "Segundo operando cargado correctamente.\n"
#define OPERATIONS_ERROR "Hubo problemas para realizar las operaciones"
#define OPERATIONS_ERROR_NO_ACCESS "Es necesario que esten los dos operandos cargados para realizar las operaciones.\n"
#define PRINT_OPERATIONS_ERROR_NO_ACCESS "Es necesario calcular las operaciones en el paso 3, antes de podes mostrarlas en pantalla.\n"


int main(void)
{
	int opcion;
	float operandoUno;
	float operandoDos;
	int flagOperandoUno = FALSE;
	int flagOperandoDos = FALSE;
	int flagOperacionesRealizadas = FALSE;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMulti;
	float resultadoDiv;

	int resultadoFactorialUno;
	int resultadoFactorialDos;

	do
	{
		imprimirEstadosyValores(flagOperandoUno, flagOperandoDos, flagOperacionesRealizadas, operandoUno, operandoDos);
		if(utn_getInt(&opcion, MAIN_MENU, MAIN_MENU_INPUT_ERROR, 1, 5, 5) == 0)
		{
			switch(opcion)
			{
				case 1:
					if(utn_getFloat(&operandoUno, INPUT_PRIMER_OPERANDO, INPUT_ERROR, 5) == 0)
					{
						printf(BANNER_GENERIC);
						printf(INPUT_PRIMER_OPERANDO_SUCCESS);
						printf(BANNER_GENERIC);
						flagOperandoUno = TRUE;
						if(flagOperacionesRealizadas == TRUE)
						{
							flagOperacionesRealizadas = FALSE;
						}
					}
					else
					{
						printf(BANNER_GENERIC);
						printf(INPUT_PRIMER_OPERANDO_ERROR);
						printf(BANNER_GENERIC);
					}
					break;
				case 2:
					if(utn_getFloat(&operandoDos, INPUT_SEGUNDO_OPERANDO, INPUT_ERROR, 5) == 0)
					{
						printf(BANNER_GENERIC);
						printf(INPUT_SEGUNDO_OPERANDO_SUCCESS);
						printf(BANNER_GENERIC);
						flagOperandoDos = TRUE;
						if(flagOperacionesRealizadas == TRUE)
						{
							flagOperacionesRealizadas = FALSE;
						}
					}
					else
					{
						printf(BANNER_GENERIC);
						printf(INPUT_SEGUNDO_OPERANDO_ERROR);
						printf(BANNER_GENERIC);
					}
					break;
				case 3:
					if(flagOperandoUno == TRUE && flagOperandoDos == TRUE)
					{
						if(realizarOperaciones(operandoUno, operandoDos, &resultadoSuma, &resultadoResta, &resultadoMulti, &resultadoDiv, &resultadoFactorialUno, &resultadoFactorialDos) == 0)
						{
							mostrarOperaciones(operandoUno, operandoDos);
							flagOperacionesRealizadas = TRUE;
						}
						else
						{
							printf(BANNER_GENERIC);
							printf(OPERATIONS_ERROR);
							printf(BANNER_GENERIC);
						}
					}
					else
					{
						printf(BANNER_GENERIC);
						printf(OPERATIONS_ERROR_NO_ACCESS);
						printf(BANNER_GENERIC);
					}
					break;
				case 4:
					if(flagOperacionesRealizadas == TRUE)
					{
						imprimirOperaciones(operandoUno, operandoDos, resultadoSuma, resultadoResta, resultadoMulti, resultadoDiv, resultadoFactorialUno, resultadoFactorialDos);
					}
					else
					{
						printf(BANNER_GENERIC);
						printf(PRINT_OPERATIONS_ERROR_NO_ACCESS);
						printf(BANNER_GENERIC);
					}
					break;
			}
		}
	}
	while(opcion !=5);

	return EXIT_SUCCESS;
}

