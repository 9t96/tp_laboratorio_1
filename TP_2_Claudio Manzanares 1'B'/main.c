#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
#define personas 20

int main()
{
    EPersona lista[personas];
    char seguir='s';
    int indice;


    for(indice=0;indice<personas;indice++)
    {
        lista[indice].estado=0;
    }
    while(seguir=='s')
    {
        system("cls");
        switch(menu())
        {
        case 1:
            altas(lista);
            system("cls");
            break;
        case 2:
            borrar_persona(lista);
            getche();
            break;
        case 3:
            listar_alfabeticamente(lista);
            getche();
            break;
        case 4:
            grafico(lista);
            getche();
            break;
        case 5:
        seguir = 'n';
            break;
        default:
            system("cls");
            printf("Error,ingrese una opcion correcta\nPresione una tecla para volver al menu.");
            getche();
            break;
        }
    }
    return 0;
}
