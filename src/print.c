#include "print.h"

// ---------- Helpers de estilo Y2K ----------

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
