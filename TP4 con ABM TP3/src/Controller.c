#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int output = -1;
	FILE* pFile;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_LIST_TEXT);
	ll_clear(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile == NULL)
		{
			printf(CONTROLLER_LOAD_LIST_NO_FILE);
		}
		else if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{
			printf(CONTROLLER_LOAD_LIST_TEXT_SUCCESS);
			output = 0;
		}
		fclose(pFile);
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
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
	int output = -1;
	FILE* pFile;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_LIST_BINARY);
	ll_clear(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		if(pFile == NULL)
		{
			printf(CONTROLLER_LOAD_LIST_NO_FILE);
		}
		else if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
		{
			printf(CONTROLLER_LOAD_LIST_BINARY_SUCCESS);
			output = 0;
		}
		fclose(pFile);
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	return output;
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
	Employee* bufferEmpleado;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_CREATE_EMPLOYEE);

	if(utn_getName(INPUT_NAME, INPUT_NAME_ERROR, name, ATTEMPTS, LONG_NAME) == 0 &&
			utn_getCharInt(horasTrabajadas, INPUT_HOUR, INPUT_HOUR_ERROR, HOUR_MIN, HOUR_MAX, ATTEMPTS) == 0 &&
			utn_getCharFloat(sueldo, INPUT_SALARY, INPUT_SALARY_ERROR, SALARY_MIN, SALARY_MAX, ATTEMPTS) == 0)
	{
		sprintf(id, "%d",controller_getNewId(pArrayListEmployee));
		bufferEmpleado = employee_newParametros(id, name, horasTrabajadas, sueldo);
		ll_add(pArrayListEmployee, bufferEmpleado);
		printf(CREATE_EMPLOYEE_SUCCESS);
		employee_printOneEmployee(bufferEmpleado);
		printf(PRINT_ONE_REGISTRY_BOTTOM);
		output = 0;
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
	int output = -1;
	char name[LONG_NAME];
	int hours;
	float salary;
	int id;
	int index;
	int op;
	int flagCarga = FALSE;
	Employee* bufferEmployee;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_MODIFY_EMPLOYEE);
	if(pArrayListEmployee != NULL)
	{
		if(utn_getInt(&id, INPUT_ID, INPUT_ID_ERROR, 1, 2000, ATTEMPTS) == 0)
		{
			index = controller_findEmployeeById(pArrayListEmployee, id);

			if(index != -1)
			{
				bufferEmployee = ll_get(pArrayListEmployee, index);
				employee_printOneEmployee(bufferEmployee);
				do
				{
					utn_getInt(&op, MENU_MODIFY, MENU_SELECT_ERROR, 1, 4, ATTEMPTS);
					switch (op)
					{
						case 1:
							if(utn_getName(INPUT_NAME,INPUT_NAME_ERROR,name, ATTEMPTS, LONG_NAME) == 0)
							{
								employee_setNombre(bufferEmployee, name);
								flagCarga = TRUE;
								printf(MODIFY_NAME_SUCCESS);
							}
							else
							{
								printf(MODIFY_NAME_ERROR);
							}
							break;
						case 2:
							if(utn_getInt(&hours, INPUT_HOUR, INPUT_HOUR_ERROR, HOUR_MIN, HOUR_MAX, ATTEMPTS) == 0)
							{
								employee_setHorasTrabajadas(bufferEmployee, hours);
								flagCarga = TRUE;
								printf(MODIFY_HOUR_SUCCESS);
							}
							else
							{
								printf(MODIFY_HOUR_ERROR);
							}
							break;
						case 3:
							if(utn_getFloat(INPUT_SALARY, INPUT_SALARY_ERROR, &salary, ATTEMPTS, SALARY_MIN, SALARY_MAX) == 0)
							{
								employee_setSueldo(bufferEmployee, salary);
								flagCarga = TRUE;
								printf(MODIFY_SALARY_SUCCESS);
							}
							else
							{
								printf(MODIFY_SALARY_ERROR);
							}
							break;
						}
				}
				while(op != 4);
				if(flagCarga == TRUE)
				{
					ll_set(pArrayListEmployee, index, bufferEmployee);
					printf(MODIFY_EMPLOYEE_SUCCESS);
					output = 0;
				}
			}
		}
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
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
	int output = -1;
	int id;
	int index;
	int op;
	Employee* bufferEmployee;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_REMOVE_EMPLOYEE);
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(ll_len(pArrayListEmployee) > 0 && utn_getInt(&id, INPUT_ID, INPUT_ID_ERROR, 1, 2000, ATTEMPTS) == 0)
	{
		index = controller_findEmployeeById(pArrayListEmployee, id);
		bufferEmployee = ll_get(pArrayListEmployee, index);
		if (index != -1 && bufferEmployee != NULL)
		{
			if(employee_printOneEmployee(bufferEmployee) == 0 &&
				utn_getInt(&op, DELETE_EMPLOYEE_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
			{
				if(op == 1)
				{
					ll_remove(pArrayListEmployee, index);
					employee_delete(bufferEmployee);
					printf(DELETE_EMPLOYEE_SUCCESS);
				}
				else
				{
					printf(DELETE_EMPLOYEE_CANCEL);
				}
				output = 0;
			}
		}
		else
		{
			printf(DELETE_EMPLOYEE_ERROR);
		}

	}
	else
	{
		printf(ERROR_GENERIC);
	}
	return output;
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
	int output = -1;
	int len = ll_len(pArrayListEmployee);
	int i = 0;
	Employee* bufferEmpleado;
	printf(ENTERING_LIST_EMPLOYEE);
	if(pArrayListEmployee != NULL && len > 0)
	{
		printf(PRINT_ONE_REGISTRY_TOP);
		do{
			bufferEmpleado = ll_get(pArrayListEmployee, i);
			if(pArrayListEmployee != NULL)
			{
				printf(PRINT_ONE_REGISTRY,employee_getId(bufferEmpleado),employee_getNombre(bufferEmpleado),
								employee_getHorasTrabajadas(bufferEmpleado), employee_getSueldo(bufferEmpleado));

			}
			i++;
		}
		while(i != len);
		printf(PRINT_ONE_REGISTRY_BOTTOM);
		output = 0;
	}
    return output;
}

/** \brief muestra un menu para que el usuario seleccione por que campo y en que orden desea ordenar la lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int output = -1;
	int op;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_SORT_EMPLOYEE);
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(pArrayListEmployee != NULL)
	{
		do
		{
			utn_getInt(&op, CONTROLLER_SORT_MENU, MENU_SELECT_ERROR, 1, 9, ATTEMPTS);
			switch(op)
			{
				case 1:
					ll_sort(pArrayListEmployee,employee_compareById,1);
					output = 0;
					break;
				case 2:
					ll_sort(pArrayListEmployee,employee_compareById,0);
					output = 0;
					break;
				case 3:
					ll_sort(pArrayListEmployee,employee_compareByName,1);
					output = 0;
					break;
				case 4:
					ll_sort(pArrayListEmployee,employee_compareByName,0);
					output = 0;
					break;
				case 5:
					ll_sort(pArrayListEmployee,employee_compareByHours,1);
					output = 0;
					break;
				case 6:
					ll_sort(pArrayListEmployee,employee_compareByHours,0);
					output = 0;
					break;
				case 7:
					ll_sort(pArrayListEmployee,employee_compareBySalary,1);
					output = 0;
					break;
				case 8:
					ll_sort(pArrayListEmployee,employee_compareBySalary,0);
					output = 0;
					break;
			}
		}
		while(op != 9);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	return output;

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
	int output = -1;
	int len;
	int i = 0;
	Employee* bufferEmployee;
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(pFile != NULL)
		{

			len = ll_len(pArrayListEmployee);
			fprintf(pFile,CONTROLLER_CSV_TOP);
			for (i = 0; i < len;i++)
			{
				bufferEmployee = ll_get(pArrayListEmployee, i);
				fprintf(pFile,"%d,%s,%d,%f.2\n",employee_getId(bufferEmployee),employee_getNombre(bufferEmployee),employee_getHorasTrabajadas(bufferEmployee),employee_getSueldo(bufferEmployee));
			}
			fclose(pFile);
			printf(CONTROLLER_CREATE_SUCCESS);
			output = 0;
		}
		else
		{
			printf(CONTROLLER_SAVE_BINARY_PATH_ERROR);
		}
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
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
	FILE* pFile;
	int output = -1;
	int len = ll_len(pArrayListEmployee);
	Employee* pEmpleado;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayListEmployee != NULL && len > 0)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			for (int i = 0; i < len;i++)
			{
				pEmpleado = ll_get(pArrayListEmployee, i);
				fwrite(pEmpleado,sizeof(Employee),1,pFile);
			}
			output = 0;
			printf(CONTROLLER_CREATE_SUCCESS);
			fclose(pFile);
		}
	}
	else
	{
		printf(CONTROLLER_SAVE_TEXT_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	return output;
}

/** \brief Busca un nuevo Id disponible en una lista enlazada de empleados y lo devuelve por valor.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_getNewId(LinkedList* pArrayListEmployee)
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
/** \brief Busca un nuevo dato del tipo Empleado en una lista enlazada tomando como parametro el id retornando el valor por referencias.
 *
 * \param pArrayListEmployee LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	int output = -1;
	int len;
	int i;
	Employee* bufferEmpleado;
	if (pArrayListEmployee != NULL && isValidId(id) == 1)
	{
		len = ll_len(pArrayListEmployee);
		for(i = 0; i < len; i++)
		{
			bufferEmpleado = ll_get(pArrayListEmployee, i);
			if(employee_getId(bufferEmpleado) == id)
			{
				output = i;
			}
		}
	}
	return output;
}
int controller_filterById(LinkedList* pArrayListEmployee)
{
	int output = -1;
	if (ll_filter(pArrayListEmployee, employee_filterBySalary) == 0)
	{
		printf("ok");
	}

	return output;
}
int controller_sumAllSalaries(LinkedList* pArrayListEmployee)
{
	int output = -1;
	float salarios;
	ll_reduceFloat(pArrayListEmployee, employee_sumAllSalaries, &salarios);
	if (salarios >= 0)
	{
		//salarios = salarios / 1000;
		printf("La suma de todos los salarios es: %.2f", salarios);
	}

	return output;
}
int controller_countEmployees(LinkedList* pArrayListEmployee)
{
	int output = -1;
	int conteo = 0;
	ll_reduceInt(pArrayListEmployee, employee_countEmployees, &conteo);
	if (conteo >= 0)
	{
		//salarios = salarios / 1000;
		printf("La suma de todos los salarios es: %d", conteo);
	}

	return output;
}

