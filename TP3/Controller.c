#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;

	if (path != NULL && pointerArrayListEmployee != NULL){
		FILE *pointerFile=fopen(path,"r");
		parser_EmployeeFromText(pointerFile, pointerArrayListEmployee);
		fclose(pointerFile);
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
int controller_loadFromBinary(char* path , LinkedList* pointerArrayListEmployee)
{
	int retorno = -1;

		if (path != NULL && pointerArrayListEmployee != NULL){
			FILE *pointerFile=fopen(path,"rb");
			parser_EmployeeFromText(pointerFile, pointerArrayListEmployee);
			fclose(pointerFile);
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
int controller_addEmployee(LinkedList* pointerArrayListEmployee)
{
    return 1;
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
    return 1;
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
	if (pointerArrayListEmployee != NULL){

		for(int i = 0; i < lenghtEmployees; i++ ){
		Employee*  auxiliarEmployee= ll_get(pointerArrayListEmployee, i);


			printf( "%d , %s, %d, %d",employee_getId(auxiliarEmployee, &auxiliarId),
									  employee_getNombre(auxiliarEmployee, auxiliarNombre),
									  employee_setHorasTrabajadas(auxiliarEmployee, auxiliarHorasTrabajadas),
									  employee_getSueldo(auxiliarEmployee, &auxiliarSueldo));
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
	int retorno = -1;

	if (path != NULL && pointerArrayListEmployee != NULL){
	//	FILE *pFile=fopen(path,"w");



		retorno = 0;
	};
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
	/*
	Employee* auxiliarEmployee;
	int validacion;
	if (path != NULL && pointerArrayListEmployee != NULL){
		FILE *pointerFile=fopen(path,"wb");

	/	validacion = fwrite(auxiliarEmployee, sizeof(Employee),1, pointerFile);


		retorno = 0;
	};*/
	return retorno;
}

