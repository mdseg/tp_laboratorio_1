/*
 * utn.h
 *
 *  Created on: 10 sep. 2020
 *      Author: marcos
 */

#ifndef UTN_H_
#define UTN_H_
#define LIMITE_BUFFER_STRING 4096

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(char* mensaje,char* mensajeError,float* pResultado,int minimo,int maximo,int reintentos);
int getCadenaNoNumerica(char* mensaje, char*mensajeError, char* pResultado, int reintentos, int limite);
int utn_getName(char* message, char* errorMessage, char* pResult, int attemps, int limit);
int getMinimoArrayInt(int array[], int *pResultado, int size);
int getMaximoArrayInt(int array[], int *pResultado, int size);
int promedioArray(int array[], float* pResultado, int size);
int ordenarArrayIntAsc(int* pArray, int limite);
int ordenarArrayIntDesc(int* pArray, int limite);
int printArrayInt(int* pArray, int limite);
int contadorArray(int* pArray, int limite, int valorBuscado, int* pContador);
int contadorArrayChar(char* pArray, char valorBuscado, int* pContador);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_verifyUpperFirstCharArray(char *pArray);
int utn_UpperFirstCharArray(char pArray[]);
int utn_isValidName(char* array, int limit);
#endif /* UTN_H_ */
