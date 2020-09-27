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
#define QTY_EMPLOYEE 5
#define ATTEMPTS 5
#define SECTOR_MIN 1
#define SECTOR_MAX 10
#define SALARY_MIN 1000
#define SALARY_MAX 100000
#define ID_MAX 1000
#define ID_MIN 0
#define MENU_FIRST "\n1-Alta \n2-Salir"
#define MENU_SECOND "\n1-Alta\n2-Actualizar\n3-Dar de baja Empleado\n4-Ordenar empleados de forma descendente\n5-Ordenar empleados de forma ascendente\n6-Imprimir todos\n7-Imprimir Empleado por Id\n10-Salir"
#define ERROR_GENERIC "\nError"
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int employee_addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int index); //Hecho
int employee_findEmployeeById(Employee* list, int len,int id); //Hecho
int employee_initEmployees(Employee* list, int len); //Hecho
int employee_printEmployees(Employee* list, int length); //Hecho
int employee_removeEmployee(Employee* list, int len, int id); //Hecho
int employee_uploadEmployee(Employee* list, int len, int new);
int employee_searchIndexFree(Employee* list,int* pIndex, int len);
int employee_sortEmployees(Employee* list, int len, int order);
static int generateNewId(void);
#endif /* ARRAYEMPLOYEES_H_ */
