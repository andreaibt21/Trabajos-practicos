#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
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



int main()
{
	setbuf(stdout, NULL);
    int respuesta = 0;
    printf("\nfuncinoa");

   LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	mostrarMenu(&respuesta);

        switch(respuesta) {
            case 1:
            	if(controller_loadFromText("data.csv",listaEmpleados)){
            		printf("Error, intente nuevamente");
            	}else{
            		printf("Todo ok");
            	}

                ;
                break;
			case 2:

				controller_loadFromBinary("data.bin",listaEmpleados);

				break;
			case 3:
				controller_addEmployee(listaEmpleados);

				break;
			case 4:
				controller_editEmployee(listaEmpleados);
				break;
			case 5:
				printf("\n55");
				break;
			case 6:
				printf("\n66");
				controller_ListEmployee(listaEmpleados);

				break;
			case 7:
				printf("\n77");
				break;
			case 8:
				controller_saveAsText("data.csv",listaEmpleados);

				printf("\n88");
				break;
			case 9:
				controller_saveAsBinary("data.bin",listaEmpleados);
				//controlar que primero lo abriste en texto

				printf("\n99");
				break;
			case 10:
				printf("\n1010");
				break;

        }
    }while(respuesta != 10);
    return EXIT_SUCCESS;
}
