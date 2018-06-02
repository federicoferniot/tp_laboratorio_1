#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "paginaWeb.h"
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
                    al_add(pArrayMovies, auxMovie);
                    agregarPelicula(auxMovie);
                }
                break;
            case 2:
                borrarPelicula(pArrayMovies);
                break;
            case 3:
               break;
            case 4:
                generarPaginaWeb("pagina.html", pArrayMovies );
                break;
            case 5:
                seguir = 'n';
                break;
        }
        clearStdin();
    }

    return 0;
}
