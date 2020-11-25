#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Filtrar
*****************************************************/

#define MAIN_MENU "\n-------Sistema de Registro de Empleados ----------\nElija una de estas opciones:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nSu elección -->  "
#define ERROR_MENU "Por favor, elija una opción válida.\n"
#define LIST_OVERWRITE_CONFIRM "Usted ya ha realizado una carga de datos previamente. ¿Desea eliminar los datos previos? elija 1 para si o 2 para no.\n"
#define EXIT_PROGRAM "Saliendo de la aplicación...\n"
#define LIST_OVERWRITE_USER_CANCEL "Operación cancelada por el usuario.\n"
#define ATTEMPTS 5
#define BINARY_FILE "data.bin"
#define TEXT_FILE "data.csv"
#define TEXT_DEBUG_FILE "data1.csv"

int main()
{
    int option;
    int flagCargaDatos = FALSE;
    int optionSec;
    LinkedList* listaEmployee = ll_newLinkedList();

    do{
    	utn_getInt(&option, MAIN_MENU, ERROR_MENU, 1, 13, ATTEMPTS);
        switch(option)
        {
            case 1:
            	if(flagCargaDatos == TRUE)
            	{
            		if(utn_getInt(&optionSec, LIST_OVERWRITE_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
					{
            			if(optionSec == 1)
            			{
            				controller_loadFromText(TEXT_FILE,listaEmployee);
            			}
            			else
            			{
            				printf(LIST_OVERWRITE_USER_CANCEL);
            			}
					}
            	}
            	else if( controller_loadFromText(TEXT_FILE,listaEmployee) == 0)
            	{
            		flagCargaDatos = TRUE;
            	}
                break;
            case 2:
            	if(flagCargaDatos == TRUE)
            	{
            		if(utn_getInt(&optionSec, LIST_OVERWRITE_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
					{
            			if(optionSec == 1)
            			{
            				controller_loadFromBinary(BINARY_FILE,listaEmployee);
            			}
            			else
            			{
            				printf(LIST_OVERWRITE_USER_CANCEL);
            			}
					}
            	}
            	else if( controller_loadFromBinary(BINARY_FILE,listaEmployee) == 0)
            	{
            		flagCargaDatos = TRUE;
            	}
                break;
            case 3:
            	if(flagCargaDatos == TRUE)
            	{
            		controller_addEmployee(listaEmployee);
            	}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}

            	break;
            case 4:
            	if(flagCargaDatos == TRUE)
            	{
            		controller_editEmployee(listaEmployee);

            	}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}
            	break;
            case 5:
            	if(flagCargaDatos == TRUE)
				{
                	controller_removeEmployee(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 6:
            	if(flagCargaDatos == TRUE)
				{
                	controller_ListEmployee(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 7:
            	if(flagCargaDatos == TRUE)
				{
                	controller_sortEmployee(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 8:
            	if(flagCargaDatos == TRUE)
				{
                	controller_saveAsText(TEXT_FILE, listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 9:
            	if(flagCargaDatos == TRUE)
				{
    				controller_saveAsBinary(BINARY_FILE, listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 10:
            	if(flagCargaDatos == TRUE)
				{
            		controller_filterById(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;
            case 11:
				if(flagCargaDatos == TRUE)
				{
					controller_sumAllSalaries(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;
            case 12:
				if(flagCargaDatos == TRUE)
				{
					//controller_countEmployee(listaEmployee);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;

        }
    }while(option != 13);
    return 0;
}




