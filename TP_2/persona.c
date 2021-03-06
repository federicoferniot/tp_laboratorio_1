#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "Persona.h"
#include "utn.h"
#define EDAD_MENOR 18
#define EDAD_MAYOR 35

static int proximoId();
static int buscarLugarLibre(Persona* array,int limite);

/** \brief
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra por pantalla cada persona dada de alta en el array
 *
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("ID: %d - Nombre: %s - Edad: %d - DNI: %d\n", array[i].idPersona, array[i].nombre, array[i].edad, array[i].dni);
            }

        }
    }
    return retorno;
}

/** \brief Da de alta una persona, solicitando al usuario que ingrese los datos
 *
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    int edad;
    int dni;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidInt("\nEdad? ","\nEso no es una edad",&edad,1,200, 2))
                {
                    if(!getValidInt("\nDNI? ","\nEso no es un DNI",&dni,1,INT_MAX, 2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].edad = edad;
                        array[i].dni = dni;
                        //------------------------------
                        //------------------------------
                        array[i].idPersona = proximoId();
                        array[i].isEmpty = 0;
                    }
                    else
                    {
                        retorno = -5;
                    }

                }
                else
                {
                    retorno = -4;
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}


/** \brief Da de baja una persona, pasando el id de la persona a dar de baja
 *
 * \param array Persona*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int persona_baja(Persona* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = persona_buscarPorId(array, limite, id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}


/** \brief Ordena el array de Persona, ordenando por nombre ascendiente o descendiente
 *
 * \param array Persona*
 * \param limite int
 * \param orden int
 * \return int
 *
 */
int persona_ordenarPorNombre(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Persona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            retorno=0;
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


/** \brief Busca una persona por Id, devolviendo la posici�n en el array
 *
 * \param array Persona*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int persona_buscarPorId(Persona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPersona==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Muestra un gr�fico por pantalla, mostrando la cantidad de personas dadas de alta en distintos rangos de edades
 *
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_graficarPorEdades(Persona* array, int limite)
{
    int retorno=-1;
    int i, maxCantidadEdad;
    int contadorEdadMenor=0;
    int contadorEdadMedia=0;
    int contadorEdadMayor=0;
    if(limite > 0 && array != NULL)
    {
        retorno=0;
        for(i=0; i<limite; i++)
        {
            if(!array[i].isEmpty && array[i].edad<EDAD_MENOR)
            {
                contadorEdadMenor++;
            }
            else if(!array[i].isEmpty && array[i].edad>=EDAD_MENOR && array[i].edad<=EDAD_MAYOR)
            {
                contadorEdadMedia++;
            }
            else if(!array[i].isEmpty && array[i].edad>EDAD_MAYOR)
            {
                contadorEdadMayor++;
            }
        }
        maxCantidadEdad=maxInt(contadorEdadMenor, contadorEdadMedia);
        maxCantidadEdad=maxInt(maxCantidadEdad, contadorEdadMayor);

        for(i=maxCantidadEdad;i>0;i--)
        {
            if(i<=contadorEdadMenor)
            {
                printf("  *  ");
            }
            else
            {
                printf("     ");
            }
            if(i<=contadorEdadMedia)
            {
                printf("  *  ");
            }
            else
            {
                printf("     ");
            }
            if(i<=contadorEdadMayor)
            {
                printf("  *  \n");
            }
            else
            {
                printf("     \n");
            }
        }
        printf(" <%d %d-%d >%d",EDAD_MENOR,EDAD_MENOR,EDAD_MAYOR,EDAD_MAYOR);
    }
    return retorno;
}

int persona_altaForzada(Persona* array,int limite,char* nombre,int edad, int dni)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].edad = edad;
            array[i].dni = dni;
            //------------------------------
            //------------------------------
            array[i].idPersona = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
