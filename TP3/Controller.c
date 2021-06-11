#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pointerArrayListEmployee){
	ll_clear(pointerArrayListEmployee);
	int retorno = -1;
	if (path != NULL && pointerArrayListEmployee != NULL){
		FILE *pointerFile=fopen(path,"r");
		parser_EmployeeFromText(pointerFile, pointerArrayListEmployee);
		fclose(pointerFile);   //le falta varias validaciones a esta funcion
		retorno = 0;
	};
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pointerArrayListEmployee){
	ll_clear(pointerArrayListEmployee);
	int retorno = -1;

		if (path != NULL && pointerArrayListEmployee != NULL){
			FILE *pointerFile=fopen(path,"rb");
			parser_EmployeeFromBinary(pointerFile, pointerArrayListEmployee);
			fclose(pointerFile); //le falta varias validaciones a esta funcion
			retorno = 0;
		};
	    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pointerArrayListEmployee){
    int retorno = -1;
    Employee *auxiliarEmployee = NULL;
    int  auxiliarId = 0;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;


    		if (pointerArrayListEmployee != NULL){


    				printf("\n    ---------------- Alta de un empleado nuevo ------------- \n");
    				if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
					      (utn_getNumero(&auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas  ", "\n Error, intente nuevamente", 0, 500,3) == 0) &&
					      (utn_getNumero(&auxiliarSueldo,"\n Ingrese el sueldo  ", "\n Error, intente nuevamente", 1, 90000,3) == 0)
				       ){

    					auxiliarId++;   //ARREGLAR EL AUTOINCREMENTAL, SIEMPRE MANDA 1
    					auxiliarEmployee = employee_new();
    					if(   (employee_setId(auxiliarEmployee, auxiliarId) == 0) &&
  							  (employee_setNombre(auxiliarEmployee, auxiliarNombre) == 0) &&
							  (employee_setHorasTrabajadas(auxiliarEmployee, auxiliarHorasTrabajadas) == 0) &&
							  (employee_setSueldo(auxiliarEmployee, auxiliarSueldo) == 0)

    					){
    						ll_add(pointerArrayListEmployee, auxiliarEmployee);
							printf("\nEl empleado cargado es: \n");
    						employee_printfOne(auxiliarEmployee);
							retorno=0;
    					}


    				};

    		};
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pointerArrayListEmployee)
{

	int retorno = -1;
	Employee *auxiliarEmployee = NULL;
	int  auxiliarId = 0;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;
	int datoACambiar;

		if (pointerArrayListEmployee != NULL){

			printf("\n    ---------------- Modificación de un empleado nuevo ------------- \n");
		    	controller_ListEmployee(pointerArrayListEmployee);

		    	utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar horas trabajadas \n3- modificar salario ", "\n Error, ingrese nuevamente", 1, 3, 3);

		    	 //AACA QUEDAMOS WEY
		    	 //

				if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
					  (utn_getNumero(&auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas  ", "\n Error, intente nuevamente", 0, 500,3) == 0) &&
					  (utn_getNumero(&auxiliarSueldo,"\n Ingrese el sueldo  ", "\n Error, intente nuevamente", 1, 90000,3) == 0)
				   ){
					printf("\nDATOS PEDIDOS\n");

					auxiliarId++;
					auxiliarEmployee = employee_new();
					if(   (employee_setId(auxiliarEmployee, auxiliarId) == 0) &&
						  (employee_setNombre(auxiliarEmployee, auxiliarNombre) == 0) &&
						  (employee_setHorasTrabajadas(auxiliarEmployee, auxiliarHorasTrabajadas) == 0) &&
						  (employee_setSueldo(auxiliarEmployee, auxiliarSueldo) == 0)

					){
						ll_add(pointerArrayListEmployee, auxiliarEmployee);
						printf("\nEl empleado cargado es: \n");
						employee_printfOne(auxiliarEmployee);
						retorno=0;

					}


				};

		};
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pointerArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;

	int lenghtEmployees = ll_len(pointerArrayListEmployee);
	if (pointerArrayListEmployee != NULL && lenghtEmployees > 0){

		for(int i = 0; i < lenghtEmployees; i++ ){
			Employee*  auxiliarEmployee= ll_get(pointerArrayListEmployee, i);

			employee_getId( auxiliarEmployee, &auxiliarId);
			employee_getNombre(auxiliarEmployee, auxiliarNombre);
			employee_getHorasTrabajadas(auxiliarEmployee, &auxiliarHorasTrabajadas);
			employee_getSueldo(auxiliarEmployee, &auxiliarSueldo);


			printf( "\n%d , %s, %d, %d ", auxiliarId,
									   auxiliarNombre,
									   auxiliarHorasTrabajadas,
									   auxiliarSueldo);
		};
		retorno = 0;
	};


    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pointerArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pointerArrayListEmployee)
{
	int  auxiliarId;
	char auxiliarNombre[200];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;
	int retorno = -1;
	//int ll_isEmpty(LinkedList* this); cero si no esta vacia, tiene algo

	if(ll_isEmpty(pointerArrayListEmployee) == 0){
	FILE *pointerFile=fopen(path,"w");
		if (path != NULL && pointerArrayListEmployee != NULL && pointerFile != NULL){
			fprintf( pointerFile,"id,    nombre,    horasTrabajadas,    sueldo\n");
			for(int i = 0; i < ll_len(pointerArrayListEmployee); i++){

				Employee  *auxiliarEmployee = ll_get(pointerArrayListEmployee, i);
				if(employee_getId( auxiliarEmployee, &auxiliarId) == 0 &&
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
			retorno = 0;
		};
	}else{
		printf("Error, No hay datos para guardar");

	}

	return retorno;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;
	int cantidadEscrita;

	if(ll_isEmpty(pointerArrayListEmployee) == 0){
		if (path != NULL && pointerArrayListEmployee != NULL){
			FILE *pointerFile=fopen(path,"wb");

			int lenghtEmployees = ll_len(pointerArrayListEmployee);

			for(int i = 0; i < lenghtEmployees; i++ ){

				Employee*  auxiliarEmployee= ll_get(pointerArrayListEmployee, i);
				if(pointerFile != NULL){
					cantidadEscrita = fwrite(auxiliarEmployee, sizeof(Employee),1, pointerFile);
				};
			}
			if (cantidadEscrita < 1){
			printf("\nError al escribir el archivo");

			}

			fclose(pointerFile);

			retorno = 0;
		};
	}else{
		printf("Error, No hay datos para guardar");

	}
	return retorno;
}

