/*
 * menu.c
 *
 *  Created on: Apr 16, 2021
 *      Author: andrea briceño
 */

#include <stdio.h>
#include <stdlib.h>
int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo){

	int retorno = -1;
	int buffer ; //variable auxiliar;
	if (resultado != NULL  && mensaje != NULL && mensajeError != NULL && minimo <= maximo ){

		do{
		printf("%s \n", mensaje);
		scanf("%d", &buffer);
		if(buffer >= minimo && buffer <=maximo ){
			*resultado =buffer;
		printf("Opcion seleccionada %d", buffer);
			retorno = 0;

		}else{

			printf("%s", mensajeError);
			retorno = -1;
		};
		}while(*resultado != 5);
	}
	return retorno;
};

