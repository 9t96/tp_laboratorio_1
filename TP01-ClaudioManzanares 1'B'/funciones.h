#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

double factorial(float);
float suma(float,float);
float resta(float,float);
float multiplicacion(float,float);
float division(float,float);
float faltade_operandos(float,float);

/**Recibe un flotante del programa principal
*para calcular su factorial
*se devuelve un 'double' para numeros grandes.
*Variable 'x' recibe un flotante del programa principal.
*Uso 'i' para controlar la iteracion que calcula el factorial.
*En 'result'guardo el resultado de la operacion
*/
double factorial(float x)
{
    double result,i;

    if(x==1)
        return 1;
    else
        for(i=1;i>x;)
        {
            result=(x*factorial(x-1));
        }
    return result;
}
/**Recibe dos flotantes del programa principal
* para realizar la suma, devuelve un float.
*Variable 'x' recibe un flotante del programa principal.
*Variable 'y' recibe un flotante del programa principal.
*En 'result'guardo el resultado de la operacion
*/
float suma(float x, float y)
{
    float result;
    result=x+y;
    return result;

}
/**Recibe dos flotantes del programa principal
*para realizar la resta, opera y devuelve otro flotante.
*Variable 'x' recibe un flotante del programa principal.
*Variable 'y' recibe un flotante del programa principal.
*En 'result'guardo el resultado de la operacion
*/
float resta(float x, float y)
{
    float result;

    result=x-y;
    return result;
}
/**Recibe dos flotantes del programa principal
*para realizar la multiplicacion, opera y devuelve un flotante.
*Variable 'x' recibe un flotante del programa principal.
*Variable 'y' recibe un flotante del programa principal.
*En 'result'guardo el resultado de la operacion
*/
float multiplicacion(float x, float y)
{
    float result;
    result=x*y;
    return result;

}
/**Se reciben dos flotantes del programa principal
*para realizar la divison, se opera y devuelve un flotante.
*Variable 'x' recibe un flotante del programa principal.
*Variable 'y' recibe un flotante del programa principal.
*En 'result'guardo el resultado de la operacion
*/
float division(float x, float y)
{
    float result;
    if(y==0)
    printf("Error, esta intentando dividir por '0'.");

    result=x/y;
    return result;
}
/**
*Funcion crea con el fin de avisarle al usuario
*que no puede realizar la operacion deseada
*por falta de un operando
*X e Y reciben de valor de una variable bandera
*que se iguala a 1 si se ingresa el operando
*En el programa principal X seria 'a'
*e Y seria 'b'.
*/
float faltade_operandos(float x, float y)
{
    if(x==0||y==0)
    {
        printf("Error!!\nFalta un operando, reingrese y vuelva a intentar");
        return 1;
    }
    else
        return 0;
}
#endif // FUNCIONES_H_INCLUDED
