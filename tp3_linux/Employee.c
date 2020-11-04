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
                        && !(employee_setSueldo(this, atof (sueldo))))
                {
                        return this;
                }
        }
        employee_delete(this);
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

float employee_getSueldo(Employee* this)
{
        return this->sueldo;
}

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

int isValidSueldo(char* sueldo)
{
	int output = 0;
	if (isFloat(sueldo) == 1 && utn_countPointsArray(sueldo) == 0)
	{
		output = 1;
	}
    return output;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
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
