#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"


int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id);

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
	int output = -1;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_LIST_TEXT);
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile == NULL)
	{
		printf(CONTROLLER_LOAD_LIST_NO_FILE);
	}
	else
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		printf(CONTROLLER_LOAD_LIST_TEXT_SUCCESS);
		output = 0;
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
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_LIST_TEXT);
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile == NULL)
	{
		printf(CONTROLLER_LOAD_LIST_NO_FILE);
	}
	else
	{
		if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
		{

			printf(CONTROLLER_LOAD_LIST_TEXT_SUCCESS);
			output = 0;
		}
		fclose(pFile);

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

	if(utn_getName(INPUT_NAME, INPUT_NAME_ERROR, name, ATTEMPTS, LONG_NAME) == 0 &&
			utn_getCharInt(horasTrabajadas, INPUT_HOUR, INPUT_HOUR_ERROR, HOUR_MIN, HOUR_MAX, ATTEMPTS) == 0 &&
			utn_getCharFloat(sueldo, INPUT_SALARY, INPUT_SALARY_ERROR, SALARY_MIN, HOUR_MAX, ATTEMPTS) == 0)

	{
		sprintf(id, "%d",controller_getFreeIndex(pArrayListEmployee));
		bufferEmpleado = employee_newParametros(id, name, horasTrabajadas, sueldo);
		ll_add(pArrayListEmployee, bufferEmpleado);
		printf(CREATE_EMPLOYEE_SUCCESS);
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
	printf(ENTERING_MODIFY_EMPLOYEE);
	if(utn_getInt(&id, INPUT_ID, INPUT_ID_ERROR, 1, 2000, ATTEMPTS) == 0)
	    	{
	    		index = controller_findEmployeeById(pArrayListEmployee, id);

	    		if(index != -1)
	    		{
	    			bufferEmployee = ll_get(pArrayListEmployee, index);
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
	printf(ENTERING_REMOVE_EMPLOYEE);
	if(ll_len(pArrayListEmployee) > 0 && utn_getInt(&id, INPUT_ID, INPUT_ID_ERROR, 1, 2000, ATTEMPTS) == 0)
	{
		index = controller_findEmployeeById(pArrayListEmployee, id);
		bufferEmployee = ll_get(pArrayListEmployee, index);
		if (index != -1 && bufferEmployee != NULL)
		{
			if(employee_printOneEmployee(bufferEmployee) == 0 &&
				utn_getInt(&op, DELETE_EMPLOYEE_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
			{
				ll_pop(pArrayListEmployee, index);
				employee_delete(ll_get(pArrayListEmployee, index));
				printf(DELETE_EMPLOYEE_SUCCESS);
				output = 0;
			}
			else
			{
				printf(DELETE_EMPLOYEE_CANCEL);
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
				printf(PRINT_ONE_REGISTRY,employee_getId(bufferEmpleado),employee_getNombre(bufferEmpleado),
						employee_getHorasTrabajadas(bufferEmpleado), employee_getSueldo(bufferEmpleado));
			i++;
		}
		while(i != len);
		printf(PRINT_ONE_REGISTRY_BOTTOM);
		output = 0;
	}
    return output;
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
	int output = -1;
	if(pArrayListEmployee != NULL)
	{
		ll_sort(pArrayListEmployee,employee_compareByName,1);
		output = 0;
	}
	return output;
	/*
	int output = -1;
	int len = ll_len(pArrayListEmployee);
	Employee* bufferFirstEmployee;
	Employee* bufferSecondEmployee;
	int r;
	int i;
	if (pArrayListEmployee != NULL)
	{
		for(i = 0;i < len;i++)
		{
			bufferFirstEmployee = ll_get(pArrayListEmployee, i);
			bufferSecondEmployee = ll_get(pArrayListEmployee,i+1);
			r = ll_sort(pArrayListEmployee, employee_sortEmployesByName, 1);
		}
		output = 0;

	}
    return output;
    */
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
	if(pFile != NULL)
	{
		printf("Archivo creado o abierto con éxito.");
		len = ll_len(pArrayListEmployee);
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for (i = 0; i < len;i++)
		{
			bufferEmployee = ll_get(pArrayListEmployee, i);
			fprintf(pFile,"%d,%s,%d,%f.2\n",employee_getId(bufferEmployee),employee_getNombre(bufferEmployee),employee_getHorasTrabajadas(bufferEmployee),employee_getSueldo(bufferEmployee));
		}
		fclose(pFile);
		output = 0;
	}
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
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			output = 0;
			for (int i = 0; i < len;i++)
			{
				pEmpleado = ll_get(pArrayListEmployee, i);
				fwrite(pEmpleado,sizeof(Employee),1,pFile);
				printf("%s\n",pEmpleado->nombre);
			}

		}
		fclose(pFile);

	}
	return output;

	/*
	int output = -1;
	int len;
	int i = 0;
	char encabezado[100];
	Employee* bufferEmployee;
	FILE* pFile;
	int bufferId;
	int bufferHorasTrabajadas;
	char bufferName[LONG_NAME];
	float bufferSalary;
	pFile = fopen(path,"wb");
	if(pFile != NULL)
	{
		//strcpy(encabezado,"id,nombre,horasTrabajadas,sueldo\n");
		//printf("Archivo creado o abierto con éxito.");
		len = ll_len(pArrayListEmployee);
		//fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		//fwrite(encabezado,sizeof(encabezado),1,pFile);
		for (i = 0; i < len;i++)
		{

			bufferEmployee = ll_get(pArrayListEmployee, i);
			fwrite(&bufferEmployee,sizeof(Employee),1,pFile);

			bufferId = employee_getId(bufferEmployee);
			strcpy(bufferName, employee_getNombre(bufferEmployee));
			bufferHorasTrabajadas = employee_getHorasTrabajadas(bufferEmployee);
			bufferSalary = employee_getSueldo(bufferEmployee);
			fwrite(&bufferId,sizeof(int),1,pFile);
			fwrite(bufferName,LONG_NAME,1,pFile);
			fwrite(&bufferHorasTrabajadas,sizeof(int),1,pFile);
			fwrite(&bufferSalary,sizeof(float),1,pFile);

			//fprintf(pFile,"%d,%s,%d,%d\n",employee_getId(bufferEmployee),employee_getNombre(bufferEmployee),employee_getHorasTrabajadas(bufferEmployee),employee_getSueldo(bufferEmployee));
		}
		fclose(pFile);
		output = 0;
	}

    return output;
    */
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

int controller_saveBinaryPrueba(char* path)
{
	int retorno = -1;
	FILE* pFile;
	int prueba = 8;

	pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			//strcpy(encabezado,"id,nombre,horasTrabajadas,sueldo\n");
			//printf("Archivo creado o abierto con éxito.");
			//fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
			//fwrite(encabezado,sizeof(encabezado),1,pFile);
			fwrite(&prueba,sizeof(int),1,pFile);
				//fprintf(pFile,"%d,%s,%d,%d\n",employee_getId(bufferEmployee),employee_getNombre(bufferEmployee),employee_getHorasTrabajadas(bufferEmployee),employee_getSueldo(bufferEmployee));
			fclose(pFile);
			retorno = 0;
		}

	return retorno;
}



