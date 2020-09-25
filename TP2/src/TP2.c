/*
 ============================================================================
 Name        : TP2.c
 Author      : Marcos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"



int main(void) {
	int op;
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);
	do
	{
			utn_getInt(&op, "\n1-Alta\n2-Actualizar\n3-Baja\n4-Dar de baja Empleado\n5-Imprimir todos\n6-Imprimir Empleado por Id\n8-Salir", "\nError", 1, 8, 2);
			switch(op)
			{
			case 1:

				break;
			}
	}
	while(op != 8);
	return EXIT_SUCCESS;
}
