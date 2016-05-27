#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    int puntaje;
    int estado;
    char descripcion[50];
    char linkImg[100];
}EMovie;

int menu(void);
/**
 *  Agrega una pelicula al archivo binario
 *  @param *movie recibe como parametro un puntero del tipo EMovie
 *  @return siempre retorna 0
 */
int agregarPelicula(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param *movie recibe como parametro un puntero del tipo EMovie
 *  @return siempre retorna 0.
 *  siempre retorna 0.
 */

int borrarPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param *movie recibe como parametro un puntero del tipo EMovie
 *  siempre retorna 0.
 */
int generarPagina(EMovie *movie);


#endif // FUNCIONES_H_INCLUDED

