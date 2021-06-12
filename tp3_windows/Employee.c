
#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include <stdlib.h>


Employee* employee_new()
{
	return(Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmpleado = employee_new();
	if(auxEmpleado!= NULL)
	{
		if  (employee_setId(auxEmpleado,idStr) < 0 ||
			 employee_setNombre(auxEmpleado,nombreStr) < 0 ||
			 employee_setHorasTrabajadas(auxEmpleado, horasTrabajadasStr) < 0 ||
			 employee_setSueldo(auxEmpleado,sueldoStr) < 0 )
		{
			employee_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}
	return auxEmpleado;
}

int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
////////////////---------------------------------------------ID-------------------------

int employee_setId(Employee* this,char* id)///2:53
{
	int retorno = -1;
	int idEmpleado;
	if(this != NULL && id != NULL && isValidId(id))
	{
		idEmpleado=atoi(id);
		this->id=idEmpleado;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this, int* flagError)
{
	*flagError = -1;
	int auxid;
	if(this != NULL && flagError!=NULL )
	{
		auxid = this->id;
		*flagError = 0;
	}
	return auxid;
}

int isValidId(char* id)
{
	int retorno=-1;
	if(esNumerica(id)==0)
	{
		retorno=1;
	}
	return retorno;
}
////////////////---------------------------------HORAS TRABAJADAS------------------------
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	int auxHorasTrabajadas;
	if(this!= NULL && horasTrabajadas>=0 && isValidHorasTrabajadas(horasTrabajadas)&&esNumerica(horasTrabajadas)==0)
	{
		auxHorasTrabajadas=atoi(horasTrabajadas);
		this->horasTrabajadas=auxHorasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* flagError)
{
	*flagError = -1;
	int auxHorasTrabajadas;
	if(this!= NULL && flagError!=NULL)
	{
		auxHorasTrabajadas = this->horasTrabajadas;
		*flagError = 0;
	}
	return auxHorasTrabajadas;
}

int isValidHorasTrabajadas(char* horasTrabajadas)
{
	return 1;
}

//------------------------------------------------------------Sueldo------------------------------
int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno = -1;
	int auxSueldo;
	if(this!= NULL && sueldo>=0 && isValidSueldo(sueldo)&&esNumerica(sueldo)==0)
	{
		auxSueldo=atoi(sueldo);
		this->sueldo=auxSueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* flagError)
{
	*flagError = -1;
	int auxSueldo;
	if(this != NULL && flagError != NULL )
	{
		auxSueldo = this->sueldo;
		*flagError = 0;
	}
	return auxSueldo;
}
int isValidSueldo(char* sueldo)
{
	return 1;
}
//----------------------------------------------------------------Nombre----------------------------------------
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre!= NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

char* employee_getNombre(Employee* this, int* flagError)
{
	*flagError = -1;
	char* auxnombre = 0;
	if(this != NULL && flagError != NULL )
	{
		auxnombre=this->nombre;
		*flagError = 0;
	}
	return auxnombre;
}

int isValidNombre(char* tipo)
{
	return 1;
}
