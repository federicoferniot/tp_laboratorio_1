#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

int factorial(int primerNumero, unsigned long* resultado);
void calcularYMostrarSuma(int primerOperando, int segundoOperando);
void calcularYMostrarResta(int primerOperando, int segundoOperando);
void calcularYMostrarDivision(int primerOperando, int segundoOperando);
void calcularYMostrarMultiplicacion(int primerOperando, int segundoOperando);
void calcularYMostrarFactorial(int primerOperando);

int main()
{
    char seguir='s';
    int opcion=0;
    int primerOperando=NULL;
    int segundoOperando=NULL;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n", primerOperando);
        printf("2- Ingresar 2do operando (B=%d)\n", segundoOperando);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando\n");
                scanf("%d", &primerOperando);
                break;
            case 2:
                printf("Ingrese el segundo operando\n");
                scanf("%d", &segundoOperando);
                break;
            case 3:
                calcularYMostrarSuma(primerOperando, segundoOperando);
                break;
            case 4:
                calcularYMostrarResta(primerOperando, segundoOperando);
                break;
            case 5:
                calcularYMostrarDivision(primerOperando, segundoOperando);
                break;
            case 6:
                calcularYMostrarMultiplicacion(primerOperando, segundoOperando);
                break;
            case 7:
                calcularYMostrarFactorial(primerOperando);
                break;
            case 8:
                calcularYMostrarSuma(primerOperando, segundoOperando);
                calcularYMostrarResta(primerOperando, segundoOperando);
                calcularYMostrarDivision(primerOperando, segundoOperando);
                calcularYMostrarMultiplicacion(primerOperando, segundoOperando);
                calcularYMostrarFactorial(primerOperando);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void calcularYMostrarSuma(int primerOperando, int segundoOperando)
{
    float resultado;

    if(sumarEnteros(primerOperando, segundoOperando, &resultado)==0)
    {
        printf("La suma es %f.0\n", resultado);
    }
    else
    {
        printf("Se produjo un error\n");
    }
}

void calcularYMostrarResta(int primerOperando, int segundoOperando)
{
    float resultado;
    if(restarEnteros(primerOperando, segundoOperando, &resultado)==0)
    {
        printf("La resta es %f.0\n", resultado);
    }
    else
    {
        printf("Se produjo un error\n");
    }
}

void calcularYMostrarDivision(int primerOperando, int segundoOperando)
{
    float resultado;
    if(dividirEnteros(primerOperando, segundoOperando, &resultado)==0)
    {
        printf("La division es %g\n", resultado);
    }
    else
    {
        printf("Error, no se puede dividir por 0\n");
    }
}

void calcularYMostrarMultiplicacion(int primerOperando, int segundoOperando)
{
    float resultado;
    if(multiplicarEnteros(primerOperando, segundoOperando, &resultado)==0)
    {
        printf("La multiplicacion es %g\n", resultado);
    }
    else
    {
        printf("Se produjo un error\n");
    }
}

void calcularYMostrarFactorial(int primerOperando)
{
    unsigned long resultado;
    int estadoOperacionFactorial;
    estadoOperacionFactorial = factorial(primerOperando, &resultado);
    if(estadoOperacionFactorial==0)
    {
        printf("El factorial es %lu \n", resultado);
    }
    else if(estadoOperacionFactorial==-1)
    {
        printf("Se ha producido un error\n");
    }
    else
    {
        printf("No se puede calcular el factorial a un numero negativo\n");
    }
}


/** Calcula el factorial de un numero, guardando el resultado en resultado
 *
 * Si no hubo errores devuelve 0.
 * En caso de error de overflow devuelve -1.
 * En caso de querer calcular el factorial de un numero negativo devuelve -2.
 */
int factorial(int primerNumero, unsigned long* resultado)
{
    int contador;
    *resultado=1;
    unsigned long long resultadoCalculo=1;
    int retorno=0;

    for(contador=primerNumero;contador>1;contador--)
    {
        resultadoCalculo*=contador;
        if(resultadoCalculo>=ULONG_MAX)
        {
            retorno=-1;
            break;
        }
    }

    *resultado = resultadoCalculo;

    if(primerNumero<0)
    {
        retorno=-2;
    }
    return retorno;
}
