#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int menu(void)
{
        int option;
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar listado web\n");
        printf("4- Salir\n");
        scanf("%d",&option);
        return option;
        system("cls");
}

int agregarPelicula(EMovie* movie)
{
    FILE *bin;
    movie->estado=0;


        fflush(stdin);
        printf("Titulo de pelicula: ");
        gets(movie->titulo);
        fflush(stdin);
        while(strlen(movie->titulo)>20)
        {
            system("cls");
            printf("Error, maxima cantidad de caracteres 20.\n\nPresione caulquier tecla para continuar.");
            getche();
            printf("Titulo de pelicula: ");
            gets(movie->titulo);
        }

        system("cls");
        fflush(stdin);
        printf("Genero: ");
        gets(movie->genero);
        fflush(stdin);
        while(strlen(movie->genero)>20)
        {
            system("cls");
            printf("Error, maxima cantidad de caracteres 20.\n\nPresione caulquier tecla para continuar");
            getche();
            printf("Genero: ");
            gets(movie->genero);
        }

        system("cls");
        printf("Duracion [solo minutos]: ");
        scanf("%d",&movie->duracion);
        while(movie->duracion<1||movie->duracion>300)
        {
            system("cls");
            printf("Error! Duracion invalida.\n  Vuelva a ingresar: ");
            scanf("%d",&movie->duracion);
        }

        system("cls");
        fflush(stdin);
        printf("Descripcion: ");
        gets(movie->descripcion);
        while(strlen(movie->descripcion)<1||strlen(movie->descripcion)>50)
        {
            system("cls");
            printf("Error!\nIngrese descripcion entre 1-50 caracteres: ");
            gets(movie->descripcion);
        }

        system("cls");
        printf("Puntaje [1-100]: ");
        scanf("%d",&movie->puntaje);
        while(movie->puntaje<1||movie->puntaje>100)
        {
            system("cls");
            printf("Error!\n Ingrese puntaje entre 1-100 : ");
            scanf("%d",&movie->puntaje);
        }

        fflush(stdin);
        system("cls");
        printf("Ingrese link de imagen: ");
        gets(movie->linkImg);
        while(strlen(movie->linkImg)<1||strlen(movie->linkImg)>100)
        {
            system("cls");
            printf("Error!\nIngrese link entre 1-100 caracteres: ");
            gets(movie->linkImg);
        }

        movie->estado=1;

        if((bin=fopen("datmovies.bin","ab+"))!=NULL)
        {
            fflush(stdin);
            fwrite(movie,sizeof(EMovie),1,bin);
        }
        else
        {
            printf("Error, al gurdar datos en el archivo. Vuelva a cargar pelicula");
            getche();
        }
        printf("Se guardo la pelicula.\n\nPresione una tecla para continuar...\n");
        fclose(bin);
        return 0;
}

int borrarPelicula(EMovie *movie)
{
    FILE *pointDat;
    char auxTitulo[20];
    int encontro=0;

    printf("Ingrese nombre de la pelicula que desea borrar:");
    fflush(stdin);
    strlwr(gets(auxTitulo));



    if((pointDat=fopen("datmovies.bin","r+"))!=NULL)
    {
        while((fread(movie,sizeof(EMovie),1,pointDat))!=0)
        {
           if(movie->estado==1)
            {
                strlwr(movie->titulo);
                if(strcmp(movie->titulo,auxTitulo)==0)
               {
                   fseek(pointDat,-sizeof(EMovie),SEEK_CUR);
                   movie->estado=0;
                   fwrite(movie,sizeof(EMovie),1,pointDat);
                   encontro=1;
                   printf("Se borro satisfactoriamente la pelicula!");
                   
                   break;
               }
            }
        }

        if(encontro==0)
        {
            printf("No se encontro la pelicula solicitada.");
            return 0;
        }

    }
    else
    {
        printf("No se puedo abrir el archivo correctamente.");
        return 0;
    }

    if(fclose(pointDat)==-1)
    {
        printf("Error al cerrar el archivo, vuelva a intentarlo.\n\nPresione una tecla para continuar");
        return 0;
    }
    else
    {
        printf("\n\nPresione una tecla para continuar...");
    }
    return 0;
}

int generarPagina(EMovie *movie)
{
    FILE *pointDat,*pointHtml;

    if((pointDat=fopen("datmovies.bin","rb"))!=NULL)
    {
        if((pointHtml=fopen("listapeliculas.html","wb"))!=NULL)
        {
            fprintf(pointHtml,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            while((fread(movie,sizeof(EMovie),1,pointDat))!=0)
            {

               if(movie->estado==1)
               {
                    fprintf(pointHtml,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movie->linkImg,movie->titulo,movie->genero,movie->puntaje,movie->duracion,movie->descripcion);
               }

            }

            fprintf(pointHtml,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }
        else
        {
            printf("No se pudo crear el html vuelva a intentarlo.\n\nPresione una tecla para continuar");
            return 0;
        }
    }
    else
    {
        printf("No se pudo cargar la estructura de peliculas, vuelva a intentarlo.\n\nPresiones una tecla para continuar");
        return 0;
    }

    printf("Se creo satisfactoriamente el listado de peliculas\n\nPresioene una tecla para continuar");
    fclose(pointDat);
    fclose(pointHtml);

    return 0;
}
