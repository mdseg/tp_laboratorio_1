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
    10. Salir
*****************************************************/

#define MAIN_MENU "\n-------Sistema de Registro de Empleados ----------\nElija una de estas opciones:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nSu elección -->  "
#define ERROR_MENU "Por favor, elija una opción válida.\n"
#define EXIT_PROGRAM "Saliendo de la aplicación...\n"
#define ATTEMPTS 5

int main()
{
    int option;
    int flagCargaDatos = FALSE;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //controller_loadFromText("data.csv",listaEmpleados);

    do{
    	utn_getInt(&option, MAIN_MENU, ERROR_MENU, 1, 10, ATTEMPTS);
        switch(option)
        {
            case 1:
                if (controller_loadFromText("data.csv",listaEmpleados)== 0 && flagCargaDatos == FALSE)
                {
                	flagCargaDatos = TRUE;
                }
                break;
            case 2:
            	if (controller_loadFromBinary("data2.csv", listaEmpleados)== 0 && flagCargaDatos == FALSE)
				{
					flagCargaDatos = TRUE;
				}
            	break;
            case 3:
            	if(flagCargaDatos == TRUE)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}

            	break;
            case 4:
            	if(flagCargaDatos == TRUE)
            	{
            		controller_editEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}
            	break;
            case 5:
            	if(flagCargaDatos == TRUE)
				{
                	controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 6:
            	if(flagCargaDatos == TRUE)
				{
                	controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 7:
            	if(flagCargaDatos == TRUE)
				{
                	controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 8:
            	if(flagCargaDatos == TRUE)
				{
                	controller_saveAsText("data1.csv", listaEmpleados);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 9:
            	if(flagCargaDatos == TRUE)
				{
    				controller_saveAsBinary("data2.csv", listaEmpleados);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;
            case 10:
            	printf(EXIT_PROGRAM);

        }
    }while(option != 10);
    return 0;
}



