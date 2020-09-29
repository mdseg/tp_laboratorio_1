/*
 * ArrayEmployees.h
 *
 *  Created on: 24 sep. 2020
 *      Author: marcos
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME 50
#define QTY_EMPLOYEE 1000
#define ATTEMPTS 5
#define SECTOR_MIN 1
#define SECTOR_MAX 100
#define SALARY_MIN 1
#define SALARY_MAX 10000000
#define ID_MAX 1000
#define ID_MIN 0
#define MAIN_MENU "\nElija una de estas opciones:\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR"
#define MENU_MODIFY "\nSeleccione el campo a modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Volver al menú principal"
#define EXIT_PROGRAM "\nSaliendo de la aplicación..."
#define ERROR_GENERIC "\nError"
#define CREATE_EMPLOYEE_SUCCESS "Empleado creado con éxito.\n"
#define CREATE_EMPLOYEE_ERROR "Error en la carga del empleado.\n"
#define MODIFY_EMPLOYEE_ERROR "Error en la modificación del empleado.\n"
#define MODIFY_EMPLOYEE_SUCCESS "Empleado modificado correctamente.\n"
#define DELETE_EMPLOYEE_ERROR "No existe un empleado con ese ID.\n"
#define DELETE_EMPLOYEE_SUCCESS "Empleado dado de baja correctamente.\n"
#define REPORT_EMPLOYEES_SUCCESS "El salario total es: %.2f.\nEl salario promedio es: %.2f.\nEl número de empleados que supera el promedio es: %d"
#define REPORT_EMPLOYEES_ERROR "Error al realizar el informe.\n"
#define PRINT_ONE_EMPLOYEE "ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n"
#define UP 1
#define DOWN 0
#define INPUT_LASTNAME "Ingrese el apellido:\n"
#define INPUT_NAME "Ingrese el nombre:\n"
#define INPUT_SECTOR "Ingrese el sector (valores permitidos: 1-100):\n"
#define INPUT_ID "Ingrese el Id del empleado:\n"
#define INPUT_SALARY "Ingrese el salario (valores permitidos: 1-1000000):\n"
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int employee_initEmployees(Employee* list, int len);
int employee_modifyEmployee(Employee* list, int len, int flagFirstEmployee);
int employee_unsuscribeEmployee(Employee* list, int len, int flagFirstEmployee);
int employee_createEmployee(Employee* list, int len, int* pflagFirstEmployee);
int employee_PrintEmployeesByLastNameAndSector(Employee* list, int len, int pflagFirstEmployee);
int employee_addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int employee_createTestEmployeesList(Employee* list, int len);

#endif
