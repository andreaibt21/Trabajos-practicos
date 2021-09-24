 /** Employee.h
 *
 *      Author: Andrea Briceño
 */

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Libro;



/** \brief reserva un espacio de memoria de tipo empleado y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \return Retorna un empleado nuevo
 *
 */
Libro* pelicula_new();


/** \brief Crea un empleado nuevo y lo devuelve por retorno
 *
 * \param char* idStr id del empleado
 * \param char* nombreStr nombre del empleado
 * \param char* horasTrabajadasStr horas de trabajo del empleado
 * \param char* sueldoStr sueldo del empleado
 * \return Retorna un empleado nuevo
 */
Libro* pelicula_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);



/** \brief Asigna un id al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_setId(Libro* this,int id);

/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_getId(Libro* this,int* id);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_setNombre(Libro* this,char* nombre);

/** \brief Asigna un nombre del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_getNombre(Libro* this,char* nombre);


/** \brief Asigna  horas de trabajo al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_setHorasTrabajadas(Libro* this,int horasTrabajadas);

/** \brief Asigna horas de trabajo del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_getHorasTrabajadas(Libro* this,int* horasTrabajadas);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_setSueldo(Libro* this,int sueldo);
/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int employee_getSueldo(Libro* this,int* sueldo);

/** \brief Imprime por consola un empleado
 * \param Employee* this empleado
 * \return void
 */
void employee_printfOne(Libro* this);



/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA horas de trabajo de un empleado
 * \param void* thisB horas de trabajo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int employee_sortHoras(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA nombre  de un empleado
 * \param void* thisB nombre de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int employee_sortNombres(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA id de un empleado
 * \param void* thisB id de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int employee_sortID(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA sueldo de un empleado
 * \param void* thisB sueldo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int employee_sortSueldo(void* thisA, void* thisB);

#endif // employee_H_INCLUDED
