#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


static int employee_generarId(int idMaximo)
{
	static int contador=0;
	contador=idMaximo;
	contador++;
	return contador;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee,int* pIdMaximo)
{
	FILE* pFile;
	Employee* pE;
	char nombreAux[256];
	char horasTrabajadas[256];
	char sueldoAux[256];
	char idAux[256];
	int flagOnce=0;
	int indice=0;
	int idMax;
	int idEmp;
	pFile = fopen(path,"r");
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadas,sueldoAux)==4)
			{
				if(flagOnce!=0)
				{
					if(esNumerica(idAux)==0)
					{
						idEmp=atoi(idAux);
						if(indice==0 || idEmp>idMax)
						{
							idMax=idEmp;
						}
					}
					pE=employee_newParametros(idAux,nombreAux,horasTrabajadas,sueldoAux);
					ll_add(pArrayListEmployee,pE);
					indice++;
				}
				else
				{
					flagOnce=1;
				}
			}
		}while(feof(pFile)==0);
		fclose(pFile);
		*pIdMaximo=idEmp;
	}
	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int* pIdMaximo)
{
	FILE* pFile;
	Employee* pE;
	int i;
	//emp_initArray(empleados,100);
	pFile = fopen(path,"rb");
	if(pFile!=NULL)
	{
		i=0;
		do{
			pE = employee_new();
			if(fread(pE,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee,pE);
				i++;
			}
			else
			{
				employee_delete(pE);
			}
		}while(feof(pFile)==0 && i<1000);
		fclose(pFile);
	}
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int idMaximo)
{
	int retorno=-1;
	int idMax;
	char auxId[255];
	char auxNombre[255];
	char auxhorasTrabajadas[255];
	char auxSueldo[255];
	Employee* pE;
	if(pArrayListEmployee!=NULL)
	{
		if(utn_getTexto("Ingrese Nombre:","Error!!!! Reingrese Nombre:",auxNombre,3,50)==0 &&
		   utn_getTexto("Ingrese horas trabajadas:","Error!!!! Reingrese horas trabajadas:",auxhorasTrabajadas,3,50)==0 &&
		   utn_getTexto("Ingrese Sueldo:","Error!!!! Reingrese Sueldo:",auxSueldo,3,50)==0)
		   {
				idMax=employee_generarId(idMaximo);
				sprintf(auxId,"%d",idMax);
				pE=employee_newParametros(auxId,auxNombre,auxhorasTrabajadas,auxSueldo);
				if(pE!=NULL)
				{
					ll_add(pArrayListEmployee,pE);
					retorno=0;
					printf("-------------------------------------ALTA REALIZADA CORRECTAMENTE---------------------------------------\n");
				}
				else
				{
					employee_delete(pE);
				}
		   }
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pE;
	int flagError;
	int j;
	for(j=0;j<ll_len(pArrayListEmployee);j++)
	{
		pE=(Employee*)ll_get(pArrayListEmployee,j);
		printf("Id:[%d] Nombre:%s Horas Trabajadas: %d Sueldo: %d\n",employee_getId(pE,&flagError),employee_getNombre(pE,&flagError),employee_getHorasTrabajadas(pE,&flagError),employee_getSueldo(pE,&flagError));
	}
	return 1;
}

static Employee* buscarPorId(LinkedList* pArrayListEmployee,int idABuscar,int* posicionLinkedlist)
{
	int i;
	int lenLista;
	Employee* pEmpEdit;
	Employee* pRetorno=NULL;
	int posicion;
	int idEncontrado;
	int flag;

	if(pArrayListEmployee!=NULL)
	{
		lenLista = ll_len(pArrayListEmployee);
		for(i=0; i<lenLista; i++)
		{
			pEmpEdit=(Employee*)ll_get(pArrayListEmployee, i);
			idEncontrado = employee_getId(pEmpEdit,&flag);
			if(idABuscar == idEncontrado)
			{
				posicion=i;
				pRetorno=pEmpEdit;
				break;
			}
		}
	}
	*posicionLinkedlist=posicion;
	return pRetorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pE;
	int idAModificar;
	char auxNombre[255];
	char auxHorasTrabajadas[255];
	char auxSueldo[255];
	int retorno=-1;
	int posicionLinkedlist;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getEntero("Ingresate un ID:","Error!!!!Reingrese Id",&idAModificar,3,999999,0)==0)
		{
			pE= buscarPorId(pArrayListEmployee,idAModificar,&posicionLinkedlist);
			if(pE!=NULL)
			{
				if(utn_getTexto("Ingrese Nombre:","Error!!! Reingrese nombre: ",auxNombre,2,255)==0 &&///////ver funcion para simplificar cod
				   utn_getTexto("Ingrese Horas Trabajadas:","Error!!! Reingrese Horas Trabajadas: ",auxHorasTrabajadas,2,255)==0 &&
				   utn_getTexto("Ingrese Sueldo:","Error!!! Reingrese Sueldo: ",auxSueldo,2,255)==0)
				{
					if(employee_setNombre(pE,auxNombre)==0 &&
					   employee_setHorasTrabajadas(pE,auxHorasTrabajadas)==0 &&
					   employee_setSueldo(pE,auxSueldo)==0)
					   {
							printf("\n--------------------EL EMPLEADO FUE MODIFICADO CORRECTAMENTE---------------------");
							retorno=0;
					   }
				}
			}
			else
			{
				printf("El id ingresado no es valido\n");
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pE;
	int idAModificar;
	int retorno=-1;
	int posicionLinkedlist;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getEntero("Ingresate un ID:","Error!!!!Reingrese Id",&idAModificar,3,999999,0)==0)
		{
			pE= buscarPorId(pArrayListEmployee,idAModificar,&posicionLinkedlist);
			if(pE!=NULL)
			{
				employee_delete(pE);
				ll_remove(pArrayListEmployee,posicionLinkedlist);
				printf("\n--------------------EL EMPLEADO FUE ELIMINADO CORRECTAMENTE---------------------");
				retorno=0;
			}
		}
		else
		{
			printf("El ID ingresado no es valido\n");
		}
	}
	return retorno;
}
int funcioCriterioHorasTrabajadas(void* el1,void* el2)
{
	int retorno=-1;
	Employee* pEmp1;
	Employee* pEmp2;
	int flagError;
	int hora1;
	int hora2;
	pEmp1=(Employee*)el1;
	pEmp2=(Employee*)el2;
	hora1=employee_getSueldo(pEmp1,&flagError);
	hora2=employee_getSueldo(pEmp2,&flagError);
	if(hora1==hora2)
	{
		retorno=0;
	}else if(hora1>hora2)
	{
		retorno=1;
	}else{
		retorno=-1;
	}
	return retorno;
}

int funcioCriterioSueldo(void* el1,void* el2)
{
	int retorno=-1;
	Employee* pEmp1;
	Employee* pEmp2;
	int flagError;
	int sueldo1;
	int sueldo2;
	pEmp1=(Employee*)el1;
	pEmp2=(Employee*)el2;
	sueldo1=employee_getSueldo(pEmp1,&flagError);
	sueldo2=employee_getSueldo(pEmp2,&flagError);
	if(sueldo1==sueldo2)
	{
		retorno=0;
	}else if(sueldo1>sueldo2)
	{
		retorno=1;
	}else{
		retorno=-1;
	}
	return retorno;
}

int funcioCriterioId(void* el1,void* el2)
{
	int retorno=-1;
	Employee* pEmp1;
	Employee* pEmp2;
	int flagError;
	int id1;
	int id2;
	pEmp1=(Employee*)el1;
	pEmp2=(Employee*)el2;
	id1=employee_getId(pEmp1,&flagError);
	id2=employee_getId(pEmp2,&flagError);
	if(id1==id2)
	{
		retorno=0;
	}else if(id1>id2)
	{
		retorno=1;
	}else{
		retorno=-1;
	}
	return retorno;
}

int funcioCriterioNombre(void* el1,void* el2)
{
	Employee* pEmp1;
	Employee* pEmp2;
	int flagError;
	char* nombre1;
	char* nombre2;
	pEmp1=(Employee*)el1;
	pEmp2=(Employee*)el2;
	nombre1=employee_getNombre(pEmp1,&flagError);
	nombre2=employee_getNombre(pEmp2,&flagError);
	return strcmp(nombre1,nombre2);
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int orden;
	do{
		utn_getEntero("Ingrese: \n1)Ordenar por Nombre\n2)Ordenar por Horas Trabajadas\n3)Ordenar por Sueldo\n4)Ordenar por ID\n5)Salir", "Error!!!!Reingrese numero:",&opcion,3,5,0);
		switch(opcion)
		{
		case 1:
			if(utn_getEntero("Ingrese: \n1)Para Orden Ascendente\n2)Para Orden Descendente", "Error!!! Reingrese numero",&orden,3,2,0)==0)
			{
				ll_sort(pArrayListEmployee,funcioCriterioNombre,orden);
			}
			break;
		case 2:
			if(utn_getEntero("Ingrese: \n1)Para Orden Ascendente\n2)Para Orden Descendente", "Error!!! Reingrese numero",&orden,3,2,0)==0)
			{
				ll_sort(pArrayListEmployee,funcioCriterioHorasTrabajadas,orden);
			}
			break;
		case 3:
			if(utn_getEntero("Ingrese: \n1)Para Orden Ascendente\n2)Para Orden Descendente", "Error!!! Reingrese numero",&orden,3,2,0)==0)
			{
				ll_sort(pArrayListEmployee,funcioCriterioSueldo,orden);
			}
			break;
		case 4:
			if(utn_getEntero("Ingrese: \n1)Para Orden Ascendente\n2)Para Orden Descendente", "Error!!! Reingrese numero",&orden,3,2,0)==0)
			{
				ll_sort(pArrayListEmployee,funcioCriterioId,orden);
			}
			break;
		}
	}while(opcion!=5);
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int i;
	int flagError;
	char* pNombre;
	int horasTrabajadas;
	int len=ll_len(pArrayListEmployee);
	int sueldo;
	int id;
	FILE* pFile;
	Employee* pE;
	pFile = fopen(path,"w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<len;i++)
		{
			pE=ll_get(pArrayListEmployee,i);
			if(pE!=NULL)
			{
				pNombre = employee_getNombre(pE,&flagError);
				horasTrabajadas = employee_getHorasTrabajadas(pE,&flagError);
				sueldo = employee_getSueldo(pE,&flagError);
				id = employee_getId(pE,&flagError);
				fprintf(pFile,"%d,%s,%d,%d\n",id,pNombre,horasTrabajadas,sueldo);
				ret=0;
			}
		}
		fclose(pFile);
	}
	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* pe;
	int len=ll_len(pArrayListEmployee);
	int i;
	pFile = fopen(path,"wb");
	if(pFile!=NULL)
	{
		//fprintf(pFile,"%s,%s,%d\n",pE->nombre,pE->apellido,pE->idEmpleado); // imprime texto
		//fwrite(listaEmpleados,sizeof(Empleado),5,pFile);
		for(i=0; i<len; i++)
		{
			pe=(Employee*)ll_get(pArrayListEmployee,i);
			if(pe!=NULL)
			{
				fwrite(pe,sizeof(Employee),1,pFile);
			}
		}
		fclose(pFile);
	}
    return 1;
}

