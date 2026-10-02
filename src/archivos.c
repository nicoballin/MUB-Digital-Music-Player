/**
 * @file archivos.c
 * @brief Implementacion del manejo de archivo csv, Fisher-Yates y validaciones
 * @author Nicolas Balic
 */
#include "archivos.h"
#include "print.h"
#include "creacion.h"
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
        printf(ROJO"Error al abrir archivo para guardar catalogo\n"RESET);
        return 0;
    }

    //Titulo de cada columna
    fprintf(f, "id,titulo,artista,album,genero,duracion_seg,anho,n_reproducciones\n");

    //Contenido
    for (i = 0; i < n; i++)
    {
        if(Cancion_Es_Valida(&arr[i]))
        {
            fprintf(f, "%d,%s,%s,%s,%s,%d,%d,%d\n",
            arr[i].id,arr[i].nombre,arr[i].artista,arr[i].album,arr[i].genero,arr[i].duracion_seg,arr[i].anho,arr[i].n_reproducciones);
        }
        
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
        int consumidos = 0;

        if (cancion.nombre == NULL || cancion.artista == NULL || cancion.album == NULL || cancion.genero == NULL)
        {
            free(cancion.nombre);
            free(cancion.artista);
            free(cancion.album);
            free(cancion.genero);
            break;
        }

        int resultado = sscanf(linea, "%d,%99[^,],%99[^,],%99[^,],%49[^,],%d,%d,%d%n",
            &cancion.id,
            cancion.nombre,
            cancion.artista,
            cancion.album,
            cancion.genero,
            &cancion.duracion_seg,
            &cancion.anho,
            &cancion.n_reproducciones,
            &consumidos);

        int sin_campos_de_mas = (linea[consumidos + strspn(linea + consumidos, " \t\r\n")] == '\0');

        if (resultado == 8 && sin_campos_de_mas && Cancion_Es_Valida(&cancion))
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

const char* Seleccionar_Archivo_Catalogo()
{
    int existe_base = Archivo_Existe(ARCHIVO_CATALOGO);
    int existe_actualizado = Archivo_Existe(ARCHIVO_EXPORTADO);
    
    // Si existen ambos, dejamos que el usuario elija
    if (existe_base && existe_actualizado)
    {
        printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");
        Print_Opcion(-1, "Se detectaron 2 catalogos disponibles");
        printf("\t\t" CIAN_NEON"["RESET ROSA_CHICLE"1"RESET CIAN_NEON"] "RESET "Catalogo Base original " VERDE"('%s')\n"RESET, ARCHIVO_CATALOGO);
        printf("\t\t" CIAN_NEON"["RESET ROSA_CHICLE"2"RESET CIAN_NEON"] "RESET "Catalogo Actualizado " VERDE"('%s')\n\n"RESET, ARCHIVO_EXPORTADO);
        printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n\n");
        Print_Opcion(-1, "¿Cual catalogo desea cargar? (1 o 2): ");
        Print_Prompt(1);
        
        int opcion = Escoger_Opcion_Menu();
        if(opcion == 1) return ARCHIVO_CATALOGO;
        else return ARCHIVO_EXPORTADO;
    }
    
    if (existe_actualizado) return ARCHIVO_EXPORTADO;
    if (existe_base) return ARCHIVO_CATALOGO;
    
    return NULL; // No existe ninguno
}

int Generar_Catalogo_Inicial(Cancion arr[])
{
    printf(ROSA_CHICLE"Generando Catalogo por Primera vez...\n"RESET);
    int cantidad = Pedir_cantidad_de_Canciones();
    
    Crear_Canciones(arr, cantidad);
    Mezclar_Fisher_Yates(arr, cantidad);
    if (Guardar_Catalogo_CSV(ARCHIVO_CATALOGO, arr, cantidad))
    {
        Print_Animacion();
        printf("\t" VERDE "[Catalogo generado y guardado exitosamente en "RESET ROSA_CHICLE"'%s']\n" RESET, ARCHIVO_CATALOGO);
        sleep(2);
        return cantidad;
    }
    else
    {
        printf("\t" ROJO "[Error al guardar el catalogo en '%s']\n" RESET, ARCHIVO_CATALOGO);
        return 0;
    }
}

