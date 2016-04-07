#include <stdio.h>
#include <windows.h>
#include "funciones.h"
#include <conio.h>

int main()
{
    char seguir='s';
    int opcion=0;
    float operando_uno=0,operando_dos=0,result,busca_errora=0,busca_errorb=0,faltaoperando;
    double resultado_factorial;

        printf("----Hola, eliga una opcion y presione 'ENTER'----\n\n");
        while(seguir=='s')
        {

            printf("1- Ingresar 1er operando (A=%f)\n",operando_uno);
            printf("2- Ingresar 2do operando (B=%f)\n",operando_dos);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            scanf("%d",&opcion);
            system("cls");
            switch(opcion)
            {
                case 1:
                    printf("Primer operando 'A': ");
                    scanf("%f",&operando_uno);
                    busca_errora++;/**contador que aumenta en 1 si se le ingrese un valor cualquiera, para despues porder comparar si estan los 2 operandos para operar.**/
                    break;
                case 2:
                    printf("Segundo operando 'B': ");
                    scanf("%f",&operando_dos);
                    busca_errorb++;
                    break;
                case 3:
                    faltaoperando=faltade_operandos(busca_errora,busca_errorb);/**le envio el valor de las banderas a la funcion que indica si falta o no algun operando**/
                    if(faltaoperando==1)
                        break;
                    result=suma(operando_uno,operando_dos);
                    printf("El resultado de %f+%f es: %f",operando_uno,operando_dos,result);
                    break;
                case 4:
                    faltaoperando=faltade_operandos(busca_errora,busca_errorb);
                    if(faltaoperando==1)
                        break;
                    result=resta(operando_uno,operando_dos);
                    printf("El resultado de %f-%f es: %f",operando_uno,operando_dos,result);
                    break;
                case 5:
                    if(operando_dos==0)
                        {
                            printf("Error!!\n Parece que esta intentando divir por '0'.");
                            break;
                        }
                    result=division(operando_uno,operando_dos);
                    printf("El resultado de %f/%f es: %f",operando_uno,operando_dos,result);
                    break;
                case 6:
                    faltaoperando=faltade_operandos(busca_errora,busca_errorb);
                    if(faltaoperando==1)
                        break;

                    result=multiplicacion(operando_uno,operando_dos);
                    printf("El resultado de %f*%f es: %f",operando_uno,operando_dos,result);
                    break;
                case 7:
                    if(operando_uno==1)
                    printf("El resultado del factorial de 1 es: 1");
                            else if(operando_uno<0)
                            {
                                printf("ERROR, ingrese un numero positivo");
                            }
                                else
                                {
                                    resultado_factorial=factorial(operando_uno);
                                    printf("El resultado del factorial de %f es: %ld",operando_uno,resultado_factorial);
                                }
                    break;
                case 8:

                        result=resta(operando_uno,operando_dos);
                        printf("\nEl resultado de %f-%f es: %f",operando_uno,operando_dos,result);
                        result=suma(operando_uno,operando_dos);
                        printf("\nEl resultado de %f+%f es: %f",operando_uno,operando_dos,result);
                        result=division(operando_uno,operando_dos);
                        printf("\nEl resultado de %f/%f es: %f",operando_uno,operando_dos,result);
                        result=multiplicacion(operando_uno,operando_dos);
                        printf("\nEl resultado de %f*%f es: %f",operando_uno,operando_dos,result);
                        result+=factorial(operando_uno);
                        printf("\nEl resultado del factorial de %f es: %lf",operando_uno,result);

                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
            printf("\nDesea continuar S/N?: ");
            seguir=tolower(getche());
            system("cls");
        }
    return 0;
}
