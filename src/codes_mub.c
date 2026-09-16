#include "codes_mub.h"

void Print_Menu_Inicial() //Funcion para imprimir el menu
{

    sleep(2);
    system("clear");
    printf("\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t MUB - Digital Player Music\n");
    printf("\t[1] Lista de Canciones\n");
    printf("\t[2] Reproducir Canciones\n");
    printf("\t[3] Ordenar Canciones\n");
    printf("\t[4] Opcion tres\n");
    printf("\t[0] Salir :(");
    printf("\n\n");
    printf("Ingrese la opción que desea escoger : ");
}

void Print_Menu_Criterios_Ordenamiento()
{
    sleep(2);
    system("clear");
    printf("\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\tHaz Seleccionado: Ordenar Canciones\n\t¿Como desea ordenar las canciones?\n");
    printf("\t[1] Por ID\n");
    printf("\t[2] Por Titulo\n");
    printf("\t[3] Por Artista\n");
    printf("\t[4] Por Album\n");
    printf("\t[5] Por Genero\n");
    printf("\t[6] Por Duracion\n");
    printf("\t[7] Por Anho\n");
    printf("\t[8] Por Numero de Reproducciones\n");
    printf("\t[0] Volver al Menu Incial");
    printf("\n\n");
    printf("Ingrese la opción que desea escoger : ");
    return;
}

void Print_Opciones_Orden()
{
    printf("\t¿De que manera desea ordenar las canciones?\n");
    printf("\t[1] Ascendente (Menor a Mayor / A-Z)\n");
    printf("\t[2] Descendente (MAyor a menor / Z-A)\n");
    printf("\t[0] Volver al menu de Opciones.");
    printf("\n\n");
    printf("Ingrese la opción que desea escoger : ");
    
    return;
}

int Pedir_cantidad_de_Canciones() //Funcion que pide mediante scanf un numero entero de canciones a generar
{
    printf("\t\t - Creador de Canciones - \n\n");
    printf("Ingrese el numero de canciones que desea generar: \n");
    int cantidad_de_canciones = Escoger_Opcion_Menu();
    while(cantidad_de_canciones <= 0 || cantidad_de_canciones > 200)
    {
        printf("\t La cantidad de canciones no puede ser menor a 0 o Mayor a 200\n");
        printf("Ingrese nuevamente el Numero de canciones que desea generar: \n");
        cantidad_de_canciones = Escoger_Opcion_Menu();
    }
    return cantidad_de_canciones;
}

int Escoger_Opcion_Menu() //Funcion utilizadap ara escojer una opcion en el menu
{
    int opcion;
    scanf("%d", &opcion);
    printf("\n\n");
    return opcion;
}

void Print_Lista_Canciones(Cancion arr[],int cantidad_de_canciones)
{
    printf("\n\t%-7s | %-18s | %-14s | %-24s | %-10s | %s | %-4s | %-8s |\n", "ID", "Titulo", "Artista", "Album", "Genero", "Duracion", "Anho", "Reprod.");
    printf("\t-------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        printf("\tID: %-3d | %-18s | %-14s | %-24s | %-10s | %2dm %02ds | %-4d | %-8d |\n",
        arr[i].id,
        arr[i].nombre, 
        arr[i].artista,
        arr[i].album,
        arr[i].genero,
        arr[i].duracion_seg/60, arr[i].duracion_seg%60, 
        arr[i].anho,
        arr[i].n_reproducciones);
    }
    sleep(5);
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

void Inicializar_Playlist(Cancion arr[], int cantidad_de_canciones)
{
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        arr[i].id = 0;
    }
}