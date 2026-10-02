#include "print.h"
#include "codes_mub.h"



void Print_Titulo(const char* titulo)
{
    printf("\n");
    printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");
    printf("\t  " NEGRITA ROSA_FUCSIA "✦ " PLATA "%s" ROSA_FUCSIA " ✦" RESET "\n", titulo);
    printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");
}

void Print_Opcion(int numero, const char* texto)
{
    if(numero == -1) printf("\t" CIAN_NEON "%s" RESET "\n", texto);
    else
    printf("\t" CIAN_NEON "[" NEGRITA ROSA_CHICLE "%d" RESET CIAN_NEON "]" RESET " " PLATA "%s" RESET "\n", numero, texto);
}

void Print_Prompt(int num)
{
    if(num == 0)
        printf("\n" LILA "  ➤ " RESET);
    else
        printf("\n" LILA "  ➤ " PLATA "Ingrese la opcion que desea escoger" ROSA_CHICLE " : " RESET);
}

void Print_Menu_Inicial() //Funcion para imprimir el menu
{
    Limpiar_Pantalla();
    Print_Titulo("M U B  ·  Digital Player Music");
    printf("\n");
    //Bloque 1: Todo lo que es Catalogo
    Print_Opcion(-1, "--- CATALOGO ---");
    Print_Opcion(1, "Lista de Canciones");
    Print_Opcion(2, "Buscar una Cancion");
    Print_Opcion(3, "Ordenar Canciones");
    Print_Opcion(4, "Listar Canciones por otras categorias");
    printf("\n");

    // Bloque 2: Reproduccion y playlist
    Print_Opcion(-1, "--- REPRODUCCION Y FILA ---");
    Print_Opcion(5, "Menu de Lista de Reproduccion");
    Print_Opcion(6, "Reproducir Canciones e Historial");
    printf("\n");

    // Bloque 3: Utilidades y salida
    Print_Opcion(-1, "--- SISTEMA ---");
    Print_Opcion(7, "Exportar Catalogo Actualizado");
    Print_Opcion(0, "Salir :(");
    printf("\t" CIAN_NEON "◆" ROSA_CHICLE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" CIAN_NEON "◆" RESET "\n");

    Print_Prompt(1);
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
    Print_Prompt(1);
}

void Print_Playlist(Cancion arr[], int cantidad_de_canciones)
{
    printf("\n\t%-7s | %-18s | %-14s | %-24s | %s  | %-8s |\n", "ID", "Titulo", "Artista", "Album", "Duracion", "Reprod.");
    printf("\t----------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0 ; i < cantidad_de_canciones; i++)
    {
        if (i == 0 && arr[i].id == 0)
        {
            printf(ROJO_NEON"\t Lista de Reproduccion vacia! \n"RESET);
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
    Print_Titulo("Menu de la Lista de Reproduccion");
    Print_Opcion(1, "Ver Lista de Canciones");
    Print_Opcion(2, "Ver Lista de Reproduccion");
    Print_Opcion(3, "Anhadir una cancion a la Lista de Reproduccion");
    Print_Opcion(4, "Quitar Canciones");
    Print_Opcion(0, "Volver al Menu Principal");
    printf("\n\n");
    printf("Ingrese la opcion que desea escoger : ");
}

void Print_Opciones_Orden()
{
    printf("\n\t" LILA "¿De que manera desea ordenar las canciones?" RESET "\n");
    Print_Opcion(1, "Ascendente (Menor a Mayor / A-Z)");
    Print_Opcion(2, "Descendente (Mayor a menor / Z-A)");
    Print_Opcion(0, "Volver al menu de Opciones");
    Print_Prompt(1);
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
    Print_Prompt(1);
}

void Print_Menu_Reproduccion()
{
    Limpiar_Pantalla();
    Print_Titulo("Reproduccion e Historial");
    printf("\n");
    Print_Opcion(1, "Reproducir Cancion (primera de la fila)");
    Print_Opcion(2, "Ver Historial de Reproduccion");
    Print_Opcion(0, "Volver al Menu Principal");
    Print_Prompt(1);
}

void Print_Menu_Anhadir_Playlist()
{
    Limpiar_Pantalla();
    Print_Titulo("Anhadir Canciones a la Fila");
    printf("\n");
    Print_Opcion(1, "Ver Lista de Canciones");
    Print_Opcion(2, "Anhadir por ID");
    Print_Opcion(3, "Anhadir por Nombre/Titulo");
    Print_Opcion(4, "Anhadir por Artista");
    Print_Opcion(0, "Volver a Menu de Lista de Reproduccion");
    Print_Prompt(1);
}

void Esperar_Enter()
{
    int c;
    printf("\n\t" GRIS "Presione " ROSA_CHICLE "ENTER" GRIS " para volver..." RESET);

    while ((c = getchar()) != '\n' && c != EOF);   // limpia lo pendiente
    if (c == EOF) return;                          // entrada cerrada (Ctrl+D)

    while ((c = getchar()) != '\n' && c != EOF);   // espera ENTER
}

void Animacion_Reproduccion(int duracion)
{ 
    int ancho_barra = 40; 
    int tiempo_animacion = 10; //en seg 
    
    for(int i = 0; i<= tiempo_animacion * 10; i++)
    {
        float progreso =(float) i/(tiempo_animacion * 10);
        int posicion = progreso * ancho_barra;

        //timepo mostrando la animacion
        int seg_actual = i/10;
        
        //duracion rial de la cancion;
        int min_total = duracion/60;
        int seg_total = duracion%60;

        ///regresar al inico de la linea 
        printf("\r\t");

        //parte en reproduccion
        for(int j = 0; j < posicion; j++)
            printf(VERDE"="RESET);

        //cusor
        if(posicion < ancho_barra)
        printf(VERDE">"RESET);

        //parte pendiente
        for(int j = posicion +1; j < ancho_barra; j++)
        printf(GRIS"="RESET);

        //tiempo
        printf("%02d:%02d / %02d:%02d", seg_actual / 60, seg_actual % 60, min_total, seg_total);
        fflush(stdout);

        usleep(100000);

    }

    printf("\n"); 
}

void Print_Animacion_Custom(const char* mensaje)
{
    //Caracteres animacion
    int giros = 20;
    char simbolos[] = {'/', '-', '\\', '|'};
    
    // Gira la barrita n veces
    for (int i = 0; i < giros; i++)
    {
        // El '\r' regresa al inicio de la linea para sobrescribir el texto anterior
        printf("\r\t%s %c", mensaje, simbolos[i % 4]);
        fflush(stdout);
        
        // Pausa de 100 milisegundos para que se alcance a ver el giro
        usleep(100000); 
    }
    sleep(0.1);
    //Limpiar terminal
    printf(VERDE"\r\t¡Listo!                                            \n"RESET);
}