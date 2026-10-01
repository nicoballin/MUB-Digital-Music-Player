#include "print.h"
#include "codes_mub.h"


/** @brief Imprime un titulo con marco estilo Y2K. */
void Print_Titulo(const char* titulo)
{
    printf("\n");
    printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");
    printf("\t  " NEGRITA ROSA_FUCSIA "✦ " PLATA "%s" ROSA_FUCSIA " ✦" RESET "\n", titulo);
    printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");
}

/** @brief Imprime una opcion de menu con el formato [n] texto. */
void Print_Opcion(int numero, const char* texto)
{
    printf("\t" CIAN_NEON "[" NEGRITA ROSA_CHICLE "%d" RESET CIAN_NEON "]" RESET " " PLATA "%s" RESET "\n", numero, texto);
}

/** @brief Imprime el prompt para ingresar una opcion. */
void Print_Prompt()
{
    printf("\n" LILA "  ➤ " PLATA "Ingrese la opción que desea escoger" ROSA_CHICLE " : " RESET);
}


//funciones

void Print_Menu_Inicial() //Funcion para imprimir el menu
{
    Limpiar_Pantalla();
    Print_Titulo("M U B  ·  Digital Player Music");
    printf("\n");
    Print_Opcion(1, "Lista de Canciones");
    Print_Opcion(2, "Menu de Lista de Reproduccion");
    Print_Opcion(3, "Ordenar Canciones");
    Print_Opcion(4, "Reproducir Canciones");
    Print_Opcion(5, "Exportar Catalogo Actualizado");
    Print_Opcion(0, "Salir :(");
    Print_Prompt();
}

void Print_Menu_Criterios_Ordenamiento()
{
    Limpiar_Pantalla();
    Print_Titulo("Ordenar Canciones");
    printf("\n\t" LILA "¿Como desea ordenar las canciones?" RESET "\n");
    Print_Opcion(1, "Por ID");
    Print_Opcion(2, "Por Titulo");
    Print_Opcion(3, "Por Artista");
    Print_Opcion(4, "Por Album");
    Print_Opcion(5, "Por Genero");
    Print_Opcion(6, "Por Duracion");
    Print_Opcion(7, "Por Anho");
    Print_Opcion(8, "Por Numero de Reproducciones");
    Print_Opcion(0, "Volver al Menu Inicial");
    Print_Prompt();
}

void Print_Opciones_Orden()
{
    printf("\n\t" LILA "¿De que manera desea ordenar las canciones?" RESET "\n");
    Print_Opcion(1, "Ascendente (Menor a Mayor / A-Z)");
    Print_Opcion(2, "Descendente (Mayor a menor / Z-A)");
    Print_Opcion(0, "Volver al menu de Opciones");
    Print_Prompt();
}

void Print_Lista_Canciones(Cancion arr[], int cantidad_de_canciones)
{
    printf("\n\t" NEGRITA CIAN_NEON "%-7s | %-18s | %-14s | %-24s | %-10s | %s | %-4s | %-8s |" RESET "\n",
           "ID", "Titulo", "Artista", "Album", "Genero", "Duracion", "Anho", "Reprod.");
    printf("\t" ROSA_CHICLE "-------------------------------------------------------------------------------------------------------------------------" RESET "\n");
    for (int i = 0; i < cantidad_de_canciones; i++)
    {
        const char* color_fila = (i % 2 == 0) ? PLATA : LILA;
        printf("\t%sID: %-3d | %-18s | %-14s | %-24s | %-10s | %2dm %02ds | %-4d | %-8d |" RESET "\n",
               color_fila,
               arr[i].id,
               arr[i].nombre,
               arr[i].artista,
               arr[i].album,
               arr[i].genero,
               arr[i].duracion_seg / 60, arr[i].duracion_seg % 60,
               arr[i].anho,
               arr[i].n_reproducciones);
    }
    printf("\n\t" GRIS "Presione " ROSA_CHICLE "ENTER" GRIS " para volver al menu..." RESET);
    while (getchar() != '\n'); // Limpia buffer anterior
    getchar();                 // Espera ENTER del usuario
}

void Print_Menu_Quitar_Playlist()
{
    Limpiar_Pantalla();
    Print_Titulo("Quitar Canciones de la Fila");
    printf("\n");
    Print_Opcion(1, "Ver Lista de Reproduccion");
    Print_Opcion(2, "Quitar por ID");
    Print_Opcion(3, "Quitar por Posicion");
    Print_Opcion(4, "Vaciar toda la fila");
    Print_Opcion(0, "Volver al Menu de Lista de Reproduccion");
    Print_Prompt();
}

void Print_Menu_Reproduccion()
{
    Limpiar_Pantalla();
    Print_Titulo("Reproduccion e Historial");
    printf("\n");
    Print_Opcion(1, "Reproducir Cancion (primera de la fila)");
    Print_Opcion(2, "Ver Historial de Reproduccion");
    Print_Opcion(0, "Volver al Menu Principal");
    Print_Prompt();
}

void Print_Menu_anhadir_Playlsit()
{
    sleep(2);
    Limpiar_Pantalla();
    Print_Titulo("Anhadir Canciones a la Fila");
    printf("\n");
    Print_Opcion(1, "Ver Lista de Canciones");
    Print_Opcion(2, "Anhadir por ID");
    Print_Opcion(3, "Anhadir por Nombre");
    Print_Opcion(0, "Volver a Menu de Lista de Reproduccion");
    Print_Prompt();
}