#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sumar(int* pResultado,int operandoUno, int operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno + operandoDos;
		retorno = 0;
	}
	return retorno;
}
int restar(int* pResultado, int operandoUno, int operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno - operandoDos;
		retorno = 0;
	}
	return retorno;
}
int multiplicar(int* pResultado, int operandoUno, int operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operandoUno * operandoDos;
		retorno = 0;
	}
	return retorno;
}
int dividir(float* pResultado, int operandoUno, int operandoDos)
{
	int retorno = -1;
	if (pResultado != NULL && operandoDos != 0)
	{
		*pResultado = (float)operandoUno / operandoDos;
		retorno = 0;
	}
	return retorno;
}
int factorial(int* pResultado, int operandoUno)
{
	int retorno = -1;
	if (pResultado != NULL && operandoUno > 0)
	{
		int contador;
		int acumuladorFactorial = 1;
		for(contador = 1; contador <= operandoUno;contador++)
		{
			acumuladorFactorial *= contador;
		}
		*pResultado = acumuladorFactorial;
		retorno = 0;
	}
	return retorno;
}
