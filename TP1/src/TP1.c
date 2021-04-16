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
	utn_getNumero(&opcion, "Bienvenido al menu de la Calculadora \n "
			"1. Ingresar 1er operando (A=x)"
			"\n 2. Ingresar 2do operando (B=y)"
			"\n 3. Calcular todas las operaciones\n"
			" a) Calcular la suma (A+B)\n "
			"b) Calcular la resta (A-B) \n "
			"c) Calcular la division (A/B)\n "
			"d) Calcular la multiplicacion (A*B)\n "
			"e) Calcular el factorial (A!)\n"
			, "\nError ingrese un numero del 1 al 5 \n\n", 1,5);

		return EXIT_SUCCESS;

};












