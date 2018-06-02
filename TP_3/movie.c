#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "utn.h"

int validarGenero(char* genero);
int validarLinkImg(char* linkImg);
int validarDescripcion(char* titulo);
int validarTitulo(char* titulo);
int validarDuracion(int duracion);
int validarPuntaje(int puntaje);

EMovie* movie_new(void)
{
    EMovie* auxMovie = malloc(sizeof(EMovie));
    return auxMovie;
}

EMovie* movie_newP(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImg)
{
    EMovie* auxMovie = malloc(sizeof(EMovie));
    if(auxMovie != NULL)
    {
        movie_setTitulo(auxMovie, titulo);
        movie_setGenero(auxMovie, genero);
        movie_setDuracion(auxMovie, duracion);
        movie_setDescripcion(auxMovie, descripcion);
        movie_setPuntaje(auxMovie, puntaje);
        movie_setLinkImg(auxMovie, linkImg);
    }
    return auxMovie;
}

void movie_delete(EMovie* this)
{
    free(this);
}

int movie_setTitulo(EMovie* this,char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && validarTitulo(titulo))
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }
    return retorno;
}

int movie_setGenero(EMovie* this,char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && validarGenero(genero))
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }
    return retorno;
}

int movie_setDuracion(EMovie* this,int duracion)
{
    int retorno = -1;
    if(this != NULL && !validarDuracion(duracion))
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}

int movie_setDescripcion(EMovie* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && validarDescripcion(descripcion))
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}

int movie_setPuntaje(EMovie* this,int puntaje)
{
    int retorno = -1;
    if(this != NULL && !validarPuntaje(puntaje))
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}

int movie_setLinkImg(EMovie* this,char* linkImg)
{
    int retorno = -1;
    if(this != NULL && linkImg != NULL && validarLinkImg(linkImg))
    {
        strcpy(this->linkImg, linkImg);
        retorno = 0;
    }
    return retorno;
}

int movie_getTitulo(EMovie* this,char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo ,this->titulo);
        retorno = 0;
    }
    return retorno;
}

int movie_getGenero(EMovie* this,char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero ,this->genero);
        retorno = 0;
    }
    return retorno;
}

int movie_getDuracion(EMovie* this,int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

int movie_getDescripcion(EMovie* this,char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion ,this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int movie_getPuntaje(EMovie* this,int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

int movie_getLinkImg(EMovie* this,char* linkImg)
{
    int retorno = -1;
    if(this != NULL && linkImg != NULL)
    {
        strcpy(linkImg ,this->linkImg);
        retorno = 0;
    }
    return retorno;
}

int validarTitulo(char* titulo)
{
    return esAlfaNumerico(titulo);
}

int validarDescripcion(char* descripcion)
{
    return esAlfaNumerico(descripcion);
}

int validarLinkImg(char* linkImg)
{
    return esLink(linkImg);
}

int validarGenero(char* genero)
{
    return esAlfaNumerico(genero);
}

int validarDuracion(int duracion)
{
    if(duracion > 0 && duracion < 1440)
        return 0;
    return -1;
}

int validarPuntaje(int puntaje)
{
    if(puntaje >0 && puntaje < 100)
        return 0;
    return -1;
}
