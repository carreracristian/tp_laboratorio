/** \brief mostrar menu
 *
 * \param [] char recibe un mensaje
 * \return int retorna una opcion
 *
 */
int menu(char []);

/** \brief pide el ingreso de un dato.
 *
 * \param [] char recibe un mensaje para mostrar
 * \param [] char recibe un dato para guardar
 * \return void sin nada a retornar
 *
 */
void getString(char [], char []);

/** \brief pide ingresar un dato alfabetico y lo valida
 *
 * \param [] char recibe un mensaje
 * \param [] char recibe un dato para guardar
 * \return void sin nada a retornar
 *
 */
void getSoloLetras(char [], char []);

/** \brief pide un numero entero y lo valida
 *
 * \param [] char recibe un mensaje
 * \return int retorna un numero ingresado y lo convierte en un entero
 *
 */
int getSoloEnteros(char []);

/** \brief pide al usuario el ingreso de un numero flotante (sin signo), realizando la validacion correspondiente
 *
 * \param [] char recibe el mensaje a mostrar.
 * \return float retorna un numero ingresado y lo convierte en un flotante
 *
 */
float getSoloFlotantes(char []);
