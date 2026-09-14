#include "codes_mub.h"

void Print_Menu_Inicial()
{

    sleep(2);
    system("clear");
    printf("\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t MUB - Digital Player Music\n");
    printf("\t[1] Lista de Canciones\n");
    printf("\t[2] Opcion dos\n");
    printf("\t[3] Opcion tres\n");
    printf("\t[4] Opcion tres\n");
    printf("\t[0] Salir :(");
    printf("\n\n");
    printf("Ingrese la opción que desea escoger : ");
}

int Pedir_cantidad_de_Canciones()
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

int Escoger_Opcion_Menu()
{
    int opcion;
    scanf("%d", &opcion);
    printf("\n\n");
    return opcion;
}

void Crear_Canciones(cancion arr[],int cantidad_de_canciones)
{
    for(int i = 0; i<cantidad_de_canciones;i++)
    {
        arr[i].id = 1+i;
        arr[i].duracion_seg = Generar_Duracion_Seg();
        arr[i].año = Generar_Anho_Cancion();
        arr[i].nombre = Generar_Titulo();
    }
}

char* Generar_Titulo()
{
    const char* adjetivo[] = {"MODO", "corrido", "casa del"};
    const char* sustantivo[] = {"LOCO", "pro", "tierno"};

    int Rand_Adjetivo = rand() % 3; //elige un adjetivo y sustantivo random
    int Rand_Sustantivo = rand() % 3;
    char* Titulo = (char*)malloc(50 * sizeof(char)); //pedimos 50 espacios para las letras
    if(Titulo != NULL)
    {
        sprintf(Titulo, "%s %s", adjetivo[Rand_Adjetivo], sustantivo[Rand_Sustantivo]);
    }
    return Titulo;
}

int Generar_Duracion_Seg()
{
    int seg;
    seg = rand()%531 + 30; //cancion minima 30s, maxima 10minutos
    return seg;
}

int Generar_Anho_Cancion() //Esta funcion se podria mejorar, que por tipo de genero sea de cierta epoca
{                           // Para que no haya un regueton del 1950 que ni existía 
    int anho;
    anho = rand()%77 + 1950; //min 1950 max 2026
    return anho;
}

void Prinf_Lista_Canciones(cancion arr[],int cantidad_de_canciones)
{
    printf("\n\t%-7s | %-23s | %-20s | %-10s\n", "ID", "Titulo", "Duracion", "Anho");
    printf("\t--------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        printf("\tID: %-4d| %-23s |%d m %ds (%4d totales)| %d\n",
        arr[i].id,
        arr[i].nombre, 
        arr[i].duracion_seg/60, 
        arr[i].duracion_seg%60, arr[i].duracion_seg, 
        arr[i].año);
    }
    sleep(10);
}

void Liberar_Memoria_Titulos(cancion arr[], int cantidad_de_cancioens)
{
    for(int i = 0; i < cantidad_de_cancioens; i++)
    {
        free(arr[i].nombre);
    }
}