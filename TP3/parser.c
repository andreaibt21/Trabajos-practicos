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
int parser_EmployeeFromText(FILE* pointerFile , LinkedList* pointerArrayListEmployee){
	int retorno = 0;
	char buffer[4][130];

	Employee* pointerAuxEmpleado=NULL;

	if(pointerFile!=NULL && pointerArrayListEmployee!=NULL){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);


	while( !feof(pointerFile) ){
			int readAll;
			readAll = fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if (readAll < 4){
				employee_delete(pointerAuxEmpleado);
				break;
			}else{
				pointerAuxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				if(pointerAuxEmpleado!=NULL){
					ll_add(pointerArrayListEmployee,pointerAuxEmpleado);
					retorno=0;
				};
			};
		};
	};


  	 return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pointerArrayListEmployee)
{

    return 1;
}
