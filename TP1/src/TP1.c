/*
 ============================================================================
 Name        : TP1.c
 Author      : 	ANDREA BRICE�O
 ============================================================================
Bienvenido al menu de la Calculadora
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	//utn_menu();
	do{
	utn_getNumero(&opcion, "\n  Bienvenido al menu de la Calculadora \n "
			"1. Ingresar 1er operando (A=x)"
			"\n 2. Ingresar 2do operando (B=y)"
			"\n 3. Calcular todas las operaciones\n"
			" ( Calcular la suma, resta, division, multiplicacion y el factorial)\n"
			" 4. Informar resultados\n"
			" 5. Salir \n"
			, "\nError ingrese un numero del 1 al 5 \n\n", 1,5);

			int numero2;
			int numero1;
			int resultadoSuma;
			int resultadoResta;
			int resultadoDivision;
			int resultadoMultiplicacion;
			int seIngresoPrimerNumero = 0;
			int seIngresoSegundoNumero = 0;
			switch (opcion){

				case 1:
				if (seIngresoPrimerNumero!= 1)
					{
					seIngresoPrimerNumero = 1;
				utn_getNumero(&numero1,"\nIngrese el primer operando  \n", "Intente nuevamente",-999999,999999);
				//printf("%d",seIngresoPrimerNumero);
					}else{
					printf("Ya ingresaste el primer numero\n");
				};

					break;
				case 2:
					if (seIngresoSegundoNumero == 0)
					{
						utn_getNumero(&numero2,"\nIngrese el segundo operando  \n", "Intente nuevamente",-999999,999999);
						seIngresoSegundoNumero = 1;
					}else{
						printf("Ya ingresaste el segundo numero\n");
					};
						break;
				case 3:
					//hacer validacion de haber ingresado opcion 1 y 2 primero
				utn_getSuma(numero1, numero2, &resultadoSuma);
				utn_getResta(numero1, numero2, &resultadoResta);
				utn_getDivision(numero1, numero2, &resultadoDivision);
				utn_getMultiplicacion(numero1, numero2, &resultadoMultiplicacion);
						break;
				case 4:
					//hacer validacion de haber ingresado opcion 1,2 y 3 primero
				printf(" El resultado de la suma es %d \n",resultadoSuma);
				printf(" El resultado de la resta es %d \n",resultadoResta);
				printf(" El resultado de la division es %d \n", resultadoDivision);
				printf(" El resultado de la multiplicacion es %d \n", resultadoMultiplicacion);
				break;
				}//fin switch

		//	printf("%d, %d", numero1, numero2);
		}
		while( opcion != 5);





		return EXIT_SUCCESS;

};












