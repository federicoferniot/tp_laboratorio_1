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


int Persona_init(Persona* array,int limite);
int Persona_mostrar(Persona* array,int limite);
int Persona_alta(Persona* array,int limite);
int Persona_baja(Persona* array,int limite, int id);
int Persona_ordenarPorNombre(Persona* array,int limite, int orden);
int Persona_graficarPorEdades(Persona* array, int limite);
int Persona_buscarPorId(Persona* array,int limite, int id);
int Persona_altaForzada(Persona* array,int limite,char* nombre,int edad, int dni);

#endif // PANTALLA_H_INCLUDED



