#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

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
int factorial(int* pResultado, float operando)
{
	int retorno = -1;
	if (pResultado != NULL && operando >= 0)
	{
		if (operando == 0)
		{
			*pResultado = 1;
		}
		else
		{
			int contador;
			int acumuladorFactorial = 1;
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

