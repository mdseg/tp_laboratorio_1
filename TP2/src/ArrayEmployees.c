
#include "utn.h"
#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int generateNewId(void);
static int employee_modifyEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector,int index);
static int employee_searchIndexFree(Employee* list,int* pIndex, int len);
static int employee_findEmployeeById(Employee* list, int len,int id);
static int employee_printEmployees(Employee* list, int length);
static int employee_removeEmployee(Employee* list, int len, int id);
static int employee_loadEmployee(Employee* list, int len, int new);
static int employee_sortEmployees(Employee* list, int len, int order);
static int employee_calculateAverageSalary(Employee* list, int len, float *pAvg, int *pSavg, float *acmulatorSalary);


static void send_errorMessage(int flagFirstEmployee,char* mainError)
{
	if(flagFirstEmployee == TRUE)
	{
		printf("%s",mainError);
	}
	else
	{
		printf("Debe cargar al menos un registro para poder acceder a esta funcionalidad.");
	}
}

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
			list[i].isEmpty = TRUE;
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
lastName[],float salary,int sector)
{

	int retorno=0;
	int index;
	if(employee_searchIndexFree(list, &index, len) == 0)
	{
		list[index].id=id;
	    utn_UpperFirstCharArray(name);
	    utn_UpperFirstCharArray(lastName);
	    strcpy(list[index].name,name);
	    strcpy(list[index].lastName,lastName);
	    list[index].salary=salary;
	    list[index].sector=sector;
	    list[index].isEmpty = FALSE;
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
static int employee_modifyEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector, int index)
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
static int employee_findEmployeeById(Employee* list, int len,int id)
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
static int employee_removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int bufferIndex = employee_findEmployeeById(list, len, id);
	if( list != NULL && len > 0 &&
		id > 0 && bufferIndex != -1
		&& list[bufferIndex].isEmpty == FALSE)
	{
		list[bufferIndex].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return retorno
 *
 */
static int employee_printEmployees(Employee* list, int length)
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
				printf(PRINT_ONE_EMPLOYEE,list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
 return retorno;
}
/*
 * \brief generates a new id for a new user
 * \return id int the current id after it is generated by the function
 */
static int generateNewId(void)
{
	static int id= ID_MIN; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}
/** \brief requests data from the user to create or modify an Employee record
*
* \param list Employee*
* \param len int
* \param new If it's true it means that a new employee is entered. If it's false it means that an existing employee will be modified
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
static int employee_loadEmployee(Employee* list, int len, int new)
{

	int retorno = -1;
	int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int index;
    int op;
    if (new == TRUE)
    {
    	if(employee_searchIndexFree(list, &index, len) == 0 &&
    	    	utn_getName(INPUT_NAME,ERROR_GENERIC,name, ATTEMPTS, LONG_NAME) == 0 &&
    	    	utn_getName(INPUT_LASTNAME,ERROR_GENERIC,lastName, ATTEMPTS, LONG_NAME) == 0 &&
    	    	utn_getFloat(INPUT_SALARY,ERROR_GENERIC,&salary,SALARY_MIN,SALARY_MAX,ATTEMPTS) == 0 &&
    	    	utn_getInt(&sector, INPUT_SECTOR,ERROR_GENERIC, SECTOR_MIN, SECTOR_MAX, ATTEMPTS) == 0
    			)
    	    {
    	    	id = generateNewId();
    	    	employee_addEmployee(list, len, id, name, lastName, salary, sector);
    	    	retorno = 0;
    	    }
    }
    else
    {
    	if(utn_getInt(&id, INPUT_ID, ERROR_GENERIC, ID_MIN, ID_MAX, 2) == 0)
    	{
    		index = employee_findEmployeeById(list, QTY_EMPLOYEE, id);
    		if(index != -1)
    		{
    			Employee bufferEmployee = list[index];
    			int flagCarga = FALSE;
    			do
    			{
        			utn_getInt(&op, MENU_MODIFY, ERROR_GENERIC, 1, 5, ATTEMPTS);
    				switch (op)
					{
						case 1:
							if(utn_getName(INPUT_NAME,ERROR_GENERIC,name, ATTEMPTS, LONG_NAME) == 0)
							{
								strcpy(bufferEmployee.name,name);
								flagCarga = TRUE;
							}
							break;
						case 2:
							if(utn_getName(INPUT_NAME,ERROR_GENERIC,name, ATTEMPTS, LONG_NAME) == 0)
							{
								strcpy(bufferEmployee.lastName,lastName);
								flagCarga = TRUE;
							}
							break;
						case 3:
							if(utn_getFloat(INPUT_SALARY,ERROR_GENERIC,&salary,SALARY_MIN,SALARY_MAX,ATTEMPTS) == 0)
							{
								bufferEmployee.salary = salary;
								flagCarga = TRUE;
							}
							break;
						case 4:
							if(utn_getInt(&sector, INPUT_SECTOR, ERROR_GENERIC, SECTOR_MIN, SECTOR_MAX, ATTEMPTS) == 0)
							{
								bufferEmployee.sector =sector;
								flagCarga = TRUE;
							}
							break;
					}
    			}
    			while(op != 5);
    			if(flagCarga == TRUE)
    			{
    				employee_modifyEmployee(list, len, bufferEmployee.id, bufferEmployee.name, bufferEmployee.lastName, bufferEmployee.salary, bufferEmployee.sector,index);
    				retorno = 0;
    			}
    		}
    	}
    }
	return retorno;
}
/** \brief search the first free index on an array of employees
*
* \param list Employee*
* \param int pIndex* is a pointer that saves the first space available to save an employee.
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
static int employee_searchIndexFree(Employee* list,int* pIndex, int len)
{
	int retorno = -1;
		int i;
			if(list != NULL && len > 0)
			{
				for(i = 0;i<len;i++)
				{
					if(list[i].isEmpty == TRUE)
					{
						*pIndex = i;
						retorno = 0;
						break;

					}
				}
			}
		return retorno;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
static int employee_sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;

	int flagSwap;
	int i;
	Employee buffer;
	int nuevoLimite;
	if(list != NULL && len >=0)
	{
		nuevoLimite = len - 1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite;i++)
			{
				switch (order)
				{
					case 0:
						if(list[i].sector < list[i+1].sector)
						{
							flagSwap=1;
							buffer = list[i];
							list[i] = list[i+1];
							list[i+1] = buffer;
						}
						break;
					case 1:
						if(list[i].sector > list[i+1].sector)
						{
							flagSwap=1;
							buffer = list[i];
							list[i] = list[i+1];
							list[i+1] = buffer;
						}
						break;
				}
			}
			nuevoLimite--;

		}
		while(flagSwap);
		nuevoLimite = len - 1;
				do
				{

					flagSwap=0;
					for(i=0; i<nuevoLimite;i++)
					{
						switch (order)
						{
							case 0:
								if(list[i].lastName[0] < list[i+1].lastName[0])
								{

									flagSwap=1;
									buffer = list[i];
									list[i] = list[i+1];
									list[i+1] = buffer;

								}
								break;
							case 1:
								if(list[i].lastName[0] > list[i+1].lastName[0])
								{
									flagSwap=1;
									buffer = list[i];
									list[i] = list[i+1];
									list[i+1] = buffer;
								}
								break;
						}
					}
					nuevoLimite--;

				}
				while(flagSwap);

		retorno = 0;


	}

	return retorno;
}
/** \brief Calculates the sum of all employee salaries, the average salary and the amount of salarys that are above average
*
* \param list Employee*
* \param len int
* \param *pAvg it's a Pointer that stores the average salary
* \param *pSAve it's a Pointer that stores the amount of salarys that are above average
* \param *acumulatorSalary it's a pointer that stores the sum of all employee salaries
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
static int employee_calculateAverageSalary(Employee* list, int len, float *pAvg, int *pSAvg, float *acumulatorSalary)
{
	int retorno = -1;
	float bAcumulatorSalary = 0;
	int counterSalary = 0;
	float averageSalary = 0;
	int counterSAverage = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				bAcumulatorSalary+= list[i].salary;
				counterSalary++;
			}
		}
		averageSalary = bAcumulatorSalary / counterSalary;
		for(i = 0;i<len;i++)
		{
			if(list[i].salary > averageSalary)
			{

				counterSAverage++;

			}
		}
		*pAvg = averageSalary;
		*pSAvg = counterSAverage;
		*acumulatorSalary = bAcumulatorSalary;
		retorno = 0;
	}


	return retorno;
}
int employee_createEmployee(Employee* list, int len, int* pflagFirstEmployee)
{

	int retorno = -1;
	if(employee_loadEmployee(list, QTY_EMPLOYEE, TRUE) == 0)
	{
		*pflagFirstEmployee = 1;
		printf(CREATE_EMPLOYEE_SUCCESS);
		retorno = 0;
	}
	else
	{
		printf(CREATE_EMPLOYEE_ERROR);
	}
	return retorno;
}
int employee_publicModifyEmployee(Employee* list, int len, int flagFirstEmployee)
{
	int retorno = -1;
	if(flagFirstEmployee == TRUE && employee_loadEmployee(list, QTY_EMPLOYEE, FALSE) == 0)
	{
		printf(MODIFY_EMPLOYEE_SUCCESS);
		retorno = 0;
	}
	else
	{
		send_errorMessage(flagFirstEmployee, MODIFY_EMPLOYEE_ERROR);
	}
	return retorno;
}
int employee_unsuscribeEmployee(Employee* list, int len, int flagFirstEmployee)
{
	int retorno = -1;
	int scanId;
	if(flagFirstEmployee == TRUE && utn_getInt(&scanId, INPUT_ID, ERROR_GENERIC, ID_MIN, ID_MAX, ATTEMPTS) == 0 &&
		employee_removeEmployee(list, QTY_EMPLOYEE, scanId) == 0)
	{
		printf(DELETE_EMPLOYEE_SUCCESS);
		retorno = 0;
	}
	else
	{
		send_errorMessage(flagFirstEmployee, DELETE_EMPLOYEE_ERROR);
	}

	return retorno;
}
int employee_PrintEmployeesByLastNameAndSector(Employee* list, int len, int flagFirstEmployee)
{
	int retorno = -1;
	float resultAvg;
	int resultCountAvg;
	float acumulatorSalary;
	if(flagFirstEmployee == TRUE && employee_sortEmployees(list, QTY_EMPLOYEE, UP) == 0 &&
	   employee_printEmployees(list, QTY_EMPLOYEE) == 0 &&
	   employee_calculateAverageSalary(list, QTY_EMPLOYEE, &resultAvg, &resultCountAvg,&acumulatorSalary) == 0)
	{
		printf(REPORT_EMPLOYEES_SUCCESS,acumulatorSalary,resultAvg,resultCountAvg);
	}
	else
	{
		send_errorMessage(flagFirstEmployee, REPORT_EMPLOYEES_ERROR);
	}
	return retorno;
}
