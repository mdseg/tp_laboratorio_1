#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_getFreeIndex(LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	else
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
	}

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	char name[LONG_NAME];
	char horasTrabajadas[LONG_HORAS];
	char sueldo[LONG_SUELDO];
	char id[LONG_ID];

	if(utn_getName(INPUT_NAME, INPUT_NAME_ERROR, name, ATTEMPTS, LONG_NAME) == 0 &&
			utn_getCharInt(name, INPUT_HOUR, INPUT_HOUR_ERROR, HOUR_MIN, HOUR_MAX, ATTEMPTS) == 0 &&
			utn_getCharInt(sueldo, INPUT_SALARY, INPUT_SALARY_ERROR, SALARY_MIN, HOUR_MAX, ATTEMPTS) == 0)

	{
		id = (char*)controller_getFreeIndex(pArrayListEmployee);
		strcpy(id,controller_getFreeIndex(pArrayListEmployee));
		employee_newParametros(id, name, horasTrabajadas, sueldo);
	}
    return output;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int len = ll_len(pArrayListEmployee);
	int i = 0;
	Employee* bufferEmpleado;
	printf(PRINT_ONE_REGISTRY_TOP);
	do{
		bufferEmpleado = ll_get(pArrayListEmployee, i);
			printf(PRINT_ONE_REGISTRY,employee_getId(bufferEmpleado),employee_getNombre(bufferEmpleado),
					employee_getHorasTrabajadas(bufferEmpleado), employee_getSueldo(bufferEmpleado));
		i++;
	}
	while(i != len);

	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
int controller_getFreeIndex(LinkedList* pArrayListEmployee)
{
	int output = -1;
	int len;
	Employee* bufferEmpleado;
	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		bufferEmpleado = ll_get(pArrayListEmployee, (len-1));
		output = employee_getId(bufferEmpleado) + 1;
	}

	return output;
}

