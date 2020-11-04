#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define LONG_ID 55
#define LONG_NOMBRE 55
#define LONG_HORAS 12
#define LONG_SUELDO 20

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	char idEmpleado[LONG_ID];
	char nombre[LONG_NOMBRE];
	char horasTrabajadas[LONG_HORAS];
	char sueldo[LONG_SUELDO];
	int r;
	int flagEncabezado = 0;

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
				//printf("Lei %s %s %s %s\n",idEmpleado,nombre,horasTrabajadas,sueldo);
				bufferEmployee = employee_newParametros(idEmpleado, nombre,horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, bufferEmployee);
			}
			else
			{
				printf("El archivo esta corrupto");
				break;
			}
		}


	}while(!feof(pFile));
	fclose(pFile);
    return 1;
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
	Employee* newEmployee;
	int idEmpleado;
	char nombre[LONG_NOMBRE];
	int horasTrabajadas;
	float sueldo;
	char horasChar[LONG_HORAS];
	char sueldoChar[LONG_SUELDO];
	char idChar[LONG_ID];
	int flagEncabezado = 0;
	char encabezado[50];
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
				output = 0;
			}

		}while(!feof(pFile));



	}
	return output;

}


int parser_Prueba(char* path)
{
	int output = -1;
	int numero;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile != NULL)
	{

		//fread(encabezado,sizeof(encabezado),1,pFile);
		do
		{
			if (fread(&numero,sizeof(int),1,pFile) == 1 )
			{

				printf("%d",numero);

				output = 0;
			}



		}while(!feof(pFile));
		fclose(pFile);



	}
	return output;

}
