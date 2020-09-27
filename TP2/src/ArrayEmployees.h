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
#define QTY_EMPLOYEE 10
#define ATTEMPTS 5
#define SECTOR_MIN 1
#define SECTOR_MAX 10
#define SALARY_MIN 1000
#define SALARY_MAX 100000
#define ID_MAX 1000
#define ID_MIN 0
#define MENU_FIRST "\nMenu inicial, para proseguir es necesario dar de alta el primer usuario:\n1-Alta \n2-Salir"
#define MENU_SECOND "\nElija una de estas opciones:\n1-Alta\n2-Actualizar\n3-Dar de baja Empleado\n4-Informe\n5-Salir"
#define MENU_MODIFY "\nSeleccione el campo a modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Volver al menú principal"
#define ERROR_GENERIC "\nError"
#define UP 1
#define DOWN 0
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
int employee_calculateAverageSalary(Employee* list, int len, float *pAvg, int *pSavg, float *acmulatorSalary);
static int generateNewId(void);
#endif /* ARRAYEMPLOYEES_H_ */
