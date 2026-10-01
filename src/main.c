/**
 * @file main.c
 * @authors Nicolas Balic (nbalic@umagallanes.cl), Tomas Minte (tminte@umagallanes.cl), Daniel Uribe (daniurib@umagallanes.cl).
 * @brief Main de nuestro Reproducto de Musica 
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
    const char* archivo_seleccionado = Seleccionar_Archivo_Catalogo();
    
    if(archivo_seleccionado != NULL)
    {
        printf("\t[Cargando catalogo desde '%s' ...]\n", archivo_seleccionado);
        Print_Animacion();
        cantidad_de_canciones = Cargar_Catalogo_CSV(archivo_seleccionado, Canciones, MAX_CANCIONES);
        if (cantidad_de_canciones <= 0)
        {
            printf(ROJO "\n\t[ERROR: El archivo '%s' esta vacio o danhado]\n" RESET, archivo_seleccionado);
            printf("\t¿Desea generar uno nuevo desde cero? (1: Si / 0: Salir): ");
            if (Escoger_Opcion_Menu() != 1)
            {
                free(Canciones);
                return 1; // Salir sin tocar archivos
            }
        }
        else
        {
            printf("\t" VERDE "[Catalogo cargado con exito: %d canciones]\n" RESET, cantidad_de_canciones);
            sleep(1);
        }
    }
    
    //Si no existe catalogo se genera una unica vez
    if (cantidad_de_canciones <= 0)
    {
        cantidad_de_canciones = Generar_Catalogo_Inicial(Canciones);
        if (cantidad_de_canciones <= 0)
        {
            free(Canciones);
            return 1;
        }
    }

    Cancion* Playlist = (Cancion*)malloc(cantidad_de_canciones * sizeof(Cancion)); //fila de reproduccion
    Cancion Historial[TAMANHO_HISTORIAL];
    Inicializar_Playlist(Playlist, cantidad_de_canciones);
    Inicializar_Playlist(Historial, TAMANHO_HISTORIAL);
    //Crear_Canciones(Canciones,cantidad_de_canciones); ya n se necestia aqui
    int opcion_menu, opcion_criterio, opcion_orden;
    int running = 1;
    
    while(running)
    {
        Print_Menu_Inicial(); //Mostramos Menu
        opcion_menu = Escoger_Opcion_Menu();
        if (opcion_menu == 0) running =0;

        switch (opcion_menu)
        {
        case 0: 
        {//salir
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
        }
        
        case 1://Mostrar lista de canciones
        {
            Print_Lista_Canciones(Canciones,cantidad_de_canciones);
            break;
        }

        case 2://Playlist / reproduccion
        {
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
        }

        case 3://Imprimir menyu de ordenamiento
        {
            
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

            printf("\t¿Que algoritmo desea usar para ordenar?\n");
            printf("\t[1] Bubble Sort (iterativo)\n");
            printf("\t[2] Quick Sort  (recursivo)\n");
            printf("\tOpcion: ");
            int opcion_algo = Escoger_Opcion_Menu();
            if (opcion_algo == 2)
                Quick_Sort(Canciones, 0, cantidad_de_canciones - 1, opcion_criterio, opcion_orden);
            else
                Bubble_Sort(Canciones, cantidad_de_canciones, opcion_criterio, opcion_orden);
            Print_Lista_Canciones(Canciones, cantidad_de_canciones);
            break;
        }
        
        case 4://HISTORIAL DE REPRODUCCIÓN
        {
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
        }
        
        case 5://Exportar
        {
            printf("\t[Exportando catalogo a '%s' ...]\n", ARCHIVO_EXPORTADO);
            Print_Animacion();
            if (Exportar_Catalogo_CSV(ARCHIVO_EXPORTADO, Canciones, cantidad_de_canciones))
                printf("\t" VERDE "[Exito: Catalogo exportado correctamente]\n" RESET);
            
            else
                printf("\t" ROJO "[Error: No se pudo exportar el catalogo]\n" RESET);

            sleep(2);
            break;
        }

        case 6: // Artistas y generos
        {
            printf("\n\t[1] Listar todos los artistas disponibles\n");
            printf("\t[2] Ver cantidad de canciones por cada genero\n");
            printf("\t[3] Listar canciones de un genero especifico\n");
            printf("\t[4] Top N canciones mas escuchadas\n");
            printf("\tOpcion: ");
            int op_genero = Escoger_Opcion_Menu();
            if (op_genero == 1)
            {
                Listar_Artistas_Disponibles(Canciones, cantidad_de_canciones);
            }
            else if (op_genero == 2)
            {
                Resumen_Canciones_Por_Genero(Canciones, cantidad_de_canciones);
            }
            else if (op_genero == 3)
            {
                char genero[50];
                printf("Ingrese el genero musical (ej: Rock, Pop, Jazz): ");
                Leer_Texto(genero, 50);
                Listar_Canciones_Por_Genero(Canciones, cantidad_de_canciones, genero);
            }
            else if(op_genero == 4)
            {
                printf("\tIngrese el valor de N para el ranking: ");
                int top_n = Escoger_Opcion_Menu();
                Top_N_Canciones(Canciones, cantidad_de_canciones, top_n);
            }
            break;
        }
        
        case 7: //Busqueda de Canciones
        {
            printf("\n\t" CIAN "=== BUSQUEDA DE CANCIONES ===" RESET "\n");
            break;
        }

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