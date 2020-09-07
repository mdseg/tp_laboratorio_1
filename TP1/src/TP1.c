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
#include "utnFunciones.h"

int ingresarOperando(int* pOperando, int reintentos);
int mostrarMenu(char* pOperacionElegida);



int main(void) {
	int operandoUno;
	int operandoDos;
	char operacion;
	int resultado;
	float resultadoDivision;
	if(ingresarOperando(&operandoUno,2) == 0)
	{
		if(ingresarOperando(&operandoDos,2) == 0)
		{
			if(mostrarMenu(&operacion) == 0)
			{
				switch(operacion)
				{
					case 'a':
						sumar(&resultado,operandoUno,operandoDos);
						printf("El resultado de la suma es: %d.\n", resultado);
						break;
					case 'b':
						restar(&resultado,operandoUno,operandoDos);
						printf("El resultado de la resta es: %d.\n", resultado);
						break;
					case 'c':
						multiplicar(&resultado, operandoUno,operandoDos);
						printf("El resultado de la multiplicación es: %d.\n", resultado);
						break;
					case 'd':
						if(dividir(&resultadoDivision,operandoUno,operandoDos) == 0)
						{
							printf("El resultado de la división es: %.2f.\n", resultadoDivision);
						}
						else
						{
							printf("No se puede dividir por cero.\n");
						}
						break;
					case 'e':
						if(factorial(&resultado,operandoUno) == 0)
						{
							printf("El resultado de la función factorial es: %d.\n", resultado);
						}
						else
						{
							printf("El operando uno no puede ser menor a 1.\n");
						}

				}

			}
			else
			{
				printf("Hubo problemas para seleccionar la operación");
			}

			/*sumar(&resultado,operandoUno,operandoDos);
			printf("El resultado de la suma es: %d.\n", resultado);
			restar(&resultado,operandoUno,operandoDos);
			printf("El resultado de la resta es: %d.\n", resultado);
			multiplicar(&resultado, operandoUno,operandoDos);
			printf("El resultado de la multiplicación es: %d.\n", resultado);
			if(dividir(&resultadoDivision,operandoUno,operandoDos) == 0)
			{
				printf("El resultado de la división es: %.2f.\n", resultadoDivision);
			}
			else
			{
				printf("No se puede dividir por cero.\n");
			}
			if(factorial(&resultado,operandoUno) == 0)
			{
				printf("El resultado de la función factorial es: %d.\n", resultado);
			}
			else
			{
				printf("El operando uno no puede ser menor a 1.\n");
			}
			*/
		}
		else
		{
			printf("Hubo problemas al ingresar el segundo operando.\n");
		}
	}
	else
	{
		printf("Hubo problemas al ingresar el primer operando.\n");
	}

	return EXIT_SUCCESS;
}

int ingresarOperando(int* pOperando, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	while(reintentos >=0)
	{
		printf("Ingrese el operando:\n");
		__fpurge(stdin);
		if(scanf("%d", &bufferInt) == 1)
		{
			*pOperando = bufferInt;
			retorno = 0;
			break;
		}
		else
		{
			printf("Error al cargar el número. Intentos restantes para ingresar el número: %d.\n", reintentos);
			reintentos--;
		}
	}
	return retorno;
}
int mostrarMenu(char *pOperacionElegida)
{
	int retorno = -1;
	char operacionIngresada;
	printf("Por favor, seleccione la operación a realizar escribiendo la letra correspondiente:\n");
	printf("a-Sumar\n");
	printf("b-Restar\n");
	printf("c-Multiplicar\n");
	printf("d-Dividir\n");
	printf("e-Factorial\n");
	__fpurge(stdin);
	scanf("%c", &operacionIngresada);
	switch(operacionIngresada)
	{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
			retorno = 0;
			*pOperacionElegida = operacionIngresada;
			break;
	}

	return retorno;
}
