/*
 * utn.h
 *
 *  Created on: May 13, 2021
 *      Author: andrea briceño
 */


#ifndef UTN_H_
#define UTN_H_


 /**  \brief obtiene un numero entero, muestra un mensaje antes de pedir el numero y si hubo un error muestra otro mensaje
 * \param int *resultado
 * \param char *mensaje mensaje antes de pedir el numero
 * \param char *mensajeError mensaje de error
 * \param int minimo limite del numero
 * \param int maximo limite del numero
 * \param int reintentos cantidad de oportunidades
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 * */
int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
/**  \brief obtiene un numero flotate/con decimales, muestra un mensaje antes de pedir el numero y si hubo un error muestra otro mensaje
* \param int *resultado
* \param char *mensaje mensaje antes de pedir el numero
* \param char *mensajeError mensaje de error
* \param int minimo limite del numero
* \param int maximo limite del numero
* \param int reintentos cantidad de oportunidades
* \return Retorna 0 si fue un exito, -1 si hubo un error
* */
int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
/**  \brief Muestra un menú con opciones por consola y guarda un numero pedido, por puntero
* \param respuesta Numero pedido al usuario usando utn_getNumero
* \return Retorna 0
* */
int mostrarMenu(int *respuesta);

/**  \brief obtiene un cuil como String, muestra un mensaje antes de pedir el string y si hubo un error muestra otro mensaje
* \param char auxiliar[] string auxiliar
* \param char *mensaje mensaje antes de pedir el numero
* \param char *mensajeError mensaje de error
* \param int reintentos cantidad de oportunidades
* \return Retorna 0 si fue un exito, -1 si hubo un error si no tiene el formato de un cuil
* */
int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
/**  \brief obtiene un String, muestra un mensaje antes de pedir el string y si hubo un error muestra otro mensaje
* \param char auxiliar[] string auxiliar
* \param char *mensaje mensaje antes de pedir el numero
* \param char *mensajeError mensaje de error
* \param int reintentos cantidad de oportunidades
* \return Retorna 0 si fue un exito, -1 si hubo un error
* */
int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
/**  \brief obtiene un Char, muestra un mensaje antes de pedir el char y si hubo un error muestra otro mensaje
* \param char variableChar es pedido por consola
* \param char *mensaje mensaje antes de pedir el numero
* \param char *mensajeError mensaje de error
* \param int reintentos cantidad de oportunidades
* \return Retorna 0 si el valor obtenido es 's' o 'n', -1 si hubo un error
* */
int utn_getCharAceptar(char *variableChar, char *mensaje, char *mensajeError, int reintentos);


//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

#endif /* UTN_H_ */
