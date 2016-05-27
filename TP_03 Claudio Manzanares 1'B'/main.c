#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    char seguir='s';

    EMovie movie;

    do
    {
        system("cls");
        switch(menu())
        {
            case 1:
                system("cls");
                agregarPelicula(&movie);
                getche();
                break;
            case 2:
                system("cls");
                borrarPelicula(&movie);
                getche();
                break;
            case 3:
               system("cls");
               generarPagina(&movie);
               getche();
               break;
            case 4:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Error, por favor ingrese una opcion correcta\n\nPresiones una tecla para continuar");
                getche();
                break;
        }

    } while(seguir!='n');
return 0;
}
