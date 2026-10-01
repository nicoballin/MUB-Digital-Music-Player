/**
 * @file main.c
 * @authors Nicolas Balic (nbalic@umagallanes.cl), Tomas Minte (tminte@umagallanes.cl), Daniel Uribe (daniurib@umagallanes.cl).
 * @brief Main de nuestro Reproductor de Musica 
 * @version 1.0 Alpha
 * @date 2026-09-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "colores.h"
#include "algoritmos.h"
#include "codes_mub.h"
#include "creacion.h"
#include "archivos.h"
#include <stdio.h>

int main()
{
    srand(time(NULL));

    
    //= Pedir_cantidad_de_Canciones(); //Numero de canciones
    Cancion* Canciones = (Cancion*)malloc(MAX_CANCIONES * sizeof(Cancion)); //Arreglo de Canciones
    if (Canciones == NULL) 
    {
        fprintf(stderr, "Error: Memoria insuficiente para el catalogo.\n");
        return 1;
    }
    int cantidad_de_canciones = 0;
    
    //Primero cargar catalogo si ya existe el CSV
    if (Archivo_Existe(ARCHIVO_CATALOGO))
    {
        printf("\t[Cargando catalogo existente desde '%s' ...]\n", ARCHIVO_CATALOGO);
        Print_Animacion();
        sleep(2);
        cantidad_de_canciones = Cargar_Catalogo_CSV(ARCHIVO_CATALOGO, Canciones, MAX_CANCIONES);
        printf("Cnatidad de canciones = %d\n", cantidad_de_canciones);
        if (cantidad_de_canciones <= 0)
        {
            printf("\t[Aviso: Archivo '%s' vacio o invalido. Se procedera a generar uno nuevo]\n", ARCHIVO_CATALOGO);
        }
        else
        {
            printf("\t[Catalogo cargado con exito: %d canciones]\n", cantidad_de_canciones);
            sleep(1);
        }
    }

    //Si no existe catalogo se genera una unica vez
    if (cantidad_de_canciones <= 0)
    {
        cantidad_de_canciones = Pedir_cantidad_de_Canciones();
        Crear_Canciones(Canciones, cantidad_de_canciones);

        // Mezclar aleatoriamente con fisher-yates antes de guardar
        Mezclar_Fisher_Yates(Canciones, cantidad_de_canciones);

        // Guardar por primera vez en CSV
        if (Guardar_Catalogo_CSV(ARCHIVO_CATALOGO, Canciones, cantidad_de_canciones))
        {
            Print_Animacion();
            printf("\t[Catalogo generado y guardado exitosamente en '%s']\n", ARCHIVO_CATALOGO);
        }
        else
        {
            printf("\t[Error al guardar el catalogo en '%s']\n", ARCHIVO_CATALOGO);
        }
        sleep(2);
    }

    Cancion* Playlist = (Cancion*)malloc(cantidad_de_canciones * sizeof(Cancion)); //fila de reproduccion
    Cancion Historial[TAMANHO_HISTORIAL];
    Inicializar_Playlist(Playlist, cantidad_de_canciones);
    Inicializar_Playlist(Historial, TAMANHO_HISTORIAL);

    int opcion_menu, opcion_criterio, opcion_orden;
    int running = 1;
    
    while(running)
    {
        Print_Menu_Inicial(); //Mostramos Menu
        opcion_menu = Escoger_Opcion_Menu();
        if (opcion_menu == 0) running =0;

        switch (opcion_menu)
        {
        case 0: //salir
            printf("Ha seleccionado Salir del reproductor de musica\n");
            printf("\t[Exportando catalogo a '%s' ...]\n", ARCHIVO_CATALOGO);
            Print_Animacion();
            if (Exportar_Catalogo_CSV(ARCHIVO_EXPORTADO, Canciones, cantidad_de_canciones))
                printf("\t" VERDE "[Exito: Catalogo exportado correctamente]\n" RESET);
            
            else
                printf("\t" ROJO "[Error: No se pudo exportar el catalogo]\n" RESET);

            printf("Bye Bye...\n");
            running = 0;
            break;
        
        case 1: 
                //Mostrar lista de canciones
            Print_Lista_Canciones(Canciones,cantidad_de_canciones);
            break;

        
        case 2: //Playlist / reproduccion
            int running_playlist = 1;
            int opcion_menu_playlist;
            while (running_playlist)
            {
                Print_Menu_Playlsit();
                opcion_menu_playlist = Escoger_Opcion_Menu();
                switch (opcion_menu_playlist)
                {
                case 1:
                    Print_Lista_Canciones(Canciones,cantidad_de_canciones);
                    break;
                
                case 2:
                    Print_Playlist(Playlist,cantidad_de_canciones);
                    break;
                case 3:
                    int opcion_anhadir_playlist = 1;
                    int opcion_menu_anhadir_playlist;
                    while (opcion_anhadir_playlist)
                    {
                        Print_Menu_anhadir_Playlsit();
                        opcion_menu_anhadir_playlist = Escoger_Opcion_Menu();
                        switch (opcion_menu_anhadir_playlist)
                        {
                        case 1:
                            Print_Lista_Canciones(Canciones,cantidad_de_canciones);
                            break;
                        case 2:
                            int id_cancion;
                            printf("Ingrese la ID de la cancion a agregar : ");
                            id_cancion = Escoger_Opcion_Menu();
                            Anhadir_Cancion_ID_Playlist(Canciones, Playlist, cantidad_de_canciones, id_cancion);
                            break;
                        case 0:
                            opcion_anhadir_playlist = 0;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 4:
                    break;
                case 0:
                    running_playlist = 0;
                    break;
                default:
                    printf("Ingrese una opción Valida");
                    break;
                }
            }
            break;

        case 3:
            //Imprimir menyu de ordenamiento
            Print_Menu_Criterios_Ordenamiento();
            opcion_criterio = Escoger_Opcion_Menu() - 1;
            if(opcion_criterio < 0) break;

            //switch con cad tipo de orden
            switch (opcion_criterio)
            {
                case ID: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"ID\n"RESET);
                    break;
                case NOMBRE:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Titulo\n"RESET); 
                    break;
                case ARTISTA:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Artista\n"RESET); 
                    break;
                case ALBUM: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Album\n"RESET); 
                    break;
                case GENERO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Genero\n"RESET); 
                    break;
                case DURACION: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Duracion\n"RESET); 
                    break;
                case ANHO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Anho\n"RESET); 
                    break;
                case REPRODUCCIONES: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"Numero de Reproducciones\n"RESET); 
                    break;
                default: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO"OPCION NO ENCONTRADA\n"RESET); 
                    break;
            }

            Print_Opciones_Orden();
            opcion_orden = Escoger_Opcion_Menu() - 1;

            if(opcion_orden < 0)
                break;

            Bubble_Sort(Canciones, cantidad_de_canciones, opcion_criterio, opcion_orden);
            Print_Lista_Canciones(Canciones, cantidad_de_canciones);

            break;
        
        case 4: //HISTORIAL DE REPRODUCCIÓN
            int running_reproduccion = 1;
            int opcion_menu_reproduccion;
            while(running_reproduccion)
            {
                Print_Menu_Reproduccion();
                opcion_menu_reproduccion = Escoger_Opcion_Menu();
                switch (opcion_menu_reproduccion)
                {
                case 1:
                    Reproducir_Cancion(Canciones,Playlist,Historial,cantidad_de_canciones);
                    break;
                case 2:
                    Print_Historial(Historial);
                    break;
                case 0:
                    running_reproduccion = 0;
                    break;
                default:
                    printf("Ingrese una opción valida!");
                    break;
                }
            }
            break;
        
        case 5:
            printf("\t[Exportando catalogo a '%s' ...]\n", ARCHIVO_EXPORTADO);
            Print_Animacion();
            if (Exportar_Catalogo_CSV(ARCHIVO_EXPORTADO, Canciones, cantidad_de_canciones))
                printf("\t" VERDE "[Exito: Catalogo exportado correctamente]\n" RESET);
            
            else
                printf("\t" ROJO "[Error: No se pudo exportar el catalogo]\n" RESET);

            sleep(2);
            break;
        default:
            printf("\tIngrese una opción Valida!\n");
            break;
        }
    }
    Liberar_Memoria_Canciones(Canciones, cantidad_de_canciones);
    free(Canciones);
    free(Playlist);
    return 0;
}