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
	int flagFirstEmployee = FALSE;
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);
//	employee_createTestEmployeesList(empleados, QTY_EMPLOYEE);
	do
	{
		utn_getInt(&op, MAIN_MENU, ERROR_GENERIC, 1, 5, ATTEMPTS);
		switch(op)
		{
			case 1:
				employee_createEmployee(empleados, QTY_EMPLOYEE, &flagFirstEmployee);
				break;
			case 2:
				employee_modifyEmployee(empleados, QTY_EMPLOYEE, flagFirstEmployee);
				break;
			case 3:
				employee_unsuscribeEmployee(empleados, QTY_EMPLOYEE, &flagFirstEmployee);
				break;
			case 4:
				employee_PrintEmployeesByLastNameAndSector(empleados, QTY_EMPLOYEE, flagFirstEmployee);
				break;
			case 5:
				printf(EXIT_PROGRAM);
				break;
		}
	}
	while(op != 5);
	return EXIT_SUCCESS;
}
