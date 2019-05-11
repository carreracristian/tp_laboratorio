#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1


typedef struct
{
    int estado;
    float salario;
    char nombre[10];
    char apellido[10];
    int id;
    char sector[10];
}eEmployee;

/** \brief pide ingresar datos de un empleado
 *
 * \return eEmploye estructura del empleado
 *
 */
eEmployee pedirEmpleado();
/** \brief pide ingresar un dato alfabetico y lo valida
 *
 * \param [] char recibe un mensaje
 * \param [] char recibe un dato para guardar
 * \return void sin nada a retornar
 *
 */
int ingresarEmpleado(eEmployee[], int);
/** \brief muestra los datos del empleado
 *
 * \param eEmploye recibe la estructura
 * \return void sin nada a retornar
 *
 */
void mostrarEmpleado(eEmployee);
/** \brief ordena el listado de empleados alfabeticamente por apellido y por sector.
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return void sin nada a retornar
 *
 */
void ordenarEmpleados(eEmployee[], int);
/** \brief informa el total y el promedio de los salarios, y cantidad de salarios mayores al promedio.
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return void sin nada a retornar
 *
 */
void mostrarSalario(eEmployee[], int);
/** \brief genera un numero de ID autoincremental en 1
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return int retorna el numero de ID
 *
 */
int crearId(eEmployee[], int );
/** \brief pide ingresar un dato alfabetico y lo valida
 *
 * \param [] char recibe un mensaje
 * \param [] char recibe un dato para guardar
 * \return void sin nada a retornar
 *
 */
void cargarArray(eEmployee[], int);
/** \brief muestra el listado de los empleados
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void mostrarArray(eEmployee[], int);
/** \brief inicializa todos los valores de la estructura
 *
 * \param [] eEmploye recibe un array de la estructura
 * \param int recibe el tamaño del array
 * \return void sin nada a retornar
 *
 */
void construirArray(eEmployee[], int);
/** \brief da de alta a un empleado de la estructura
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return int retorna el indice del nuevo empleado, o -1 si no hay mas lugar
 *
 */
int insertarEmpleado(eEmployee [], int );
/** \brief busca un lugar libre en la estructura
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array
 * \return int retorna el primer indice del primer elemento que encontro libre, o -1 si no hay mas lugar
 *
 */
int dameLugarLibre(eEmployee[],int);
/** \brief elimina un empleado de la estructura, ingresando su ID
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return int retorna 0 si el ID ingresado no coincide, o 1 si es correcto.
 *
 */
int borrarEmpleado(eEmployee[], int);
/** \brief modifica un dato de un empleado de la estructura, pidiendo que ingrese su ID y dando a elegir entre nombre, apellido, sector o salario.
 *
 * \param [] eEmployee recibe un array de la estructura
 * \param int recibe el tamaño del array.
 * \return int retorna 0 si el ID ingresado no coincide, o 1 si es correcto.
 *
 */
int editarEmpleado(eEmployee [], int );
