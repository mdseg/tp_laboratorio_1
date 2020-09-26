
#include "utn.h"
#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int employee_initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
		if(list != NULL && len > 0)
		{
			for(i = 0;i<len;i++)
			{
			list[i].id = -1;
			list[i].isEmpty = 1;
			}
			retorno = 0;
		}
		return retorno;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int employee_addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector,int index)
{

	int retorno=0;
    list[index].id=id;
    utn_UpperFirstCharArray(name);
    utn_UpperFirstCharArray(lastName);
    strcpy(list[index].name,name);
    strcpy(list[index].lastName,lastName);
    list[index].salary=salary;
    list[index].sector=sector;
    list[index].isEmpty = FALSE;
    return retorno;



}
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int employee_findEmployeeById(Employee* list, int len,int id)
{
	int i = 0;
	int retorno = -1;
		if(list != NULL && len > 0 && id > 0)
		{
			for ( i = 0; i < len; i++)
			{
				if(list[i].id == id)
				{

					retorno = i;
				}
			}
		}
	return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int employee_removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int bufferIndex = employee_findEmployeeById(list, len, id);
	Employee bufferEmployee;
	if( list != NULL && len > 0 &&
		id > 0 && bufferIndex != -1
		&& list[bufferIndex].isEmpty == FALSE)
	{
		bufferEmployee.isEmpty = TRUE;
		list[id] = bufferEmployee;
		retorno = 0;
	}
	return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int employee_printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i;
	int flagResults = FALSE;
	if (list != NULL && length > 0)
	{
		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(flagResults == FALSE)
				{
					flagResults = TRUE;
					retorno = 0;
				}
				printf("ID: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
 return retorno;
}
static int generateNewId(void)
{
	static int id= ID_MIN; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}
int employee_uploadEmployee(Employee* list, int len, int new)
{

	int retorno = -1;
	int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int index;
    if(employee_searchIndexFree(list, &index, len) == 0 &&
    	utn_getName("\nIngrese el nombre:","\nError",name, ATTEMPTS, LONG_NAME) == 0 &&
    	utn_getName("\nIngrese el apellido:","\nError",lastName, ATTEMPTS, LONG_NAME) == 0 &&
    	utn_getFloat("\nIngrese el salario:","\nError",&salary,SALARY_MIN,SALARY_MAX,ATTEMPTS) == 0 &&
    	utn_getInt(&sector, "\nIngrese el sector:", "\nError", SECTOR_MIN, SECTOR_MAX, ATTEMPTS) == 0
		)
    {
    	id = generateNewId();
    	employee_addEmployee(list, len, id, name, lastName, salary, sector, index);
    	retorno = 0;
    }
	return retorno;


}
int employee_searchIndexFree(Employee* list,int* pIndex, int len)
{
	int retorno = -1;
		int i;
			if(list != NULL && len > 0)
			{
				for(i = 0;i<len;i++)
				{
					if(list[i].isEmpty == 1)
					{
						*pIndex = i;
						retorno = 0;
						break;

					}
				}
			}
		return retorno;
}
