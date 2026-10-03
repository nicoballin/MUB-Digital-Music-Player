#include "codes_mub.h"
#include "algoritmos.h"
#include "creacion.h"
#include "print.h"


int Pedir_cantidad_de_Canciones()
{
    
    Print_Titulo("- Creador de Canciones -");
    Print_Opcion(-1,"Ingrese el numero de canciones que desea generar: ");
    int cantidad_de_canciones = Escoger_Opcion_Menu();
    while(cantidad_de_canciones < 1 || cantidad_de_canciones > MAX_CANCIONES)
    {
        printf(ROJO"\t La cantidad de canciones no puede ser menor a 1 o Mayor a %d\n"RESET, MAX_CANCIONES);
        printf(CIAN"Ingrese nuevamente el Numero de canciones que desea generar: \n"RESET);
        cantidad_de_canciones = Escoger_Opcion_Menu();
    }
    return cantidad_de_canciones;
}

int Escoger_Opcion_Menu()
{
    int opcion = -1;
    int lectura;
    while ((lectura = scanf("%d", &opcion)) != 1)
    {
        if (lectura == EOF) exit(0);   // entrada cerrada: terminar
        printf(CIAN_NEON"\tPor favor, ingrese solo numeros: "RESET);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n\n");
    return opcion;
}

void Liberar_Memoria_Canciones(Cancion arr[], int cantidad_de_cancioens)
{
    for(int i = 0; i < cantidad_de_cancioens; i++)
    {
        free(arr[i].nombre);
        free(arr[i].artista);
        free(arr[i].album);
        free(arr[i].genero);
    }
}

void Inicializar_Playlist(Cancion arr[], int cantidad_de_canciones)
{
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        arr[i].id = 0;
        arr[i].anho = 0;
        arr[i].duracion_seg = 0;
        arr[i].n_reproducciones = 0;
        arr[i].album = "";
        arr[i].genero = "";
        arr[i].artista = "";
        arr[i].nombre = "";

    }
}

void Anhadir_Cancion_ID_Playlist(Cancion canciones[], Cancion Playlist[], int cantidad_de_canciones, int target)
{
    int indice_encontrado = -1;
    for(int i = 0; i < cantidad_de_canciones; i++)
    {
        if(target == canciones[i].id)
        {                             
            indice_encontrado = i; //si la id q ingresa el usuario coincide con la
            break;                //id de una cancion de la lista, guardamos su pos.
        }
    }
    if(indice_encontrado == -1)//si nunca guarda una pos, significa q no encontro una id valida
    {
        printf(ROJO"Ingrese una ID valida\n"RESET);
        return;
    }

    //si el id de la cancion es la misma que esta en la fila, se cancela
    for(int i = 0; i < cantidad_de_canciones; i++)
    {
        if(Playlist[i].id == canciones[indice_encontrado].id)
        {
            printf(ROJO"La cancion ya esta en la fila\n"RESET);
            return;
        }
    }

    if (Playlist[cantidad_de_canciones - 1].id != 0)
    {
        printf(ROJO"La fila esta llena\n"RESET);
        return;
    }

    // Se desplaza todo una posicion a la derecha (desde el final para no pisar datos)
    for (int i = cantidad_de_canciones - 1; i > 0; i--)
        Playlist[i] = Playlist[i - 1];

    // La cancion nueva queda al comienzo de la fila
    Playlist[0] = canciones[indice_encontrado];
    printf(VERDE"Cancion agregada correctamente\n"RESET);
}

void Aumentar_Reproduccion(Cancion Canciones[],int cantidad_de_canciones,int id_cancion)
{
    for(int i = 0 ; i<cantidad_de_canciones;i++)
    {
        if(Canciones[i].id == id_cancion)
        {
            Canciones[i].n_reproducciones++;
            return;
        }
    }
}

void Agregar_Cancion_Historial(Cancion historial[],Cancion cancion_reproducida)
{
    for (int i = TAMANHO_HISTORIAL - 1; i > 0; i--)
    {
        historial[i] = historial[i - 1]; //copia de abajo hacia arriba
    }
    historial[0] = cancion_reproducida;
}

void Quitar_Primera_Cancion_Playlist(Cancion playlist[],int cantidad_de_canciones)
{
    for (int i = 0; i < cantidad_de_canciones - 1; i++)
    {
        playlist[i] = playlist[i + 1]; 
    }
    playlist[cantidad_de_canciones - 1].id = 0;
}

void Reproducir_Cancion(Cancion canciones[],Cancion playlist[], Cancion historial[],int cantidad_de_canciones)
{
    if(playlist[0].id == 0)
    {
        printf(ROJO"\tLa fila de reproduccion esta vacia! No se puede reproducir nada\n"RESET);
        sleep(2);
        return ;
    }
    Cancion cancion_actual = playlist[0];
    cancion_actual.n_reproducciones++;
    printf(ROSA_CHICLE"\n\t Reproduciendo ahora:\n"RESET);
    printf("\t %s - %s [%s]\n", cancion_actual.nombre, cancion_actual.artista, cancion_actual.album);
    Aumentar_Reproduccion(canciones,cantidad_de_canciones,cancion_actual.id);
    Agregar_Cancion_Historial(historial,cancion_actual);
    Quitar_Primera_Cancion_Playlist(playlist,cantidad_de_canciones);

    Animacion_Reproduccion(cancion_actual.duracion_seg);

    return;
}

void Print_Historial(Cancion historial[])
{
    printf("\n\t%-7s | %-18s | %-14s | %-24s | %-8s |\n", "ID", "Titulo", "Artista", "Album", "Reprod.");
    printf("\t---------------------------------------------------------------------------------\n");
    for (int i = 0; i < TAMANHO_HISTORIAL; i++)
    {
        if (i == 0 && historial[i].id == 0)
        {
            printf(ROSA_CHICLE"\t Aun no se ha reproducido ninguna cancion! \n"RESET);
            return;
        }
        else if (historial[i].id == 0)
            continue;

        printf("\tID: %-3d | %-18s | %-14s | %-24s | %-8d |\n",
            historial[i].id,
            historial[i].nombre,
            historial[i].artista,
            historial[i].album,
            historial[i].n_reproducciones);
    }
    sleep(5);
}

void Quitar_Cancion_ID_Playlist(Cancion playlist[], int cantidad_de_canciones, int id_cancion)
{
    int posicion = -1;

    if( id_cancion <= 0 )
    {
        printf(ROJO"\tLa id debe ser un numero mayor a 0"RESET);
        return;
    }

    for(int i = 0 ; i < cantidad_de_canciones ; i++)
    {
        if(playlist[i].id == id_cancion)
        {
            posicion = i;
            break;
        }
    }

    if(posicion == -1)
    {
        printf(ROJO_NEON"\t La cancion con ID %d no esta en la playlist\n"RESET, id_cancion);
        return;
    }

    for (int i = posicion ; i < cantidad_de_canciones - 1; i++)
        playlist[i] = playlist[i+1];
    playlist[cantidad_de_canciones-1].id  = 0;

    printf(VERDE"\t Cancion con ID %d quitada de la fila\n"RESET, id_cancion);
    return;
}

int Contar_Canciones_Playlist(Cancion playlist[], int cantidad_de_canciones)
{
    int total = 0;
    for (int i = 0; i < cantidad_de_canciones; i++)
    {
        if (playlist[i].id != 0)
            total++;
    }
    return total;
}

void Quitar_Cancion_Posicion_Playlist(Cancion playlist[], int cantidad_de_canciones, int posicion)
{
    int total = Contar_Canciones_Playlist(playlist, cantidad_de_canciones);

    if (total == 0)
    {
        printf(ROSA_CHICLE  "\tLa fila de reproduccion esta vacia\n"RESET);
        return;
    }

    if (posicion < 1 || posicion > total)
    {
        printf(ROJO"\tPosicion invalida. Debe estar entre 1 y %d\n"RESET, total);
        return;
    }

    int indice = posicion - 1; 

    // Desplazar a la izquierda las canciones posteriores
    for (int i = indice; i < cantidad_de_canciones - 1; i++)
    {
        playlist[i] = playlist[i + 1];
    }
    playlist[cantidad_de_canciones - 1].id = 0;

    printf(VERDE"\tCancion en la posicion %d quitada de la fila\n"RESET, posicion);
}

void Vaciar_Playlist(Cancion playlist[], int cantidad_de_canciones)
{
    if (Contar_Canciones_Playlist(playlist, cantidad_de_canciones) == 0)
    {
        printf(ROJO_NEON"\tLa fila de reproduccion ya estaba vacia\n"RESET);
        return;
    }

    Inicializar_Playlist(playlist, cantidad_de_canciones);
    printf(VERDE"\tFila de reproduccion vaciada correctamente\n"RESET);
}

void Print_Animacion() 
{
    //Caracteres animacion
    int giros = 20;
    char simbolos[] = {'/', '-', '\\', '|'};
    
    // Gira la barrita 20 veces
    for (int i = 0; i < giros; i++)
    {
        // El '\r' regresa al inicio de la linea para sobrescribir el texto anterior
        printf(ROSA_CHICLE"\r\tCargando %c"RESET, simbolos[i % 4]);
        fflush(stdout);
        
        // Pausa de 100 milisegundos para que se alcance a ver el giro
        usleep(100000); 
    }
    sleep(0.1);
    //Limpiar terminal
    printf(VERDE"\r\t¡Listo!                         \n"RESET);
}

void Limpiar_Pantalla()
{
    printf("\033[H\033[J"RESET); // Codigo VT100/ANSI para limpiar pantalla jeje
}

void Listar_Artistas_Disponibles(Cancion arr[], int n)
{
    printf("\n\t" CIAN "=== ARTISTAS DISPONIBLES Y SU CANCION MAS ESCUCHADA ===" RESET "\n");
    int total_unicos = 0;

    for (int i = 0; i < n; i++)
    {
        int ya_mostrado = 0;
        // Comprobamos si este artista ya aparece antes
        for (int j = 0; j < i; j++)
        {
            if (strcmp(arr[i].artista, arr[j].artista) == 0)
            {
                ya_mostrado = 1;
                break;
            }
        }
        if (!ya_mostrado)
        {
            total_unicos++;
            
            // Buscamos la cancion con mas reproducciones de este artista
            Cancion mas_reproducida = arr[i];
            for (int k = 0; k < n; k++)
            {
                if (strcmp(arr[k].artista, arr[i].artista) == 0)
                {
                    if (arr[k].n_reproducciones > mas_reproducida.n_reproducciones)
                    {
                        mas_reproducida = arr[k];
                    }
                }
            }

            printf("\t[%2d] Artista: %s\n", total_unicos, arr[i].artista);
            printf("\t     -> Top: '%s' (%d reproducciones)\n", 
                   mas_reproducida.nombre, mas_reproducida.n_reproducciones);
        }
    }
    printf("\t------------------------------------------------------------\n");
    printf("\tTotal de artistas unicos: %d\n\n", total_unicos);
}

void Resumen_Canciones_Por_Genero(Cancion arr[], int n)
{
    const char* generos_conocidos[] = {"Rock", "Pop", "Hip Hop", "Jazz", "Regueton", "Funk", "Trap", "Dubstep"};
    int total_generos = 8;
    int conteos[8] = {0};

    // Estructura para guardar la cancion con mas reproducciones por cada genero conocido
    Cancion top_genero[8];
    int max_reprods[8] = {-1}; // Inicializamos con valores negativos

    for (int i = 0; i < n; i++)
    {
        for (int g = 0; g < total_generos; g++)
        {
            if (strcasecmp(arr[i].genero, generos_conocidos[g]) == 0)
            {
                conteos[g]++;
                // Actualizamos si esta cancion tiene mas reproducciones que la anterior del genero
                if (arr[i].n_reproducciones > max_reprods[g])
                {
                    max_reprods[g] = arr[i].n_reproducciones;
                    top_genero[g] = arr[i];
                }
                break;
            }
        }
    }

    printf("\n\t" AZUL "=== RESUMEN Y CANCION TOP POR GENERO ===" RESET "\n");
    for (int g = 0; g < total_generos; g++)
    {
        if (conteos[g] > 0)
        {
            printf("\t%-10s | Cantidad: %4d | Top: %s (%d repr)\n", 
                   generos_conocidos[g], conteos[g], top_genero[g].nombre, top_genero[g].n_reproducciones);
        }
        else
        {
            printf("\t%-10s | Cantidad:    0 | Sin canciones\n", generos_conocidos[g]);
        }
    }
    printf("\t--------------------------------------------------------\n");
}

void Listar_Canciones_Por_Genero(Cancion arr[], int n, const char* genero_buscado)
{
    int encontradas = 0;
    printf("\n\tCanciones del genero '%s':\n", genero_buscado);
    printf("\t-------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(arr[i].genero, genero_buscado) == 0)
        {
            printf("\tID: %-3d | %-18s | %-14s | %-24s | %2dm %02ds | %-4d | %-8d |\n",
                   arr[i].id, arr[i].nombre, arr[i].artista, arr[i].album,
                   arr[i].duracion_seg/60, arr[i].duracion_seg%60, arr[i].anho, arr[i].n_reproducciones);
            encontradas++;
        }
    }
    if (encontradas == 0)
    {
        printf("\t" ROJO "No se encontraron canciones para el genero '%s'\n" RESET, genero_buscado);
    }
    else
    {
        printf("\tTotal de canciones del genero '%s': %d\n", genero_buscado, encontradas);
    }
}

void Leer_Texto(char* buffer, int max)
{
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (fgets(buffer, max, stdin) != NULL)
    {
        //Quita el \n
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}
