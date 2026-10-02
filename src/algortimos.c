#include "algoritmos.h"
#include "print.h"

int Binary_Search (Cancion arr[], int low, int high, Cancion target, Tipo_Criterio criterio)
{
    if (low > high) return -1;
    
    int mid = low + (high - low)/2;
    int comparacion = Comparar_Canciones_Search(arr[mid], target, criterio);

    if(comparacion == 0) return mid; //Seencontro la cancionn

    if(comparacion > 0) 
        return Binary_Search(arr, low, mid - 1, target, criterio);
    else
        return Binary_Search(arr, mid +1, high, target, criterio);
}

int Comparar_Canciones_Search(Cancion a, Cancion target, Tipo_Criterio criterio)
{
    int diferencia = 0;
    switch (criterio)
    {
    case ID:
        diferencia = a.id - target.id;
        if(diferencia == 0) return 0;
        else if(diferencia < 0) return -1;
        else return 1;

    case ANHO:
        diferencia = a.anho - target.anho;
        if(diferencia == 0) return 0;
        else if(diferencia < 0) return -1;
        else return 1;

    case NOMBRE:
        if(strcmp(a.nombre, target.nombre) == 0) return 0;
        else if(strcmp(a.nombre, target.nombre) < 0) return -1;
        else return 1;

    case ARTISTA:
        if(strcmp(a.artista, target.artista) == 0) return 0;
        else if(strcmp(a.artista, target.artista) < 0) return -1;
        else return 1;

    case ALBUM:
        if(strcmp(a.album, target.album) == 0) return 0;
        else if(strcmp(a.album, target.album) < 0) return -1;
        else return 1;

    case GENERO:
        if(strcmp(a.genero, target.genero) == 0) return 0;
        else if(strcmp(a.genero, target.genero) < 0) return -1;
        else return 1;
    
    default:
        return 0;
    }
}

void Bubble_Sort (Cancion song[], int numero_canciones, Tipo_Criterio criterio, Orden orden)
{
    int i, j, swap;
    Cancion temp;
    
    for (i = 0; i < numero_canciones - 1; i++)
    {
        swap = 0;
        for (j = 0; j < numero_canciones - 1; j++)
        {
            if (Comparar_Canciones_Sort(song[j], song[j+1], criterio, orden) == 1)
            {
                //Intercambio
                temp = song[j];
                song[j] = song[j+1];
                song[j + 1] = temp;

                //hubo swap
                swap += 1;
            }
        }
        if (swap == 0)
            break; // se sale del ciclo si no hubo intercambio
    }

    printf("\tLista de canciones ordenada correctamente\n");
    return;
}

int Comparar_Canciones_Sort(Cancion a, Cancion b, Tipo_Criterio criterio, Orden orden)
{
    switch (criterio)
    {
    case ID:
        if(orden == ASCENDENTE)
        {
            if(a.id > b.id) return 1;
        }
        else 
        {
            if(a.id < b.id) return 1;
        }
        return 0;
    
    case NOMBRE:
        if(orden == ASCENDENTE) // de A -> Z
        {
            if( strcmp(a.nombre, b.nombre) > 0) return 1;
        }
        else // de Z -> A
        {
            if( strcmp(a.nombre, b.nombre) < 0) return 1;
        }
        return 0;
    
    case ARTISTA:
        if(orden == ASCENDENTE)// de A -> Z
        {
            if( strcmp(a.artista, b.artista) > 0) return 1;
        }
        else// de Z -> A
        {
            if( strcmp(a.artista, b.artista) < 0)
                return 1;
        }
        return 0;
    
    case ALBUM:
        if(orden == ASCENDENTE)// de A -> Z 
        {
            if( strcmp(a.album, b.album) > 0)
                return 1;
        }
        else// de Z -> A
        {
            if( strcmp(a.album, b.album) < 0)
                return 1;
        }
        return 0;
    
    case GENERO:
        if(orden == ASCENDENTE)// de A -> Z
        {
            if( strcmp(a.genero, b.genero) > 0)
                return 1;
        }
        else // de Z -> A
        {
            if( strcmp(a.genero, b.genero) < 0)
                return 1;
        }
        return 0;    

    case ANHO:
        if( orden == ASCENDENTE) // de menor a mayor
        {
            if(a.anho > b.anho)
                return 1;
        }
        else
        {
            if(a.anho < b.anho)
                return 1;
        }
        return 0;

    case DURACION:
        if(orden == ASCENDENTE)// de menor a mayor
        {
            if(a.duracion_seg > b.duracion_seg)
                return 1;
        }
        else
        {
            if(a.duracion_seg < b.duracion_seg)
                return 1;
        }
        return 0;

    case REPRODUCCIONES:
        if(orden == ASCENDENTE)// de menor a mayor
        {
            if(a.n_reproducciones > b.n_reproducciones)
                return 1;
        }
        else
        {
            if(a.n_reproducciones < b.n_reproducciones)
                return 1;
        }
        return 0;

    default:
        return 0;
    }
}

void Quick_Sort(Cancion catalogo[], int low, int high, Tipo_Criterio criterio, Orden orden)
{
    if (low < high)
    {
        //el ultimo elemento es el pivote
        Cancion pivot = catalogo[high];
        int i = (low - 1);

        // se comparr cancione ssegun el pivote, menores al pivote al a izq y mayores a la der
        for (int j = low; j <= high - 1; j++)
        {
            if (Comparar_Canciones_Sort(catalogo[j], pivot, criterio, orden) == 0)
            {
                i++;
                Cancion temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
        
        //se deja al pivote enmedio
        Cancion temp = catalogo[i + 1];
        catalogo[i + 1] = catalogo[high];
        catalogo[high] = temp;
        
        int pi = i + 1; //pos dodne queda el pivote

        //Se llama al a funcion para que ordene a la iz y ala der del pivote
        Quick_Sort(catalogo, low, pi - 1, criterio, orden);
        Quick_Sort(catalogo, pi + 1, high, criterio, orden);
    }
}

void Top_N_Canciones(Cancion catalogo[], int n, int top)
{
    if (top <= 0 || top > n) top = n;
    
    //Hago una copia para no alterar el original
    Cancion* copia = (Cancion*)malloc(n * sizeof(Cancion));
    if (copia == NULL)
    {
        printf(ROJO"Error: memoria insuficiente para el ranking.\n"RESET);
        return;
    }
    memcpy(copia, catalogo, n * sizeof(Cancion));

    // ordenar la copia por reprod de mayor a menor y uso Bubble
    Bubble_Sort(copia, n, REPRODUCCIONES, DESCENDENTE);
    Print_Animacion_Custom("Ordenando Canciones mediante Bubble Sort");
    sleep(1);
    printf(CIAN_NEON"\n\t\t\t\t=== "RESET ROSA_CHICLE"TOP %d "RESET CIAN_NEON"CANCIONES "RESET ROSA_CHICLE"MAS "RESET CIAN_NEON"ESCUCHADAS ===\n"RESET, top);
    Print_Lista_Canciones(copia, top);
    
    //libero la copia
    free(copia);
}

void Buscar_Y_Mostrar_Coincidencias(Cancion catalogo[], int cantidad_de_canciones, int pos, Cancion target, Tipo_Criterio criterio)
{
    if (pos == -1)
    {
        printf(ROJO_NEON"\t[ERROR]: "RESET);
        printf("No se encontraron coincidencias en el catalogo\n");
        return;
    }

    int encontradas = 0;
    printf(VERDE"\t[¡Coincidencia(s) encontrada(s)!]\n"RESET);
    printf("\t-------------------------------------------------------------------------------------------------------------------------\n");

    // Expandir haci ala izq desde pos
    int i = pos;
    while (i >= 0 && Comparar_Canciones_Search(catalogo[i], target, criterio) == 0)
    {
        i--;
    }
    int inicio = i + 1; // es el primer indice valido con el mismo valor

    //Buscar a la derecha desde el pos
    i = pos;
    while (i < cantidad_de_canciones && Comparar_Canciones_Search(catalogo[i], target, criterio) == 0)
    {
        i++;
    }
    int fin = i - 1; // ultimo indice que es valido y tiene el mismo valor

    //Mostrar todas las canconesnecontradas con el mismo rango
    for (int j = inicio; j <= fin; j++)
    {
        printf("\tID: %-3d | %-18s | %-14s | %-24s | %2dm %02ds | %-4d | %-8d |\n",
               catalogo[j].id, catalogo[j].nombre, catalogo[j].artista, catalogo[j].album,
               catalogo[j].duracion_seg/60, catalogo[j].duracion_seg%60, catalogo[j].anho, catalogo[j].n_reproducciones);
        encontradas++;
    }
    
    printf("\t-------------------------------------------------------------------------------------------------------------------------\n");
    printf(VERDE"\tTotal de canciones encontradas: "RESET ROSA_CHICLE"%d\n"RESET, encontradas);

}

