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
	int flagFirstUser = FALSE;
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);

	/*employee_addEmployee(empleados, QTY_EMPLOYEE, 4, "Lionel", "Zoriano", 1800, 1, 4);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 2, "Marianela", "Hernandez", 2500, 2, 2);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 3, "Jorge", "Sampahumoli", 4000, 2, 3);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 1, "Dario", "Benitez", 4000, 2, 1);
	employee_addEmployee(empleados, QTY_EMPLOYEE, 0, "Alvaro", "Elena", 4000, 2, 0);
	*/
	do
	{
		utn_getInt(&op, MENU_FIRST, ERROR_GENERIC, 1, 2, ATTEMPTS);
		switch(op)
		{
			case 1:
				if(employee_uploadEmployee(empleados, QTY_EMPLOYEE, TRUE) == 0)
				{
					printf("Empleado cargado correctamente.\n");
					flagFirstUser = TRUE;
					op = 2;
				}
				else
				{
					printf("Error en la carga del empleado.\n");
				}
				break;
		}
	}
	while(op != 2);
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
						printf("Empleado cargado correctamente.\n");
					}
					else
					{
						printf("Error en la carga del empleado.\n");
					}
					break;
				case 2:
					if(employee_uploadEmployee(empleados, QTY_EMPLOYEE, FALSE) == 0)
					{
						printf("Empleado modificado correctamente.\n");
					}
					else
					{
						printf("Error en la modificación del empleado.\n");
					}
					break;
				case 3:
					if(utn_getInt(&scanId, "Ingrese el Id del empleado:\n", "Error.\n", ID_MIN, ID_MAX, 2) == 0)
					{
						if(employee_removeEmployee(empleados, QTY_EMPLOYEE, scanId) == 0)
						{
							printf("Empleado eliminado con éxito");
						}
						else
						{
							printf("No existe un empleado con ese ID");
						}
					}
					break;
				case 4:
					if(employee_sortEmployees(empleados, QTY_EMPLOYEE, 0) == 0)
					{
						printf("Orden realizado correctamente");
					}
					else
					{
						printf("Error al ordenar");
					}
					break;
				case 5:
					if(employee_sortEmployees(empleados, QTY_EMPLOYEE, 1) == 0)
					{
						printf("Orden realizado correctamente");
					}
					else
					{
						printf("Error al ordenar");
					}
					break;
				case 6:
					if(employee_printEmployees(empleados, QTY_EMPLOYEE) != 0)
					{
						printf("No hay registros cargados.\n");
					}
					break;
				case 7:
					if(utn_getInt(&scanId, "Ingrese el Id del empleado:\n", "Error.\n", ID_MIN, ID_MAX, 2) == 0)
					{
						if(employee_findEmployeeById(empleados, QTY_EMPLOYEE, scanId) != 0)
						{
							printf("No hay registros cargados.\n");
						}
					}
					break;
				}
		}
		while(op != 10);

	}

	return EXIT_SUCCESS;
}
