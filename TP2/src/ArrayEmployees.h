/*
 * ArrayEmployees.h
 *
 *  Created on: 24 sep. 2020
 *      Author: marcos
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
// Valores precompilación
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
#define UP 1
#define DOWN 0

#define MAIN_MENU "\n-------Sistema de Registro de Empleados----------\nElija una de estas opciones:\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n"
#define MENU_MODIFY "-------Menu de modificación----------\nSeleccione el campo a modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Volver al menú principal\n"
#define MENU_REPORT "-------Menu de reporte----------\nSeleccione el tipo de informe que desea:\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n3-Volver al menú principal\n"
#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"
#define EXIT_PROGRAM "Saliendo de la aplicación...\n"
#define ERROR_GENERIC "Error\n"
#define PRINT_ONE_EMPLOYEE "ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n"
//Create
#define CREATE_EMPLOYEE_SUCCESS "\nEmpleado creado con éxito.\n"
#define DELETE_EMPLOYEE_ERROR "No existe un empleado con ese ID.\n"
#define DELETE_EMPLOYEE_SUCCESS "\nEmpleado dado de baja correctamente.\n"
#define REPORT_EMPLOYEES_SUCCESS "El salario total es: %.2f.\nEl salario promedio es: %.2f.\nEl número de empleados que supera el promedio es: %d.\n"
#define REPORT_EMPLOYEES_ERROR "\nError al realizar el informe.\n"
#define CREATE_EMPLOYEE_ERROR "\nError en la carga del empleado.\n"
#define REPORT_EMPLOYEES_SUCCESS_FINISH "----Finalizado el informe----\n"
//Modifiy
#define MODIFY_EMPLOYEE_SUCCESS "\nEmpleado modificado correctamente.\n"
#define MODIFY_EMPLOYEE_ERROR "\nError en la modificación del empleado.\n"
#define MODIFY_NAME_SUCCESS "Nombre modificado con éxito.\n"
#define MODIFY_NAME_ERROR "Error al intentar modificar el nombre.\n"
#define MODIFY_LASTNAME_SUCCESS "Apellido modificado con éxito.\n"
#define MODIFY_LASTNAME_ERROR "Error al intentar modificar el apellido.\n"
#define MODIFY_SALARY_SUCCESS "Salario modificado con éxito.\n"
#define MODIFY_SALARY_ERROR "Error al intentar modificar el salario.\n"
#define MODIFY_SECTOR_SUCCESS "Sector modificado con éxito.\n"
#define MODIFY_SECTOR_ERROR "Error al intentar modificar el sector.\n"
//Input
#define INPUT_LASTNAME "Ingrese el apellido:\n"
#define INPUT_NAME "Ingrese el nombre:\n"
#define INPUT_SECTOR "Ingrese el sector (valores permitidos: 1-100):\n"
#define INPUT_ID "Ingrese el Id del empleado:\n"
#define INPUT_SALARY "Ingrese el salario (valores permitidos: 1-1000000):\n"
//Acceso
#define ENTERING_CREATE_EMPLOYEE "Ingresando al sector de altas...\n"
#define ENTERING_MODIFY_EMPLOYEE "Ingresando al sector de modificaciones...\n"
#define ENTERING_REMOVE_EMPLOYEE "Ingresando al sector de bajas...\n"
#define ERROR_NOT_AVAILABLE "Debe ingresar al menos un usuario para utilizar esta funcionalidad.\n"

#define MENU_ORDER "Seleccione el orden alfabético del informe:\n1-Ascendente\n2-Descendente\n"

struct
{
 int id;
 char name[LONG_NAME];
 char lastName[LONG_NAME];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int employee_createDebugEmployeesList(Employee* list, int len);
int employee_createEmployee(Employee* list, int len);
int employee_createEmployeeReport(Employee* list, int len);
int employee_initEmployees(Employee* list, int len);
int employee_modifyEmployee(Employee* list, int len);
int employee_unsuscribeEmployee(Employee* list, int len);

#endif
