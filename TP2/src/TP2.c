/*
 ============================================================================
 ANDREA BRICEÑO
 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
 Se debe utilizar estructuras, permitiendo al usuario trabajar con los datos a través de un ABM.
 Hacer con estructuras - Crear un menú

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmpleados.h"
#include "utn.h"
#define  CANTIDADEMPLEADOS 3
#define LARGODESTRING 51

//almunos.h en el punto c incluyo el .h para que las funciones me sirven


int inicializarEstructuraEmpleados(estructuraEmpleados array[], int tamano);
int buscarLibre(estructuraEmpleados array[], int tamano);
int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
int mostrarUnEstudiante( estructuraEmpleados unEmpleado);
int mostrarTodosLosEstudiantes(estructuraEmpleados array[], int tamano);
int agregarEmpleado( estructuraEmpleados   array[], int tamanoDeArray, int *contadorDeLegajo );
int modificarAlumno( estructuraEmpleados   array[], int tamanoDeArray, int posicion);
int buscarLegajo(estructuraEmpleados array[], int tamanoDeArray);
int borrarElEmpleado(estructuraEmpleados array[], int tamano);

//int mostrarSiCargoBien(estructuraEmpleados array[], int tamano);
//int utn_getCharSexo(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

	estructuraEmpleados empleado[CANTIDADEMPLEADOS];

	inicializarEstructuraEmpleados(empleado, CANTIDADEMPLEADOS);


	int respuesta = 0;

    int contadorDeLegajo = 1000;
    int seIngresoUnEmpleado= -1;
		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

		case 1: //AGREGAR UN EMPLEADO

			agregarEmpleado( empleado, CANTIDADEMPLEADOS, &contadorDeLegajo );

			break;
		case 2:  // MODIFICAR UN EMPLEADO

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADEMPLEADOS);
			if (seIngresoUnEmpleado > 0){
				//modificarAlumno(alumno, CANTIDADALUMNOS );

				printf("\n // MODIFICAR UN ALUMNO");
			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}

			break;
		case 3: // ELIMINAR UN EMPLEADO

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADEMPLEADOS);
			if (seIngresoUnEmpleado > 0){

			borrarElEmpleado(empleado, CANTIDADEMPLEADOS);

			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}

			break;

		case 4: // MOSTRAR ALUMNOS

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADEMPLEADOS);
			if (seIngresoUnEmpleado > 0){
			mostrarTodosLosEstudiantes(empleado, CANTIDADEMPLEADOS);

			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}
			break;

		case 5: // SALIR
			break;


		}

	} while (respuesta != 5);

	return EXIT_SUCCESS;
};




int inicializarEstructuraEmpleados(estructuraEmpleados array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que está libre.
		}
		retorno = 0;
	}
	return retorno;
};

/*
int mostrarSiCargoBien(datosPersonales array[], int tamano) {
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


// INGRESO - ALTA


int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[30];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 30)
			{
				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
};

/*
void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos){

	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*variableChar = bufferChar;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}

*/

/*
int utn_getCharSexo(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin); // SIEMPRE VA AL TOMAR CHARs
			scanf("%c", &bufferChar);

			if(bufferChar == 'f' || bufferChar == 'm')
			{
				*variableChar = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;

			}
		}while(reintentos>=0);
	}
	return retorno;

}
 * */


//3-Listar

int mostrarUnEstudiante( estructuraEmpleados unEmpleado){
	printf("          %d      %s        %s        %.2f        %d      \n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido , unEmpleado.salario, unEmpleado.sector);

	return 0;

}

int mostrarTodosLosEstudiantes(estructuraEmpleados array[], int tamano){
	int retorno = -1;

		if(array != NULL && array > 0){
			printf(" ****************  DATOS PERSONALES DE EMPLEADOS  ***************** \n ");
			printf("        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR \n");

			for(int i = 0; i < tamano ; i++){
				if(array[i].isEmpty == 0){

				mostrarUnEstudiante( array[i]);
				}
			}
			retorno = 0;
		}

	return retorno;

}

/*
int promediarNotas(float *promedio, int nota1, int nota2){

	int retorno = -1;
	float auxiliarpromedio;

	if (promedio != NULL){
		auxiliarpromedio = ((float)nota1 + nota2)/ 2;
		*promedio= auxiliarpromedio;
		retorno = 0;
	};
	return retorno;
}

 * */

int agregarEmpleado( estructuraEmpleados   array[], int tamanoDeArray, int *contadorDeLegajo ){
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
				  (utn_getString(empleadoAuxiliar.nombre,"\n Ingrese el nombre ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getString(empleadoAuxiliar.apellido,"\n Ingrese el apellido ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getFloat(&empleadoAuxiliar.salario,"\n Ingrese el salario (Entre 10000 y 80000)", "\n Error, ingrese la nota1. Entre 1 y 10", 10000, 80000,3) == 0) &&
				  (utn_getNumero(&empleadoAuxiliar.sector,"\n Ingrese el sector al que pertenece \n    1- Ventas \n    2- RRHH \n    3- IT       ", "\n Error, ingrese la nota2. Entre 1 y 10", 0, 10,3) == 0)
			   )
					{
					empleadoAuxiliar.isEmpty = 0;
					empleadoAuxiliar.id= *contadorDeLegajo;
					array[posicion] = empleadoAuxiliar;
					(*contadorDeLegajo)++; //Aumenta el lejago en 1, inicializado en 1000

					printf("\n *** Empleado guardado *** \n");
					retorno = 0;
				}
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
		mostrarTodosLosEstudiantes(array, tamanoDeArray);
		printf("\n Ingrese un legajo   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].id==legajoAuxiliar ) //revisa si existe
			{
				if(array[i].isEmpty==0){ // y si está ocupado

					printf(" El legajo '%d' ha sido encontrado  \n", legajoAuxiliar);
					retorno = i;

					break;
				}
			}
			else
			{
				printf("El legajo  '%d' no existe \n", legajoAuxiliar);
				break;
			}
		}// fin for

	}
	return retorno;
}
int borrarElEmpleado(estructuraEmpleados array[], int tamano) {

	int retorno = -1;
	int posicion = -1;
	char respuesta;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL ) {
		printf("\nDesea borrar este legajo? \n");
		printf("\n ****************  DATOS PERSONALES DE EMPLEADOS  *****************  ");
		printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
		mostrarUnEstudiante( array[posicion]);
		printf("\n ingrese 's' para dar de baja.");
		fflush(stdin);
		scanf("%c", &respuesta);
		if(respuesta=='s'){
			array[posicion].isEmpty = 1; // Pone el campo isEmpty array en 1, es decir que está libre.
			retorno = 0;
			printf("\n *** Empleado dado de baja *** \n");
		}
	}
	return retorno;
};

//case 4
int modificarAlumno( estructuraEmpleados   array[], int tamanoDeArray, int posicion){
	int retorno = -1;
	int legajoAuxiliar;
	mostrarTodosLosEstudiantes(array, tamanoDeArray);
	printf("Ingrese el legajo del estudiante a modificar");
	fflush(stdin);
	scanf("%d", &legajoAuxiliar);
	for( int i = 0; i<tamanoDeArray ; i++ )
	{
		if(array[i].id == legajoAuxiliar ){
			mostrarUnEstudiante(array[i]);
		}

	};



	return retorno;
}
/* imprimes la lista pides legajo, submenu que dato
 * quieres mod, elije la opcion y un switch y uno pides
 * el numeo apellido y se lo asignas con el que tenía
 * recibes el array, largo legajo
 */


/*


	utn_getCharSexo(&alumno[posicion].sexo,"Ingrese el sexo -f -m\n", "Error, intente nuevamente",3);
	utn_getNumero(&alumno[posicion].edad,"Ingrese la edad\n", "Error, ingrese la edad. Entre 18 y 80\n", 18, 80,3);
	utn_getNumero(&alumno[posicion].nota1,"Ingrese la nota1\n", "Error, ingrese la nota1. Entre 1 y 10\n", 0, 10,3);
	utn_getNumero(&alumno[posicion].nota2,"Ingrese la nota2\n", "Error, ingrese la nota2. Entre 1 y 10\n", 0, 10,3);
	promediarNotas(&alumno[posicion].promedio, alumno[posicion].nota1, alumno[posicion].nota2);
	utn_getString(alumno[posicion].apellido,"Ingrese el apellido \n", "Error intente nuevamente", 3);
	alumno[posicion].isEmpty = 0;

*/





//recoro stgrin  con el strlen y te fijas con is alfa paara ver si es




