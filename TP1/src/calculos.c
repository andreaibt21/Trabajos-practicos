/*
 * calculos.c
 *
 *  Created on: Apr 8, 2021
 *      Author: AANDREA BRICE�O
 */


#include <stdio.h>
#include <stdlib.h>



int utn_ingresarNumero(){
	int retorno;
	int numero;
	printf("     Ingrese un numero \n");
	scanf("%d", &numero);
	printf("     el numero ingresado es %d\n", numero);

	retorno = numero;

	return retorno;
};

int utn_getSuma(int numero1, int numero2)
{
	int retorno;

	retorno= numero1+numero2;


	return retorno;
};





int utn_menu(){

	int opcion;

	do{
		printf("MENU \n");
		printf(	"\n 1. Ingresar 1er operando (A=x) ");
		printf("\n 2. Ingresar 2do operando (B=y)");
		printf("\n 3. Calcular todas las operaciones ");
		printf("\n 4. Informar resultados");
		printf("\n 5. Salir");

		scanf("%d", &opcion);
		while( opcion > 5 || opcion < 1){
			printf("ERROR ingrese un numero del 1 al 4 para elefir su opcion del men� \n");
				scanf("%d", &opcion);
		};
		printf("Opcion selecionada %d \n",opcion);

		int numero2;
		int numero1;
		int resultadoSuma;
		int seIngresoPrimerNumero;
		int seIngresoSegundoNumero;
		switch (opcion){

			case 1:
				if (seIngresoPrimerNumero)
				{
				seIngresoPrimerNumero = 0;
				numero1 = utn_ingresarNumero();

				}else{
					printf("Ya ingresaste el primer numero");
				};

				break;
			case 2:
				if (seIngresoSegundoNumero
						)
				{
					numero2 = utn_ingresarNumero();
					seIngresoSegundoNumero = 1;
				}else{
					printf("Ya ingresaste el segundo numero");
				};
					break;
			case 3:

			resultadoSuma=	utn_getSuma(numero1, numero2);
					break;
			case 4:
				printf(" %d ",resultadoSuma);
					break;
			}//fin switch

	//	printf("%d, %d", numero1, numero2);
	}
	while( opcion != 5);

	return EXIT_SUCCESS;


};







