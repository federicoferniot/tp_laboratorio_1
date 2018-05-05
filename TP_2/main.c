#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"
#define LEN_PER 20

int main()
{
    Persona personas[LEN_PER];
    Persona_init(personas, LEN_PER);

    Persona_altaForzada(personas, LEN_PER, "Pedro", 20, 37374994);
    Persona_altaForzada(personas, LEN_PER, "Ana", 18, 37374993);
    Persona_altaForzada(personas, LEN_PER, "Mario", 40, 24842334);
    Persona_altaForzada(personas, LEN_PER, "Carla", 35, 34554656);

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
                Persona_alta(personas, LEN_PER);
                break;
            case 2:
                getValidInt("\nIngrese el ID de la persona a borrar", "Eso no es un ID", &auxId, 0, 100000, 2);
                Persona_baja(personas, LEN_PER, auxId);
                break;
            case 3:
                Persona_ordenarPorNombre(personas, LEN_PER, 1);
                Persona_mostrar(personas, LEN_PER);
                break;
            case 4:
                Persona_graficarPorEdades(personas, LEN_PER);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
