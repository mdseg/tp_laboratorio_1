
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
			list[i].isEmpty = 1;
			}
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
lastName[],float salary,int sector)
{
	int retorno = -1;
	Employee bufferEmployee;
	if( list != NULL && len > 0 &&
		id >= 0 &&
		id < len &&
		list[id].isEmpty == TRUE)
	{
		if(
			utn_getName("\nIngrese el nombre:","\nError",bufferEmployee.name, ATTEMPTS, LONG_NOMBRE) == 0 &&
			utn_getName("\nIngrese el apellido:","\nError",bufferEmployee.lastName, ATTEMPTS, LONG_NOMBRE) == 0 &&
			utn_getFloat("\nIngrese el salario:", "\nError",bufferEmployee.salary, ATTEMPTS) == 0
			)
		{

		}
	}
 return -1;
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
 return -1;
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
 return -1;
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
 return 0;
}
