/*
 * ArrayEmpleados.h
 *
 *  Created on: May 11, 2021
 *      Author: andrea briceño
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_



typedef struct {
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;
} estructuraEmpleados;


int inicializarEstructuraEmpleado(estructuraEmpleados array[], int tamano);

int buscarLibre(estructuraEmpleados array[], int tamano);

int mostrarUnEmpleados( estructuraEmpleados unEmpleado);

int mostrarTodosLosEmpleados(estructuraEmpleados array[], int tamano);

int modificarUnEmpleado( estructuraEmpleados   array[], int tamano);

int agregarUnEmpleado( estructuraEmpleados   array[], int tamanoDeArray, int *contadorDeLegajo );

int buscarLegajo(estructuraEmpleados array[], int tamanoDeArray);

int borrarElEmpleado(estructuraEmpleados array[], int tamano);

int obtenerSector(int numeroDeSector, char nombreDeSector[]);

void ordenarApellidosYSector(estructuraEmpleados array[], int tamano, int tipoDeOrden);

int seleccionarInforme(estructuraEmpleados array[], int tamano);
//int mostrarSiCargoBien(estructuraEmpleados array[], int tamano);



#endif /* ARRAYEMPLEADOS_H_ */
