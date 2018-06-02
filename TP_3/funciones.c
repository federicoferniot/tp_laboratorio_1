#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "movie.h"
#include "utn.h"
#include "ArrayList.h"
#define CANT_PEL 20

EMovie* crearPelicula(void)
{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo\n", "\nEso no es un titulo","\nEl maximo es 50", titulo, 50,2))
        if(!getValidString("\nIngrese el genero\n","\nEso no es un genero\n","\El maximo es 30", genero, 30,2))
            if(!getValidInt("\nIngrese la duracion\n","\nEso no es una duracion", &duracion, 0, 1440,2))
                if(!getValidString("\nIngrese la descripcion\n","\nEso no es una descripcion\n", "El maximo es 256", descripcion, 256,2))
                    if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nEso no es un puntaje\n", &puntaje, 0, 10, 2))
                        if(!getValidStringLink("\nIngrese el link de la imagen\n", "\nEso no es un link\n", "\nEl maximo es 256", linkImg, 256, 2))
                        {
                            auxPelicula = movie_newP(titulo, genero, duracion, descripcion, puntaje, linkImg);
                            return auxPelicula;
                        }
    return NULL;
}

int agregarPelicula(EMovie* movie)
{
    int retorno = -1;
    FILE* peliculas = fopen("movies.bin", "ab");
    if(peliculas != NULL)
    {
        fwrite(movie, sizeof(EMovie), 1, peliculas);
        fclose(peliculas);
        retorno = 0;
    }
    return retorno;
}


int borrarPelicula(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    int i;
    char titulo[20];
    char tituloABorrar[20];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo a borrar\n", "\nEso no es un titulo","\nEl maximo es 20", tituloABorrar, 20,2))
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            movie_getTitulo(al_get(pArrayPeliculas, i), titulo);
            toLowerCase(tituloABorrar);
            toLowerCase(titulo);
            if(!strcmp(tituloABorrar, titulo))
            {
                retorno = 0;
                auxPelicula = al_pop(pArrayPeliculas, i);
                movie_delete(auxPelicula);
                break;
            }
        }
    }
    return retorno;
}

int guardarPeliculas(ArrayList* pArrayPeliculas)
{
    int i;
    int retorno = -1;
    FILE* peliculas = fopen("movies.bin", "w");
    if(peliculas != NULL)
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            fwrite(al_get(pArrayPeliculas, i), sizeof(EMovie), 1, peliculas);
        }
        fclose(peliculas);
        retorno = 0;
    }
    return retorno;
}
