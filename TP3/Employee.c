#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

Employee* employee_new(){
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* auxiliarEmployee = employee_new();

	if( idStr != NULL && nombreStr != NULL &&  horasTrabajadasStr != NULL && sueldoStr != NULL){
			if( (employee_setId( auxiliarEmployee, atoi(idStr) )  ==0) &&
				(employee_setNombre( auxiliarEmployee, nombreStr) ==0) &&
				(employee_setHorasTrabajadas( auxiliarEmployee, atoi(horasTrabajadasStr) ) ==0) &&
				(employee_setSueldo( auxiliarEmployee, atoi(sueldoStr) ) ==0) ){

				}else{
					auxiliarEmployee=NULL;

				}
	}
	return auxiliarEmployee;
}

int employee_setId(Employee* this,int id){
	int retorno=-1;
		if(this != NULL && id > 0){
			this -> id = id;
			retorno = 0;
		}

	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno=-1;
	if( this != NULL && id != NULL ){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


int employee_setNombre(Employee* this,char* nombre){
	int retorno=-1;
	if( this != NULL && nombre != NULL){
		strcpy( this -> nombre , nombre );
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno=-1;
	if( this != NULL && nombre != NULL){
		strcpy( nombre , this -> nombre );
		retorno = 0;
	}
	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno=-1;
	if( this != NULL &&  horasTrabajadas > -1){
		 this -> horasTrabajadas = horasTrabajadas ;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno=-1;
	if( this != NULL &&  horasTrabajadas != NULL){
		*horasTrabajadas = this -> horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_setSueldo(Employee* this,int sueldo){
	int retorno=-1;
	if( this != NULL &&  sueldo > -1){
		 this -> sueldo = sueldo ;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int retorno=-1;
	if( this != NULL &&  sueldo != NULL){
		*sueldo = this -> sueldo;
		retorno = 0;
	}
	return retorno;
}

void employee_printfOne(Employee* this){
	printf("\n  ****************  DATOS PERSONALES DEL EMPLEADO  ***************** ");
	printf("\n %d.  Empleado: %s,     Horas trabajadas: %d,      Sueldo: $%d ",
			(*(this)).id,
			(*(this)).nombre,
			(*(this)).horasTrabajadas,
			(*(this)).sueldo);

};




int employee_sortHoras(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarHorasA;
	int auxiliarHorasB;

		if(thisA!=NULL && thisB!=NULL){
			if(     employee_getHorasTrabajadas(thisA, &auxiliarHorasA)==0 &&
					employee_getHorasTrabajadas(thisB, &auxiliarHorasB)==0){
				if(auxiliarHorasA > auxiliarHorasB){
					retorno=1;
				}
				if(auxiliarHorasA < auxiliarHorasB){
					retorno=-1;
				}
			}
		}
		return retorno;
}

//if(strcmp(auxNombre1,auxNombre2)>0

int employee_sortNombres(void* thisA, void* thisB){
	int retorno=0;
	char auxiliarNombreA[130];
	char auxiliarNombreB[130];

		if(thisA!=NULL && thisB!=NULL){
			if(     employee_getNombre(thisA, auxiliarNombreA)==0 &&
					employee_getNombre(thisB, auxiliarNombreB)==0){
				if(strcmp (auxiliarNombreA , auxiliarNombreB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarNombreA , auxiliarNombreB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int employee_sortID(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarIdA;
	int auxiliarIdB;

		if(thisA!=NULL && thisB!=NULL){
			if(     employee_getId(thisA, &auxiliarIdA)==0 &&
					employee_getId(thisB, &auxiliarIdB)==0){
				if(auxiliarIdA > auxiliarIdB){
					retorno=1;
				}
				if(auxiliarIdA < auxiliarIdB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int employee_sortSueldo(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarSueldoA;
	int auxiliarSueldoB;

		if(thisA!=NULL && thisB!=NULL){
			if(     employee_getSueldo(thisA, &auxiliarSueldoA)==0 &&
					employee_getSueldo(thisB, &auxiliarSueldoB)==0){
				if(auxiliarSueldoA > auxiliarSueldoB){
					retorno=1;
				}
				if(auxiliarSueldoA < auxiliarSueldoB){
					retorno=-1;
				}
			}
		}
		return retorno;
}

