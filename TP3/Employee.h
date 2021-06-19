#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



/** \brief reserva un espacio de memoria de tipo empleado y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \return Retorna un empleado nuevo
 *
 */
Employee* employee_new();


/** \brief Crea un empleado nuevo y lo devuelve por retorno
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Retorna un empleado nuevo
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_printfOne(Employee* this);

int employee_sortID(void* thisA, void* thisB);
int employee_sortNombres(void* thisA, void* thisB);
int employee_sortHoras(void* thisA, void* thisB);
int employee_sortSueldo(void* thisA, void* thisB);

#endif // employee_H_INCLUDED
