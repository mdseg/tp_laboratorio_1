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

int mostrarMenu(char *pOperacionElegida, int reintentos, float operandoUno, float operandoDos);

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
/**
* \brief despliega un menu en pantalla con las opciones sobre las operaciones matemáticas y solicita al usuario elegir una.
* \param char* pOperacionElegida puntero al espacio de memoria donde se dejará el valor con el char de la operacion elegida.
* \param int reintentos, cantidad de oportunidades para ingresar el dato
* \param int operandoUno, primer valor ingresado para ser mostrado en pantalla.
* \param int operandoDos, segundo valor ingresado para ser mostrado en pantalla.
* \return (-1) Error / (0) Ok
*/
int mostrarMenu(char *pOperacionElegida, int reintentos, float operandoUno, float operandoDos)
{
	int retorno = -1;
	char operacionIngresada;
	int resultadoIngreso;
	if(pOperacionElegida != NULL && reintentos >=0)
	{
		printf("A = %.2f, B = %.2f\n",operandoUno,operandoDos);
		do{
			printf("Por favor, seleccione la operación a realizar escribiendo la letra correspondiente:\na-Sumar\nb-Restar\nc-Multiplicar\nd-Dividir\ne-Factorial\n");
			__fpurge(stdin);
			resultadoIngreso = scanf("%c", &operacionIngresada);
			if(resultadoIngreso == 1)
			{
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
					default:
						printf("Error en el ingreso.\n");
						reintentos--;
						if(reintentos >0)
						{
							printf("Vuelva a intentarlo.\n");
						}
				}
				if(retorno == 0)
				{
					break;
				}
			}
		}
		while(reintentos > 0);
	}
	return retorno;
}
