/*
 * menu.c
 *
 *  Creado en: Abril 16, 2021
 *      Autor: Andrea Brice�o
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo){

	int retorno = -1;
	int auxiliar ; //variable auxiliar;
	if (resultado != NULL  && mensaje != NULL && mensajeError != NULL && minimo <= maximo ){


		printf("%s \n", mensaje);
		scanf("%d", &auxiliar);
		if(auxiliar >= minimo && auxiliar <=maximo ){
			*resultado =auxiliar;

			retorno = 0;

		}else{

			printf("%s", mensajeError);
			retorno = -1;
		};

	}
	return retorno;
};

