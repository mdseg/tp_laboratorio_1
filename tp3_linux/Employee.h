#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define LONG_ID 55
#define LONG_NAME 55
#define LONG_HORAS 12
#define LONG_SUELDO 20
#define ATTEMPTS 5

#define HOUR_MIN 0
#define HOUR_MAX 1000
#define SALARY_MIN 1
#define SALARY_MAX 1000000

#define PRINT_ONE_REGISTRY "|%-4d |%-24s| %-24d| %-24d |\n"
#define PRINT_ONE_REGISTRY_TOP "--ID-------Nombre------------------Horas trabajadas--------------Sueldo--------------\n"
#define PRINT_ONE_REGISTRY_BOTTOM "-------------------------------------------------------------------------------------\n"

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
#define INPUT_NAME "Ingrese el nombre:\n"
#define INPUT_NAME_ERROR "Por favor, ingrese un nombre válido.\n"
#define INPUT_ID "Ingrese el Id del empleado:\n"
#define INPUT_ID_ERROR "Por favor, ingrese un id válido.\n"
#define INPUT_SALARY "Ingrese el salario:\n"
#define INPUT_SALARY_ERROR "Por favor, ingrese un salario válido.\n"
#define INPUT_HOUR "Ingrese la cantidad de horas trabajadas:\n"
#define INPUT_HOUR_ERROR "Por favor, ingrese una cantidad de horas trabajadas válidas.\n"
//Acceso
#define ENTERING_CREATE_EMPLOYEE "Ingresando al sector de altas...\n"
#define ENTERING_MODIFY_EMPLOYEE "Ingresando al sector de modificaciones...\n"
#define ENTERING_REMOVE_EMPLOYEE "Ingresando al sector de bajas...\n"
#define ERROR_NOT_AVAILABLE "Debe ingresar al menos un usuario para utilizar esta funcionalidad.\n"


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

int isValidId(int id);
int isValidNombre(char* nombre);
int isValidHorasTrabajadas(int horasTrabajadas);
int isValidSueldo(int sueldo);

#endif // employee_H_INCLUDED
