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

#include "print.h"
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
        printf(ROSA_CHICLE"\t[Cargando catalogo desde "RESET VERDE"'%s' ..."RESET VERDE"]\n"RESET, archivo_seleccionado);
        Print_Animacion();
        cantidad_de_canciones = Cargar_Catalogo_CSV(archivo_seleccionado, Canciones, MAX_CANCIONES);
        if (cantidad_de_canciones <= 0)
        {
            printf(ROJO "\n\t[ERROR: El archivo '%s' esta vacio o danhado]\n" RESET, archivo_seleccionado);
            Print_Opcion(-1, "¿Desea generar uno nuevo desde cero? (1: Si / 0: Salir): ");
            Print_Prompt(1);
            if (Escoger_Opcion_Menu() != 1)
            {
                free(Canciones);
                return 1; // Salir sin tocar archivos
            }
        }
        else
        {
            printf("\t" VERDE "[Catalogo cargado con exito: "RESET ROSA_CHICLE"%d canciones]\n" RESET, cantidad_de_canciones);
            sleep(3);
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
        case 0: //salir
        {
            printf("Ha seleccionado " ROSA_CHICLE"Salir "RESET "del reproductor de musica\n");
            printf(CIAN_NEON"\t[Exportando catalogo a " VERDE"'%s'"RESET CIAN_NEON"]\n"RESET, ARCHIVO_EXPORTADO);
            Print_Animacion();
            if (Exportar_Catalogo_CSV(ARCHIVO_EXPORTADO, Canciones, cantidad_de_canciones))
                printf("\t" VERDE "[Exito: Catalogo exportado correctamente]\n" RESET);
            
            else
                printf("\t" ROJO "[Error: No se pudo exportar el catalogo]\n" RESET);
            
            printf(CIAN_NEON"Bye Bye...\n"RESET);
            running = 0;
            break;
        }
        
        case 1://Mostrar lista de canciones
        {
            Print_Lista_Canciones(Canciones,cantidad_de_canciones);
            Esperar_Enter();
            break;
        }
        
        case 2: //Busqueda de Canciones
        {
            Print_Titulo("=== BUSQUEDA DE CANCIONES ===");
            Print_Opcion(1, "Buscar por ID");
            Print_Opcion(2, "Buscar por Nombre / Titulo");
            Print_Opcion(3, "Buscar por Artista");
            Print_Opcion(0, "Salir");
            Print_Prompt(1);
            int op_busqueda = Escoger_Opcion_Menu();

            while(op_busqueda > 3)
            {
                Print_Opcion(-1, "Ingrese una Opcion valida!");
                Print_Prompt(1);
                op_busqueda = Escoger_Opcion_Menu();
            }

            if(op_busqueda <= 0) break;

        
            if(op_busqueda == 1)
            {
                Print_Opcion(-1, "Ingrese el " ROSA_CHICLE"ID "RESET "a buscar: ");
                Print_Prompt(1);
                int id_buscado = Escoger_Opcion_Menu();
                
                Cancion target;
                target.id = id_buscado;

                Quick_Sort(Canciones, 0, cantidad_de_canciones - 1, ID, ASCENDENTE);
                Print_Animacion_Custom("Ordenando Arreglo");
                sleep(1);
                
                int pos = Binary_Search(Canciones, 0, cantidad_de_canciones -1, target, ID);
                Print_Animacion_Custom("Buscando la " CIAN_NEON"ID "RESET "Ingresada");
                sleep(1);
                if(pos != -1) //se encontro
                {
                    printf(VERDE"\t[¡Encontrada!]: "RESET);
                    printf(ROSA_CHICLE"Posicion %d -> %s - %s\n"RESET, pos, Canciones[pos].nombre, Canciones[pos].artista);
                }
                else
                {
                    printf(ROJO_NEON"\t[ERROR]: "RESET);
                    printf(ROSA_CHICLE"La cancion con ID "ROSA_CHICLE"%d "RESET"no existe en el catalogo\n"RESET, id_buscado);
                }
            }

            else if(op_busqueda == 2 || op_busqueda == 3)
            {
                char texto[100];
                if(op_busqueda == 2) Print_Opcion(-1, "Ingrese el " ROSA_CHICLE"TITULO/NOMBRE DE LA CANCION "RESET "a buscar: ");
                else Print_Opcion(-1, "Ingrese el " ROSA_CHICLE"ARTISTA "RESET "a buscar: ");
                
                Print_Prompt(0);
                Leer_Texto(texto, 100);

                Cancion target;
                Tipo_Criterio criterio;


                //se ordena el arreglo y se asigna el nombre o artista a la cancion objetivo (target)
                if(op_busqueda == 2)
                {
                    target.nombre = texto;
                    criterio = NOMBRE;
                    
                }
                else
                {
                    target.artista = texto;
                    criterio = ARTISTA;
                }
                Quick_Sort(Canciones, 0, cantidad_de_canciones - 1, criterio, ASCENDENTE);
                Print_Animacion_Custom("Ordenando Canciones mediante Quick Sort");
                sleep(1);

                //Busqueda Binaria
                int pos = Binary_Search(Canciones, 0, cantidad_de_canciones - 1, target, criterio);
                Print_Animacion_Custom("Buscando de manera Binaria");
                sleep(1);

                Buscar_Y_Mostrar_Coincidencias(Canciones, cantidad_de_canciones, pos, target, criterio);

            }
            Esperar_Enter();

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
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"ID\n"RESET);
                    break;
                case NOMBRE:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Titulo\n"RESET); 
                    break;
                case ARTISTA:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Artista\n"RESET); 
                    break;
                case ALBUM: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Album\n"RESET); 
                    break;
                case GENERO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Genero\n"RESET); 
                    break;
                case DURACION: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Duracion\n"RESET); 
                    break;
                case ANHO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Anho\n"RESET); 
                    break;
                case REPRODUCCIONES: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROSA_CHICLE"Numero de Reproducciones\n"RESET); 
                    break;
                default: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por "ROJO_NEON"OPCION NO ENCONTRADA\n"RESET); 
                    break;
            }

            Print_Opciones_Orden();
            opcion_orden = Escoger_Opcion_Menu() - 1;

            if(opcion_orden < 0)
                break;

            Print_Opcion(-1, "¿Que algoritmo desea usar para ordenar?");
            Print_Opcion(1, "Bubble Sort (iterativo)");
            Print_Opcion(2, "Quick Sort  (recursivo)");
            Print_Opcion(0, "Salir");
            Print_Prompt(1);
            int opcion_algo = Escoger_Opcion_Menu();
            while(opcion_algo > 2)
            {
                Print_Opcion(-1, "Ingrese una Opcion valida!");
                Print_Prompt(1);
                opcion_algo = Escoger_Opcion_Menu();
            }

            if(opcion_algo == 0) break;

            if (opcion_algo == 2)
            {
                sleep(1);
                Quick_Sort(Canciones, 0, cantidad_de_canciones - 1, opcion_criterio, opcion_orden);
                Print_Animacion_Custom("Ordenando Canciones con Quick Sort");
            }
            else
            {
                sleep(3);
                Bubble_Sort(Canciones, cantidad_de_canciones, opcion_criterio, opcion_orden);
                Print_Animacion_Custom("Ordenando Canciones con Bubble Sort");
            }
            Limpiar_Pantalla();
            Print_Lista_Canciones(Canciones, cantidad_de_canciones);
            Esperar_Enter();
            break;
        }

        case 4: // Artistas y generos
        {
            Print_Titulo("Menu para Listar Canciones");
            Print_Opcion(1, "Listar todos los artistas disponibles");
            Print_Opcion(2, "Ver cantidad de canciones por cada genero");
            Print_Opcion(3, "Listar canciones de un genero especifico");
            Print_Opcion(4, "Top N canciones mas escuchadas");
            Print_Opcion(0, "Salir");
            Print_Prompt(1);
            int op_genero = Escoger_Opcion_Menu();

            while(op_genero > 4)
            {
                Print_Opcion(-1, "Ingrese una Opcion valida!");
                Print_Prompt(1);
                op_genero = Escoger_Opcion_Menu();
            }

            if(op_genero == 0) break;

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
                Print_Opcion(-1, "Ingrese el genero musical (ej: Rock, Pop, Jazz)");
                Print_Prompt(0);
                Leer_Texto(genero, 50);
                Listar_Canciones_Por_Genero(Canciones, cantidad_de_canciones, genero);
            }
            else if(op_genero == 4)
            {
                printf("\tIngrese el valor de N para el ranking: ");
                int top_n = Escoger_Opcion_Menu();
                Top_N_Canciones(Canciones, cantidad_de_canciones, top_n);
                
            }

            Esperar_Enter();

            break;
        }
             
        case 5://Playlist / reproduccion
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
                {
                    Print_Lista_Canciones(Canciones,cantidad_de_canciones);
                    Esperar_Enter();
                    break;
                }
                    
                case 2://Imprimir playlist
                {
                    Print_Playlist(Playlist,cantidad_de_canciones);
                    break;
                }
                
                case 3: // anhadir cancooens apla palylist
                {
                    int opcion_anhadir_playlist = 1;
                    int opcion_menu_anhadir_playlist;
                    while (opcion_anhadir_playlist)
                    {
                        Print_Menu_Anhadir_Playlist();
                        opcion_menu_anhadir_playlist = Escoger_Opcion_Menu();
                        switch (opcion_menu_anhadir_playlist)
                        {
                        case 1:
                        {
                            Print_Lista_Canciones(Canciones,cantidad_de_canciones);
                            Esperar_Enter();
                            break;
                        }
                        case 2:
                        {
                            int id_cancion;
                            printf("Ingrese la ID de la cancion a agregar : ");
                            id_cancion = Escoger_Opcion_Menu();
                            Anhadir_Cancion_ID_Playlist(Canciones, Playlist, cantidad_de_canciones, id_cancion);
                            Esperar_Enter();
                            break;
                        }
                        case 3:
                        case 4:
                        {
                            char texto[100];
                            if(opcion_menu_anhadir_playlist == 3) Print_Opcion(-1, "Ingrese el " ROSA_CHICLE"TITULO/NOMBRE DE LA CANCION "RESET "a buscar: ");
                            else Print_Opcion(-1, "Ingrese el " ROSA_CHICLE"ARTISTA "RESET "a buscar: ");
                            
                            Print_Prompt(0);
                            Leer_Texto(texto, 100);

                            Cancion target;
                            Tipo_Criterio criterio;


                            //se ordena el arreglo y se asigna el nombre o artista a la cancion objetivo (target)
                            if(opcion_menu_anhadir_playlist == 3)
                            {
                                target.nombre = texto;
                                criterio = NOMBRE;
                                
                            }
                            else
                            {
                                target.artista = texto;
                                criterio = ARTISTA;
                            }
                            Quick_Sort(Canciones, 0, cantidad_de_canciones - 1, criterio, ASCENDENTE);
                            Print_Animacion_Custom("Ordenando Canciones mediante Quick Sort");
                            sleep(1);

                            //Busqueda Binaria
                            int pos = Binary_Search(Canciones, 0, cantidad_de_canciones - 1, target, criterio);
                            Print_Animacion_Custom("Buscando de manera Binaria");
                            sleep(1);

                            Buscar_Y_Mostrar_Coincidencias(Canciones, cantidad_de_canciones, pos, target, criterio);
                            if(pos != -1)
                            {
                                int id_cancion;
                                printf("Ingrese la ID de la cancion a agregar : ");
                                id_cancion = Escoger_Opcion_Menu();
                                Anhadir_Cancion_ID_Playlist(Canciones, Playlist, cantidad_de_canciones, id_cancion);
                            }
                            Esperar_Enter();
                            break;
                        }
                        case 0:
                            opcion_anhadir_playlist = 0;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }

                case 4: //QUITAR CANCIONES DE LA PLAYLISTTT
                {
                    int running_quitar = 1;
                    int opcion_quitar;
                    while(running_quitar)
                    {
                        Print_Menu_Quitar_Playlist();
                        opcion_quitar = Escoger_Opcion_Menu();
                        switch (opcion_quitar)
                        {
                        case 1:
                            Print_Playlist(Playlist,cantidad_de_canciones);
                            break;
                        case 2:
                            int id_quitar ;
                            printf("Ingrese la ID de la cancion a quitar : ");
                            id_quitar = Escoger_Opcion_Menu();
                            Quitar_Cancion_ID_Playlist(Playlist,cantidad_de_canciones,id_quitar);
                            sleep(1);

                            break;
                        case 3:
                            int posicion_quitar;
                            printf("Ingrese la posicion de la cancion que desea quitar : ");
                            posicion_quitar = Escoger_Opcion_Menu();
                            Quitar_Cancion_Posicion_Playlist(Playlist,cantidad_de_canciones,posicion_quitar);
                            sleep(1);
                            break;
                        case 4:
                            Vaciar_Playlist(Playlist,cantidad_de_canciones);
                            sleep(2);
                            break;
                        case 0:
                            
                            running_quitar = 0;
                            break;

                        default:
                            printf("Ingrese una opcion valida! \n");
                            sleep(2);
                            break;
                        }
                    }
                    break;
                }

                case 0:
                {
                    running_playlist = 0;
                    break;
                }

                default:
                {
                    printf("Ingrese una opcion Valida");
                    break;
                }

                }
            }
            break;
        }
 
        case 6://Reproducir Canciones
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
                {
                    Reproducir_Cancion(Canciones,Playlist,Historial,cantidad_de_canciones);
                    break;
                }
                case 2:
                {
                    Print_Historial(Historial);
                    break;
                }
                case 0:
                {
                    running_reproduccion = 0;
                    break;
                }
                default:
                {
                    printf("Ingrese una opcion valida!");
                    break;
                }

                }
            }
            break;
        }      
        
        case 7://Exportar
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

        default:
        {
            printf(ROJO"\tIngrese una opcion Valida!\n"RESET);
            break;
        }
        }
    }
    Liberar_Memoria_Canciones(Canciones, cantidad_de_canciones);
    free(Canciones);
    free(Playlist);
    return 0;
}