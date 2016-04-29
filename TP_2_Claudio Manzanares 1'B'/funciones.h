#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/** \brief Menu de opciones
 * \return retorna el entero de la opcion seleccionada del menu
 */
int menu(void);

/** \brief Ingresa al sistema empleados solicitando nombre dni y edad.
 * \param  lista recibe el array de struct
 * \return no retorna valores
 */
void altas(EPersona lista[]);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni);

/** \brief se pide el dni se compara y si hay coincidencia cambia el estado del array a 0
 * \param lista el array se pasa como parametro.
 * \param dni recibe el dni a ser comparado
 * \return retorna el indice del dni
 */
void borrar_persona(EPersona lista[]);

/** \brief ordena los array alfabeticamente y los lista
 * \param lista el array se pasa como parametro.
 * \return no retorna valores
 */
void listar_alfabeticamente(EPersona lista[]);

/** \brief grafico de edad
 * \param lista el array se pasa como parametro.
 */
void grafico(EPersona lista[]);
#endif // FUNCIONES_H_INCLUDED
