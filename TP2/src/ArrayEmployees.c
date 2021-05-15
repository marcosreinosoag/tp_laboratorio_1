/*
 * ArrayEmployees.c
 *
 *  Created on: 2 oct. 2020
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utn.h"
#include "ArrayEmployees.h"


static int Employee_generarNuevoId (void);

int employee_alta(Employee* list, int len)
{
	int id;
	int retorno=-1;
	Employee bufferEmployee;
	if(list!=NULL && len>0)
	{
		if(utn_getNombre("iNGRESE NOMBRE","ERROR!!!!!!!!!!!REINGRESE NOMBRE",bufferEmployee.name,3,LONG_NOMBRE)==0 &&
		utn_getNombre("iNGRESE APELLIDO","ERROR!!!!!!!!!!!REINGRESE APELLIDO",bufferEmployee.lastName,3,LONG_NOMBRE)==0 &&
		utn_getfloat("INGRESE SALARIO", "ERROR!!!!!!!!!!!REINGRESE SALARIO",&bufferEmployee.salary,3, 99999,0)==0 &&
		utn_getEntero("INGRESE SECTOR", "ERROR!!!!!!!!!!!REINGRESE SECTOR",&bufferEmployee.sector, 3,999999, 0)==0)
		{
			id = Employee_generarNuevoId();
			if(addEmployee(list,LEN_EMPLOYEE,id,bufferEmployee.name,bufferEmployee.lastName,bufferEmployee.salary,bufferEmployee.sector)==0)
			{
			retorno=0;
			}
			else
			{
				printf("ERRORR!!!!!!!!!!!!!");
			}
		}
	}
	return retorno;
}

int employee_modificarEmpleado(Employee* list,int len)
{
	int retorno=-1;
	int idAbuscar;
	if(list!=NULL && len>0)
	{
		if(employee_buscarOcupado(list,len)==0)
		{
			employee_print(list,LEN_EMPLOYEE);
			if(utn_getEntero("\nINGRESE EL ID QUE DESEA MODIFICAR:","\nERROR REINGRESE ID!!!!!",&idAbuscar,3,9999,0)==0)
			{
				findEmployeeById(list,LEN_EMPLOYEE,idAbuscar);
				retorno=0;
			}
		}
		else
		{
			printf("Error!!!! Debe ingresar un empleado para ingresar a esta opcion");
		}
	}
	return retorno;
}

int employee_bajaEmpleado(Employee* list,int len)
{
	int retorno=-1;
	int idAborrar;
	if(list!=NULL && len>0)
	{
		if(employee_buscarOcupado(list, LEN_EMPLOYEE)==0)
		{
			employee_print(list,LEN_EMPLOYEE);
			if(utn_getEntero("\nINGRESE EL ID QUE DESEA ELIMINAR:","\nERROR REINGRESE ID!!!!!",&idAborrar,3,9999,0)==0)
			{
				removeEmployee(list,LEN_EMPLOYEE,idAborrar);
				retorno=0;
			}
		}
		else
		{
			printf("Error!!!! Debe ingresar un empleado para ingresar a esta opcion");
		}
	}
	return retorno;
}

/** \brief Genera un id para asociarlo al Empleado
 */

static int Employee_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if (list != NULL && len >0){
		for (int i = 0; i<len; i++ )
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int indice;
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		if(employee_buscarLibreRef(list, len, &indice)==0)
		{
			strncpy(list[indice].name,name,LONG_NOMBRE);
			strncpy(list[indice].lastName,lastName,LONG_APELLIDO);
			list[indice].salary=salary;
			list[indice].sector=sector;
			list[indice].isEmpty=FALSE;
			list[indice].id=id;
			printf("\n/////////////////////////////////////////////////////////ALTA REALIZADA CORRECTAMENTE////////////////////////////////////////////////////////////////////\n"
			"\///////////////////////////////////////////Name: %s - LastName: %s - Salary %f - Sector: %d - ID: %d//////////////////////////////////////////////////////////\n"
				,list[indice].name ,list[indice].lastName , list[indice].salary, list[indice].sector,list[indice].id);
			retorno=0;
		}
		else{
			printf("La cantidad de empleados disponible ha sido ocupada");
		}
	}
	return retorno;
}



/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int indiceAmodificar;
	int retorno = -1;
	Employee bufferList;
	if(employee_buscarIndicePorIdRef(list,len,id,&indiceAmodificar) == 0)
	{
		bufferList = list[indiceAmodificar];

		if(utn_getNombre("\nINGRESE NUEVO NOMBRE","ERROR!!!REINGRESE NOMBRE",bufferList.name,3,LONG_NOMBRE) == 0 &&
			utn_getNombre("\nINGRESE NUEVO APELLIDO","ERROR!!!REINGRESE APELLIDO",bufferList.lastName,3,LONG_NOMBRE) == 0 &&
			utn_getfloat("INGRESE NUEVO SALARIO","ERROR!!! REINGRESE SALARIO",&bufferList.salary, 3, 9999999, 0)==0 &&
			utn_getEntero("INGRESE NUEVO SECTOR","ERROR!!! REINGRESE SECTOR",&bufferList.sector, 3, 9999999, 0)==0)
			{
				list[indiceAmodificar] = bufferList;
				retorno = 0;
			}
	}
	else
	{
		printf("ID no encontrado");
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int indiceAborrar;
	int retorno = -1;
	if(list!=NULL && len>0)
	{
		if(employee_buscarIndicePorIdRef(list,len,id,&indiceAborrar) == 0)
		{
			list[indiceAborrar].isEmpty=TRUE;
		}
		else{
			printf("ID no encontrado");
		}
	}
	return retorno;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	Employee bufferEmployee;
	if(order)
	{
	    for(int i= 0; i < len-1 ; i++)
	    {
	        for(int j= i+1; j <len; j++)
	        {
	            if( list[i].isEmpty == 0 && list[j].isEmpty == 0 && strcmp(list[i].lastName, list[j].lastName)>0 )
	            {
	            	bufferEmployee = list[i];
	                list[i] = list[j];
	                list[j] = bufferEmployee;
	                retorno=0;
	            }
	        }
	    }
	}
	else
	{
		for(int i= 0; i < len-1 ; i++)
		{
			for(int j= i+1; j <len; j++)
			{
				if( list[i].isEmpty == 0 && list[j].isEmpty == 0 && strcmp(list[i].lastName, list[j].lastName)<0 )
				{
					bufferEmployee = list[i];
					list[i] = list[j];
					list[j] = bufferEmployee;
					retorno=0;
				}
			}
		}
	}
return retorno;
}



/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
	int i;
	int contador=0;
	int acumulador=0;
	float promedios;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumulador=acumulador+list[i].salary;
				contador++;
			}
		}
	}
	promedios=(float)acumulador/contador;
	printf("El total de los salarios es: %d y el promedio de salarios es: %f",acumulador,promedios);
return 0;
}


/** \brief Busca el en el array Employee un lugar libre y devuelve el indice por referencia
 *
 * \param Valor Employee *arrayEmployees es el puntero al array de clientes
 * \param Valor limiteEmployee es el tamaño del array de Employee
 * \param Valor * pindex es el puntero al indice encontrado
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */

int employee_buscarLibreRef(Employee pArrayEmployee[],int limiteEmployee, int *pindex)
{
	int retorno=-1;
	int i;
	if(pArrayEmployee !=NULL && limiteEmployee>0 && pindex!=NULL)
	{
		for(i = 0;i<limiteEmployee;i++)
		{
			if(pArrayEmployee[i].isEmpty==TRUE)
			{
				*pindex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Busca el en el array Employee un lugar ocupado
 *
 * \param Valor Employee *arrayEmployees es el puntero al array de clientes
 * \param Valor limiteEmployee es el tamaño del array de Employee
 * \param Valor * pindex es el puntero al indice encontrado
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */

int employee_buscarOcupado(Employee pArrayEmployee[],int limiteEmployee)
{
	int retorno=-1;
	int i;
	if(pArrayEmployee !=NULL && limiteEmployee>0)
	{
		for(i = 0;i<limiteEmployee;i++)
		{
			if(pArrayEmployee[i].isEmpty== FALSE)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Imprime los Employee
 *
 * \param Valor Employee *arrayClientes es el puntero al array de Employee
 * \param Valor limiteEmployee es el tamaño del array de Employee
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */
int employee_print (Employee * pArrays , int limiteCliente)
{
	int retorno = -1;
	if (pArrays != NULL && limiteCliente >0){
		for (int i=0 ; i<limiteCliente ; i++)
		{
			if(pArrays[i].isEmpty == FALSE)
			{
				printf("\n ID: %d - Nombre: %s - Apellido: %s - Salario: %f - Sector %d",pArrays[i].id,pArrays[i].name,pArrays[i].lastName, pArrays[i].salary , pArrays[i].sector);
			}
		}
		retorno = 0;
	}
return retorno;
}

/** \brief Busca el indice por el id y devuelve por referencia el indice
 *
 * \param Valor Cliente *arrayClientes es el puntero al array de clientes
 * \param Valor limiteCliente es el tamaño del array de clientes
 * \param Valor idBuscar es el id que se va a buscar
 * \param Valor * pIndice es el puntero al indice encontrado
 * \return Devuelve 0 si no hubo errores y -1 si hubo errores
 *
 */

int employee_buscarIndicePorIdRef (Employee * pArrays, int limiteEmployee,int idBuscar, int * pIndice)
{
	int retorno = -1;
	int i ;
		if (pArrays != NULL && limiteEmployee >0 && idBuscar >= 0)
		{
				for ( i = 0; i<limiteEmployee; i++)
				{
					if(pArrays[i].isEmpty == FALSE &&
					   pArrays[i].id == idBuscar)
					{
					*pIndice= i;
					retorno = 0;
					break;
					}
				}
		}
		else
		{
			printf("ERRORR!!!!!!!!!!!!");
		}
	return retorno;
}


int employee_informes(Employee * pArrays, int limiteEmployee)
{
	char opcionMenu;
	int retorno;
	int opcionMenuOrden;
	do
	{
		if(utn_getChar("\n|//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
						 "\n|/////INGRESE: a) Listado de los empleados ordenados alfabéticamente por Apellido y Sector./////////////////////////////////////////////////////////////////////////////////////|"
						 "\n|//////////////b) Total y promedio de los salarios, y cuántos empleados superan el salario promedio./////////////////////////////////////////////////////////////////////////////|"
						 "\n|//////////////c) Salir./////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|",
						"\n|////////////////////////////////////////////////////////ERROR!!! LETRA MAL INGRESADA!!!!////////////////////////////////////////////////////////////////////////////////////|",
						 &opcionMenu,3)==0)
		{
			switch(opcionMenu)
			{
				case  'a':
					utn_getEntero("Ingrese: 1- para orden ascendente \n 2-Orden Ascendente", "Error!!!Reingrese numero ", &opcionMenuOrden, 3, 2, 0);
					if(sortEmployees(pArrays,limiteEmployee,opcionMenuOrden)==0)
					{
						retorno=0;
					}
					else
					{
						printf("No hay Empleados cargados");
					}
					break;
				case 'b':
					if(printEmployees(pArrays,limiteEmployee)==0)
					{
					retorno= 0;
					}
					else
					{
						printf("No hay Empleados cargados");
					}
			}
		}
	}while(opcionMenu !='c');

	return retorno;
}
