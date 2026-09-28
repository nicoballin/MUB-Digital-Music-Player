#include "creacion.h"

void Crear_Canciones(Cancion arr[],int cantidad_de_canciones) //Funcion para Crear Canciones
{
    int i, j;
    int album_encontrado;
    char* album_existentes[cantidad_de_canciones];
    char* artista_album[cantidad_de_canciones];
    int anho_album[cantidad_de_canciones];
    int cantidad_albumes = 0;
    
    for(i = 0; i < cantidad_de_canciones;i++)
    {
        arr[i].id = 1 + i;
        arr[i].duracion_seg = Generar_Duracion_Seg();
        arr[i].nombre = Generar_Titulo();

        arr[i].artista = Generar_Artista();
        arr[i].album = Generar_Album(album_existentes, cantidad_albumes);
        arr[i].genero = Generar_Genero();
        arr[i].anho = Generar_Anho_Cancion(arr[i].genero);

        //si se reutiliza un album hay que usar el msimo artista
        if(strcmp(arr[i].album, "Single") != 0)
        {
            album_encontrado = -1;

            for(j = 0; j < cantidad_albumes; j++)
            {
                if(strcmp(arr[i].album, album_existentes[j]) == 0)
                {
                    album_encontrado = j;
                    break;
                }
            }
            
            //si el album se encontro  y ya existia se utiliza su artista
            if(album_encontrado != -1)
            {
                free(arr[i].artista);
                
                arr[i].artista = (char*)malloc(20 * sizeof(char)); 
                if(arr[i].artista != NULL) 
                    sprintf(arr[i].artista, "%s", artista_album[album_encontrado]);

                arr[i].anho = anho_album[album_encontrado]; //la cancion toma el año del album
            }
            else // si es album nuevo se guarda el album + su año + artista
            {
                album_existentes[cantidad_albumes] = arr[i].album;
                
                artista_album[cantidad_albumes] = (char*)malloc(20 * sizeof(char));
                if(artista_album[cantidad_albumes] != NULL) 
                    sprintf(artista_album[cantidad_albumes], "%s", arr[i].artista);

                anho_album[cantidad_albumes] = arr[i].anho;//guardamos el año del album
                cantidad_albumes++;
            }

        }

        arr[i].n_reproducciones = Generar_N_Reproducciones();

    }
}

char* Generar_Titulo()
{
    const char* sustantivo[] = {
    "Modo", "Corrido", "Casa de", "Deseo", "Am0r", "Noche", "Fuego", "Sueno",
    "Baile", "Oda al", "Mi duo", "Ritmo", "Locura", "Guerra", "Lagrimas", "Tormenta",
    "Ciudad", "Camino", "Reino", "Sombra", "Luna", "Fiesta", "Vicio", "Aura",
    "Midnight", "Broken", "Golden", "Neon", "Stereo", "Highway", "Velvet", "Gravity",
    "Electric", "Wild", "Silent", "Lonely", "Burning", "Paper", "Crystal", "Ghost",
    "Rebel", "Dream", "Static", "Thunder", "Sunset", "Hollow", "Runaway", "Cosmic"
};

    const char* adjetivo[] = {
    "LOCO", "pro", "tierno", "inge", "TriStE", "distinto", "eterno", "salvaje",
    "perdido", "dorado", "oscuro", "secreto", "final", "mortal", "cruel", "veloz",
    "amargo", "radical", "prohibido", "callejero", "bravo", "peligroso", "genial", "2.0",
    "Heart", "Nights", "Dreams", "Fire", "Rain", "Love", "Skies", "Road",
    "Kids", "Echoes", "Lights", "Stars", "Waves", "Souls", "Blues", "Season",
    "Ghosts", "Summer", "Machine", "Paradise", "Fever", "Eyes", "Dance", "Tears"
};

    int Rand_Sustantivo = rand() % 48; //elige un adjetivo y sustantivo random
    int Rand_Adjetivo = rand() % 48;
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
    const char* sustantivo[] = {
    "El", "Rip", "Lil", "Don", "Lit", "The", "King", "Big",
    "MC", "DJ", "Sir", "Doc", "Kid", "Ice", "Mr", "Yung"};
    const char* adjetivo[] = {
    "Pepe", "Diamante", "Mencho", "TROLL", "Tierno", "DaRaptor4", "nBallinn", "WhopperT",
    "under", "Fantasma", "Coyote", "Nova", "Zorro", "Cobra", "Vandal", "Sombra",
    "Rayo", "Chacal", "Fenix", "Titan", "Loko", "Phantom", "Rocket", "Bandido",
    "Wolf", "Menta", "Cactus", "Turbo", "Flamingo", "Magnate"};

    int Rand_Sustantivo = rand() % 16;
    int Rand_Adjetivo = rand() % 30;
    char* Artista = (char*)malloc(20 * sizeof(char));
    if(Artista != NULL)
    {
        sprintf(Artista, "%s %s", sustantivo[Rand_Sustantivo], adjetivo[Rand_Adjetivo]);
    }
    return Artista;
}

char* Generar_Album(char* album_existentes[], int cantidad_albumes)
{
    int tipo_album = rand()%100;
   
    if(tipo_album < 20) // 20% de las canciones sera Single
    {
        char* Album = (char*)malloc(30 * sizeof(char)); 
        if(Album != NULL) 
            sprintf(Album, "Single"); 
        
        return Album;
    }
    if(tipo_album < 70 && cantidad_albumes > 0) // Si hay 1 album o mas el 50% de las canciones se añadira al album
    {
        int album_random = rand() % cantidad_albumes; 
        char* Album = (char*)malloc(30 * sizeof(char)); 
        
        if(Album != NULL) 
            sprintf(Album, "%s", album_existentes[album_random]); 
       
        return Album;
    }

    // 30% faltante es un album nuevo
    //misma estructura que el titulo
    const char* sustantivo[] = {
    "After", "Los", "Noche de", "Un verano sin", "Yo soy", "eL nUevo", "x100pre", "Viaje a",
    "Regreso a", "Mundo de", "Historias de", "Lo mejor de", "Pura", "Solo", "Full", "Modo",
    "Era de", "Sin fin", "Ultimo", "Gran"};

    const char* adjetivo[] = {
    "2.0", "mortem", "Fortnite", "Kirk", "Aura", "Mambo", "Sonido", "67",
    "Neon", "Vertigo", "Cenizas", "Oro", "Caos", "Gloria", "Frio", "Rebelde",
    "Eclipse", "Nostalgia", "Verano", "Cristal", "Infierno", "Paraiso", "Fantasia", "Delirio",
    "Sabor", "Gravedad", "Hielo", "Trueno", "Mareas", "Elegancia"};
    
    int Rand_sustantivo = rand() % 20;
    int Rand_adjetivo = rand() % 30;
    char* Album = (char*)malloc(30 * sizeof(char));

    if(Album != NULL)
        sprintf(Album, "%s %s", sustantivo[Rand_sustantivo], adjetivo[Rand_adjetivo]);
    

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
    if (strcmp(gnro, "Regueton") == 0 || strcmp(gnro, "Dubstep") == 0 || strcmp(gnro, "Trap") == 0)
        anho = rand() % 27 + 2000; // 2000 - 2026

    else if (strcmp(gnro, "Hip Hop") == 0)
        anho = rand() % 48 + 1979;  // 1979 - 2026

    else if (strcmp(gnro, "Rock") == 0)
        anho = rand() % 72 + 1955;  // 1960 - 2026

    else if (strcmp(gnro, "Jazz") == 0)
        anho = rand() % 87 + 1940;  // 1950 - 2026

    else if (strcmp(gnro, "Pop") == 0)
        anho = rand() % 67 + 1960;  // 1980 - 2026

    else if (strcmp(gnro, "Jazz") == 0)
        anho = rand() % 87 + 1940;  // 1940 - 2026

    else
        anho = rand() % 67 + 1950; // 1950 - 2016

    return anho;
}

int Generar_N_Reproducciones()
{
    int rep;
    rep = rand()%6701+1; //min 1 max 6700 , post multiplicar x10 : min 10 max 67000
    rep = rep*10; //para que el ultimo digito siempre sea 0.
    return rep;
}