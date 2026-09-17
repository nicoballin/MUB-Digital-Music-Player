#include "algoritmos.h"
#include "codes_mub.h"
#include "creacion.h"

#include <stdio.h>

int main()
{
    srand(time(NULL));

    int cantidad_de_canciones = Pedir_cantidad_de_Canciones(); //Numero de canciones
    Cancion Canciones[cantidad_de_canciones]; //Arreglo de Canciones
    Cancion Playlist[cantidad_de_canciones]; //fila de reproduccion
    Inicializar_Playlist(Playlist, cantidad_de_canciones);
    Crear_Canciones(Canciones,cantidad_de_canciones);
    int opcion_menu, opcion_criterio, opcion_orden;
    
    int running = 1;
    
    while(running)
    {
        Print_Menu_Inicial(); //Mostramos Menu
        opcion_menu = Escoger_Opcion_Menu();
        if (opcion_menu == 0) running =0;

        switch (opcion_menu)
        {
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
                    printf("\tHaz Seleccionado: Ordenar las Canciones por ID\n");
                    break;
                case NOMBRE:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Titulo\n"); 
                    break;
                case ARTISTA:
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Artista\n"); 
                    break;
                case ALBUM: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Album\n"); 
                    break;
                case GENERO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Genero\n"); 
                    break;
                case DURACION: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Duracion\n"); 
                    break;
                case ANHO: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Anho\n"); 
                    break;
                case REPRODUCCIONES: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por Numero de Reproducciones\n"); 
                    break;
                default: 
                    printf("\tHaz Seleccionado: Ordenar las Canciones por OPCION NO ENCONTRADA\n"); 
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
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            break;

        default:
            printf("\tIngrese una opción Valida!\n");
            break;
        }
    }


    Liberar_Memoria_Canciones(Canciones, cantidad_de_canciones);
    return 0;
}