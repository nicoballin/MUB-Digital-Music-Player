#ifndef codes
#define codes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct _cancion
{
    int id;
    char* nombre;
    char* artista;
    char* album;
    char* genero;
    int duracion_seg;
    int año;
    int n_reproducciones;
}Cancion;

//aca definamos los algoritmos que usaremos 

void Print_Menu_Inicial();
int Escoger_Opcion_Menu();
int Pedir_cantidad_de_Canciones();
void Crear_Canciones(Cancion arr[],int cantidad_de_canciones);
int Generar_Duracion_Seg();
int Generar_Anho_Cancion();
char* Generar_Titulo();
char* Generar_Artista();
void Print_Lista_Canciones(Cancion arr[],int cantidad_de_canciones);
void Liberar_Memoria_Canciones(Cancion arr[], int cantidad_de_canciones);

#endif