/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define LONG_NOMBRE 51

int main(void) {
	setbuf(stdout,NULL);
	Employee list[LEN_EMPLOYEE];
	initEmployees(list, LEN_EMPLOYEE);
	int operacion;
	do
	{
		utn_getEntero("\n 1-Alta Empleado\n 2-Modificar Empleado \n 3-Borrar Empleado \n 4-Informes \n 5-Salir ","\nError!!!! Reingrese numero",&operacion,3,5,1);
		switch(operacion)
		{
			case 1:
				employee_alta(list,LEN_EMPLOYEE);
				break;
			case 2:
				employee_modificarEmpleado(list, LEN_EMPLOYEE);
				break;
			case 3:
				employee_bajaEmpleado(list, LEN_EMPLOYEE);
				break;
			case 4:
				if(employee_buscarOcupado(list, LEN_EMPLOYEE)==0)
				{
					employee_informes(list,LEN_EMPLOYEE);

				}
				else
				{
					printf("Error!!!! Debe ingresar un empleado para ingresar a esta opcion");
				}
				break;
		}
	}while(operacion != 5);
}
