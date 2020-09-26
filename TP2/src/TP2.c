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
	Employee empleados[QTY_EMPLOYEE];
	employee_initEmployees(empleados, QTY_EMPLOYEE);

	employee_addEmployee(empleados, QTY_EMPLOYEE, 5, "Lionel", "Scaloni", 1800, 1, 5);

	do
	{
		utn_getInt(&op, "\n1-Alta\n2-Actualizar\n3-Baja\n4-Dar de baja Empleado\n5-Imprimir todos\n6-Imprimir Empleado por Id\n8-Salir", "\nError", 1, 8, 2);
		switch(op)
		{
			case 1:
				if(employee_uploadEmployee(empleados, QTY_EMPLOYEE) == 0)
				{
					printf("Empleado cargado correctamente.\n");
				}
				else
				{
					printf("Error en la carga del empleado.\n");
				}
				break;
			case 5:
				if(employee_printEmployees(empleados, QTY_EMPLOYEE) != 0)
				{
					printf("No hay registros cargados.\n");
				}
				break;
			case 4:
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
			case 6:
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
	while(op != 8);
	return EXIT_SUCCESS;
}
