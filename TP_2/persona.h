#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    //------------
    int idPersona;
    int isEmpty;
}Persona;


int persona_init(Persona* array,int limite);
int persona_mostrar(Persona* array,int limite);
int persona_alta(Persona* array,int limite);
int persona_baja(Persona* array,int limite, int id);
int persona_ordenarPorNombre(Persona* array,int limite, int orden);
int persona_graficarPorEdades(Persona* array, int limite);
int persona_buscarPorId(Persona* array,int limite, int id);
int persona_altaForzada(Persona* array,int limite,char* nombre,int edad, int dni);

#endif // PANTALLA_H_INCLUDED



