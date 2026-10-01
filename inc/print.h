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



void Print_Titulo(const char* titulo);
void Print_Opcion(int numero, const char* texto);
void Print_Prompt();


void Print_Menu_Inicial();
void Print_Menu_Criterios_Ordenamiento();
void Print_Opciones_Orden();
void Print_Menu_Playlsit();
void Print_Playlist(Cancion arr[], int cantidad_de_canciones);
void Print_Menu_anhadir_Playlsit();
void Print_Menu_Reproduccion();
void Print_Historial(Cancion historial[]);
void Print_Menu_Quitar_Playlist();
void Print_Lista_Canciones(Cancion arr[],int cantidad_de_canciones);


#endif

