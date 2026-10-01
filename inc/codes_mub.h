#ifndef codes
#define codes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TAMANHO_HISTORIAL 10
#define MAX_CANCIONES 200
#define ANHO_MINIMO 1920
#define ANHO_MAXIMO 2026
#define DURACION_MIN_SEG 10
#define DURACION_MAX_SEG 3600

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
void Print_Menu_Reproduccion();
void Print_Historial(Cancion historial[]);
void Print_Animacion();
void Limpiar_Pantalla();

int Escoger_Opcion_Menu();
int Pedir_cantidad_de_Canciones();
void Liberar_Memoria_Canciones(Cancion arr[], int cantidad_de_canciones);
void Inicializar_Playlist(Cancion arr[], int cantidad_de_canciones);
void Anhadir_Cancion_ID_Playlist(Cancion canciones[], Cancion Playlist[], int cantidad_de_canciones, int target);

void Reproducir_Cancion(Cancion canciones[],Cancion playlist[], Cancion historial[],int cantidad_de_canciones);
void Quitar_Primera_Cancion_Playlist(Cancion playlist[],int cantidad_de_canciones);
void Agregar_Cancion_Historial(Cancion historial[],Cancion cancion_reproducida);
void Aumentar_Reproduccion(Cancion Canciones[],int cantidad_de_canciones,int id_cancion);

/**
 * @brief Funcion que enlista aa todos los artistas disponibles del catalogo
 * 
 * @param arr 
 * @param n 
 */
void Listar_Artistas_Disponibles(Cancion arr[], int n);

/**
 * @brief Funcion que resume todas las cancionessegun e genero.
 * 
 * @param arr 
 * @param n 
 */
void Resumen_Canciones_Por_Genero(Cancion arr[], int n);

/**
 * @brief Funcion que Enlista a todas las canciones segun su genero
 * 
 * @param arr 
 * @param n 
 * @param genero_buscado 
 */
void Listar_Canciones_Por_Genero(Cancion arr[], int n, const char* genero_buscado);

void Leer_Texto(char* buffer, int max);

#endif