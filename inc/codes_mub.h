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
    REPRODUCCIONES,
    SALIR_CRITERIO
}Tipo_Criterio;

// Como ordenar el Catalogo
typedef enum _orden
{
    ASCENDENTE,
    DESCENDENTE,
    SALIR_ORDEN
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