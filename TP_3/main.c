#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "ArrayList.h"
#include "funciones.h"
#include "movie.h"
#include "utn.h"

int main()
{
    ArrayList* pArrayMovies;
    pArrayMovies = al_newArrayList();
    char seguir='s';
    int opcion;

    EMovie* auxMovie;

    cargarPeliculas(pArrayMovies);

    while(seguir=='s')
    {
        opcion = 0;
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                auxMovie = crearPelicula();
                if(auxMovie != NULL)
                {
                    if(agregarPelicula(pArrayMovies, auxMovie))
                       printf("\nHubo un error");
                }
                break;
            case 2:
                if(borrarPelicula(pArrayMovies))
                    printf("\nHubo un error");
                break;
            case 3:
                if(modificarPelicula(pArrayMovies))
                    printf("\nHubo un error");
               break;
            case 4:
                generarPagina(pArrayMovies );
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion incorrecta");
        }
        clearStdin();
    }

    return 0;
}
