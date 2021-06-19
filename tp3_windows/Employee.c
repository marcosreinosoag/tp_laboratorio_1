
#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include <stdlib.h>

/** \brief Crea un espacio en memoria para un empleado.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
	return(Employee*) malloc(sizeof(Employee));
}

/** \brief Carga los datos del empleado.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee*
 *
 */
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
/** \brief Libera el espacio en memoria del empleado.
 *
 * \param Employee* this
 * \return int retorno
 *
 */
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
/** \brief Carga el id del empleado.
 *
 * \param Employee* this
 * \param char* id
 * \return int retorno
 *
 */
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

/** \brief Obtiene el id del empleado.
 *
 * \param Employee* this
 * \param int* flagError
 * \return int auxid
 *
 */
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
/** \brief Valida que la cadena de caracteres sea numerica.
 *
 * \param char* id
 * \return int retorno
 *
 */
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
/** \brief Carga las Horas Trabajadas del empleado.
 *
 * \param Employee* this
 * \param char* id
 * \return int retorno
 *
 */

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

/** \brief Obtiene las Horas Trabajadas del empleado.
 *
 * \param Employee* this
 * \param int* flagError
 * \return int auxHorasTrabajadas
 *
 */
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

/** \brief Valida que la cadena de caracteres sea numerica.
 *
 * \param char* horasTrabajadas
 * \return int retorno
 *
 */
int isValidHorasTrabajadas(char* horasTrabajadas)
{
	return 1;
}

//------------------------------------------------------------Sueldo------------------------------
/** \brief Carga el sueldo del empleado.
 *
 * \param Employee* this
 * \param char* sueldo
 * \return int retorno
 *
 */
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
/** \brief Obtiene el sueldo del empleado.
 *
 * \param Employee* this
 * \param int* flagError
 * \return int auxSueldo
 *
 */
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
/** \brief Valida que la cadena de caracteres sea numerica.
 *
 * \param char* horasTrabajadas
 * \return int retorno
 *
 */
int isValidSueldo(char* sueldo)
{
	return 1;
}
//----------------------------------------------------------------Nombre----------------------------------------
/** \brief Carga el nombre del empleado.
 *
 * \param Employee* this
 * \param char* nombre
 * \return int retorno
 *
 */
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

/** \brief Obtiene el nombre del empleado.
 *
 * \param Employee* this
 * \param int* flagError
 * \return int auxnombre
 *
 */
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
/** \brief Valida que la cadena de caracteres sea numerica.
 *
 * \param char* horasTrabajadas
 * \return int retorno
 *
 */
int isValidNombre(char* tipo)
{
	return 1;
}
