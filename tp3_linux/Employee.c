#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "utn.h"
#include "LinkedList.h"


Employee* employee_new(void)
{
        return (Employee*)malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
        Employee* this = employee_new();
        if(this != NULL)
        {
                if(!(employee_setId(this, atoi(id)))
                        && !(employee_setNombre(this, nombre))
                        && !(employee_setHorasTrabajadas(this, atoi(horasTrabajadas)))
                        && !(employee_setSueldo(this, atoi (sueldo))))
                {
                        return this;
                }
        }
        return NULL;
}

int employee_getId(Employee* this)
{
        return this->id;
}

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
int isValidId(int id)
{
	int output = 0;
	if (id >0)
	{
		output = 1;
	}
    return output;
}

char* employee_getNombre(Employee* this)
{
        return this->nombre;
}

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
int isValidNombre(char* nombre)
{
	int output = 0;
	if(utn_isValidName(nombre, LONG_NAME) == 1)
	{
		output = 1;
	}
	return output;
}

int employee_getHorasTrabajadas(Employee* this)
{
        return this->horasTrabajadas;
}

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
int isValidHorasTrabajadas(int horasTrabajadas)
{
	int output = 0;
	if (horasTrabajadas >=0)
	{
		output = 1;
	}
	return output;
}

int employee_getSueldo(Employee* this)
{
        return this->sueldo;
}

int employee_setSueldo(Employee* this, int sueldo)
{
        int output = -1;
        if(this != NULL  && isValidSueldo(sueldo) == 1)
        {
                this->sueldo = sueldo;
                output = 0;
        }
         return output;
}

int isValidSueldo(int sueldo)
{
	int output = 0;
	if (sueldo > 0)
	{
		output = 1;
	}
    return output;
}
