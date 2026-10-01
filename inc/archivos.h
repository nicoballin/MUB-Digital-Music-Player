/**
 * @file archivos.h
 * @brief archivo para todo lo que es realcionado al csv y fisher yates
 */
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codes_mub.h"

#define ARCHIVO_CATALOGO "build/catalogo.csv"
#define ARCHIVO_EXPORTADO "build/catalogo_actualizado.csv"

/**
 * @brief Mezcla aleatoriamente el arreglo de canciones utilizando el algoritmo fisher yates
 * @param arr Arreglo de canciones a mezclar
 * @param n Cantidad de canciones en el arreglo
 */
void Mezclar_Fisher_Yates(Cancion arr[], int n);

/**
 * @brief Guarda el catalogo de canciones en un archivo con formato CSV.
 *        Tiene la forma: id,titulo,artista,album,genero,duracion_seg,anho,n_reproducciones
 * @param nombre_archivo Ruta del archivo CSV
 * @param arr Arreglo con las cancione
 * @param n Cantidad de canciones a almacenar
 * @return 1 en caso de exito, 0 si ocurrio un error al abrir o escribir el archivo
 */
int Guardar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int n);

/**
 * @brief Carga las canciones desde un archivo CSV validando cada fila.
 * @param nombre_archivo Ruta del archivo CSV a leer.
 * @param arr Arreglo destino donde se guardaran las canciones.
 * @param max_capacidad Cantidad maxima de canciones que caben en el arreglo.
 * @return Cantidad de canciones cargadas con exito, o -1 si el archivo no existe/no se pudo abrir.
 */
int Cargar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int max_capacidad);

/**
 * @brief Exporta el catalogo actualizado a un nuevo archivo CSV tras modificar reproducciones.
 * @param nombre_archivo Ruta del nuevo archivo CSV.
 * @param arr Arreglo de canciones actualizado.
 * @param n Cantidad de canciones.
 * @return 1 en caso de exito, 0 si fallo.
 */
int Exportar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int n);

/**
 * @brief Comprueba si un archivo existe en el sistema de archivos.
 * @param nombre_archivo Ruta del archivo.
 * @return 1 si existe y puede ser leido, 0 en caso contrario.
 */
int Archivo_Existe(const char* nombre_archivo);

/**
 * @brief Verifica si una cancion es valida antes de guardar en el archivo CSV
 * 
 * @param c Puntero constante a la estructura Cancion a evaluar
 * @return Retorna 1 si la cancion cumple con todas las caracteristitcas y 0 si ahay algun problema
 */
int Cancion_Es_Valida(const Cancion* c);

/**
 * @brief Determina que archivo CSV cargar segun su existencia y la eleccion del usuario.
 * @return La ruta del archivo a cargar o NULL si no existe ningun catalogo previo.
 */
const char* Seleccionar_Archivo_Catalogo();

/**
 * @brief Genera un catalogo aleatorio nuevo, lo mezcla con Fisher-Yates y lo guarda.
 * @return Cantidad de canciones generadas o 0 si ocurrio un error al guardar.
 */
int Generar_Catalogo_Inicial(Cancion arr[]);

#endif
