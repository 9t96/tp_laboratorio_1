#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include "funciones.h"
#define personas 20


int menu()
{
    int opcion;
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    scanf("%d",&opcion);

    return opcion;
}
void altas(EPersona lista[])
{
    int indice;
    system("cls");
    indice=obtenerEspacioLibre(lista);
    printf("\nIngrese Nombre: ");
    fflush(stdin);
    gets(lista[indice].nombre);
    system("cls");
    printf("\nIngrese Edad: ");
    scanf("%d",&lista[indice].edad);
    system("cls");
    printf("\nIngrese DNI *sin puntos ni comas*: ");
    scanf("%ld",&lista[indice].dni);
    lista[indice].estado=1;
    system("cls");

}
int obtenerEspacioLibre(EPersona lista[])
{
    int indice;
    for(indice=0;indice<personas;indice++)
    {
        if(lista[indice].estado==0)
        {
            break;
        }
        if(indice==personas)
        {
            printf("No hay mas espacio, se llego a la capacidad maxima de empleados");
            break;
        }
    }

    return indice;
}

void borrar_persona(EPersona lista[])
{
    int indice,flag=0;
    long int dni;
    system("cls");
    printf("Ingrese el DNI de la persona que desea eliminar 'sin comas ni puntos': ");
    scanf("%ld",&dni);
    for(indice=0;indice<=personas;indice++)
    {

        if(dni==lista[indice].dni)
        {
            lista[indice].estado=0;
            flag=1;
            system("cls");
            printf("Se limpiaron los datos de %s\n\nPresione una tecla para volver al menu.",lista[indice].nombre);
            break;
        }
    }
    if(indice==personas&&flag!=1)
    {
        system("cls");
        printf("\nError, No se puedo encontrar el DNI vuelva a ingresar\n\nPresione una tecla para volver al menu.");
    }

}

void listar_alfabeticamente(EPersona lista[])
{
    int i,j;
    EPersona aux_datos;
    for(i=0;i<personas-1;i++)
    {
        for(j=i+1;j<personas;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux_datos=lista[i];
                lista[i]=lista[j];
                lista[j]=aux_datos;
            }
        }
    }

    printf("****Nombre*******Edad*******DNI****\n");
    for(i=0;i<personas;i++)
    {

        if(lista[i].estado==1)
        {
            printf("%s\t\t%d\t\t%ld\n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }

    printf("\n\nPresione cualquier tecla para volver al menu.");
}

void grafico(EPersona lista[])
{
    int indice,menor_19=0,e19_y35=0,may_35=0,mayor;
    system("cls");
    for(indice=0;indice<personas;indice++)/**<Acumulo por edad las personas a graficar*/
    {
        if(lista[indice].estado!=0)
        {
            if(lista[indice].edad<19)
            {
                menor_19++;
            }
            else
            {
                if(lista[indice].edad>18&&lista[indice].edad<36)
                e19_y35++;
                if(lista[indice].edad>35)
                may_35++;
            }
        }
    }

    mayor=0;/**< Busco el mayor para saber hasta cuando graficar*/
    if(menor_19>mayor)
    {
        mayor=menor_19;
    }
    else
    {
        if(e19_y35>mayor)
        {
            mayor=e19_y35;
        }
        else
        {
            if(may_35>mayor)
            {
                mayor=may_35;
            }
        }
    }

    for(indice=mayor;indice>0;indice--)
    {
        if(menor_19==indice&&e19_y35==indice&&may_35==indice)
        {
            printf("*\t*\t*");
            menor_19--;
            e19_y35--;
            may_35--;
        }
        else
        {
            if(menor_19==mayor&&e19_y35==mayor)
            {
                printf("*\t*");
                menor_19--;
                e19_y35--;
            }
            else if(menor_19==indice&&may_35==indice)
            {
                printf("*\t*");
                menor_19--;
                may_35--;
            }
            else if(e19_y35==mayor&&may_35==mayor)
            {
                printf("\t*\t*");
                e19_y35--;
                may_35--;
            }
            else
            {
                if(may_35==mayor)
                {
                    printf("\t\t*");
                    may_35--;
                }
                else if(e19_y35==mayor)
                {
                    printf("\t*");
                    e19_y35--;
                }
                else
                {
                    if(menor_19==mayor)
                    {
                        printf("*");
                        menor_19--;
                    }
                }
            }
        }
    printf("\n");
    }

    printf("<19\t19-35\t>35\n\nPresione una tecla para volver al menu.");

}
