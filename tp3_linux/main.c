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
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	utn_getInt(&option, MAIN_MENU, ERROR_MENU, 1, 10, ATTEMPTS);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_addEmployee(listaEmpleados);
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
        }
    }while(option != 10);
    return 0;
}

