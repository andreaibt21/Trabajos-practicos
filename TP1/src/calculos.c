/*
 * calculos.c
 *
 *  Created on: Apr 8, 2021
 *      Author: ANDREA BRICE�O
 */


#include <stdio.h>
#include <stdlib.h>



int utn_getSuma(int numero1, int numero2, int *respuestaSuma)
{
	if(respuestaSuma != NULL){
	int resultado = numero1+numero2;
	*respuestaSuma = resultado;

	};
	return 0;
};

int utn_getResta(int numero1, int numero2, int *respuestaResta)
{
	if(respuestaResta != NULL){
	int resultado = numero1-numero2;
	*respuestaResta = resultado;

	};
	return 0;
};

int utn_getDivision(int numero1, int numero2, int *respuestaDivision)
{
	if(respuestaDivision != NULL){
	int resultado = numero1/numero2;
	*respuestaDivision = resultado;

	};
	return 0;
};

int utn_getMultiplicacion(int numero1, int numero2, int *respuestaMultiplicacion)
{
	if(respuestaMultiplicacion != NULL){
	int resultado = numero1*numero2;
	*respuestaMultiplicacion = resultado;

	};
	return 0;
};







