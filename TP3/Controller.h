 /** controller.h
 *
 *      Author: Andrea Brice�o
 */

/** \brief Alta de empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addLibro(LinkedList* pointerArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editLibro(LinkedList* pointerArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeLibro(LinkedList* pointerArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pointerArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_sortLibro(LinkedList* pointerArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int controller_saveAsText(char* path , LinkedList* pointerArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pointerArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pointerArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pointerArrayListEmployee);





