#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "paginaWeb.h"
#include "funciones.h"
#include "movie.h"
#include "utn.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


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
