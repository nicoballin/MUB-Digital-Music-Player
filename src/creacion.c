#include "creacion.h"

void Crear_Canciones(Cancion arr[],int cantidad_de_canciones) //Funcion para Crear Canciones
{
    for(int i = 0; i<cantidad_de_canciones;i++)
    {
        arr[i].id = 1+i;
        arr[i].duracion_seg = Generar_Duracion_Seg();
        arr[i].nombre = Generar_Titulo();
        arr[i].artista = Generar_Artista();
        arr[i].album = Generar_Album();
        arr[i].genero = Generar_Genero();
        arr[i].n_reproducciones = Generar_N_Reproducciones();
        arr[i].anho = Generar_Anho_Cancion(arr[i].genero);
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
    char* Album = (char*)malloc(30 * sizeof(char));
    if(Album != NULL)
    {
        sprintf(Album, "%s %s", sustantivo[Rand_sustantivo], adjetivo[Rand_adjetivo]);
    }
    return Album;
}

char* Generar_Genero()
{
    const char* genero[] = {"Rock", "Pop", "Hip Hop", "Jazz", "Regueton", "Funk", "Trap", "Dubstep"};

    int rand_genero = rand() % 8;
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

int Generar_Anho_Cancion(char* gnro) //Esta funcion se podria mejorar, que por tipo de genero sea de cierta epoca
{                           // Para que no haya un regueton del 1950 que ni existía 
    int anho;
    if(gnro == 'Regueton')
        anho = rand()%27 + 2000; //min 2000 max 2026
    else if(gnro == 'Dubstep')
        anho = rand()%27 + 2000; //min 2000 max 2026
    else if(gnro == 'Rock')
        anho = rand()%50 + 1960; //min 1960 max 2009 
    else 
        anho = rand()%67 + 1950; 

    return anho;
}

int Generar_N_Reproducciones()
{
    int rep;
    rep = rand()%6701+1; //min 1 max 6700 , post multiplicar x10 : min 10 max 67000
    rep = rep*10; //para que el ultimo digito siempre sea 0.
    return rep;
}