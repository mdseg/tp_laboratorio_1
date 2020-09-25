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
#define LONG_NOMBRE 50
#define QTY_EMPLOYEE 100
#define ATTEMPTS 5
#define SECTOR_MIN 1
#define SECTOR_MAX 10
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int employee_addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int employee_findEmployeeById(Employee* list, int len,int id);
int employee_initEmployees(Employee* list, int len);
int employee_printEmployees(Employee* list, int length);
int employee_removeEmployee(Employee* list, int len, int id);
#endif /* ARRAYEMPLOYEES_H_ */
