/**
 * @file print.h
 * @author Daniel Uribe (daniurib@umagallanes.cl).
 * @brief Archivo header para declarar los colores y funciones relacionadas a la interfaz (printf)
 * @version 0.1
 * @date 2026-09-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef PRINT
#define PRINT

#include "codes_mub.h"
#include <stdio.h>

// Colores basicos (los originales)
#define ROJO     "\033[31m"
#define VERDE    "\033[32m"
#define RESET    "\033[0m"
#define NEGRO    "\033[30m"
#define AMARILLO "\033[33m"
#define AZUL     "\033[34m"
#define MAGENTA  "\033[35m"
#define CIAN     "\033[36m"
#define BLANCO   "\033[37m"

// Paleta Y2K (colores de 256 tonos)
#define ROSA_CHICLE      "\033[38;5;213m"
#define ROSA_FUCSIA      "\033[38;5;199m"
#define CIAN_NEON        "\033[38;5;51m"
#define AZUL_ELECTRICO   "\033[38;5;39m"
#define LILA             "\033[38;5;141m"
#define PLATA            "\033[38;5;252m"
#define GRIS             "\033[38;5;245m"
#define LIMA             "\033[38;5;118m"
#define NARANJA          "\033[38;5;208m"
#define AMARILLO_NEON    "\033[38;5;226m"
#define ROJO_NEON        "\033[38;5;197m"

// Estilos
#define NEGRITA          "\033[1m"
#define FONDO_ROSA       "\033[48;5;199m"
#define FONDO_CIAN       "\033[48;5;51m"

// Etiquetas para mensajes: printf("\t" TAG_OK "texto\n");
#define TAG_OK     NEGRITA LIMA          "[✔] " RESET
#define TAG_ERROR  NEGRITA ROJO_NEON     "[✘] " RESET
#define TAG_INFO   NEGRITA CIAN_NEON     "[✦] " RESET
#define TAG_AVISO  NEGRITA AMARILLO_NEON "[!] " RESET


/** @brief Imprime un titulo con marco estilo Y2K. 
 * @param titulo Es el string del titulo en "".
*/
void Print_Titulo(const char* titulo);

/**
 * @brief Imprime de manera estetica una opcion en el menu, con laf orma [numero] "Texto".
 * 
 * @param numero es el numero que lleva la opcion (si es -1 no imprime la casilla)
 * @param texto Es lo que dice tal opcion
 */
void Print_Opcion(int numero, const char* texto);

/**
 * @brief Imprime el prompt para ingresar una opcion. 
 * 
 * @param num 1 para ponerm ensaje y 0 para solo mostrar >
 */
void Print_Prompt(int num);

/**
 * @brief Imprime el menu inicial*/
void Print_Menu_Inicial();

/*** @brief Imprime el Menu de criterios de ordenamiento*/
void Print_Menu_Criterios_Ordenamiento();

/**
 * @brief Imprime las opciones de ordenamiento que existen
 * 
 */
void Print_Opciones_Orden();
/**
 * @brief Imprime el menu de la playlist
 * 
 */
void Print_Menu_Playlsit();

/**
 * @brief Imprime la playlist en pantalla
 * 
 * @param arr Es el arrelgo de la playlist
 * @param cantidad_de_canciones Es la cantidad e canciones en playlist
 */
void Print_Playlist(Cancion arr[], int cantidad_de_canciones);

/**
 * @brief Imprime el menu de opciones para anhadir una cancion a la playlist
 * 
 */
void Print_Menu_Anhadir_Playlist();

/**
 * @brief Imprime el menu e reproduccion e historial
 * 
 */
void Print_Menu_Reproduccion();
/**
 * @brief Imprime el arreglo Historial de canciones
 * 
 * @param historial Es el arreglo de canciones dentor del historial
 */
void Print_Historial(Cancion historial[]);

/**
 * @brief imprime el menu para quitar una cancion de la playlist
 * 
 */
void Print_Menu_Quitar_Playlist();

/**
 * @brief Imprime la lista de canciones
 * 
 * @param arr Es el repertorio de toda la musica
 * @param cantidad_de_canciones Es la cantidad de cancione sen el repertorio
 */
void Print_Lista_Canciones(Cancion arr[],int cantidad_de_canciones);

/**
 * @brief Funcion que usa un getchar par imprimir Prersione Enter para continuar
 * 
 */
void Esperar_Enter();

/**
 * @brief Funcion para animar mientras se reproducce una cancion
 * 
 * @param duracion es la duracion de es acancion on cancion_actual.duracion
 */
void Animacion_Reproduccion(int duracion);

/**
 * @brief Funcion para poner mensaje animado custom
 * 
 * @param mensaje Es el mensaje que se quiere poner (eJ: cargando..)
 */
void Print_Animacion_Custom(const char* mensaje);


#endif

