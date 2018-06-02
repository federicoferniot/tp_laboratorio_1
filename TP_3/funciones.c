#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "movie.h"
#include "utn.h"
#include "ArrayList.h"
#include "parser.h"
#include "paginaWeb.h"

EMovie* crearPelicula(void)
{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", titulo, 50,2))
        if(!getValidString("\nIngrese el genero\n","\nEso no es un genero\n","\nEl maximo es 30\n", genero, 30,2))
            if(!getValidInt("\nIngrese la duracion\n","\nEso no es una duracion\n", &duracion, 0, 1440,2))
                if(!getValidString("\nIngrese la descripcion\n","\nEso no es una descripcion\n", "\nEl maximo es 256\n", descripcion, 256,2))
                    if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nEso no es un puntaje\n", &puntaje, 0, 10, 2))
                        if(!getValidStringLink("\nIngrese el link de la imagen\n", "\nEso no es un link\n", "\nEl maximo es 256\n", linkImg, 256, 2))
                        {
                            auxPelicula = movie_newP(titulo, genero, duracion, descripcion, puntaje, linkImg);
                            return auxPelicula;
                        }
    return NULL;
}

int agregarPelicula(ArrayList* pArrayPeliculas, EMovie* movie)
{
    if(movie != NULL)
    {
        al_add(pArrayPeliculas, movie);
        if(!guardarPeliculas(pArrayPeliculas))
            return 0;
    }
    return -1;
}


int borrarPelicula(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    int i;
    char titulo[50];
    char tituloABorrar[50];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo a borrar\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", tituloABorrar, 50,2))
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
                guardarPeliculas(pArrayPeliculas);
                break;
            }
        }
    }
    return retorno;
}

int modificarPelicula(ArrayList* pArrayPeliculas)
{
    int retorno = -1;
    int i;
    char titulo[50];
    char tituloAModificar[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];
    EMovie* auxPelicula;
    if(!getValidString("\nIngrese el titulo a modificar\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", tituloAModificar, 50,2))
    {
        for(i=0; i<al_len(pArrayPeliculas);i++)
        {
            movie_getTitulo(al_get(pArrayPeliculas, i), titulo);
            toLowerCase(tituloAModificar);
            toLowerCase(titulo);
            if(!strcmp(tituloAModificar, titulo))
            {
                auxPelicula = al_get(pArrayPeliculas, i);
                if(!getValidString("\nIngrese el titulo\n", "\nEso no es un titulo\n","\nEl maximo es 50\n", titulo, 50,2))
                    if(!getValidString("\nIngrese el genero\n","\nEso no es un genero\n","\El maximo es 30\n", genero, 30,2))
                        if(!getValidInt("\nIngrese la duracion\n","\nEso no es una duracion\n", &duracion, 0, 1440,2))
                            if(!getValidString("\nIngrese la descripcion\n","\nEso no es una descripcion\n", "El maximo es 256\n", descripcion, 256,2))
                                if(!getValidInt("\nIngrese el puntaje[0-10]\n", "\nEso no es un puntaje\n", &puntaje, 0, 10, 2))
                                    if(!getValidStringLink("\nIngrese el link de la imagen\n", "\nEso no es un link\n", "\nEl maximo es 256\n", linkImg, 256, 2))
                                    {
                                        retorno = 0;
                                        movie_setTitulo(auxPelicula, titulo);
                                        movie_setGenero(auxPelicula, genero);
                                        movie_setDuracion(auxPelicula, duracion);
                                        movie_setDescripcion(auxPelicula, descripcion);
                                        movie_setPuntaje(auxPelicula, puntaje);
                                        movie_setLinkImg(auxPelicula, linkImg);
                                    }
                guardarPeliculas(pArrayPeliculas);
                break;
            }
        }
    }
    return retorno;
}

void generarPagina(ArrayList* pArrayPeliculas)
{
    char nombreArchivo[20];
    if(!getValidString("\nIngrese el nombre del archivo a generar\n", "\nNo es valido\n", "\nEl maximo es 20\n", nombreArchivo, 20, 5))
        generarPaginaWeb(nombreArchivo, pArrayPeliculas);
}
