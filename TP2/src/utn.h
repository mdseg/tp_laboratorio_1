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
int utn_getFloat(char message[], char errorMessage[], float *pResult, int attemps, int minimo, int maximo);
int utn_getName(char* message, char* errorMessage, char* pResult, int attemps, int limit);
int utn_getMinimoArrayInt(int array[], int *pResultado, int size);
int utn_getMaximoArrayInt(int array[], int *pResultado, int size);
int utn_promedioArray(int array[], float* pResultado, int size);
int utn_ordenarArrayIntAsc(int* pArray, int limite);
int utn_ordenarArrayIntDesc(int* pArray, int limite);
int utn_printArrayInt(int* pArray, int limite);
int utn_contadorArray(int* pArray, int limite, int valorBuscado, int* pContador);
int utn_contadorArrayChar(char* pArray, char valorBuscado, int* pContador);
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_verifyUpperFirstCharArray(char *pArray);
int utn_upperFirstCharArray(char pArray[]);
int utn_isValidName(char* array, int limit);
#endif
