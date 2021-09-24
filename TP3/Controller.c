 /** controller.c
 *
 *      Author: Andrea Briceño
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


int controller_addLibro(LinkedList* pointerArrayListEmployee){

	int retorno = -1;
    Libro *auxiliarEmployee = NULL;
    int  auxiliarId = 0;
	int idMaximo;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;
	int cantidadEmployees;

    		if (pointerArrayListEmployee != NULL){

    			printf("is empty de ll ?  %d",ll_isEmpty(pointerArrayListEmployee));
    				printf("\n    ---------------- Alta de un empleado nuevo ------------- \n");
    				if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
					      (utn_getNumero(&auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas (Entre 0 y 500) ", "\n Error, intente nuevamente", 0, 500,3) == 0) &&
					      (utn_getNumero(&auxiliarSueldo,"\n Ingrese el sueldo (Entre 1 y 90000) ", "\n Error, intente nuevamente", 1, 90000,3) == 0)
				       ){
    					if( ll_isEmpty(pointerArrayListEmployee) == 0){

    						cantidadEmployees = ll_len(pointerArrayListEmployee);

							for(int i=0; i<cantidadEmployees ; i++){

								auxiliarEmployee =ll_get(pointerArrayListEmployee, i);
								libro_getId(auxiliarEmployee, &idMaximo);

								if(  auxiliarId>idMaximo ){
									idMaximo = auxiliarId;
								};
							};
    					};
    					printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					idMaximo++;
    				    printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					auxiliarEmployee = pelicula_new();

    					if(   (libro_setId(auxiliarEmployee, idMaximo) == 0) &&
  							  (employee_setNombre(auxiliarEmployee, auxiliarNombre) == 0) &&
							  (employee_setHorasTrabajadas(auxiliarEmployee, auxiliarHorasTrabajadas) == 0) &&
							  (employee_setSueldo(auxiliarEmployee, auxiliarSueldo) == 0)

    					){
    						ll_add(pointerArrayListEmployee, auxiliarEmployee);
							printf("\nEl empleado cargado es: \n");
    						employee_printfOne(auxiliarEmployee);
							retorno=0;
    					}else{
    						printf("\nHubo un error al cargar el empleado \n");

    					};
    				};
    		};
	return retorno;
}


int controller_editLibro(LinkedList* pointerArrayListEmployee)
{

	int retorno = -1;
	Libro *auxiliarEmployee = NULL;
	int  auxiliarId = 0;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;
	int datoACambiar;
	int idEmployeeACambiar;
	int cantidadEmployees;
	int idMaximo;
	if(ll_isEmpty(pointerArrayListEmployee) == 0 && pointerArrayListEmployee != NULL){

			printf("\n    ---------------- Modificación de un empleado ------------- \n");


				cantidadEmployees = ll_len(pointerArrayListEmployee);
				for(int i=0; i<cantidadEmployees ; i++){
					auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
					libro_getId(auxiliarEmployee, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;


					};
				};


				if(	utn_getNumero(&idEmployeeACambiar, "\nIngrese el id del Empleado a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadEmployees; i++) {
						auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
						libro_getId(auxiliarEmployee, &auxiliarId);

						if (idEmployeeACambiar == auxiliarId) {
							printf("\nEmpleado encontrado");
							employee_printfOne(auxiliarEmployee);
							break;
						}
					}
					do{
						utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar horas trabajadas \n3- modificar salario, \n4-  Volver al menú principal        ", "\n Error, ingrese nuevamente", 1, 4, 3);

						switch (datoACambiar) {
							case 1:
								if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
									  (employee_setNombre(auxiliarEmployee, auxiliarNombre) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											employee_printfOne(auxiliarEmployee);
											retorno=0;
								}
								break;
							case 2:
								if (  (utn_getNumero(&auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas  ", "\n Error, intente nuevamente", 0, 500,3) == 0) &&
									  (employee_setHorasTrabajadas(auxiliarEmployee, auxiliarHorasTrabajadas) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											employee_printfOne(auxiliarEmployee);
											retorno=0;
								}
								break;
							case 3:
								if (  (utn_getNumero(&auxiliarSueldo,"\n Ingrese el sueldo  ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
									  (employee_setSueldo(auxiliarEmployee, auxiliarSueldo) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											employee_printfOne(auxiliarEmployee);
											retorno=0;
								}
							break;
							case 4:
							break;
						}
					 }while(  datoACambiar != 4);


				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay empleados cargados");

	}

	return retorno;
}


int controller_removeLibro(LinkedList* pointerArrayListEmployee)
{

	int retorno = -1;
	Libro *auxiliarEmployee = NULL;
	int  auxiliarId = 0;
	char validacion;
	int idEmployeeACambiar;
	int cantidadEmployees;
	int idMaximo;

	int indexEmployee;
	if(ll_isEmpty(pointerArrayListEmployee) == 0 && pointerArrayListEmployee != NULL){

			printf("\n    ---------------- Baja de un empleado ------------- \n");


				cantidadEmployees = ll_len(pointerArrayListEmployee);
				for(int i=0; i<cantidadEmployees ; i++){
					auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
					libro_getId(auxiliarEmployee, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;
					};
				};


				if(	utn_getNumero(&idEmployeeACambiar, "\nIngrese el id del Empleado a dar de baja  ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadEmployees; i++) {
						auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
						libro_getId(auxiliarEmployee, &auxiliarId);

						if (idEmployeeACambiar == auxiliarId) {
							printf("\nEmpleado encontrado");
							employee_printfOne(auxiliarEmployee);
							indexEmployee =  ll_indexOf(pointerArrayListEmployee, auxiliarEmployee);
							break;
						}

					}
							utn_getCharAceptar(&validacion, "\n¿Está seguro que desea borrar este empleado?  ('s' o 'n')        ", "\n Error, ingrese nuevamente", 3);
							switch (validacion) {

								case 's':
									ll_remove(pointerArrayListEmployee, indexEmployee);
									printf("\n Empleado eliminado");
								break;
								case 'n':
									printf("\n Operación cancelada");
								break;
							}
				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay empleados cargados");

	}

	return retorno;
}

int controller_ListLibro(LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;

	int lenghtEmployees = ll_len(pointerArrayListEmployee);
	if (pointerArrayListEmployee != NULL && lenghtEmployees > 0){
		printf("\n  ****************  DATOS PERSONALES DE EMPLEADOS  ***************** ");


		for(int i = 0; i < lenghtEmployees; i++ ){
			Libro*  auxiliarEmployee= ll_get(pointerArrayListEmployee, i);

			libro_getId( auxiliarEmployee, &auxiliarId);
			employee_getNombre(auxiliarEmployee, auxiliarNombre);
			employee_getHorasTrabajadas(auxiliarEmployee, &auxiliarHorasTrabajadas);
			employee_getSueldo(auxiliarEmployee, &auxiliarSueldo);

			printf("\n %d.  Empleado: %s,     Horas trabajadas: %d,      Sueldo: $%d ",
																	   auxiliarId,
																	   auxiliarNombre,
																	   auxiliarHorasTrabajadas,
																	   auxiliarSueldo);
		};
		retorno = 0;
	}else{
		printf("No hay empleados cargados");

	}


    return retorno;
}


int controller_sortLibro(LinkedList* pointerArrayListEmployee)
{
		int retorno = -1;
		int(*funcionTipoOrden)(void*,void*);
		int tipodeSort;


		int lenghtEmployees = ll_len(pointerArrayListEmployee);
		if (pointerArrayListEmployee != NULL && lenghtEmployees > 0){



			utn_getNumero(&tipodeSort, "\n Ingrese una opcion del 1 al 8 "
					"\n1- Ordenar ID de forma ascendente "
					"\n2- Ordenar ID de forma descendente "
					"\n3- Ordenar Nombres de forma ascendente "
					"\n4- Ordenar Nombres de forma descendente "
					"\n5- Ordenar Horas de trabajo de forma ascendente "
					"\n6- Ordenar Horas de trabajo de forma descendente "
					"\n7- Ordenar Sueldo de forma ascendente "
					"\n8- Ordenar Sueldo de forma descendente "
					"\n9-  Volver al menú principal        ", "\n Error, ingrese nuevamente", 1, 9, 3);

					switch (tipodeSort) {
						case 1:
						case 2:
							funcionTipoOrden = employee_sortID;
							break;
						case 3:
						case 4:
							funcionTipoOrden = employee_sortNombres;
							break;
						case 5:
						case 6:
							funcionTipoOrden = employee_sortHoras;
							break;
						case 7:
						case 8:
							funcionTipoOrden = employee_sortSueldo;
							break;
						case 9:
							break;
					}//Fin switch

			if(tipodeSort % 2 != 0){
				ll_sort(pointerArrayListEmployee, funcionTipoOrden, 1);
			}else{
				ll_sort(pointerArrayListEmployee, funcionTipoOrden, 0);
			}
			printf("\n               ** Lista ordenada ** ");
			retorno = 0;
		}else{
			printf("No hay empleados cargados");

		}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;

	if(ll_isEmpty(pointerArrayListEmployee) == 0){
	FILE *pointerFile = fopen(path,"w");
		if (path != NULL && pointerArrayListEmployee != NULL && pointerFile != NULL){
			fprintf( pointerFile,"id,    nombre,    horasTrabajadas,    sueldo\n");
			for(int i = 0; i < ll_len(pointerArrayListEmployee); i++){

				Libro  *auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
				if(libro_getId( auxiliarEmployee, &auxiliarId) == 0 &&
				employee_getNombre(auxiliarEmployee, auxiliarNombre) == 0 &&
				employee_getHorasTrabajadas(auxiliarEmployee, &auxiliarHorasTrabajadas) == 0 &&
				employee_getSueldo(auxiliarEmployee, &auxiliarSueldo) == 0 ){
				fprintf( pointerFile,"%d, %s, %d, %d\n", auxiliarId,
														 auxiliarNombre,
													     auxiliarHorasTrabajadas,
														 auxiliarSueldo);
				}
			}

			fclose(pointerFile);
			printf("\nDatos guardados en %s", path);
			retorno = 0;
		};
	}else{
		printf("Error, No hay datos para guardar");

	}

	return retorno;


}


int controller_saveAsBinary(char* path , LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;
	int cantidadEscrita;

	if(ll_isEmpty(pointerArrayListEmployee) == 0){
		if (path != NULL && pointerArrayListEmployee != NULL){
			FILE *pointerFile=fopen(path,"wb");

			int lenghtEmployees = ll_len(pointerArrayListEmployee);

			for(int i = 0; i < lenghtEmployees; i++ ){

				Libro*  auxiliarEmployee= ll_get(pointerArrayListEmployee, i);
				if(pointerFile != NULL){
					cantidadEscrita = fwrite(auxiliarEmployee, sizeof(Libro),1, pointerFile);
				};
			}
			if (cantidadEscrita < 1){
				printf("\nError al escribir el archivo");
			}else{
				printf("\nDatos guardados en %s", path);
				retorno = 0;
			}
			fclose(pointerFile);
		};
	}else{
		printf("Error, No hay datos para guardar");

	}
	return retorno;
}


int controller_loadFromText(char* path , LinkedList* pointerArrayListEmployee){

	int retorno = -1;
	char validacion = 's';
	if (path != NULL && pointerArrayListEmployee != NULL){


		if(ll_isEmpty (pointerArrayListEmployee ) == 1){

			FILE *pointerFile=fopen(path,"r");

			if(pointerFile != NULL &&
			   parser_LibroFromText(pointerFile, pointerArrayListEmployee) == 0 ){
				printf("\nArchivo leido y cerrado con éxito");
				retorno = 0;

			}else{
				printf("\nNo se pudo leer el archivo");
			}
			fclose(pointerFile);

		}else{

			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
			switch (validacion)
			{
				case 'n':
					printf("\nSe han borrado los datos cargados anteriormente.  ");
					ll_clear(pointerArrayListEmployee);
					FILE *pointerFile=fopen(path,"r");

					if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListEmployee) == 0 )
					{
						printf("\nArchivo nuevo leido y cerrado con éxito");
						fclose(pointerFile);
						retorno = 0;
					}
				break;
				case 's':
					if(controller_saveAsText( "respaldo.csv", pointerArrayListEmployee) == 0){

						ll_clear(pointerArrayListEmployee);

						FILE *pointerFile=fopen(path,"r");

						if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListEmployee) == 0 )
						{
							printf("\nArchivo nuevo leido y cerrado con éxito");
							fclose(pointerFile);
							retorno = 0;
						}


					}
				break;
				}
			}
	}
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pointerArrayListEmployee){

	    int retorno = -1;
	    	char validacion = 's';
	    	if (path != NULL && pointerArrayListEmployee != NULL){


	    		if(ll_isEmpty (pointerArrayListEmployee ) == 1){

	    			FILE *pointerFile=fopen(path,"rb");

	    			if(pointerFile != NULL &&
	    				parser_LibroFromBinary(pointerFile, pointerArrayListEmployee) == 0 ){
	    				printf("\nArchivo leido y cerrado con éxito");
	    				retorno = 0;

	    			}else{
	    				printf("\nNo se pudo leer el archivo");
	    			}
	    			fclose(pointerFile);

	    		}else{

	    			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
	    			switch (validacion)
	    			{
	    				case 'n':
	    					printf("\nSe han borrado los datos cargados anteriormente.  ");
	    					ll_clear(pointerArrayListEmployee);
	    					FILE *pointerFile=fopen(path,"rb");

	    					if(  pointerFile != NULL &&
	    					     parser_LibroFromBinary(pointerFile, pointerArrayListEmployee)  == 0  )
	    					{
	    						printf("\nArchivo nuevo leido y cerrado con éxito");
	    						fclose(pointerFile);
	    						retorno = 0;
	    					}
	    				break;
	    				case 's':
	    					if ( controller_saveAsBinary("respaldo.bin",pointerArrayListEmployee) == 0 )
	    					{
								ll_clear(pointerArrayListEmployee);
								FILE *pointerFile=fopen(path,"rb");

								if(  pointerFile != NULL &&
									 parser_LibroFromBinary(pointerFile, pointerArrayListEmployee)  == 0  )
								{
									printf("\nArchivo nuevo leido y cerrado con éxito");
									fclose(pointerFile);
									retorno = 0;
								}
	    					}
	    				break;
	    				}
	    			}
	    	}
	        return retorno;


}

