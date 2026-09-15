#include "algoritmos.h"

int Binary_Search (int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    else 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return Binary_Search (arr, low, mid - 1, x);
        else
            return Binary_Search (arr, mid + 1,high, x);
    }
}

//Ordenamiento Burbuja segun Criterio y en que orden (ascendente o descendente)
void Bubble_Sort (Cancion song[], int numero_canciones, Tipo_Criterio criterio, Orden orden)
{
    int i, j, swap;
    Cancion temp;
    
    for (i = 0; i < numero_canciones - 1; i++)
    {
        swap = 0;
        for (j = 0; j < numero_canciones - 1; j++)
        {
            if (Comparar_Canciones(song[j], song[j+1], criterio, orden) == 1)
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

//Funcion para comparar 2 canciones segun el criterio y tipo de orden, retorna 1 si se tiene que aplicar el swap.
int Comparar_Canciones(Cancion a, Cancion b, Tipo_Criterio criterio, Orden orden)
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
