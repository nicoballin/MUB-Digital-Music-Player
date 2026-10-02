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
#define MAX_CANCIONES 5000
#define ANHO_MINIMO 1920
#define ANHO_MAXIMO 2026
#define DURACION_MIN_SEG 10
#define DURACION_MAX_SEG 3600

/**
 * @brief Es el Tipo de criterio para Ordenar / Buscar una cancion
 * 
 */
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

/**
 * @brief Manera de ordenar un arreglo
 * 
 */
typedef enum _orden
{
    ASCENDENTE,
    DESCENDENTE
}Orden;

/**
 * @brief Estructura que define a una cancion
 * @param id Es la ID de la cancion (int)
 * @param nombre Es el Titulo / Nombre de la cancion (char*)
 * @param artista Es el nombre del Artista de la cancion (char*)
 * @param album Es el nombre del Album de la cancion (char*)
 * @param duracion_seg Es la Duracion en segundos de la cancion (int)
 * @param anho Es el Anho de la cancion (int)
 * @param n_reproducciones Es la cantidad de Reproducciones de la cancion (int)
 */
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


/**
 * @brief Funcion de animacion de Cargando...
 * 
 */
void Print_Animacion();
/**
 * @brief Funcion para limpiar la pantalla
 * 
 */
void Limpiar_Pantalla();

/**
 * @brief Funcion que se utiliza para leer una opcion numerica ingresada por el usuario
 * 
 * @return Devuelve un entero que corresponde al opcion ingresada
 */
int Escoger_Opcion_Menu();
/**
 * @brief Funcion para pedir un numero entero de canciones a generar
 * 
 * @return Retorna la cantidad de cancioens que se van a generar
 */
int Pedir_cantidad_de_Canciones();

/**
 * @brief Funcin para liberar memoria de las canciones
 * 
 * @param arr 
 * @param cantidad_de_cancioens 
 */
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

/**
 * @brief Funcion utilizada para Reproducir una cancion cualquiera del Arreglo de canciones
 * 
 * @param canciones Es el arreglo de todas las cancionesdel repertorio
 * @param playlist Es el arreglo de la playlsit de canciones en cola
 * @param historial Es el historial que guarda canciones ya reproducidas
 * @param cantidad_de_canciones Es la cantidad de Canciones del reperotiro
 */
void Reproducir_Cancion(Cancion canciones[],Cancion playlist[], Cancion historial[],int cantidad_de_canciones);

/**
 * @brief Funcion que ELIMINA  la primera cancion del arreglo de playlist
 * 
 * @param playlist Es el arreglo de canciones en cola para reproducir
 * @param cantidad_de_canciones Es la cantidad de canciones en la playlist
 */
void Quitar_Primera_Cancion_Playlist(Cancion playlist[],int cantidad_de_canciones);

/**
 * @brief Funcion que AGREGA una cancion al historial de reproduccion 
 * una vez se haya reproducido
 * 
 * @param historial Es el arreglo de canciones ya reproducidas
 * @param cancion_reproducida Es la cancion que se acaba de rerpoducir
 */
void Agregar_Cancion_Historial(Cancion historial[],Cancion cancion_reproducida);

/**
 * @brief Funcion que AUMENTA en +1 las reproduccionmes de una cancion 
 * al ser reproducida
 * 
 * @param Canciones Es el arreglo de canciones en el repertorio
 * @param cantidad_de_canciones Es la cantida de canciones
 * @param id_cancion Es la ID de la cancion Reproducida
 */
void Aumentar_Reproduccion(Cancion Canciones[],int cantidad_de_canciones,int id_cancion);

/**
 * @brief Funcion que ELIMINA una cancion del aplaylist segun su ID
 * 
 * @param playlist Es el arreglo de canciones en cola para reproducir
 * @param cantidad_de_canciones Es la cantidad de canciones en la playlist
 * @param id_cancion Es la ID de la cancion a ELIMINAR
 */
void Quitar_Cancion_ID_Playlist(Cancion playlist[], int cantidad_de_canciones, int id_cancion);

/**
 * @brief Funcion que ELIMINA una cancion de la playlist segun su POSICION
 * 
 * @param playlist Es el arreglo de canciones en cola para reproducir
 * @param cantidad_de_canciones Es la cantidad de canciones en la playlist
 * @param posicion Es la POSICION de la cancion a ELIMINAR dentro del arreglo playlist 
 */
void Quitar_Cancion_Posicion_Playlist(Cancion playlist[], int cantidad_de_canciones, int posicion);

/**
 * @brief Funcion que VACIA toda la playlist
 * 
 * @param playlist Es el arreglo de canciones en cola para reproducir
 * @param cantidad_de_canciones Es la cantidad de canciones en la playlist
 */
void Vaciar_Playlist(Cancion playlist[], int cantidad_de_canciones);


/**
 * @brief Funcion que imprime todosl os artistas disponibles en el catalogo 
 * 
 * @param arr Es el arreglo de canciones (repertorio entero)
 * @param n Es la cantidad de canciones en el repertorio
 */
void Listar_Artistas_Disponibles(Cancion arr[], int n);

/**
 * @brief Funcion qeue imprime una tabla con los generos disponiblesen el repertorio de musica
 * 
* @param arr Es el arreglo de canciones (repertorio entero)
 * @param n Es la cantidad de canciones en el repertorio
 */
void Resumen_Canciones_Por_Genero(Cancion arr[], int n);

/**
 * @brief Funcion que lista las cancioens de un genrro especifico
 * 
 * @param arr Es el arreglo de canciones (repertorio entero)
 * @param n Es la cantidad de canciones en el repertorio
 * @param genero_buscado Ese el genero a lsitar
 */
void Listar_Canciones_Por_Genero(Cancion arr[], int n, const char* genero_buscado);

/**
 * @brief Funcion que limpia el buffer para leer texto
 * 
 * @param buffer 
 * @param max 
 */
void Leer_Texto(char* buffer, int max);

#endif