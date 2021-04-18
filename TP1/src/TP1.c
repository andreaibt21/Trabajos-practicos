/*******************************************************************
*Programa:Calculadora
*
*Objetivo:
*Ingresar dos numeros y calcular operaciones entre ellos
*
*1. Ingresar 1er operando (A=x)
*2. Ingresar 2do operando (B=y)
*3. Calcular todas las operaciones
*a) Calcular la suma (A+B)
*b) Calcular la resta (A-B)
*c) Calcular la division (A/B)
*d) Calcular la multiplicacion (A*B)
*e) Calcular el factorial (A!)
*4. Informar resultados
*a) “El resultado de A+B es: r”
*b) “El resultado de A-B es: r”
*c) “El resultado de A/B es: r” o “No es posible dividir por cero”
*d) “El resultado de A*B es: r”
*e) “El factorial de A es: r1 y El factorial de B es: r2”
*5. Salir
*
*Version:0.1 del 17 Abril del 2021
*Autor:Andrea Briceño Tovar
*Division: 1E
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int numero2;
	int numero1;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int seIngresoPrimerNumero = 0;
	int seIngresoSegundoNumero = 0;
	int seHicieronLosCalculos = 0;
	do{

			utn_getNumero(&opcion, "\n  Bienvenido al menu de la Calculadora \n "
			"1. Ingresar 1er operando (A=x)"
			"\n 2. Ingresar 2do operando (B=y)"
			"\n 3. Calcular todas las operaciones\n"
			" ( Calcular la suma, resta, division, multiplicacion y el factorial)\n"
			" 4. Informar resultados\n"
			" 5. Salir \n"
			, "\nError ingrese un numero del 1 al 5 \n\n", 1,5);

			switch (opcion){

				case 1:
					if (seIngresoPrimerNumero == 0 )
						{
							seIngresoPrimerNumero = 1;
							utn_getNumero(&numero1,"\nIngrese el primer operando  \n", "Intente nuevamente",-999999,999999);
							printf(" A = %d \n", numero1);
						}else{
							printf("Error, Ya ingresaste el primer operando\n");
					};

					break;
				case 2:
					if (seIngresoSegundoNumero == 0)
					{
						seIngresoSegundoNumero = 1;
						utn_getNumero(&numero2,"\nIngrese el segundo operando  \n", "Intente nuevamente",-999999,999999);
						printf(" B = %d \n", numero2);
					}else{
						printf("Error, ya ingresaste el segundo operando\n");
					};
						break;
				case 3:
					if (seIngresoPrimerNumero == 1 && seIngresoSegundoNumero == 1){

						seHicieronLosCalculos = 1;
						printf("A = %d, B = %d\n", numero1, numero2);
						utn_getSuma(numero1, numero2, &resultadoSuma);
						utn_getResta(numero1, numero2, &resultadoResta);
						utn_getDivision(numero1, numero2, &resultadoDivision);
						utn_getMultiplicacion(numero1, numero2, &resultadoMultiplicacion);
						unt_getFactorial(numero1, &resultadoFactorial1);
						unt_getFactorial(numero2, &resultadoFactorial2);
					} else{

						printf("Error, debe de ingresar los dos operandos para realizar las operaciones");

					};
						break;
				case 4:
					if (seHicieronLosCalculos == 1){

						/*
						 * a) “El resultado de A+B es: r”
							b) “El resultado de A-B es: r”
							c) “El resultado de A/B es: r” o “No es posible dividir por cero”
							d) “El resultado de A*B es: r”
							e) “El factorial de A es: r1 y El factorial de B es: r2”
							*/

						//suma
						printf(" El resultado de %d+%d es: %d \n",numero1,numero2,resultadoSuma);
						//restaa
						printf(" El resultado de %d-%d es: %d \n",numero1,numero2,resultadoResta);
						//division
						if(utn_getDivision(numero1, numero2, &resultadoDivision) != 0){
							printf(" No se puede dividir entre 0 \n");
						}else{
							printf(" El resultado de %d/%d es: %.2f \n",numero1,numero2,resultadoDivision);
						};
						//multiplicacion
						printf(" El resultado de %d*%d es: %d \n",numero1,numero2,resultadoMultiplicacion);
						//factorial numero1
						if(  unt_getFactorial(numero1, &resultadoFactorial1) != 0 ){
								printf("No se puede calcular el factorial de numeros negativos\n");
						}else{
							printf(" El factorial de %d es: %d\n",numero1, resultadoFactorial1);
						};
						//factorial numero2
						if(  unt_getFactorial(numero2, &resultadoFactorial2) != 0 ){
							printf("No se puede calcular el factorial de numeros negativos\n");
						}else{
						printf(" El factorial de %d es: %d \n",numero2, resultadoFactorial2);

						};

					}else{

						printf("Error, no has realizado los calculos\n");
					};

				break;
				case 5:
						printf("Calculadora cerrada");
					break;
				}//fin switch


		}
		while( opcion != 5);//fin do while





		return EXIT_SUCCESS;

};












