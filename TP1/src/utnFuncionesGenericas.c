#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/**
* \brief Solicita un entero al usuario
* \param int* pResultado, puntero al espacio de memoria donde se dejará el valor obtenido.
* \param char* mensaje, Es el mensaje a ser mostrado al usuario.
* \param char* mensajeError, Es el mensaje de error a ser mostrado al usuario.
* \param int minimo, valor minimo admitido
* \param int maximo, valor maximo admitido
* \param int reintentos, cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno =-1;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		while(reintentos>=0)
		{
			printf("%s",mensaje);
			__fpurge(stdin);  //fflush(stdin);
			resultadoScan = scanf("%d",&bufferInt);

			if(resultadoScan == 1 && bufferInt > minimo && bufferInt < maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}

		}
	}
	return retorno;
}
/**
* \brief Solicita un dato del tipo float al usuario
* \param float* pResultado, puntero al espacio de memoria donde se dejará el valor obtenido.
* \param char* mensaje, Es el mensaje a ser mostrado al usuario.
* \param char* mensajeError, Es el mensaje de error a ser mostrado al usuario.
* \param int reintentos, cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	float bufferFloat;
	int retorno =-1;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		while(reintentos>=0)
		{
			printf("%s",mensaje);
			__fpurge(stdin);  //fflush(stdin);
			resultadoScan = scanf("%f",&bufferFloat);

			if(resultadoScan == 1)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}

		}
	}
	return retorno;
}


