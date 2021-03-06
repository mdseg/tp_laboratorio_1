#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define LONG_ID 55
#define LONG_NOMBRE 55
#define LONG_HORAS 12
#define LONG_SUELDO 20
#define READ_ERROR "Error al leer el archivo"
#define TRUE 1
#define FALSE 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* bufferEmployee;
	char idEmpleado[LONG_ID];
	char nombre[LONG_NOMBRE];
	char horasTrabajadas[LONG_HORAS];
	char sueldo[LONG_SUELDO];
	int r;
	int flagEncabezado = FALSE;
	int flagErrores = FALSE;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idEmpleado,nombre,horasTrabajadas,sueldo);
			if (flagEncabezado == 0)
			{
				flagEncabezado = 1;
			}
			else
			{
				if(r==4)
				{
					bufferEmployee = employee_newParametros(idEmpleado, nombre,horasTrabajadas, sueldo);
					ll_add(pArrayListEmployee, bufferEmployee);
				}
				else
				{
					employee_delete(bufferEmployee);
					flagErrores = TRUE;
					break;
				}
			}


		}while(!feof(pFile));
		if(flagErrores == FALSE)
		{
			output = 0;
		}
	}
    return output;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int output = -1;
	Employee* bufferEmployee;
	int retornoLectura;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			bufferEmployee = employee_new();
			if(bufferEmployee != NULL)
			{
				retornoLectura = fread(bufferEmployee,sizeof(Employee),1,pFile);
				if(retornoLectura == 1)
				{
					ll_add(pArrayListEmployee, bufferEmployee);
				}
				else
				{
					employee_delete(bufferEmployee);
					break;
				}
			}
		}while(!feof(pFile));
		output = 0;
	}
	return output;
}

