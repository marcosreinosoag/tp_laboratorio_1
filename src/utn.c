/*
 * utn.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Marcos Reinoso
 */

#include <stdio.h>
#include <stdlib.h>

int operacionSumar(int operadorA,int operadorB,int *resultado)
{
	*resultado=operadorA + operadorB;
	return 0;
}
int operacionRestar(int operadorA,int operadorB,int *resultado)
{
	*resultado=operadorA - operadorB;
	return 0;
}
int operacionDividir(int operadorA,int operadorB,float *resultado)
{
	int retorno=-1;
	if(operadorB !=0)
	{
		*resultado =(float)operadorA/operadorB;
		retorno=0;
	}
	return retorno;
}
int operacionMultiplicar(int operadorA,int operadorB,int *resultado)
{
	*resultado = operadorA * operadorB;
	return 0;
}

int operacionFactorial(int numero, int*resultado)
{
	int retorno=-1;
	int factorial=1;
	int contador;

	if(numero>=0)
	{
		for(contador=1;contador<=numero;contador++)
		{
			factorial*=contador;
		}
	retorno=0;
	}
	*resultado=factorial;
	return retorno;
}

int utn_getNumero(int* respuesta, char* mensaje,char* mensajeError,int minimo, int maximo)
{
	if(respuesta !=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
	{
		int resultado;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &resultado);
		while(resultado <minimo || resultado>maximo)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &resultado);
		}
		*respuesta=resultado;
		}
	return 0;
}

