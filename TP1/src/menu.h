/*
 * menu.h
 *
 *  Creado en: Abril 16, 2021
 *      Autor: Andrea Briceño
 */

#ifndef MENU_H_
#define MENU_H_



/*
 * Brief Solicita un numero al usuario, valida y devuelve el resultado
 * param resultado puntero donde se guardará lo que ingrese el usuario
 * param mensaje mensaje a ser mostrado
 * param mensajeError mensaje mostrado en caso de error
 * param minimo numero minimo aceptado
 * param maximo numero maximo aceptado
 * return en caso de exito 0, error -1
 * */
int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo);


#endif /* MENU_H_ */
