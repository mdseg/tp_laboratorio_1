/*
 * utnFunciones.h
 *
 *  Created on: 6 sep. 2020
 *      Author: marcos
 */

#ifndef UTNFUNCIONESCALCULADORA_H_
#define UTNFUNCIONESCALCULADORA_H_

#define PRINT_TABLE_BODY "%-32s|%-32s%-32.2f\n"
#define PRINT_TABLE_BODY_ALT "%-32s|%-68s\n"
#define BANNER_GENERIC "-----------------------------------------------------------------------------------------\n"
#define TRUE 1
#define FALSE 0

int sumar(float* pResultado, float operandoUno, float operandoDos);
int restar(float* pResultado, float operandoUno, float operandoDos);
int multiplicar(float* pResultado, float operandoUno, float operandoDos);
int dividir(float* pResultado, float operandoUno, float operandoDos);
int factorial(int* pResultado, float operando);
int mostrarMenu(char *pOperacionElegida, int reintentos, float operandoUno, float operandoDos);
int mostrarOperaciones(float operandoUno, float operandoDos);
int realizarOperaciones(float operandoUno, float operandoDos, float* pResultadoSuma, float* pResultadoResta, float* pResultadoMulti, float* pResultadoDiv, int* pResultadoFactUno, int* pResultadoFactDos);
int imprimirOperaciones(float operandoUno, float operandoDos, float resultadoSuma, float resultadoResta, float resultadoMulti, float resultadoDiv, int resultadoFactUno, int resultadoFactDos);
int imprimirEstadosyValores(int flagOperandoUno, int flagOperandoDos, int flagOperacionesRealizadas, float operandoUno, float operandoDos );
#endif /* UTNFUNCIONESCALCULADORA_H_ */
