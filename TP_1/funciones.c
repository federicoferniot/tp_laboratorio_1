#include <limits.h>

int sumarEnteros(int primerNumero, int segundoNumero, float* resultado)
{

    long long resultadoCalculo;
    int retorno=-1;

    resultadoCalculo = (long)primerNumero+segundoNumero;
    if(resultadoCalculo<INT_MAX && resultadoCalculo>INT_MIN)
    {
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}

int restarEnteros(int primerNumero, int segundoNumero, float* resultado)
{
    long resultadoCalculo;
    int retorno = -1;

    resultadoCalculo = (long)primerNumero-segundoNumero;
    if(resultadoCalculo<INT_MAX && resultadoCalculo>INT_MIN)
    {
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}

int dividirEnteros(int primerNumero, int segundoNumero, float* resultado)
{
    int retorno=-1;
    if(segundoNumero!=0)
    {
        *resultado = (float)primerNumero/segundoNumero;
        retorno=0;
    }
    return retorno;
}

int multiplicarEnteros(int primerNumero, int segundoNumero, float* resultado)
{
    long resultadoCalculo;
    int retorno=-1;

    resultadoCalculo = primerNumero*segundoNumero;
    if(resultadoCalculo<INT_MAX && resultadoCalculo>INT_MIN)
    {
        *resultado=resultadoCalculo;
        retorno=0;
    }
    return retorno;
}
