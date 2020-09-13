/*
 ============================================================================
 Name        : TP1.c
 Author      : Marcos Reinoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main(void) {

	setbuf(stdout,NULL);
	int operadorNumero1;
	int operadorNumero2;
	int respuesta;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicar;
	int factorialNumero1;
	int factorialNumero2;


	do
	{
		utn_getNumero(&respuesta,"Bienvenido a la calculadora!!! Ingrese: 1-Ingresar 1er operando 2- Ingresar 2do operando 3-Calcular todas las operaciones 4-Informar resultados "
								" 5-Salir\n","Erroor!!! Reingrese el numero: 1-Ingresar 1er operando 2- Ingresar 2do operando 3-Calcular todas las operaciones 4-Informar resultados 5-Salir\n", 1, 5);
		switch(respuesta)
		{
			case 1:
				utn_getNumero(&operadorNumero1,"\nIngrese el 1er operando: ","Erroor!!! Reingrese el numero:",-99999999,99999999);
				break;
			case 2:
				utn_getNumero(&operadorNumero2,"\nIngrese el 2do operando: ","Erroor!!! Reingrese el numero:",-99999999,99999999);
				break;
			case 3:
				operacionSumar(operadorNumero1,operadorNumero2, &resultadoSuma);
				operacionRestar(operadorNumero1,operadorNumero2, &resultadoResta);
				operacionDividir(operadorNumero1,operadorNumero2, &resultadoDivision);
				operacionMultiplicar(operadorNumero1,operadorNumero2, &resultadoMultiplicar);
				operacionFactorial(operadorNumero1,&factorialNumero1);
				operacionFactorial(operadorNumero2,&factorialNumero2);
				break;
			case 4:
				printf("\nEl resultado de %d+%d es: %d",operadorNumero1,operadorNumero2,resultadoSuma);
				printf("\nEl resultado de %d-%d es: %d",operadorNumero1,operadorNumero2,resultadoResta);
				if(operacionDividir(operadorNumero1,operadorNumero2, &resultadoDivision)==0)
				{
					printf("\nEl resultado de %d/%d es: %f",operadorNumero1,operadorNumero2,resultadoDivision);
				}
				else
				{
					printf("\n No es posible dividir por cero");
				}
				printf("\nEl resultado de %d*%d es: %d\n",operadorNumero1,operadorNumero2,resultadoMultiplicar);
				if(operacionFactorial(operadorNumero1,&factorialNumero1)==0){
					printf("\nEl factorial de %d es: %d",operadorNumero1,factorialNumero1 );
				}
				else{
					printf("\nNo se puedo realizar el factorial de %d porque es un numero negativo",operadorNumero1 );
				}
				if(operacionFactorial(operadorNumero2,&factorialNumero2)==0){
					printf("\nEl factorial de %d es: %d\n",operadorNumero2,factorialNumero2 );
				}
				else{
					printf("\nNo se puedo realizar el factorial de %d porque es un numero negativo\n",operadorNumero2);
				}
				break;
		}
	}while(respuesta!=5);

	return EXIT_SUCCESS;
}



