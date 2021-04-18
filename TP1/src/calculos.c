/*
 * calculos.c
 *
 *  Creado en: Abril 8, 2021
 *      Author: Andrea Brice�o
 */

#include <stdio.h>
#include <stdlib.h>



int utn_getSuma(int numero1, int numero2, int *respuestaSuma)
{   int retorno = 1;
	if(respuestaSuma != NULL){
	int resultado = numero1+numero2;
	*respuestaSuma = resultado;
	retorno = 0 ;
	};
	return retorno;
};

int utn_getResta(int numero1, int numero2, int *respuestaResta)
{	int retorno = 1;
	if(respuestaResta != NULL){
	int resultado = numero1-numero2;
	*respuestaResta = resultado;
	retorno = 0 ;
		};
	return retorno;
};

int utn_getDivision(int numero1, int numero2, float *respuestaDivision)
{

	int retorno = 1;
	if(respuestaDivision != NULL && numero2 != 0 && numero1 != 0){
	float resultado;
		resultado = (float)numero1/numero2;
	*respuestaDivision = resultado;
	retorno = 0 ;
	};
	return retorno;
};

int utn_getMultiplicacion(int numero1, int numero2, int *respuestaMultiplicacion)
{
	int retorno = 1;
	if(respuestaMultiplicacion != NULL){
	int resultado = numero1*numero2;
	*respuestaMultiplicacion = resultado;
	retorno = 0 ;
	};
	return retorno;
};

int unt_getFactorial(int numero, int *respuestaFactorial){
	int resultado;
	int retorno;
	if(respuestaFactorial != NULL && numero > 0){
		resultado = numero;
			for ( int i = numero; i > 1;i--)
				{
				resultado = ((i - 1) * resultado);
				*respuestaFactorial = resultado;

				}
			retorno= 0;
	}else{
		resultado = 0;
		*respuestaFactorial = resultado;
		retorno = 1;
	};
	return retorno;
};






