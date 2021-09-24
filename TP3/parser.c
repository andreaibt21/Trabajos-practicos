#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pointerFile , LinkedList* pointerArrayListEmployee){
	int retorno = 0;
	char buffer[4][130];

	Libro* pointerAuxEmpleado=NULL;

	if(pointerFile != NULL && pointerArrayListEmployee != NULL){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));


	while( !feof(pointerFile) ){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));
		pointerAuxEmpleado = pelicula_newParametros(*(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3));

		if(pointerAuxEmpleado != NULL){
			ll_add(pointerArrayListEmployee,pointerAuxEmpleado); //Agrego cada empleado de la lista a la linkedlist
			retorno=0;
		}


	}

	}
  	 return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromBinary(FILE* pointerFile , LinkedList* pointerArrayListEmployee)
{	int retorno;
	int retornoLeido;
	Libro* pointerAuxEmpleado=NULL;
	Libro auxiliarEmployee;

		if(pointerFile!=NULL && pointerArrayListEmployee!=NULL){

			while( !feof(pointerFile) ){

				retornoLeido = fread(&auxiliarEmployee,sizeof(Libro),1,pointerFile);
				pointerAuxEmpleado = pelicula_new();
				if (pointerAuxEmpleado != NULL ) {

					if(retornoLeido != 0){

						if(  (libro_setId(pointerAuxEmpleado, auxiliarEmployee.id)   == 0) &&
						(employee_setNombre(pointerAuxEmpleado, auxiliarEmployee.nombre)  == 0) &&
						(employee_setHorasTrabajadas(pointerAuxEmpleado, auxiliarEmployee.horasTrabajadas) == 0) &&
						(employee_setSueldo(pointerAuxEmpleado, auxiliarEmployee.sueldo) == 0) ){

							ll_add(pointerArrayListEmployee, pointerAuxEmpleado);
							retorno = 0;
						}
					}

				}
			}
		}

    return retorno;
}
