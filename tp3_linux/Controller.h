
#define MENU_MODIFY "-------Menu de modificación----------\nSeleccione el campo a modificar:\n1-Nombre\n2-Horas trabajaas\n3-Salario\n4-Volver al menú principal\n"
#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"
#define ATTEMPTS 5
#define TRUE 1
#define FALSE 0
#define CONTROLLER_LOAD_LIST_TEXT "Selecciono la opción de cargar la lista de empleados desde data.csv en modo texto.\n\n"
#define CONTROLLER_LOAD_LIST_NO_FILE "No existe el archivo.\n"
#define CONTROLLER_LOAD_LIST_TEXT_SUCCESS "Lista cargada con éxito.\n"

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



