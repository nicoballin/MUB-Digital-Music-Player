/**
 * @file creacion.h
 * @author Nicolas Balic (nbalic@umagallanes.cl), Tomas Minte (tminte@umagallanes.cl), Daniel Uribe (daniurib@umagallanes.cl).
 * @brief Header para declarar las funciones que tienen relacion con la creacion y generacion de parametros
 * para las canciones.
 * @version 0.1
 * @date 2026-09-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef CREACION
#define CREACION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "codes_mub.h"

/**
 * @brief Funcion para crear canciones
 * 
 * @param arr Es el arrgwelo de canciones
 * @param cantidad_de_canciones Es la cantida de canciones del arreglo
 */
void Crear_Canciones(Cancion arr[],int cantidad_de_canciones);

/**
 * @brief Funcion para generar la duracin de una cancion en segun dos y de manera aleatoria
 * 
 * @return Numero generado en segundos (int)
 */
int Generar_Duracion_Seg();

/**
 * @brief Funcion poara generar de manea aleatoria el anho dela cancion segun su genero
 * 
 * @param gnro Es el genero de la cancion
 * @return Anho generado de manera aleatoria (int)
 */
int Generar_Anho_Cancion(char* gnro);

/**
 * @brief Fuuncion que gneera de manera alaeatoria el numero de reproducciones de una cancion
 * 
 * @return Numero de reproducciones entre 10 a 67000
 */
int Generar_N_Reproducciones();

/**
 * @brief Funcion qe generqaa eltitulo dentro de las opciones disponibes
 * 
 * @return Retorna el titulo generado para la cancion
 */
char* Generar_Titulo();

/**
 * @brief Funcion que genera de manera aleatoria la artista segun las opciones disponibles
 * 
 * @return El nombre generado dela artista
 */
char* Generar_Artista();

/**
 * @brief Funcion que genera de manera aleatoria el nombre el album segun las opciones disponibles 
 * 
 * @param album_existentes es una rregl ode albumes con nombres ya existentes
 * @param cantidad_albumes Son la cantidad de albumes ya creados
 * @return Devuelve el nombre del album para una cancion especifica
 */
char* Generar_Album(char* album_existentes[], int cantidad_albumes);

/**
 * @brief Funcion que genera de manera aleatoriael genero de una cancion dentro de las opciones disponibles
 * 
 * @return Retorna el genero seleccionado para dicha cancion
 */
char* Generar_Genero();

#endif