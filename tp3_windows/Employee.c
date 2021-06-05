
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	return (Employee*) malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
////////////////---------------------------------------------Descripcion-------------------------
int employee_setId(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL && isValidId(id))
	{
		strcpy(this->id,id);
		retorno = 0;
	}
	return retorno;
}

char* employee_getId(Employee* this, int* flagError)
{
	*flagError = -1;
	char* auxid= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxDescripcion = this->id;
		*flagError = 0;
	}
	return id;
}

int isValidDescripcion(char* nombre)
{
	return 1;
}
////////////////---------------------------------------------Nacionalidad-------------------------
int producto_setNacionalidad(Producto* this,int nacionalidad)
{
	int retorno = -1;
	if(this!= NULL && nacionalidad >=0 && isValidNacionalidad(nacionalidad))
	{
		this->nacionalidad=nacionalidad;
		retorno = 0;
	}
	return retorno;
}

int producto_getNacionalidad(Producto* this, int* flagError)
{
	*flagError = -1;
	int auxnacionalidad;
	if(this!= NULL && flagError!= NULL )
	{
		auxnacionalidad = this->nacionalidad;
		*flagError = 0;
	}
	return auxnacionalidad;
}

int isValidNacionalidad(int nacionalidad)
{
	return 1;
}
//----------------------------------------------------------------Precio-------------------------------
int producto_setPrecio(Producto* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio>=0 && isValidPrecio(precio))
	{
		this->precio=precio;
		retorno = 0;
	}
	return retorno;
}

float producto_getPrecio(Producto* this, int* flagError)
{
	*flagError = -1;
	float auxPrecio;
	if(this != NULL && flagError != NULL )
	{
		auxPrecio = this->precio;
		*flagError = 0;
	}
	return auxPrecio;
}

int isValidPrecio(float precio)
{
	return 1;
}
//-----------------------------------------------------------------Tipo----------------------------------------
int producto_setTipo(Producto* this,char* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo!= NULL && isValidTipo(tipo))
	{
		strcpy(this->tipo,tipo);
		retorno = 0;
	}
	return retorno;
}

char* producto_getTipo(Producto* this, int* flagError)
{
	*flagError = -1;
	char* auxtipo= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxtipo = this->tipo;
		*flagError = 0;
	}
	return auxtipo;
}

int isValidTipo(char* tipo)
{
	return 1;
}
//------------------------ID PRODUCTO----------------------------------------------------------//
int producto_setIdProducto(Producto* this,int idProducto)
{
	int retorno=-1;
	if(this !=NULL && idProducto>=0 && isValidIdProducto(idProducto))
	{
		this->idProducto=idProducto;
		retorno=0;
	}
	return retorno;
}

int producto_getIdProducto(Producto* this, int* flagError)
{
	*flagError = -1;
	int auxidProducto;
	if(this!= NULL && flagError!= NULL )
	{
		auxidProducto = this->idProducto;
		*flagError = 0;
	}
	return auxidProducto;
}

int isValidIdProducto(int idProducto)
{
	return 1;
}

int employee_setId(Employee* this,int id)

int employee_getId(Employee* this,int* id)


int employee_setNombre(Employee* this,char* nombre)

int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


