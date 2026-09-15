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

void Crear_Canciones(Cancion arr[],int cantidad_de_canciones) //Funcion para Crear Canciones
{
    for(int i = 0; i<cantidad_de_canciones;i++)
    {
        arr[i].id = 1+i;
        arr[i].duracion_seg = Generar_Duracion_Seg();
        arr[i].anho = Generar_Anho_Cancion();
        arr[i].nombre = Generar_Titulo();
        arr[i].artista = Generar_Artista();
        arr[i].album = Generar_Album();
        arr[i].genero = Generar_Genero();
        arr[i].n_reproducciones = Generar_N_Reproducciones();
    }
}

char* Generar_Titulo()
{
    const char* sustantivo[] = {"MoDO", "corrido", "casa del", "deseo", "am0r", "Mi duo", "oda al "};
    const char* adjetivo[] = {"LOCO", "pro", "tierno", "inge", "TriStE", "distinto"};

    int Rand_Sustantivo = rand() % 7; //elige un adjetivo y sustantivo random
    int Rand_Adjetivo = rand() % 6;
    char* Titulo = (char*)malloc(20 * sizeof(char)); //pedimos 20 espacios para las letras
    if(Titulo != NULL)
    {
        sprintf(Titulo, "%s %s", sustantivo[Rand_Sustantivo], adjetivo[Rand_Adjetivo]);
    }
    return Titulo;
}

char* Generar_Artista()
{
    //misma estructura que el titulo
    const char* sustantivo[] = {"El", "Rip", "Lil", "Don", "Lit", "The"};
    const char* adjetivo[] = {"Pepe", "Diamante", "Mencho", "TROLL","Tierno", "DaRaptor4", "nBallinn","WhopperT"};

    int Rand_Sustantivo = rand() % 6;
    int Rand_Adjetivo = rand() % 8;
    char* Artista = (char*)malloc(20 * sizeof(char));
    if(Artista != NULL)
    {
        sprintf(Artista, "%s %s", sustantivo[Rand_Sustantivo], adjetivo[Rand_Adjetivo]);
    }
    return Artista;
}

char* Generar_Album()
{
    //misma estructura que el titulo
    const char* sustantivo[] = {"After", "Los", "Noche de", "Un verano sin", "Yo soy"};
    const char* adjetivo[] = {"2.0", "mortem", "Fortnite", "Kirk", "Aura", "Mambo"};

    int Rand_sustantivo = rand() % 5;
    int Rand_adjetivo = rand() % 6;
    char* Album = (char*)malloc(20 * sizeof(char));
    if(Album != NULL)
    {
        sprintf(Album, "%s %s", sustantivo[Rand_sustantivo], adjetivo[Rand_adjetivo]);
    }
    return Album;
}

char* Generar_Genero()
{
    const char* genero[] = {"Rock", "Pop", "Hip Hop", "Jazz", "Disco", "Funk", "Bachata"};

    int rand_genero = rand() % 7;
    char* Genero = (char*)malloc(20 * sizeof(char));
    if(Genero != NULL)
    {
        sprintf(Genero, "%s", genero[rand_genero]);
    }
    return Genero;
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

int Generar_N_Reproducciones()
{
    int rep;
    rep = rand()%6701+1; //min 1 max 6700 , post multiplicar x10 : min 10 max 67000
    rep = rep*10; //para que el ultimo digito siempre sea 0.
    return rep;
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
