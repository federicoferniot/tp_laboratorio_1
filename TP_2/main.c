#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"
#define LEN_PER 20

int main()
{
    Persona personas[LEN_PER];
    persona_init(personas, LEN_PER);

    char seguir='s';
    int opcion=0;
    int auxId;

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        getValidInt("\nIngrese la opcion: ", "Opcion no valida\n", &opcion, 1, 5, 10);

        switch(opcion)
        {
            case 1:
                if(persona_alta(personas, LEN_PER))
                {
                    printf("Hubo un error al dar de alta\n");
                }
                break;
            case 2:
                if(!getValidInt("\nIngrese el ID de la persona a borrar", "Eso no es un ID", &auxId, 0, 100000, 2))
                {
                    if(persona_baja(personas, LEN_PER, auxId))
                    {
                        printf("Hubo un error al dar de baja\n");
                    }
                }
                else
                {
                    printf("Hubo un error al ingresar el ID\n");
                }
                break;
            case 3:
                if(!persona_ordenarPorNombre(personas, LEN_PER, 1))
                {
                    persona_mostrar(personas, LEN_PER);
                }
                break;
            case 4:
                if(persona_graficarPorEdades(personas, LEN_PER))
                {
                    printf("Hubo un error al graficar\n");
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
