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
	int scanId;
	int flagFirstUser = TRUE;
	int flagExit = FALSE;
	float resultAvg;
	int resultCountAvg;
	float acumulatorSalary;
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);

	employee_addEmployee(empleados, QTY_EMPLOYEE, 4, "Lionel", "Zoriano", 1800, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 2, "Marianela", "Hernandez", 2500, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 3, "Jorge", "Sampahumoli", 4000, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 7, "Dario", "Benitez", 4000, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 8, "Oscar", "Ruggeri", 4000, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 9, "Daniel", "Soldado", 4000, 2);
	/*
	do
	{
		utn_getInt(&op, MENU_FIRST, ERROR_GENERIC, 1, 2, ATTEMPTS);
		switch(op)
		{
			case 1:
				if(employee_uploadEmployee(empleados, QTY_EMPLOYEE, TRUE) == 0)
				{
					printf(CREATE_EMPLOYEE_SUCCESS);
					flagFirstUser = TRUE;
					flagExit = TRUE;
				}
				else
				{
					printf(CREATE_EMPLOYEE_ERROR);
				}
				break;
			case 2:
				printf("Saliendo de la aplicación...");
				flagExit = TRUE;
				break;
		}
	}
	while(flagExit == FALSE);
	*/
	if(flagFirstUser == TRUE)
	{
		do
		{
			utn_getInt(&op, MENU_SECOND, ERROR_GENERIC, 1, 8, ATTEMPTS);
			switch(op)
			{
				case 1:
					if(employee_uploadEmployee(empleados, QTY_EMPLOYEE, TRUE) == 0)
					{
						printf(CREATE_EMPLOYEE_SUCCESS);
					}
					else
					{
						printf(CREATE_EMPLOYEE_ERROR);
					}
					break;
				case 2:
					if(employee_uploadEmployee(empleados, QTY_EMPLOYEE, FALSE) == 0)
					{
						printf(MODIFY_EMPLOYEE_SUCCESS);
					}
					else
					{
						printf(MODIFY_EMPLOYEE_ERROR);
					}
					break;
				case 3:
					if(utn_getInt(&scanId, INPUT_ID, ERROR_GENERIC, ID_MIN, ID_MAX, ATTEMPTS) == 0 &&
						employee_removeEmployee(empleados, QTY_EMPLOYEE, scanId) == 0	)
					{
						printf(DELETE_EMPLOYEE_SUCCESS);
					}
					else
					{
						printf(DELETE_EMPLOYEE_ERROR);
					}
					break;
				case 4:
					if(employee_sortEmployees(empleados, QTY_EMPLOYEE, UP) == 0 &&
					   employee_printEmployees(empleados, QTY_EMPLOYEE) == 0 &&
					   employee_calculateAverageSalary(empleados, QTY_EMPLOYEE, &resultAvg, &resultCountAvg,&acumulatorSalary) == 0)
					{
						printf(REPORT_EMPLOYEES_SUCCESS,acumulatorSalary,resultAvg,resultCountAvg);
					}
					else
					{
						printf(REPORT_EMPLOYEES_ERROR);
					}
					break;
				case 5:
					printf("Saliendo de la aplicación...");
					break;
			}
		}
		while(op != 5);
	}
	return EXIT_SUCCESS;
}

