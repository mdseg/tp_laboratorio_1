#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

#define LIMITE_BUFFER_STRING 4096

static int utn_verifyNumArray(char* array);
static int getInt(int* pResultado);
static int utn_myGets(char* array, int length);
static int utn_isValidName(char* array, int limit);
static int utn_verifyCharArray(char *pArray);
static int getChar(char* pResultado);


/**
* \brief Lee ​ de​ ​ stdin​ ​ hasta​ ​ que​ ​ encuentra​ ​ un​ '\n' o ​ hasta​ ​ que​ ​ haya​ ​ copiado​ ​ en​ ​ cadena
*  un​ ​ máximo​ ​ de​ '​ longitud​ - 1' ​ caracteres​ .
* \​param​ pResultado ​ Puntero​ ​ al​ ​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ copiara​ ​ la​ ​ cadena​ ​ obtenida
* \​param​ ​ longitud​ Define el ​ tamaño​ ​ de​ ​ cadena
* \return ​ Retorna​ 0 (EXITO) ​ si​ ​ se​ ​ obtiene​ ​ una​ ​ cadena​ y -1 (ERROR) ​ si​ no
*/

static int utn_myGets(char* array, int length)
{
	int retorno=-1;
	if(array != NULL && length >0 && fgets(array,length,stdin)==array)
	{
		__fpurge(stdin); // fflush o __fpurge
		if(array[strlen(array)-1] == '\n')
		{
			array[strlen(array)-1] = '\0';
		}
		retorno=0;
	}
	return retorno;
}
/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ingresada​ ​ es​ ​ numerica
* \​ param​ pResultado ​ Puntero​ ​ al​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ dejara​ el ​ resultado​ ​ de​ ​ la​ ​ funcion
* \return ​ Retorna​ 0 (EXITO) ​ si​ se​ ​ obtiene​ ​ un​ ​ numero​ ​ entero​ y -1 (ERROR) ​ si​ no
*/
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if(utn_myGets(buffer,sizeof(buffer)) == 0 && utn_verifyNumArray(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);
		}
	}
	return retorno;
}
/**
 * \brief Verifica una cadena como parametros para determinar si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (!0) INdica que es un nombre valido
 * */
static int utn_isValidName(char* array, int limit)
{
	int respuesta = 1; // TOdo ok
	int i;
	for (i=0;array[i] != '\0';i++)
	{
		if((array[i] < 'a' || array[i] > 'z') &&
		   (array[i] < 'A' || array[i] > 'Z'))
		{
			respuesta = 0;

		}
	}
	return respuesta;

}


/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ es​ ​ numerica
* \​param​ ​ cadena​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ vardadero​ ) ​ si​ ​ la​ ​ cadena​ ​ es​ ​ numerica​ y 0 (​ falso​ ) ​ si​ no ​ lo​ ​ es
*/
static int utn_verifyNumArray(char* array)
{
	int i=0;
	int retorno = 1;
	if(array[0] == '-')
		{
			i = 1;
		}
	if(array != NULL && strlen(array) > 0)
		{
		while(array[i] != '\0')
		{
			if(array[i] < '0' || array[i] > '9' )
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}



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
static int getChar(char* pResultado)
{
	int retorno = -1;
	char buffer[1];

	if (pResultado != NULL)
	{
		if(utn_myGets(buffer,1) == 0)
		{
			retorno = 0;
			*pResultado = atoi(buffer);

		}
	}
	return retorno;
}
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos > 0);
	}
	return retorno;
}
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getChar(pResultado) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos > 0);
	}
	return retorno;
}
int utn_getName(char* message, char* errorMessage, char* pResult, int attemps, int limit)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];
	if ( message != NULL && errorMessage != NULL && pResult != NULL && attemps >= 0 && limit >0)
	{
		do
		{
			printf("%s",message);
			if(utn_myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<=limit &&
				utn_isValidName(bufferString,limit) != 0)
			{
				retorno = 0;
				strncpy(pResult,bufferString,limit);
				break;
			}
			else
			{
				printf("%s",errorMessage);
				attemps--;
			}
		}
		while(attemps > 0);
	}
	return retorno;

}
int getMaximoArrayInt(int *pArray, int *pResultado, int size)
{
	int retorno = -1;
	int maximo;
	int i;
	if(pArray != NULL && pResultado!=NULL && size > 0)
	{
		for(i = 0; i < size;i++)
		{
			if(pArray[i] > maximo || i == 0)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}

int getMinimoArrayInt(int *pArray, int *pResultado, int size)
{
	int retorno = -1;
	int minimo;
	int i;
	if(pArray!= NULL && pResultado!=NULL && size > 0)
	{
		for(i = 0; i < size;i++)
		{
			if(pArray[i] < minimo || i == 0)
			{
				minimo = pArray[i];
			}
		}
		*pResultado = minimo;
		retorno = 0;
	}
	return retorno;
}

int promedioArray(int array[], float* pResultado, int size)
{
	int retorno = -1;
	int i = 0;
	int acumulador = 0;
	if(array != NULL && pResultado != NULL && size > 0)
	{
		for (i = 0;i < size;i++)
		{
			acumulador+= array[i];
		}
		if(i != 0)
		{
			*pResultado = (float)acumulador / i;
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Imprime a modo DEBUG la información de un array de enteros.
 * \param pArray es el puntero al array a ser ordenado.
 * \pram size Es la longitud del array.
 * \return 0 si Ok o -1 para indicar un error.
 */
int printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for (i = 0;i<limite;i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}
/**
 * \brief ordena un array de enteros DESC
 * \param pArray es el puntero al array a ser ordenado.
 * \pram size Es la longitud del array.
 * \return Cantidad de iteraciones necesarias para Ordenar si Ok o -1 para indicar un error.
 */

int ordenarArrayIntDesc(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	int buffer;
	int nuevoLimite;
	if(pArray != NULL && limite >=0)
	{
		nuevoLimite = limite - 1;
		do
		{

			flagSwap=0;
			for(i=0; i<nuevoLimite;i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{

					flagSwap=1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;

				}

			}
			nuevoLimite--;

		}
		while(flagSwap);
		retorno = contador;

	}

	return retorno;
}
int ordenarArrayIntAsc(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador = 0;
	int retorno = -1;
	int buffer;
	int nuevoLimite;
	if(pArray != NULL && limite >=0)
	{
		nuevoLimite = limite - 1;
		do
		{

			flagSwap=0;
			for(i=0; i<nuevoLimite;i++)
			{
				contador++;
				if(pArray[i] > pArray[i+1])
				{

					flagSwap=1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;

				}

			}
			nuevoLimite--;

		}
		while(flagSwap);
		retorno = contador;

	}

	return retorno;
}
int contadorArray(int* pArray, int limite, int valorBuscado, int* pContador)
{
	int contador;
	int retorno = -1;
		int i;
		if(pArray != NULL && limite >= 0)
		{
			retorno = 0;
			for (i = 0;i<limite;i++)
			{
				if(pArray[i] == valorBuscado)
				{
					contador++;
				}
			}
			*pContador = contador;
		}
	return retorno;
}
int contadorArrayChar(char* pArray, char valorBuscado, int* pContador)
{
	int contador;
	int retorno = -1;
		int i;
		if(pArray != NULL)
		{
			retorno = 0;
			for (i = 0; pArray[i] != '\0';i++)
			{
				if(pArray[i] == valorBuscado)
				{
					contador++;
				}
			}
			*pContador = contador;
		}
	return retorno;
}
int getCadenaNoNumerica(char* mensaje, char*mensajeError, char* pResultado, int reintentos, int limite)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];
	if ( mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite >0)
	{
		do
		{
			printf("%s",mensaje);
			if(utn_myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<=limite &&
				utn_isValidName(bufferString,limite) != 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}
		while(reintentos > 0);
	}
	return retorno;

}
static int utn_verifyCharArray(char *pArray)
{
	int retorno = 0;
	int i;
	if (pArray != NULL) {
		for (i = 0; pArray[i] != '\0'; i++) {
			if ((pArray[i] < 'a' || pArray[i] > 'z')
					&& (pArray[i] < 'A' || pArray[i] > 'Z') && (pArray[i] != 32)){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ del tipo char cuenta con el primer caracter como mayuscula y el resto de los caracteres en minuscula
* \​param​ ​ cadena​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si​ ​ la​ ​ cadena​ ​ es​ un char
*  con una mayuscula  en la posicion [0] y minusculas en el resto de las posiciones.
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_verifyUpperFirstCharArray(char *pArray)
{
	int retorno = 0;
	int i;
	if(pArray != NULL)
	{
		if(pArray[0] >= 'A' && pArray[0] <= 'Z' )
		{
			for (i = 1; pArray[i] != '\0'; i++) {
				if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] != 32))
				{
					retorno = -1;
					break;
				}
			}
		}
	}
	return retorno;
}
/**
* \brief ​ Convierte la primer letra de una cadena alfabetica en mayuscula y el resto en minusculas.
* \​param​ ​ cadena​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_UpperFirstCharArray(char pArray[])
{
	int retorno = 0;
		int i;
		if(pArray != NULL && utn_verifyCharArray(pArray) == 0)
		{

			if(pArray[0] < 'A' || pArray[0] > 'Z' )
			{
				pArray[0] = toupper(pArray[0]);
			}
			for (i = 1; pArray[i] != '\0'; i++) {
				if ((pArray[i] >= 'A' && pArray[i] <= 'Z'))
				{
					pArray[i] = tolower(pArray[i]);

				}
			}
		}
		else
		{
			retorno = -1;
		}
		return retorno;
}
