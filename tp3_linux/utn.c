#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

#define LIMITE_BUFFER_STRING 4096
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define LONG_NAME 50


static int getInt(int* pResultado);
static int utn_myGets(char* array, int length);
static int utn_verifyCharArray(char *pArray);
static int utn_verifyAdjacentSpaces(char pArray[]);
static int utn_lowerCharArray(char pArray[]);
static int utn_verifyLengthArray(char* pArray);
static int utn_verifyCharArrayNoSpaces(char *pArray);
int isValidFileName(char* array);

/**
 * \brief verifica que una cadena de char incluya solo letras mayusculas y minusculas y también espacios.
 * \param pArray* char es el puntero al array donde se hará la búsqueda.
 * \return 0 si Ok o -1 para indicar un error.
 */
static int utn_verifyCharArray(char *pArray)
{
	int retorno = 0;
	int i;
	if (pArray != NULL && pArray[0] != ' ') {
		for (i = 0; pArray[i] != '\0'; i++) {
			if ((pArray[i] < 'a' || pArray[i] > 'z')
					&& (pArray[i] < 'A' || pArray[i] > 'Z') && (pArray[i] != 32)){
				retorno = -1;
				break;
			}
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
 * \brief verifica que una cadena de char incluya solo letras mayusculas y minusculas y también espacios.
 * \param pArray* char es el puntero al array donde se hará la búsqueda.
 * \return 0 si Ok o -1 para indicar un error.
 */
static int utn_verifyCharArrayNoSpaces(char *pArray)
{
	int retorno = 0;
	int i;
	if (pArray != NULL && pArray[0] != ' ') {
		for (i = 0; pArray[i] != '\0'; i++) {
			if ((pArray[i] < 'a' || pArray[i] > 'z')
					&& (pArray[i] < 'A' || pArray[i] > 'Z')){
				retorno = -1;
				break;
			}
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
* \brief ​ Recorre una cadena de char buscando que no haya espacios adyacentes en la misma.
* \​param​ ​ pArray[]​ char​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
static int utn_verifyAdjacentSpaces(char pArray[])
{
	int retorno = 0;
	int i = 0;
	int flagSpace = FALSE;
	if(pArray != NULL && pArray[0] != ' ')
	{

		for(i=0 ; pArray[i] != '\0'; i++)
		{
			if(pArray[i] == ' ')
			{
				if(flagSpace == FALSE)
				{
					flagSpace = TRUE;
				}
				else
				{
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}
/**
* \brief ​ Recorre una cadena buscando que no haya mas de un punto.
* \​param​ ​ pArray[]​ char​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si no hay mas de un punto.
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_countPointsArray(char pArray[])
{
	int retorno = -1;
	int i = 0;
	int countPoint = 0;
	if(pArray != NULL)
	{

		for(i=0 ; pArray[i] != '\0'; i++)
		{
			if(pArray[i] == '.')
			{
				countPoint++;
			}
		}
		if(countPoint < 2)
		{
			retorno = 0;
		}
	}
	return retorno;
}
/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ es​ un numero del tipo float
* \​param​ string char*​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ vardadero​ ) ​ si​ ​ la​ ​ cadena​ ​ es​ ​ float​ y 0 (​ falso​ ) ​ si​ no ​ lo​ ​ es
*/
int isFloat(char string[])
{
	int retorno = 1;
	int i = 0;

	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}

		for( ; string[i] != '\0' ; i++)
		{
			if((string[i] > '9' || string[i] < '0') && string[i] != '.')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief Lee ​ de​ ​ stdin​ ​ hasta​ ​ que​ ​ encuentra​ ​ un​ '\n' o ​ hasta​ ​ que​ ​ haya​ ​ copiado​ ​ en​ ​ cadena
*  un​ ​ máximo​ ​ de​ '​ longitud​ - 1' ​ caracteres​ .
* \​param​ array char*​ Puntero​ ​ al​ ​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ copiara​ ​ la​ ​ cadena​ ​ obtenida
* \​param​ length Define el ​ tamaño​ ​ de​ ​ cadena
* \return ​ Retorna​ 0 (EXITO) ​ si​ ​ se​ ​ obtiene​ ​ una​ ​ cadena​ y -1 (ERROR) ​ si​ no
*/
static int utn_myGets(char* array, int length)
{
	int retorno=-1;
	__fpurge(stdin);// fflush o __fpurge
	if(array != NULL && length >0 && fgets(array,length,stdin)==array && array[0] != '\n')
	{
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
* \​ param​ pResultado *int​ Puntero​ ​ al​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ dejara​ el ​ resultado​ ​ de​ ​ la​ ​ funcion
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
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ es​ta compuesta por​ numeros del tipo int
* \​param​ ​ array char*​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ vardadero​ ) ​ si​ ​ la​ ​ cadena​ ​ es​ ​ numerica​ y 0 (​ falso​ ) ​ si​ no ​ lo​ ​ es
*/
int utn_verifyNumArray(char* array)
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
 * \brief Verifica una cadena como parametros para determinar si es un nombre valido
 * \param array char* Cadena a analizar
 * \param limit int indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (!0) INdica que es un nombre valido
 * */
int utn_isValidName(char* array, int limit)
{
	int respuesta = 1;
	int i;
	int flagSpace = FALSE;

	for (i=0;array[i] != '\0';i++)
	{
		if((array[i] < 'a' || array[i] > 'z') &&
		   (array[i] < 'A' || array[i] > 'Z') &&
			array[i] != ' ' && array[i] != '-')
		{
			respuesta = 0;
		}
		else
		{
			if(array[i] == ' ')
			{
				if(flagSpace == FALSE)
				{
					flagSpace = TRUE;
				}
				else
				{
					respuesta = 0;
				}
			}
			else if (((array[i] >= 'a' && array[i] <= 'z') ||
					(array[i] >= 'A' && array[i] <= 'Z')) ||
					(array[i] == '-'))
			{
				if(flagSpace == TRUE)
				{
					flagSpace = FALSE;
				}
			}
		}
	}


	return respuesta;
}
/**
* \brief Solicita un entero al usuario
* \param pResultado int* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param mensaje char* Es el mensaje a ser mostrado al usuario.
* \param mensajeError char* Es el mensaje de error a ser mostrado al usuario.
* \param minimo int valor minimo admitido
* \param maximo int valor maximo admitido
* \param reintentos int cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
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
/**
* \brief Solicita un entero al usuario
* \param pResultado int* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param mensaje char* Es el mensaje a ser mostrado al usuario.
* \param mensajeError char* Es el mensaje de error a ser mostrado al usuario.
* \param minimo int valor minimo admitido
* \param maximo int valor maximo admitido
* \param reintentos int cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
int utn_getCharInt(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(utn_myGets(bufferString, LIMITE_BUFFER_STRING) == 0 && utn_verifyNumArray(bufferString) == 1 )
			{
				strcpy(pResultado, bufferString);
				retorno = 0;
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
/**
* \brief Solicita un entero al usuario
* \param pResultado int* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param mensaje char* Es el mensaje a ser mostrado al usuario.
* \param mensajeError char* Es el mensaje de error a ser mostrado al usuario.
* \param minimo int valor minimo admitido
* \param maximo int valor maximo admitido
* \param reintentos int cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
int utn_getCharFloat(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(utn_myGets(bufferString, LIMITE_BUFFER_STRING) == 0 && isFloat(bufferString) == 1 && utn_countPointsArray(bufferString) == 0)
			{
				strcpy(pResultado, bufferString);
				retorno = 0;
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

/**
* \brief Solicita un entero al usuario
* \param message char* Es el mensaje a ser mostrado al usuario.
* \param errorMessage char* Es el mensaje de error a ser mostrado al usuario.
** \param pResult int puntero al espacio de memoria donde se dejará el valor obtenido.
* \param attempts int cantidad de oportunidades para ingresar el dato
* \param min int valor minimo admitido
* \param max int valor maximo admitido

* \return (-1) Error / (0) Ok
 */
int utn_getFloat(char message[], char errorMessage[], float *pResult, int attemps, int minimo, int maximo)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];
	float bufferFloat;

	if(message != NULL && errorMessage != NULL && pResult != NULL && attemps >= 0 && minimo <= maximo)
	{
		do
		{
			printf("%s", message);
			if(utn_myGets(bufferString, LIMITE_BUFFER_STRING) == 0 && isFloat(bufferString) == 1 && utn_countPointsArray(bufferString) == 0)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= minimo && bufferFloat<= maximo)
				{
					*pResult = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", errorMessage);
					attemps--;
				}
			}
			else
			{
				printf("%s", errorMessage);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return retorno;
}
/* \ brief get_char para pedirle al usuario que ingrese un caracter
 * \ param message char* es un puntero al espacio de memoria donde está el mensaje que verá el usuario
 * \ param userInput char* es el puntero al espacio de memoria donde se guarda el caracter que ingresa el usuario
 * \ param errorMessage char* es el puntero al espacio de memoria donde está el mensaje de error que se mostrará si el usario ingresa una opción incorrecta
 * \ param attempts int  es la variable que decrementa en 1 cada vez que el usario comete un error al ingresar un caracter no válido
 * \return (-1) Error / (0) Ok
 */
int utn_get_char(char *message, char *userInput, char errorMessage,int attempts)
{
	int retorno = -1;
	char userData[LIMITE_BUFFER_STRING];

	if (message != NULL && userInput != NULL)
	{
		do
		{
			printf("%s\n", message);
			if (utn_myGets(userData, LIMITE_BUFFER_STRING) == 0
					&& utn_verifyCharArray(userData) == 1)
			{
				strcpy(userInput, userData);
				retorno = 0;
				break;
			}
			else
			{
				attempts--;
				if (attempts != 0)
				{
					printf("Error, te quedan %d intentos.\n", attempts);
				}
			}
		} while (attempts > 0);
	}
	return retorno;
}
/**
* \brief Solicita un nombre al usuario y lo valida.
* \param message char* Es el mensaje a ser mostrado al usuario.
* \param mensajeError char* Es el mensaje de error a ser mostrado al usuario.
* \param pResultado char* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param minimo int valor minimo admitido
* \param maximo int valor maximo admitido
* \param reintentos int cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
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
/**
 * \brief Buscar el valor máximo existente en un array de enteros.
 * \param pArray int es el puntero al array donde se hará la busqueda.
 * \param pResultado int es el puntero donde se almacena el valor máximo encontrado en el array
 * \param size int Es la longitud del array.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_getMaximoArrayInt(int *pArray, int *pResultado, int size)
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
/**
 * \brief Buscar el valor mínimo existente en un array de enteros.
 * \param pArray int es el puntero al array donde se hará la busqueda.
 * \param pResultado int es el puntero donde se almacena el valor mínimo encontrado en el array
 * \param size int Es la longitud del array.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_getMinimoArrayInt(int *pArray, int *pResultado, int size)
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
/**
 * \brief realiza el promedio en un array de numeros enteros.
 * \param array[] int es el puntero al array donde se hará la busqueda.
 * \param pResultado float es el puntero donde se almacena el valor del promedio de todos los elementos del array.
 * \param size int Es la longitud del array.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_promedioArray(int array[], float* pResultado, int size)
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
 * \param pArray int es el puntero al array a ser ordenado.
 * \pram size int Es la longitud del array.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_printArrayInt(int* pArray, int limite)
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
 * \brief ordena un array de enteros ASC
 * \param pArray int es el puntero al array a ser ordenado.
 * \pram size int Es la longitud del array.
 * \param order int 1 ordena de forma ascendente y 0 de forma descendente
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_ordenarArrayInt(int* pArray, int limite, int order)
{
	int flagSwap;
	int i;
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
				if((order == UP && pArray[i] > pArray[i+1])
					||
				    (order == DOWN && pArray[i] < pArray[i+1])
					)
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
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief realiza un conteo sobre las veces que aparece un valor deseado en un Array
 * \param pArray int es el puntero al array donde se hará la búsqueda.
 * \param valorBuscado int es el numero entero a buscar.
 * \param limite int es la longitud del array.
 * \param pContador int es un puntero que almacena la cantidad de veces que aparece el valor buscado.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_contadorArray(int* pArray, int limite, int valorBuscado, int* pContador)
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
/**
 * \brief realiza un conteo sobre las veces que aparece un valor char deseado en un Array
 * \param pArray char es el puntero al array donde se hará la búsqueda.
 * \param valorBuscado char es el numero entero a buscar.
 * \param pContador int es un puntero que almacena la cantidad de veces que aparece el valor buscado.
 * \return 0 si Ok o -1 para indicar un error.
 */
int utn_contadorArrayChar(char* pArray, char valorBuscado, int* pContador)
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
/**
* \brief ​ Verifica​ ​ si​ ​ la​ ​ cadena​ ​ ingresada​ ​ del tipo char cuenta con el primer caracter como mayuscula y el resto de los caracteres en minuscula
* \​param​ ​pArray char*​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
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
* \​param​ pArray char*​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_upperFirstCharArray(char pArray[])
{
	int retorno = 0;
	int i;
	int flagSpace = FALSE;
	if(pArray != NULL && utn_verifyCharArray(pArray) == 0 &&
		utn_verifyAdjacentSpaces(pArray) == 0)
	{
		utn_lowerCharArray(pArray);
		pArray[0] = toupper(pArray[0]);
		for(i = 1; pArray[i] != '\0';i++)
		{
			if(pArray[i] == ' ')
			{
				flagSpace = TRUE;
			}
			else
			{
				if(flagSpace == TRUE)
				{
					pArray[i] = toupper(pArray[i]);
					flagSpace = FALSE;
				}
			}
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
* \brief ​ Convierte la primer letra de una cadena alfabetica en mayuscula y el resto en minusculas.
* \​param​ pArray char*​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_upperOnlyFirstCharArray(char pArray[])
{
	int retorno = 0;
	if(pArray != NULL && utn_verifyCharArrayNoSpaces(pArray) == 0)
	{
		pArray[0] = toupper(pArray[0]);
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
* \brief ​ Convierte la primer letra de una cadena alfabetica en mayuscula y el resto en minusculas.
* \​param​ pArray char*​ ​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_lowerOnlyFirstCharArray(char pArray[])
{
	int retorno = 0;
	if(pArray != NULL && utn_verifyCharArrayNoSpaces(pArray) == 0)
	{
		pArray[0] = tolower(pArray[0]);
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
* \brief ​ Convierte los caracteres alfabéticos de una cadena de char en minuscula.
* \​param​ ​ pArray[]​ char​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 0 (​ vardadero​ ) ​ si pudo realizarse la operacion
*  Devuelve -1 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_lowerCharArray(char pArray[])
{
	int retorno = -1;
	char bufferChar;
	int i = 0;
	if(pArray != NULL && utn_verifyCharArray(pArray) == 0 )
	{

		for(i=0 ; pArray[i] != '\0'; i++)
		{
			if(pArray[i] >= 'A' && pArray[i] <= 'Z')
			{
				bufferChar = pArray[i]+32;
				pArray[i] = bufferChar;
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
* \brief ​ Valida si la cadena ingresada es un cuit valido
* \​param​ ​ pArray[]​ char​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ verdadero​ ) ​ si se comprobó ser un cuit valido
*  Devuelve 0 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int utn_isValidCuit(char* array)
{
	int retorno = 0;

	if(array != NULL && utn_verifyNumArray(array) == 1 && utn_verifyLengthArray(array) == 11)
	{
		if(array[0] == '2')
		{
			if(array[1] == '0' || array[1] == '7')
			{
				retorno = 1;
			}
		}
		else if (array[0] == '3')
		{
			if(array[1] == '0' && array[1] == '3' && array[1] == '4')
			{
				retorno = 1;
			}

		}
	}

	return retorno;
}
/**
* \brief ​ Valida la cantidad de caracteres de un Array
* \​param​ ​ pArray[]​ char*​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ la cantidad de caracteres de la cadena si pudo calcularse
*  Devuelve -1(​ falso​ ) ​ si el array es nulo.
*/
static int utn_verifyLengthArray(char* pArray)
{
	int retorno = -1;
	int i;
	if (pArray != NULL)
	{
		for(i=0 ; pArray[i] != '\0'; i++)
		{

		}
		retorno = i;
	}


	return retorno;
}
/**
* \brief Solicita un CUIT al usuario y lo valida.
* \param mensaje char* Es el mensaje a ser mostrado al usuario.
* \param mensajeError char* Es el mensaje de error a ser mostrado al usuario.
* \param pResultado char* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param minimo int valor minimo admitido
* \param maximo int valor maximo admitido
* \param reintentos int cantidad de oportunidades para ingresar el dato
* \return (-1) Error / (0) Ok
 */
int utn_getCuit(char* message, char* errorMessage, char* pResult, int attemps, int limit)
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
				utn_isValidCuit(bufferString) != 0)
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
/**
* \brief ​ Valida si una cadena es un nombre de archivo valido
* \​param​ ​array​ char*​ Cadena​ ​ de​ ​ caracteres​ a ​ ser​ ​ analizada
* \return ​ Retorna​ 1 (​ verdadero​ ) ​ si se comprobó ser un nombre de arhivo valido
*  Devuelve 0 (​ falso​ ) ​ si​ no se cumplieron estas condiciones.
*/
int isValidFileName(char* array)
{
	int retorno = 1;
	int i;
	int j;
	for (i=0;array[i] != '\0';i++)
		{
			if((array[i] < 'a' || array[i] > 'z') &&
			   (array[i] < 'A' || array[i] > 'Z') &&
			   (array[i] < '0' || array[i] > '9') &&
				array[i] != ' ')
			{
				retorno = 0;
				break;
			}
			else
			{
				if(array[i] == '.')
				{
					j= i;
					for(;j < (j+2);j++)
					{
						if((array[j] < 'a' || array[j] > 'z') &&
						(array[j] < 'A' || array[j] > 'Z'))
						{
							retorno = 0;
							break;
						}
					}
				}
			}
		}
	return retorno;
}
/**
* \brief Solicita un String al usuario y lo valida.
* \param message char* Es el mensaje a ser mostrado al usuario.
* \param errorMessage char* Es el mensaje de error a ser mostrado al usuario.
* \param pResult char* puntero al espacio de memoria donde se dejará el valor obtenido.
* \param attempts int cantidad de oportunidades para ingresar el dato
* \param limit int la longitud del array permitida
* \return (-1) Error / (0) Ok
 */
int utn_getString(char* message, char* errorMessage, char* pResult, int attemps, int limit)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];
	if ( message != NULL && errorMessage != NULL && pResult != NULL && attemps >= 0 && limit >0)
	{
		do
		{
			printf("%s",message);
			if(utn_myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<=limit)
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


