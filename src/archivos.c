/**
 * @file archivos.c
 * @brief Implementacion del manejo de archivo csv, Fisher-Yates y validaciones
 * @author Nicolas Balic
 */
#include "archivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Mezclar_Fisher_Yates(Cancion arr[], int n)
{
    int i, j;
    if (n <= 1)
        return;

    for (i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);

        Cancion temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int Guardar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int n)
{
    int i;
    FILE* f = fopen(nombre_archivo, "w");
    if (f == NULL)
    {
        printf("Error al abrir archivo para guardar catalogo\n");
        return 0;
    }

    //Titulo de cada columna
    fprintf(f, "id,titulo,artista,album,genero,duracion_seg,anho,n_reproducciones\n");

    //Contenido
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%d,%s,%s,%s,%s,%d,%d,%d\n",
            arr[i].id,arr[i].nombre,arr[i].artista,arr[i].album,arr[i].genero,arr[i].duracion_seg,arr[i].anho,arr[i].n_reproducciones);
    }

    fclose(f);
    return 1;
}

int Cargar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int max_capacidad)
{
    FILE *archivo;
    char linea[500];
    int cantidad = 0;

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
        return -1;

    if (fgets(linea, sizeof(linea), archivo) == NULL)
    {
        fclose(archivo);
        return 0; // Archivo existente pero vacio
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL && cantidad < max_capacidad)
    {
        Cancion cancion;
        cancion.nombre = malloc(100);
        cancion.artista = malloc(100);
        cancion.album = malloc(100);
        cancion.genero = malloc(50);

        if (cancion.nombre == NULL || cancion.artista == NULL || cancion.album == NULL || cancion.genero == NULL)
        {
            free(cancion.nombre);
            free(cancion.artista);
            free(cancion.album);
            free(cancion.genero);
            break;
        }

        int resultado = sscanf(linea, "%d,%99[^,],%99[^,],%99[^,],%49[^,],%d,%d,%d",
            &cancion.id,
            cancion.nombre,
            cancion.artista,
            cancion.album,
            cancion.genero,
            &cancion.duracion_seg,
            &cancion.anho,
            &cancion.n_reproducciones);

        if (resultado == 8)
        {
            arr[cantidad] = cancion;
            cantidad++;
        }
        else
        {
            free(cancion.nombre);
            free(cancion.artista);
            free(cancion.album);
            free(cancion.genero);
        }
    }

    fclose(archivo);

    return cantidad;
}

int Exportar_Catalogo_CSV(const char* nombre_archivo, Cancion arr[], int n)
{
    return Guardar_Catalogo_CSV(nombre_archivo, arr, n);
}

int Archivo_Existe(const char* nombre_archivo)
{
    FILE* f = fopen(nombre_archivo, "r");
    if (f != NULL)
    {
        fclose(f);
        return 1;
    }
    return 0;
}

int Cancion_Es_Valida(const Cancion* c)
{
    if (c == NULL) return 0;
    if (c->id <= 0) return 0;
    if (c->duracion_seg < DURACION_MIN_SEG || c->duracion_seg > DURACION_MAX_SEG) return 0;
    if (c->anho < ANHO_MINIMO || c->anho > ANHO_MAXIMO) return 0;
    if (c->n_reproducciones < 0) return 0;
    if (c->nombre == NULL || c->artista == NULL || c->album == NULL || c->genero == NULL) return 0;
    return 1;
}
