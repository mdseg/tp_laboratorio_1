#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnFuncionesCalculadora.h"
#include "utnFuncionesGenericas.h"

/**
* \brief Realiza la suma entre dos numeros enteros.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la suma de los dos operandos.
* \param float operandoUno es el primer valor que será sumado
* \param float operandoDos es el segundo valor que será sumado.
* \return (-1) Error / (0) Ok
*/
int sumar(float* pResultado,float operandoUno, float operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno + operandoDos;
		retorno = 0;
	}
	return retorno;
}
/**
* \brief Realiza la resta entre dos numeros enteros.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la resta de los dos operandos.
* \param float operandoUno es el primer valor que será restado con el segundo.
* \param float operandoDos es el segundo valor que será restado al primero.
* \return (-1) Error / (0) Ok
*/
int restar(float* pResultado,float operandoUno, float operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno - operandoDos;
		retorno = 0;
	}
	return retorno;
}
/**
* \brief Realiza el producto entre dos numeros enteros.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado del producto de los dos operandos.
* \param float operandoUno es el primer valor a multiplicar
* \param float operandoDos es el segundo valor a multiplicar.
* \return (-1) Error / (0) Ok
*/
int multiplicar(float* pResultado,float operandoUno, float operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno * operandoDos;
		retorno = 0;
	}
	return retorno;
}
/**
* \brief Realiza la división entre dos numeros enteros.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la division de los dos operandos.
* \param float operandoUno es el primer valor que será dividido por el segundo.
* \param float operandoDos es el segundo valor para la división.
* \return (-1) Error / (0) Ok
*/
int dividir(float* pResultado,float operandoUno, float operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL && operandoDos != 0)
	{
		*pResultado = operandoUno / operandoDos;
		retorno = 0;
	}
	return retorno;
}
/**
* \brief Realiza la división entre dos numeros enteros. Si bien recibe datos del tipo float, en este caso la función ignorará el componente decimal
* \param int* pResultado puntero al espacio de memoria donde se dejará el resultado de la función factorial.
* \param float operando es el primer valor que será dividido por el segundo.
* \return (-1) Error / (0) Ok
*/
int  factorial(int* pResultado, float operando)
{
	int retorno = -1;
	int contador;
	int acumuladorFactorial = 1;
	if (pResultado != NULL && operando >= 0)
	{
		if (operando == 0)
		{
			*pResultado = 1;
		}
		else
		{
			for(contador = 1; contador <= operando;contador++)
			{
				acumuladorFactorial *= contador;
			}
			*pResultado = (int)acumuladorFactorial;
		}
		retorno = 0;
	}
	return retorno;
}
/**
* \brief muestra en pantalla las operaciones que serán realizadas cuando se llame a la función realizarOperaciones
* \param float operandoUno es el primer valor.
* \param float operandoDos es el segundo valor.
* \return (-1) Error / (0) Ok
*/
int mostrarOperaciones(float operandoUno, float operandoDos)
{
	int retorno = -1;
	printf("------------------Calculo de operaciones-------------------------------------------------\n");
	printf("Se calculará la suma de %.2f + %.2f\n",operandoUno,operandoDos);
	printf("Se calculará la resta de %.2f - %.2f\n",operandoUno,operandoDos);
	printf("Se calculará la multiplicación de %.2f * %.2f\n",operandoUno,operandoDos);
	printf("Se calculará la división de %.2f / %.2f\n",operandoUno,operandoDos);
	printf("Se calculará el factorial de %.2f y de %.2f\n",operandoUno,operandoDos);
	printf(BANNER_GENERIC);
	retorno = 0;
	return retorno;
}
/**
* \brief realiza las operaciones planteadas en la consigna y las almacena en los punteros correspondientes a cada una de las operaciones.
* \param float operandoUno es el primer valor.
* \param float operandoDos es el segundo valor.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la suma de los dos operandos.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la resta de los dos operandos.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado del producto de los dos operandos.
* \param float* pResultado puntero al espacio de memoria donde se dejará el resultado de la division de los dos operandos.
* \param int* pResultado puntero al espacio de memoria donde se dejará el resultado de la función factorial.
* \return (-1) Error / (0) Ok
*/
int realizarOperaciones(float operandoUno, float operandoDos, float* pResultadoSuma, float* pResultadoResta, float* pResultadoMulti, float* pResultadoDiv, int* pResultadoFactUno, int* pResultadoFactDos)
{
	int retorno = -1;
	if(sumar(pResultadoSuma, operandoUno, operandoDos) == 0 &&
		restar(pResultadoResta, operandoUno, operandoDos) == 0 &&
		multiplicar(pResultadoMulti, operandoUno, operandoDos) == 0
		)
	{
		if (operandoDos != 0)
		{
			dividir(pResultadoDiv, operandoUno, operandoDos);
		}
		if (operandoUno >= 0)
		{
			factorial(pResultadoFactUno, operandoUno);
		}
		if (operandoDos >= 0)
		{
			factorial(pResultadoFactDos, operandoDos);
		}
		retorno = 0;
	}
	return retorno;
}
/**
* \brief imprime las operaciones realizadas en realizarOperaciones y emite los eventuales mensajes de error que pudieran haber acontecido.
* \param float operandoUno es el primer valor.
* \param float operandoDos es el segundo valor.
* \param float resultadoSuma es el resultado de la suma de los dos operandos.
* \param float resultadoResta es el resultado de la resta de los dos operandos.
* \param float resultadoMulti es el resultado del producto de los dos operandos.
* \param float resultadoDiv es el resultado de la division de los dos operandos.
* \param int resultadoFactUno puntero es el resultado de la función factorial del operandoUno.
* \param int resultadoFactUno puntero es el resultado de la función factorial del operandoDos.
* \return (-1) Error / (0) Ok
*/
int imprimirOperaciones(float operandoUno, float operandoDos, float resultadoSuma, float resultadoResta, float resultadoMulti, float resultadoDiv, int resultadoFactUno, int resultadoFactDos)
{
	int retorno = -1;
	printf("-----------------Impresion de operaciones------------------------------------------------\n");
	printf("El resultado de %.2f + %.2f es: %.2f.\n", operandoUno, operandoDos, resultadoSuma);
	printf("El resultado de %.2f - %.2f es: %.2f.\n", operandoUno, operandoDos, resultadoResta);
	printf("El resultado de %.2f * %.2f es: %.2f.\n", operandoUno, operandoDos, resultadoMulti);
	if(operandoDos != 0)
	{
		printf("El resultado de %.2f / %.2f es: %.2f.\n", operandoUno, operandoDos, resultadoDiv);
	}
	else
	{
		printf("No se puede dividir por cero.\n");
	}
	if(operandoUno >= 0)
	{
		printf("El factorial del entero %.0f es: %d.\n",operandoUno,resultadoFactUno);
	}
	else
	{
		printf("No se puede realizar el factorial de %.0f ya que no es un número positivo.\n",operandoUno);
	}
	if(operandoDos >= 0)
	{
		printf("El factorial del entero %.0f es: %d.\n",operandoDos,resultadoFactDos);
	}
	else
	{
		printf("No se puede realizar el factorial de %.0f ya que no es un número positivo.\n",operandoDos);
	}
	printf(BANNER_GENERIC);
	return retorno;
}
/**
* \brief imprime en pantalla el estado de carga y los valores de operandoUno y operandoDos y orienta sobre si se han realizado las operaciones o no.
* \param int flagOperandoUno es una bandera que es TRUE en el caso se que haya completado con éxito la carga del operandoUno previamente
* \param int flagOperandoDos es una bandera que es TRUE en el caso se que haya completado con éxito la carga del operandoDos previamente
* \param int es una bandera que es TRUE si se realizaron la operaciones del punto 3 de la cosigna
* \param float operandoUno es el primer valor.
* \param float operandoDos es el segundo valor.
* \return (-1) Error / (0) Ok
*/
int imprimirEstadosyValores(int flagOperandoUno, int flagOperandoDos, int flagOperacionesRealizadas, float operandoUno, float operandoDos )
{
	int retorno = -1;
	printf("--------------Estado de variables y operaciones------------------------------------------\n");
	if(flagOperandoUno == TRUE)
	{
		printf(PRINT_TABLE_BODY,"   Primer operando", "   El valor del operando es:    ", operandoUno);
	}
	else
	{
		printf(PRINT_TABLE_BODY_ALT,"   Primer operando","   No se ha ingresado aun el primer operando.");
	}
	if(flagOperandoDos == TRUE)
	{
		printf(PRINT_TABLE_BODY,"   Segundo operando", "   El valor del operando es: ", operandoDos);
	}
	else
	{
		printf(PRINT_TABLE_BODY_ALT,"   Primer operando","   No se ha ingresado aun el segundo operando.");
	}
	if(flagOperacionesRealizadas == TRUE)
	{
		printf(PRINT_TABLE_BODY_ALT,"   Estado de operaciones","   Las operaciones han sido realizadas.");
	}
	else
	{
		printf(PRINT_TABLE_BODY_ALT,"   Estado de operaciones","   No se han realizando las operaciones del punto 3.");
	}
	printf(BANNER_GENERIC);
	return retorno;
}

