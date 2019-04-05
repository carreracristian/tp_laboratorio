#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/** \brief Pide el primer numero a operar
 *
 * \param void
 * \return El numero flotante ingresado al programa
 *
 */

float primerNumero(void);

/** \brief Pide el segundo numero a operar
 *
 * \param void
 * \return  El numero flotante ingresado al programa
 *
 */
float segundoNumero(void);

/** \brief Suma de los numeros ingresados
 *
 * \param numUno es el primer numero que se va a sumar
 * \param numDos es el Segundo numero que se va a sumar
 * \return La suma de los numeros con resultado flotante
 *
 */
float suma(float uno,float dos);

/** \brief  Resta de los numeros ingresados
 *
 * \param numUno es el primer numero, que va a ser restado por el segundo
 * \param numDos es el Segundo numero que se va a restar al primero
 * \return La resta de los numeros con resultado flotante
 *
 */
float resta(float uno,float dos);

/** \brief  multiplicacion de los numeros ingresados
 *
 * \param numUno es el primer numero que se va a multiplicar
 * \param numDos es el Segundo numero que se va a multiplicar
 * \return La multiplicacion de los numeros con resultado flotante
 *
 */
float multiplicacion(float uno,float dos);

/** \brief  division de los numeros ingresados
 *
 * \param numUno es el primer numero, que va a ser dividido por el segundo
 * \param numDos es el Segundo numero que va a dividir al primero
 * \return La division de los numeros con resultado flotante
 *
 */
float division(float uno,float dos);

/** \brief  Factorial de los numeros ingresados
 *
 * \param numUno es el primer numero factoreado
 * \param numDos es el Segundo numero factoreado
 * \return El factorial de los numeros con resultado flotante
*
*/
float factorial(float uno, float dos);


#endif // FUNCIONES_H_INCLUDED
