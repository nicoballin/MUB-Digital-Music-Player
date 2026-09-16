/**
 * @file algoritmoss.h
 * @brief Archivo Header para definir los algoritms que utilizaremos
*/
#ifndef ALGORITMO
#define ALGORITMO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <codes_mub.h>

int Binary_Search (Cancion arr[], int low, int high, Cancion target, Tipo_Criterio criterio); //arreglo, 0, numero maximo del arreglo-1, numero a buscar
int Comparar_Canciones_Search(Cancion a, Cancion target, Tipo_Criterio criterio);
void Bubble_Sort (Cancion catalogo[], int numero_canciones, Tipo_Criterio criterio, Orden orden);
int Comparar_Canciones_Sort(Cancion a, Cancion b, Tipo_Criterio criterio, Orden orden);

#endif