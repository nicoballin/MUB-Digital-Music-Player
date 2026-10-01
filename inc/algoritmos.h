/**
 * @file algoritmos.h
 * @authors Nicolas Balic (nbalic@umagallanes.cl), Daniel Uribe (daniurib@umagallanes.cl).
 * @brief Archivo Header para definir los algoritmos de busqueda y ordenamiento que utilizamos
 */
#ifndef ALGORITMO
#define ALGORITMO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "codes_mub.h"

/**
 * @brief Realiza una busqueda binaria recursiva en el arreglo de canciones.
 * 
 * @param arr Arreglo de canciones donde se realizara la busqueda.
 * @param low Indice mas bajo del arreglo (normalmente 0).
 * @param high Indice mas alto del arreglo (cantidad de canciones - 1).
 * @param target Objeto Cancion que contiene el valor objetivo a buscar.
 * @param criterio Criterio de busqueda (ej: ID, Nombre, Artista, etc.).
 * @return Retorna el indice exacto de la cancion si es encontrada, o -1 si no existe.
 */
int Binary_Search(Cancion arr[], int low, int high, Cancion target, Tipo_Criterio criterio);

/**
 * @brief Funcion auxiliar para comparar una cancion del arreglo con el objetivo en las busquedas.
 * 
 * @param a Cancion actual del arreglo que se esta evaluando.
 * @param target Elemento o valor que se esta buscando.
 * @param criterio Criterio de busqueda aplicado.
 * @return Retorna 0 si son iguales, -1 si es menor o 1 si es mayor.
 */
int Comparar_Canciones_Search(Cancion a, Cancion target, Tipo_Criterio criterio);

/**
 * @brief Algoritmo de ordenamiento iterativo (Bubble Sort).
 * 
 * @param catalogo Arreglo de canciones a ordenar.
 * @param numero_canciones Cantidad total de canciones en el catalogo.
 * @param criterio Criterio bajo el cual se ordenaran las canciones.
 * @param orden Tipo de orden (ASCENDENTE o DESCENDENTE).
 */
void Bubble_Sort(Cancion catalogo[], int numero_canciones, Tipo_Criterio criterio, Orden orden);

/**
 * @brief Compara dos canciones para determinar su precedencia en los ordenamientos.
 * 
 * @param a Primera cancion a comparar.
 * @param b Segunda cancion a comparar.
 * @param criterio Criterio de ordenamiento (ID, Titulo, Artista, etc.).
 * @param orden Tipo de orden (ASCENDENTE o DESCENDENTE).
 * @return Retorna 1 si se debe realizar un swap y 0 si no es necesario.
 */
int Comparar_Canciones_Sort(Cancion a, Cancion b, Tipo_Criterio criterio, Orden orden);

/**
 * @brief Algoritmo de ordenamiento recursivo Quick Sort.
 * 
 * @param catalogo Arreglo de canciones a ordenar.
 * @param low Indice inferior del arreglo.
 * @param high Indice superior del arreglo.
 * @param criterio Criterio de ordenamiento a utilizar.
 * @param orden Tipo de orden (ASCENDENTE o DESCENDENTE).
 */
void Quick_Sort(Cancion catalogo[], int low, int high, Tipo_Criterio criterio, Orden orden);


#endif