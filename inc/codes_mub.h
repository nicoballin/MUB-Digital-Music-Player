#ifndef codes
#define codes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Criterio para ordenar el catalogo
typedef enum _tipo_criterio
{
    ID,
    NOMBRE,
    ARTISTA,
    ALBUM,
    GENERO,
    DURACION,
    ANHO,
    REPRODUCCIONES
}Tipo_Criterio;

// Como ordenar el Catalogo
typedef enum _orden
{
    ASCENDENTE,
    DESCENDENTE
}Orden;

//Estructura que define a una Cancion
typedef struct _cancion
{
    int id;
    char* nombre;
    char* artista;
    char* album;
    char* genero;
    int duracion_seg;
    int anho;
    int n_reproducciones;
}Cancion;

//aca definamos los algoritmos que usaremos 

void Print_Menu_Inicial();
void Print_Menu_Criterios_Ordenamiento();
void Print_Opciones_Orden();
void Print_Menu_Playlsit();
void Print_Playlist(Cancion arr[], int cantidad_de_canciones);
void Print_Lista_Canciones(Cancion arr[],int cantidad_de_canciones);
void Print_Menu_anhadir_Playlsit();

int Escoger_Opcion_Menu();
int Pedir_cantidad_de_Canciones();
void Liberar_Memoria_Canciones(Cancion arr[], int cantidad_de_canciones);
void Inicializar_Playlist(Cancion arr[], int cantidad_de_canciones);

#endif