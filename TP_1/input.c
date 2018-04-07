#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int chances)
{
    int retorno=-1;
    long long inputAux;
    do
    {
        printf("%s", message);
        scanf("%lld", &inputAux);
        if(inputAux<=hiLimit && inputAux>=lowLimit)
        {
            *input=(int)inputAux;
            retorno=0;
            break;
        }
        printf("%s", eMessage);
        chances--;
    }while(chances>=0);
    return retorno;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int chances)
{
    int retorno=-1;
    double inputAux;
    do
    {
        printf("%s", message);
        scanf("%lf", &inputAux);
        if(inputAux<=hiLimit && inputAux>=lowLimit)
        {
            *input=(float)inputAux;
            retorno=0;
            break;
        }
        printf("%s", eMessage);
        chances--;
    }while(chances>=0);
    return retorno;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int chances)
{
    int retorno=-1;
    char inputAux;
    do
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%c", &inputAux);
        if(inputAux<=hiLimit && inputAux>=lowLimit)
        {
            *input=(float)inputAux;
            retorno=0;
            break;
        }
        printf("%s", eMessage);
        chances--;
    }while(chances>=0);
    return retorno;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    //.........
    //.........
    //.........
    //.........

    strcpy(input,"Sheldon");
    return 0;
}
