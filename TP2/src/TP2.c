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
#include <ctype.h>

int main(void) {
	int op;
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);
	// funcion debugger, descomentar si se quiere iniciar el programa con 5 empleados almacenados
	//employee_createDebugEmployeesList(empleados, QTY_EMPLOYEE);
	do
	{
		utn_getInt(&op, MAIN_MENU, MENU_SELECT_ERROR, 1, 5, ATTEMPTS);
		switch(op)
		{
			case 1:
				employee_createEmployee(empleados, QTY_EMPLOYEE);
				break;
			case 2:
				employee_modifyEmployee(empleados, QTY_EMPLOYEE);
				break;
			case 3:
				employee_unsuscribeEmployee(empleados, QTY_EMPLOYEE);
				break;
			case 4:
				employee_createEmployeeReport(empleados, QTY_EMPLOYEE);
				break;
			case 5:
				printf(EXIT_PROGRAM);
				break;
		}
	}
	while(op != 5);
	return EXIT_SUCCESS;
}

