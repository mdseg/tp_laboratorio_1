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


int main(void)
{
	float operandoUno;
	float operandoDos;
	char operacion;
	float resultado;
	int resultadoFactorialUno;
	int resultadoFactorialDos;
	if(utn_getFloat(&operandoUno,"Ingrese el numero A:\n","El valor ingresado es invalido.\n",2) == 0)
	{
		if(utn_getFloat(&operandoDos,"Ingrese el numero B:\n","El valor ingresado es invalido.\n",2) == 0)
		{
			if(mostrarMenu(&operacion,2,operandoUno, operandoDos) == 0)
			{
				switch(operacion)
				{
					case 'a':
						sumar(&resultado,operandoUno,operandoDos);
						printf("El resultado de A+B es: %.2f.\n", resultado);
						break;
					case 'b':
						restar(&resultado,operandoUno,operandoDos);
						printf("El resultado de A-B es: %.2f.\n", resultado);
						break;
					case 'c':
						multiplicar(&resultado, operandoUno,operandoDos);
						printf("El resultado de A*B es: %.2f.\n", resultado);
						break;
					case 'd':
						if(dividir(&resultado,operandoUno,operandoDos) == 0)
						{
							printf("El resultado de A/B es: %.2f.\n", resultado);
						}
						else
						{
							printf("No se puede dividir por cero.\n");
						}
						break;
					case 'e':
						if(factorial(&resultadoFactorialUno,operandoUno) == 0 && factorial(&resultadoFactorialDos,operandoDos) == 0)
						{
							printf("El factorial de A es: %d y El factorial de B es: %d.\n" , resultadoFactorialUno,resultadoFactorialDos);
						}
						else
						{
							printf("Ninguno de los operandos puede ser menor a 0.\n");
						}
				}
			}
			else
			{
				printf("Hubo problemas para seleccionar la operación");
			}
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
