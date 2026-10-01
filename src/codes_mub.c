#include "codes_mub.h"
#include "algoritmos.h"
#include "creacion.h"
#include "print.h"

int Pedir_cantidad_de_Canciones() //Funcion que pide mediante scanf un numero entero de canciones a generar
{
    printf("\t\t - Creador de Canciones - \n\n");
    printf("Ingrese el numero de canciones que desea generar: \n");
    int cantidad_de_canciones = Escoger_Opcion_Menu();
    while(cantidad_de_canciones < 1 || cantidad_de_canciones > MAX_CANCIONES)
    {
        printf("\t La cantidad de canciones no puede ser menor a 1 o Mayor a %d\n", MAX_CANCIONES);
        printf("Ingrese nuevamente el Numero de canciones que desea generar: \n");
        cantidad_de_canciones = Escoger_Opcion_Menu();
    }
    return cantidad_de_canciones;
}

int Escoger_Opcion_Menu() //Funcion utilizadap ara escojer una opcion en el menu
{
    int opcion = -1;
    
    // while scanf no logre leer un numero entero
    while (scanf("%d", &opcion) != 1)
    {
        printf("\tPor favor, ingrese solo numeros: ");
        
        // limpia lo de las letras
        while (getchar() != '\n');
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

void Print_Playlist(Cancion arr[], int cantidad_de_canciones)
{
    printf("\n\t%-7s | %-18s | %-14s | %-24s | %s  | %-8s |\n", "ID", "Titulo", "Artista", "Album", "Duracion", "Reprod.");
    printf("\t----------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        if (i == 0 && arr[i].id == 0)
        {
            printf("\t Lista de Reproduccion vacia! \n");
            return;
        }
        else if(arr[i].id == 0)
            continue;
        printf("\tID: %-3d | %-18s | %-14s | %-24s | %2dm %02ds | %-8d |\n",
        arr[i].id,
        arr[i].nombre, 
        arr[i].artista,
        arr[i].album,
        arr[i].duracion_seg/60, arr[i].duracion_seg%60, 
        arr[i].n_reproducciones);
    }
    sleep(5); 
}

void Print_Menu_Playlsit()
{
    Limpiar_Pantalla();
    printf("\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t Menu de Lista de Reproduccion\n");
    printf("\t[1] Ver Lista de Canciones\n");
    printf("\t[2] Ver Lista de Reproduccion\n");
    printf("\t[3] Anhadir Canciones a la Cola\n");
    printf("\t[4] Quitar Canciones\n");
    printf("\t[0] Volver a Menu Principal ");
    printf("\n\n");
    printf("Ingrese la opción que desea escoger : ");
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
        printf("Ingrese una ID valida\n");
        return;
    }

    //si el id de la cancion es la misma que esta en la fila, se cancela
    for(int i = 0; i < cantidad_de_canciones; i++)
    {
        if(Playlist[i].id == canciones[indice_encontrado].id)
        {
            printf("La cancion ya esta en la fila\n");
            return;
        }
    }

    for (int j = 0; j < cantidad_de_canciones; j++)
    {
        if (Playlist[j].id == 0)
        {
            Playlist[j] = canciones[indice_encontrado];
            printf("Cancion agregada correctamente\n");
            return;
        }
    }
    printf("La fila esta llena\n");
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
        printf("\tLa fila de reproduccion esta vacia! No se puede reproducir nada\n");
        sleep(2);
        return;
    }
    Cancion cancion_actual = playlist[0];

    printf("\n\t Reproduciendo ahora:\n");
    printf("\t %s - %s [%s]\n", cancion_actual.nombre, cancion_actual.artista, cancion_actual.album);

    Aumentar_Reproduccion(canciones,cantidad_de_canciones,cancion_actual.id);
    Agregar_Cancion_Historial(historial,cancion_actual);
    Quitar_Primera_Cancion_Playlist(playlist,cantidad_de_canciones);

    sleep(3);
}

void Print_Historial(Cancion historial[])
{
    printf("\n\t%-7s | %-18s | %-14s | %-24s | %-8s |\n", "ID", "Titulo", "Artista", "Album", "Reprod.");
    printf("\t---------------------------------------------------------------------------------\n");
    for (int i = 0; i < TAMANHO_HISTORIAL; i++)
    {
        if (i == 0 && historial[i].id == 0)
        {
            printf("\t Aun no se ha reproducido ninguna cancion! \n");
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
        printf("\tLa id debe ser un numero mayor a 0");
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
        printf("\t La cancion con ID %d no esta en la playlist\n", id_cancion);
        return;
    }

    for (int i = posicion ; i < cantidad_de_canciones - 1; i++)
        playlist[i] = playlist[i+1];
    playlist[cantidad_de_canciones-1].id  = 0;

    printf("\t Cancion con ID %d quitada de la fila\n", id_cancion);
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
        printf("\tLa fila de reproduccion esta vacia\n");
        return;
    }

    if (posicion < 1 || posicion > total)
    {
        printf("\tPosicion invalida. Debe estar entre 1 y %d\n", total);
        return;
    }

    int indice = posicion - 1; 

    // Desplazar a la izquierda las canciones posteriores
    for (int i = indice; i < cantidad_de_canciones - 1; i++)
    {
        playlist[i] = playlist[i + 1];
    }
    playlist[cantidad_de_canciones - 1].id = 0;

    printf("\tCancion en la posicion %d quitada de la fila\n", posicion);
}


void Vaciar_Playlist(Cancion playlist[], int cantidad_de_canciones)
{
    if (Contar_Canciones_Playlist(playlist, cantidad_de_canciones) == 0)
    {
        printf("\tLa fila de reproduccion ya estaba vacia\n");
        return;
    }

    Inicializar_Playlist(playlist, cantidad_de_canciones);
    printf("\tFila de reproduccion vaciada correctamente\n");
}

void Print_Animacion() 
{
    //Caracteres animacion
    int giros = 20;
    char simbolos[] = {'/', '-', '\\', '|'};
    
    // Gira la barrita 20 veces
    for (int i = 0; i < giros; i++)
    {
        // El '\r' regresa al inicio de la línea para sobrescribir el texto anterior
        printf("\r\tCargando %c", simbolos[i % 4]);
        fflush(stdout);
        
        // Pausa de 100 milisegundos para que se alcance a ver el giro
        usleep(100000); 
    }
    sleep(0.1);
    //Limpiar terminal
    printf("\r\t¡Listo!         \n");
}

void Limpiar_Pantalla()
{
    printf("\033[H\033[J"RESET); // Codigo VT100/ANSI para limpiar pantalla jeje
}

void Listar_Artistas_Disponibles(Cancion arr[], int n)
{
    printf("\n\t" CIAN "=== ARTISTAS DISPONIBLES EN EL CATALOGO ===" RESET "\n");
    int total_unicos = 0;

    for (int i = 0; i < n; i++)
    {
        int ya_mostrado = 0;
        // Comprobamos si este artista ya aparece antes en el arreglo de canciones
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
            printf("\t[%2d] %s\n", total_unicos, arr[i].artista);
        }
    }
    printf("\t--------------------------------------------\n");
    printf("\tTotal de artistas unicos: %d\n\n", total_unicos);
}

void Resumen_Canciones_Por_Genero(Cancion arr[], int n)
{
    const char* generos_conocidos[] = {"Rock", "Pop", "Hip Hop", "Jazz", "Regueton", "Funk", "Trap", "Dubstep"};
    int total_generos = 8;
    //arreglo de contadores para cada genero, tryhard
    int conteos[8] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int g = 0; g < total_generos; g++)
        {
            if (strcasecmp(arr[i].genero, generos_conocidos[g]) == 0)
            {
                conteos[g]++;
                break;
            }
        }
    }

    printf("\n\t" AZUL "=== CANTIDAD DE CANCIONES POR GENERO ===" RESET "\n");
    for (int g = 0; g < total_generos; g++)
    {
        printf("\t%-12s: %4d canciones\n", generos_conocidos[g], conteos[g]);
    }
    printf("\t----------------------------------------\n");
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
    // Limpiar buffer para leer texto
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (fgets(buffer, max, stdin) != NULL)
    {
        //Quita el \n
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}