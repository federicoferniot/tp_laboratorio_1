#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int factorial(int a);

int main()
{
    char seguir='s';
    int opcion=0;
    int primerOperando;
    int segundoOperando;
    float resultado;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
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
                resultado = sumar(primerOperando, segundoOperando);
                printf("%g\n", resultado);
                break;
            case 4:
                resultado = restar(primerOperando, segundoOperando);
                printf("%g\n", resultado);
                break;
            case 5:
                resultado = dividir(primerOperando, segundoOperando);
                printf("%g\n", resultado);
                break;
            case 6:
                resultado = multiplicar(primerOperando, segundoOperando);
                printf("%g\n", resultado);
                break;
            case 7:
                resultado = factorial(primerOperando);
                printf("%g\n", resultado);
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

int factorial(int a)
{
    int contador;
    int resultado=1;
    if(a!=0)
    {
        for(contador=a;contador>1;contador--)
        {
            resultado*=contador;
        }
    }
    return resultado;

}
