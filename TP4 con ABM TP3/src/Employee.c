#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "utn.h"
#include "LinkedList.h"


/** \brief crea un espacio de memoria del tipo Employee
 *
 * \param void
 * \return (Employee*)malloc(sizeof(Employee))
 *
 */
Employee* employee_new(void)
{
        return (Employee*)malloc(sizeof(Employee));
}

/** \brief crea un espacio de memoria del tipo Employee y les asigna los valores recibidos por parámetros
 *
 * \param id char*
 * \param nombre char*
 * \param horasTrabajadas char*
 * \param sueldo char*
 * \return int id
 *
 */
Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
        Employee* this = employee_new();
        if(this != NULL)
        {
                if(!(employee_setId(this, atoi(id)))
                        && !(employee_setNombre(this, nombre))
                        && !(employee_setHorasTrabajadas(this, atoi(horasTrabajadas)))
                        && !(employee_setSueldo(this, atof (sueldo))))
                {
                        return this;
                }
        }
        employee_delete(this);
        return NULL;
}
/** \brief devuelve por valor del Id asociado a un puntero del timpo empleado y lo retorna por valor
 *
 * \param this Employee*
 * \return int id
 *
 */
int employee_getId(Employee* this)
{
	int output = -1;
	if(this != NULL)
	{
		output = this->id;
	}
	return output;
}
/** \brief asigna el valor ingresado como parametro al campo id del tipo empleado
 *
 * \param this Employee*
 * \param id int
 * \return output int 0 si ok // -1 si error
 *
 */
int employee_setId(Employee* this, int id)
{
        int output = -1;
        if(this != NULL  && isValidId(id) == 1)
        {
                this->id = id;
                output = 0;
        }
         return output;
}
/** \brief verifica que una cadena de caracteres sea del tipo Id
 *
 * \param employee1 Employee*
 * \return int si es sueldo = 1 // si no es sueldo = 0
 *
 */
int isValidId(int id)
{
	int output = 0;
	if (id >0)
	{
		output = 1;
	}
    return output;
}
/** \brief devuelve por valor el nombre asociado a un puntero del timpo empleado y lo retorna por valor
 *
 * \param this Employee*
 * \return char*
 *
 */
char* employee_getNombre(Employee* this)
{
	char* output = NULL;
	if(this != NULL)
	{
		output = this->nombre;
	}
    return output;
}
/** \brief asigna el valor ingresado como parametro al campo nombre del tipo empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return output int 0 si ok // -1 si error
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
        int output = -1;
        if(this != NULL && isValidNombre(nombre) == 1)
        {
                strncpy(this->nombre,nombre,(int)sizeof(this->nombre));
                output = 0;
        }
        return output;
}
/** \brief verifica que una cadena de caracteres sea del tipo Nombre
 *
 * \param nombre char*
 * \return int si es nombre = 1 // si no es nombre = 0
 *
 */
int isValidNombre(char* nombre)
{
	int output = 0;
	if(utn_isValidName(nombre, LONG_NAME) == 1)
	{
		output = 1;
	}
	return output;
}
/** \brief devuelve por valor de las horas trabajadas asociado a un puntero del timpo empleado y lo retorna por valor
 *
 * \param this Employee*
 * \return float*
 *
 */
int employee_getHorasTrabajadas(Employee* this)
{
	int output = -1;
	if (this!= NULL)
	{
		output = this->horasTrabajadas;
	}
	return output;
}
/** \brief asigna el valor ingresado como parametro al campo horas trabajadas del tipo empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return output int 0 si ok // -1 si error
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
        int output = -1;
        if(this != NULL  && isValidHorasTrabajadas(horasTrabajadas) == 1)
        {
                this->horasTrabajadas = horasTrabajadas;
                output = 0;
        }
         return output;
}
/** \brief verifica que un valor int sea del tipo horasTrabajadas
 *
 * \param horasTrabajadas int
 * \return int si es horasTrabajadas = 1 // si no es horasTrabajadas = 0
 *
 */
int isValidHorasTrabajadas(int horasTrabajadas)
{
	int output = 0;
	if (horasTrabajadas >=0)
	{
		output = 1;
	}
	return output;
}
/** \brief devuelve por valor del sueldo asociado a un puntero del timpo empleado y lo retorna por valor
 *
 * \param this Employee*
 * \return float*
 *
 */
float employee_getSueldo(Employee* this)
{
	float output = -1;
	if(this != NULL)
	{
		output = this->sueldo;
	}
    return output;
}
/** \brief asigna el valor ingresado como parametro al campo sueldo trabajadas del tipo empleado
 *
 * \param this Employee*
 * \param horasTrabajadas fload
 * \return output int 0 si ok // -1 si error
 *
 */
int employee_setSueldo(Employee* this, float sueldo)
{
        int output = -1;
        char charSueldo[LONG_SUELDO];
        sprintf(charSueldo,"%f",sueldo);
        if(this != NULL && charSueldo != NULL && isValidSueldo(charSueldo) == 1)
        {
                this->sueldo = sueldo;
                output = 0;
        }
         return output;
}
/** \brief verifica que una cadena de caracteres sea del tipo sueldo
 *
 * \param sueldo char*
 * \return int si es sueldo = 1 // si no es sueldo = 0
 *
 */
int isValidSueldo(char* sueldo)
{
	int output = 0;
	if (isFloat(sueldo) == 1 && utn_countPointsArray(sueldo) == 0)
	{
		output = 1;
	}
    return output;
}
/** \brief verifica que un puntero del tipo Empleado no sea nulo y posteriormente lo elimina, liberando la memoria asociada a él
 *
 * \param employee1 Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/** \brief imprime una tabla con los datos de un unico registro de empleado
 *
 * \param employee1 Employee*
 * \return int
 *
 */
int employee_printOneEmployee(Employee* this)
{
	int output = -1;
	if (this != NULL)
	{
		printf(PRINT_ONE_REGISTRY_TOP);
		printf(PRINT_ONE_REGISTRY, employee_getId(this), employee_getNombre(this), employee_getHorasTrabajadas(this), employee_getSueldo(this));
		printf(PRINT_ONE_REGISTRY_BOTTOM);
		output = 0;
	}
	return output;
}
/** \brief función criterio para ordenar empleados por el nombre y devuelve el resultado de la comparación por valor
 *
 * \param employee1 void*
 * \param employee1 void*
 * \return int
 *
 */
int employee_compareByName(void* employee1, void* employee2)
{
	int output;
	Employee* bufferFirstEmployee;
	Employee* bufferSecondEmployee;
	bufferFirstEmployee = (Employee*) employee1;
	bufferSecondEmployee = (Employee*) employee2;
	char bufferNameFirstEmployee[LONG_NAME];
	char bufferNameSecondEmployee[LONG_NAME];
	strcpy(bufferNameFirstEmployee,employee_getNombre(bufferFirstEmployee));
	strcpy(bufferNameSecondEmployee,employee_getNombre(bufferSecondEmployee));
	if(strncmp(bufferNameFirstEmployee,bufferNameSecondEmployee,LONG_NAME)>0)
	{
		output = 1;
	}
	else
	{
		if(strncmp(bufferNameFirstEmployee,bufferNameSecondEmployee,LONG_NAME)<0)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;

}
/** \brief función criterio para ordenar empleados comparando por el id y devuelve el resultado de la comparación por valor
 *
 * \param employee1 void*
 * \param employee1 void*
 * \return int
 *
 */
int employee_compareById(void* employee1, void* employee2)
{
	int output;
	Employee* bufferFirstEmployee;
	Employee* bufferSecondEmployee;
	bufferFirstEmployee = (Employee*) employee1;
	bufferSecondEmployee = (Employee*) employee2;
	int bufferIdFirstEmployee;
	int bufferIdSecondEmployee;
	bufferIdFirstEmployee = employee_getId(bufferFirstEmployee);
	bufferIdSecondEmployee = employee_getId(bufferSecondEmployee);

	if(bufferIdFirstEmployee > bufferIdSecondEmployee)
	{
		output = 1;
	}
	else
	{
		if(bufferIdFirstEmployee < bufferIdSecondEmployee)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;

}
/** \brief función criterio para ordenar empleados comparando por la cantidad de horas trabajadas y devuelve el resultado de la comparación por valor
 *
 * \param employee1 void*
 * \param employee1 void*
 * \return int
 *
 */
int employee_compareByHours(void* employee1, void* employee2)
{
	int output;
	Employee* bufferFirstEmployee;
	Employee* bufferSecondEmployee;
	bufferFirstEmployee = (Employee*) employee1;
	bufferSecondEmployee = (Employee*) employee2;
	int bufferHourFirstEmployee;
	int bufferHourSecondEmployee;
	bufferHourFirstEmployee = employee_getHorasTrabajadas(bufferFirstEmployee);
	bufferHourSecondEmployee = employee_getHorasTrabajadas(bufferSecondEmployee);

	if(bufferHourFirstEmployee > bufferHourSecondEmployee)
	{
		output = 1;
	}
	else
	{
		if(bufferHourFirstEmployee < bufferHourSecondEmployee)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;

}
/** \brief función criterio para ordenar empleados comparando por el salario y devuelve el resultado de la comparación por valor
 *
 * \param employee1 void*
 * \param employee1 void*
 * \return int
 *
 */
int employee_compareBySalary(void* employee1, void* employee2)
{
	int output;
	Employee* bufferFirstEmployee;
	Employee* bufferSecondEmployee;
	bufferFirstEmployee = (Employee*) employee1;
	bufferSecondEmployee = (Employee*) employee2;
	float bufferSalaryFirstEmployee;
	float bufferSalarySecondEmployee;
	bufferSalaryFirstEmployee = employee_getSueldo(bufferFirstEmployee);
	bufferSalarySecondEmployee = employee_getSueldo(bufferSecondEmployee);

	if(bufferSalaryFirstEmployee > bufferSalarySecondEmployee)
	{
		output = 1;
	}
	else
	{
		if(bufferSalaryFirstEmployee < bufferSalarySecondEmployee)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;

}
int employee_filterBySalary(void* employee)
{
	int output = -1;
	int salary = employee_getSueldo(employee);
	if(salary > 30000)
	{
		output = 0;
	}
	else
	{
		output = 1;
	}
	return output;
}

float employee_sumAllSalaries(void* employee, float* pSueldo)
{
	float output = -1;
	Employee* empleado = (Employee*)(employee);
	if(employee!= NULL)
	{
		*pSueldo = employee_getSueldo(empleado);
		output = 0;
	}
	return output;
}
int employee_countEmployees(void* employee)
{
	float output = -1;
	if(employee!= NULL)
	{
		output = 1;
	}
	else
	{
		output = 0;
	}
	return output;
}

