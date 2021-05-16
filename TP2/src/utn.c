/*
 * utn.c
 *
 *  Creado en: MAYO 10, 2021
 *      Autor: Andrea Briceño
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacion.h"
#include "utn.h"
#define TAMANOSTRING 51

//INICIALIZACION

int mostrarMenu(int *respuesta) {
	int auxRespuesta;
	printf(" \n -------------------- MENÚ ABM ---------------------");
	printf( "\n |          1. ALTA DE EMPLEADOS                   |"
			"\n |          2. MODIFICAR  UN EMPLEADO              |"
			"\n |          3. DAR DE BAJA A UN EMPLEADO           |"
			"\n |          4. INFORMAR                            |"
			"\n |          5. SALIR                               |"
			"\n |_________________________________________________|");

	utn_getNumero(&auxRespuesta, "\n\n  Ingrese una opcion    ","\nError, ingrese un numero del 1 al 5\n\n", 1, 5,3);
	*respuesta = auxRespuesta;

	return 0;

};



int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){

	int retorno = -1;
	char bufferString[TAMANOSTRING];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferString);
			if(esString(bufferString) ==  0 && strlen(bufferString) < TAMANOSTRING){
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

int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int auxiliar; //variable auxiliar;
	if ( resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0 ) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	float auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin); // SIEMPRE VA AL TOMAR CHARs
			scanf("%c", &bufferChar);

			if(bufferChar == 's' || bufferChar == 'n')
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













