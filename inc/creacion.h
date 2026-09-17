#ifndef CREACION
#define CREACION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <codes_mub.h>

void Crear_Canciones(Cancion arr[],int cantidad_de_canciones);
int Generar_Duracion_Seg();
int Generar_Anho_Cancion(char* gnro);
int Generar_N_Reproducciones();
char* Generar_Titulo();
char* Generar_Artista();
char* Generar_Album(char* album_existentes[], int cantidad_albumes);
char* Generar_Genero();

#endif