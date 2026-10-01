/**
 * @file codes_mub.h
 * @author Nicolas Balic (nbalic@umagallanes.cl), Tomas Minte (tminte@umagallanes.cl), Daniel Uribe (daniurib@umagallanes.cl).
 * @brief 
 * @version 1.0
 * @date 2026-09-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */


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
void Print_Animacion();
void Limpiar_Pantalla();

int Escoger_Opcion_Menu();
int Pedir_cantidad_de_Canciones();
void Liberar_Memoria_Canciones(Cancion arr[], int cantidad_de_canciones);
/**
 * @brief Inicializa el arreglo de canciones, con valores '0' para valores numericos y "" para strings
 * 
 * @param arr 
 * @param cantidad_de_canciones 
 */
void Inicializar_Playlist(Cancion arr[], int cantidad_de_canciones);

/**
 * @brief Funcion cuyo uso es anhadir desde el arreglo de todas las canciones, una cancion en especifica indicada por la ID 
 *  Buscando en todo al arreglo de las canciones una con la misma id, y la copia en la cola de reproduccion.
 * 
 * @param canciones La lista completa de canciones
 * @param Playlist El arreglo de la fila de reproduccion 
 * @param cantidad_de_canciones La cantidad total de canciones
 * @param target La id de la cancion que se va a anhadir en el arreglo Playlist
 */
void Anhadir_Cancion_ID_Playlist(Cancion canciones[], Cancion Playlist[], int cantidad_de_canciones, int target);



void Reproducir_Cancion(Cancion canciones[],Cancion playlist[], Cancion historial[],int cantidad_de_canciones);
void Quitar_Primera_Cancion_Playlist(Cancion playlist[],int cantidad_de_canciones);
void Agregar_Cancion_Historial(Cancion historial[],Cancion cancion_reproducida);
void Aumentar_Reproduccion(Cancion Canciones[],int cantidad_de_canciones,int id_cancion);
void Quitar_Cancion_ID_Playlist(Cancion playlist[], int cantidad_de_canciones, int id_cancion);
int Contar_Canciones_Playlist(Cancion playlist[], int cantidad_de_canciones);
void Quitar_Cancion_Posicion_Playlist(Cancion playlist[], int cantidad_de_canciones, int posicion);
void Vaciar_Playlist(Cancion playlist[], int cantidad_de_canciones);


#endif