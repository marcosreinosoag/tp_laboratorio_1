/*
 * utn.h
 *
 *  Created on: 12 sep. 2020
 *      Author: Marcos Reinoso
 */

#ifndef UTN_H_
#define UTN_H_



/** \brief Recibe dos valores numéricos enteros, calcula la suma y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable operadorA
 * \param Valor correspondiente a la variable operadorB
 * \param Valor correspondiente a resultado, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int operacionSumar(int operadorA,int operadorB,int *resultado);

/** \brief Recibe dos valores numéricos enteros, calcula la resta y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable operadorA
 * \param Valor correspondiente a la variable operadorB
 * \param Valor correspondiente a resultado, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int operacionRestar(int operadorA,int operadorB,int *resultado);

/** \brief Recibe dos valores numéricos enteros, calcula la division y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable operadorA
 * \param Valor correspondiente a la variable operadorB
 * \param Valor correspondiente a resultado, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int operacionDividir(int operadorA,int operadorB,float *resultado);

/** \brief Recibe dos valores numéricos enteros, calcula la multiplicacion y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable operadorA
 * \param Valor correspondiente a la variable operadorB
 * \param Valor correspondiente a resultado, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int operacionMultiplicar(int operadorA,int operadorB,int *resultado);

/** \brief Recibe un valor numérico entero, calcula el factorial y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable numero
 * \param Valor correspondiente a resultado, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int operacionFactorial(int numero, int *resultado);
/** \brief Recibe un valor numérico entero, un mensaje de entrada, un mensaje de error, un valor minimo, un valor maximo y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable numero
 * \param Valor correspondiente a la variable mensaje, se guarda el mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable mensajeError, se guarda el de error mensaje que va a ser leido por el usuario
 * \param Valor correspondiente a la variable valor minimo, se guarda el valor minimo para establecerlo como limite de lo que se va a ingresar
 * \param Valor correspondiente a la variable valor maximo, se guarda el valor maximo para establecerlo como limite de lo que se va a ingresar
 * \return Devuelve si hubo error o no
 *
 */


int utn_getNumero(int* respuesta, char* mensaje,char* mensajeError,int minimo, int maximo);

#endif /* UTN_H_ */
