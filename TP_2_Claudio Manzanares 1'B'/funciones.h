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

/** \brief se pide el dni se compara y si hay coincidencia cambia el estado del array a 0
 * \param lista el array se pasa como parametro.
 * \return no retorna valores
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
