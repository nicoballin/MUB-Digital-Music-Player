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
#include <codes_mub.h>


void Crear_Canciones(Cancion arr[],int cantidad_de_canciones);
/**
 * @brief 
 * 
 * @return int , Numero generado en segundos
 */
int Generar_Duracion_Seg();
int Generar_Anho_Cancion(char* gnro);
int Generar_N_Reproducciones();
char* Generar_Titulo();
char* Generar_Artista();
char* Generar_Album(char* album_existentes[], int cantidad_albumes);
char* Generar_Genero();

#endif