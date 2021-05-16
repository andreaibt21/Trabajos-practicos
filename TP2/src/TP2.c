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
#include "validacion.h"
#include "utn.h"
#define  CANTIDADEMPLEADOS 5
#define LARGODESTRING 51

//almunos.h en el punto c incluyo el .h para que las funciones me sirven

/*
 * Brief inicializa en 1 cada posicion del array de estructuras
 * param resultado  resultado puntero donde se guardará lo que ingrese el usuario
 * param mensaje mensaje mensaje a ser mostrado
 * param mensajeError mensajeError mensaje mostrado en caso de error
 * param minimo numero minimo aceptado
 * param maximo maximo numero maximo aceptado
 * return retorna en caso de exito 0, error -1
 *
 */

//int utn_getCharSexo(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE



	int respuesta = 0;
    int contadorDeLegajo = 1000;
    int seIngresoUnEmpleado= -1;
    int opcionDeInforme = -1;

	estructuraEmpleados empleado[CANTIDADEMPLEADOS];

	inicializarEstructuraEmpleado(empleado, CANTIDADEMPLEADOS);
		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

		case 1: //AGREGAR UN EMPLEADO

			agregarUnEmpleado( empleado, CANTIDADEMPLEADOS, &contadorDeLegajo );

			break;
		case 2:  // MODIFICAR UN EMPLEADO

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADEMPLEADOS);
			if (seIngresoUnEmpleado > 0){
				printf("\n  ***************      MODIFICAR UN EMPLEADO     *************** \n");
				modificarUnEmpleado(empleado, CANTIDADEMPLEADOS);
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
			//seleccionarInforme(empleado, CANTIDADEMPLEADOS, &opcionDeInforme);

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





