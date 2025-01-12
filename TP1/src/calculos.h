/*
 * calculos.h
 *
 *  Creado en: Abril 8, 2021
 *      Author: Andrea Brice�o
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/*
 * BRIEf calcula la suma de dos numeros
 * param numero1 recibe un numero entero
 * param numero2 recibe un numero entero
 * param respuestaSuma recibe un puntero para guardar el resultado de la suma entre los parametros
 * return en caso de exito 0, error 1
 * */
int utn_getSuma(int numero1, int numero2, int *respuestaSuma);


/*
 * BRIEf calcula la resta de dos numeros
 * param numero1 recibe un numero entero
 * param numero2 recibe un numero entero
 * param respuestaResta recibe un puntero para guardar el resultado de la resta entre los parametros
 * return en caso de exito 0, error 1
 * */
int utn_getResta(int numero1, int numero2, int *respuestaResta);

/*
 * BRIEf calcula la division de dos numeros
 * param numero1 recibe un numero entero
 * param numero2 recibe un numero entero
 * param respuestaDivision recibe un puntero para guardar el resultado de la division entre los parametros
 * return en caso de exito 0, error 1
 * */
int utn_getDivision(int numero1, int numero2, float *respuestaDivision);

/*
 * BRIEf calcula la multiplicacion de dos numeros
 * param numero1 recibe un numero entero
 * param numero2 recibe un numero entero
 * param respuestaMultiplicacion recibe un puntero para guardar el producto los parametros
 * return en caso de exito 0, error 1
 * */
int utn_getMultiplicacion(int numero1, int numero2, int *respuestaMultiplicacion);

/*
 * BRIEF calcula el factorial de un numero
 * param numero recibe un numero entero para calcular el factorial
 * param respuestaFactorial recibe un puntero para guardar el factorial
 * return en caso de exito 0, error 1
 * */

int unt_getFactorial(int numero, int *respuestaFactorial);

#endif /* CALCULOS_H_ */
