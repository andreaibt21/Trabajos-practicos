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



int main()
{
	setbuf(stdout, NULL);
    int respuesta = 0;
    printf("\nfuncinoa");

  //  LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	mostrarMenu(&respuesta);

        switch(respuesta) {
            case 1:
            	 printf("\nfuncgvhgvhginoa");
             //   controller_loadFromText("data.csv",listaEmpleados);
                break;
			case 2:
				 printf("\n22");
				break;
			case 3:
				 printf("\n33");
				break;
			case 4:
				 printf("\n44");
				break;
			case 5:
				printf("\n55");
				break;
			case 6:
				printf("\n66");
				break;
			case 7:
				printf("\n77");
				break;
			case 8:
				printf("\n88");
				break;
			case 9:
				printf("\n99");
				break;
			case 10:
				printf("\n1010");
				break;

        }
    }while(respuesta != 10);
    return EXIT_SUCCESS;
}

