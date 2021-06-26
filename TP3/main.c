 /** main.c
 *		TP3 - 1°E
 *      Author: Andrea Briceño
 */

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
            	if( controller_loadFromText("data.csv",listaEmpleados)  != 0){
            		printf("Error, intente nuevamente");
            	}
                break;
			case 2:

				if(	controller_loadFromBinary("data.bin",listaEmpleados) != 0){
            		printf("Error, intente nuevamente");
            	}

				break;
			case 3:
				controller_addMovie(listaEmpleados);

				break;
			case 4:
				controller_editMovie(listaEmpleados);
				break;
			case 5:

				controller_removeMovie(listaEmpleados);
				break;
			case 6:

				controller_ListMovie(listaEmpleados);

				break;
			case 7:
				controller_sortMovie(listaEmpleados);
				break;
			case 8:
				controller_saveAsText("data.csv",listaEmpleados);


				break;
			case 9:
				controller_saveAsBinary("data.bin",listaEmpleados);

				break;
			case 10:
				ll_deleteLinkedList(listaEmpleados);
				printf("\n  ****************  USTED HA SALIDO  ***************** ");
				break;

        }
    }while(respuesta != 10);
    return EXIT_SUCCESS;
}
