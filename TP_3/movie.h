#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct
{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImg[256];
}EMovie;

EMovie* movie_new(void);
EMovie* movie_newP(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImg);
void movie_delete(EMovie* this);
int movie_setTitulo(EMovie* this,char* titulo);
int movie_setGenero(EMovie* this,char* genero);
int movie_setDuracion(EMovie* this,int duracion);
int movie_setDescripcion(EMovie* this,char* descripcion);
int movie_setPuntaje(EMovie* this,int puntaje);
int movie_setLinkImg(EMovie* this,char* linkImg);
int movie_getTitulo(EMovie* this,char* titulo);
int movie_getGenero(EMovie* this,char* genero);
int movie_getDuracion(EMovie* this,int* duracion);
int movie_getDescripcion(EMovie* this,char* descripcion);
int movie_getPuntaje(EMovie* this,int* puntaje);
int movie_getLinkImg(EMovie* this,char* linkImg);

#endif // MOVIE_H_INCLUDED
