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
	employee_addEmployee(empleados, QTY_EMPLOYEE, 4, "Lionel", "Zoriano", 1800, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 2, "Marianela", "Hernandez", 2500, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 3, "Jorge", "Sampahumoli", 4000, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 7, "Dario", "Soldado", 4000, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 8, "Oscar", "Ruggeri", 4000, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 9, "Daniel", "Sendra", 4000, 2);
	do
	{
		utn_getInt(&op, MAIN_MENU, ERROR_GENERIC, 1, 5, ATTEMPTS);
		switch(op)
		{
			case 1:
				employee_createEmployee(empleados, QTY_EMPLOYEE, &flagFirstEmployee);
				break;
			case 2:
				employee_publicModifyEmployee(empleados, QTY_EMPLOYEE, flagFirstEmployee);
				break;
			case 3:
				employee_unsuscribeEmployee(empleados, QTY_EMPLOYEE, flagFirstEmployee);
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
