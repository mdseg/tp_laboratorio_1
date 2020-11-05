
#define MENU_MODIFY "-------Menu de modificación----------\nSeleccione el campo a modificar:\n1-Nombre\n2-Horas trabajaas\n3-Salario\n4-Volver al menú principal\n"
#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"
#define ATTEMPTS 5
#define TRUE 1
#define FALSE 0
#define CONTROLLER_LOAD_LIST_TEXT "Selecciono la opción de cargar la lista de empleados desde data.csv en modo texto.\n\n"
#define CONTROLLER_LOAD_LIST_NO_FILE "No existe el archivo.\n"
#define CONTROLLER_LOAD_LIST_TEXT_SUCCESS "Lista cargada en modo texto con éxito.\n"
#define CONTROLLER_LOAD_LIST_BINARY "Selecciono la opción de cargar la lista de empleados desde data.csv en modo binario.\n\n"
#define CONTROLLER_LOAD_LIST_BINARY_SUCCESS "Lista cargada en modo binario con éxito.\n"
#define CONTROLLER_CREATE_SUCCESS "Archivo creado o abierto con éxito.\n"
#define CONTROLLER_CSV_TOP "id,nombre,horasTrabajadas,sueldo\n"
#define LL_NULL_ERROR "Problema al cargar la lista de empleados.\n"
#define CONTROLLER_SAVE_BINARY_PATH_ERROR "Error al crear el archivo.\n"
#define CONTROLLER_SAVE_TEXT_ERROR "Error al crear el archivo.\n"
#define CONTROLLER_SORT_MENU "-------Menu de ordenamiento----------\nElija el tipo de ordenamiento deseado:\n1. Por Id ascendentemente.\n2. Por Id descendentemente.\n3. Por nombre ascendentemente.\n4. Por nombre descendentemente.\n5. Por horas trabajadas ascendentemente.\n6. Por horas trabajadas descendentemente.\n7. Por salario ascendentemente.\n8. Por salario descendentemente.\n9. Volver al menú anterior.\nSu opción --->"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_getFreeIndex(LinkedList* pArrayListEmployee);
int controller_saveBinaryPrueba(char* path);
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id);
int controller_getNewId(LinkedList* pArrayListEmployee);



