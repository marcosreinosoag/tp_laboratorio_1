/*
 * ArrayEmployees.h
 *
 *  Created on: 2 oct. 2020
 *      Author: marco
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define LONG_NOMBRE 51
#define LONG_APELLIDO 51
#define TRUE 1
#define FALSE 0
#define LEN_EMPLOYEE 1000
typedef struct
{
	int id;
	char name[LONG_NOMBRE] ;
	char lastName[LONG_APELLIDO];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employee_alta(Employee* list, int len);
int employee_modificarEmpleado(Employee* list,int len);
int employee_bajaEmpleado(Employee* list,int len);
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int employee_buscarOcupado(Employee pArrayEmployee[],int limiteEmployee);
int printEmployees(Employee* list, int length);
int employee_buscarLibreRef(Employee pArrayEmployee[],int limiteEmployee, int *pindex);
int employee_print (Employee * pArrays , int limiteCliente);
int employee_buscarIndicePorIdRef (Employee * pArrays, int limiteEmployee,int idBuscar, int * pIndice);
int employee_informes(Employee * pArrays, int limiteEmployee);
#endif /* ARRAYEMPLOYEES_H_ */
