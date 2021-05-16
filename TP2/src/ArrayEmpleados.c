/*
 * ArrayEmpleados.c
 *
 *  Created on: May 11, 2021
 *       Author: andrea briceño
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmpleados.h"
#include "utn.h"


int modificarUnEmpleado( estructuraEmpleados   array[], int tamano){

	int retorno = -1;
	int posicion = -1;
	char respuesta;
	int datoACambiar = 0;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL && tamano > 0 && posicion !=-1) {
		printf("\n\n ");
		fflush(stdin);

		printf("\n¿Desea cambiar este legajo? \n");
		printf(" ****************  DATOS PERSONALES A CAMBIAR ***************** \n ");
		printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");

		mostrarUnEmpleados(array[posicion]); // muestra el estudiante que quieres cambiar
		utn_getSoN(&respuesta, "\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);

		utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar apellido \n3- modificar salario \n4- modificar sector ", "\n Error, ingrese nuevamente", 1, 4, 3);


		switch (datoACambiar) {

		   case 1:
				utn_getString(array[posicion].nombre ,"\n Ingrese el nombre  ", "\n Error intente nuevamente", 3);
				printf("\n *** Empleado cambiado *** ");
				printf("\n Estos son los datos nuevos: ");
				printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
				mostrarUnEmpleados(array[posicion]); // muestra el estudiante con campos nuevos;
				retorno = 0;
				break;
			case 2:
				utn_getString(array[posicion].apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3);
				printf("\n *** Empleado cambiado *** ");
				printf("\n Estos son los datos nuevos: ");
				printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
				mostrarUnEmpleados(array[posicion]); // muestra el estudiante con campos nuevos;
				retorno = 0;
				break;
			case 3:
				utn_getFloat(&array[posicion].salario,"\n Ingrese el salario (Entre 10000 y 80000)  ", "\n Error, intente nuevamente", 10000, 80000,3);
				printf("\n *** Empleado cambiado *** ");
				printf("\n Estos son los datos nuevos: ");
				printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
				mostrarUnEmpleados(array[posicion]); // muestra el estudiante con campos nuevos;
				retorno = 0;
				break;
			case 4:
				utn_getNumero(&array[posicion].sector,"\n Ingrese el sector al que pertenece \n    1- Ventas \n    2- RRHH \n    3- IT\n               ", "\n Error, intente nuevamente", 1, 3,3);
				printf("\n *** Empleado cambiado *** ");
				printf("\n Estos son los datos nuevos: ");
				printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
				mostrarUnEmpleados(array[posicion]); // muestra el estudiante con campos nuevos;
				retorno = 0;
				break;
		}//FIN SWITCH
		}//FIN IF


		return retorno;



}

int agregarUnEmpleado( estructuraEmpleados   array[], int tamanoDeArray, int *contadorDeLegajo ){
	int retorno = -1;
	int posicion;
	estructuraEmpleados empleadoAuxiliar;

	if(array != NULL && tamanoDeArray > 0 && contadorDeLegajo != NULL)
	{
		posicion = buscarLibre(array, tamanoDeArray);
		if(posicion == -1)
		{
			printf("\n No hay espacio disponible para cargar alumnos");
		}else{

			if (
				  (utn_getString(empleadoAuxiliar.nombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getString(empleadoAuxiliar.apellido,"\n Ingrese el apellido  ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getFloat(&empleadoAuxiliar.salario,"\n Ingrese el salario (Entre 10000 y 80000)  ", "\n Error, intente nuevamente", 10000, 80000,3) == 0) &&
				  (utn_getNumero(&empleadoAuxiliar.sector,"\n Ingrese el sector al que pertenece \n    1- Ventas \n    2- RRHH \n    3- IT\n               ", "\n Error, intente nuevamente", 1, 3,3) == 0)
			   )
					{
					empleadoAuxiliar.isEmpty = 0;
					empleadoAuxiliar.id= *contadorDeLegajo;
					array[posicion] = empleadoAuxiliar;
					(*contadorDeLegajo)++; //Aumenta el lejago en 1, inicializado en 1000

					printf("\n *** Empleado guardado *** \n");
					retorno = 0;
				}
			else{
				printf("\n *** Rl empleado  no pudo ser guardado *** \n");
			};
		}

	}
	return retorno;
}
int buscarLegajo(estructuraEmpleados array[], int tamanoDeArray)

{
	int retorno = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		mostrarTodosLosEmpleados(array, tamanoDeArray);
		printf("\n Ingrese un legajo   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<=tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].id==legajoAuxiliar && array[i].isEmpty==0){ // revisa si existe y si está ocupado

				printf("\n El legajo '%d' ha sido encontrado  \n", legajoAuxiliar);
				retorno = i;
				break;
			};
			if( i == tamanoDeArray )
			{
				printf("\n  El legajo  '%d' no existe  \n", legajoAuxiliar);
				break;
			};
		}// fin for

	}
	return retorno;
}

int borrarElEmpleado(estructuraEmpleados array[], int tamano) {

	int retorno = -1;
	int posicion = -1;
	char respuesta;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL && tamano > 0) {
		printf("\n¿Desea dar de baja este legajo? \n");
		printf("\n ****************  DATOS DE EMPLEADO POR DAR DE BAJA *****************  ");
		printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
		mostrarUnEmpleados( array[posicion]);

		utn_getSoN(&respuesta, "\n ¿Está seguro? ingrese 's' para sí o 'n' para no", "\n Error intente nuevamente", 3);


		if(respuesta=='s'){
			array[posicion].isEmpty = 1; // Pone el campo isEmpty array en 1, es decir que está libre.
			retorno = 0;
			printf("\n *** Empleado dado de baja *** \n");
		};
	};
	return retorno;
};

int buscarLibre(estructuraEmpleados array[], int tamanoDeArray) {
	int retorno = -1;

	if (array != NULL) {
		for (int i = 0; i < tamanoDeArray; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break; //si encontré una posicion libre rompo el for
			};
		};
	};
	return retorno;
};

int inicializarEstructuraEmpleado(estructuraEmpleados array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que está libre.
		};
		retorno = 0;
	};
	return retorno;
};

int mostrarUnEmpleados( estructuraEmpleados unEmpleado){
	char nombreDeSector[7];
	obtenerSector(unEmpleado.sector, nombreDeSector);

	printf("\n          %d      %s        %s        %.2f        %s      ", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido , unEmpleado.salario, nombreDeSector);

	return 0;

};

int mostrarTodosLosEmpleados(estructuraEmpleados array[], int tamano){
	int retorno = -1;

		if(array != NULL && array > 0){
			printf("\n  ****************  DATOS PERSONALES DE EMPLEADOS  ***************** ");
			printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");

			for(int i = 0; i < tamano ; i++){
				if(array[i].isEmpty == 0){

				mostrarUnEmpleados( array[i]);
				}
			}
			retorno = 0;
		}

	return retorno;

};

int obtenerSector(int numeroDeSector, char nombreDeSector[]){

	int retorno = 1;
	if(numeroDeSector == 1	){
		strcpy(nombreDeSector,"Ventas");
		retorno = 0;
		}
	if(numeroDeSector == 2	){
		strcpy(nombreDeSector,"RRHH");
		retorno = 0;
		}
	if(numeroDeSector == 3	){
		strcpy(nombreDeSector,"IT");
		retorno = 0;
		}
	return retorno;
};


/*
 * INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector ascendente o descendnte
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 *
 * */

void ordenarApellidosYSector(estructuraEmpleados array[], int tamano, int tipoDeOrden){


	estructuraEmpleados empleadoAuxiliar;
	if(array != NULL && tamano > 0){
		switch (tipoDeOrden) {
			case 0: //aaaa ---- zzzz
				for(int i=0; i<tamano-1; i++){
							for(int j=i+1;j<tamano; j++){


								if(array[i].sector > array[j].sector ){
									empleadoAuxiliar =array[i];
									array[i]=array[j];
									array[j]=empleadoAuxiliar;
									if((array[i].sector == array[j].sector) && (stricmp(array[i].apellido, array[j].apellido) ) > 0){
										empleadoAuxiliar =array[i];
										array[i]=array[j];
										array[j]=empleadoAuxiliar;
									  };
								} else {
									if( (stricmp(array[i].apellido, array[j].apellido) ) > 0 ){
									empleadoAuxiliar =array[i];
									array[i]=array[j];
									array[j]=empleadoAuxiliar;
									}
							    }
							}//fin for j
				}//fin for j

				break;
			case 1:
				for(int i=0; i<tamano-1; i++){

							for(int j=i+1;j<tamano; j++){
							  // zzzz ---- aaaa
								if(array[i].sector < array[j].sector ){
									empleadoAuxiliar =array[i];
									array[i]=array[j];
									array[j]=empleadoAuxiliar;
								  if( (array[i].sector == array[j].sector) && (stricmp(array[j].apellido, array[i].apellido) ) > 0 ) {
									    empleadoAuxiliar =array[i];
										array[i]=array[j];
										array[j]=empleadoAuxiliar;
								  };
							    } else {
									if( (stricmp(array[j].apellido, array[i].apellido) ) > 0 ){

									empleadoAuxiliar =array[i];
									array[i]=array[j];
									array[j]=empleadoAuxiliar;
									}
							    }
							}//fin for j
				}//fin for i

				break;
		}//fin switch


	}};

int seleccionarInforme(estructuraEmpleados array[], int tamano){
	int opcionDeInforme = 0;
	int retorno = 1;
	printf("\n ****************  SELECCIONE EL TIPO DE INFORME A MOSTRAR ***************** \n ");
	utn_getNumero(&opcionDeInforme,"\n 1-    alfabéticamente por apellido y sector ascendente \n    2-    alfabéticamente por Apellido y sector descendente    \n    3-    Total y promedio de los salarios,       ", "\n Error, intente nuevamente", 1, 3,3);

	switch (opcionDeInforme) {
		case 1:
			printf(" ****************  ASCENDENTE / SECTOR ***************** \n ");
			ordenarApellidosYSector(array, tamano, 0);
			mostrarTodosLosEmpleados(array, tamano);
			break;
		case 2:
			printf(" ****************  DESCENDENTE / SECTOR ***************** \n ");
			ordenarApellidosYSector(array, tamano, 1);
			mostrarTodosLosEmpleados(array, tamano);
			break;
		case 3:
			printf(" ****************  SALARIOS Y PROMEDIO ***************** \n ");
			mostrarTodosLosEmpleados(array, tamano);
			break;
		default:
			break;
	}

	return retorno;

}


/*
int mostrarSiCargoBien(estructuraEmpleados array[], int tamano) {
	int retorno = -1;
	if (array != NULL) {
		printf("\nDatos cargados\n");

		for (int i = 0; i < tamano; i++) {
			printf("Legajo: %d\n", array[i].legajo);
			printf("sexo: %c\n", array[i].sexo);
			printf("edad: %d\n", array[i].edad);
			printf("nota1: %d\n", array[i].nota1);
			printf("nota2: %d\n", array[i].nota2);
			printf("promedio: %.2f\n", array[i].promedio);
			printf("Apellido: %s \n", array[i].apellido);
			printf("isEmpty: %d\n", array[i].isEmpty);
			retorno = 0;
		}
	}
	return retorno;
};*/





























