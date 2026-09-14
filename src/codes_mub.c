#include "codes_mub.h"

void Print_Menu_Inicial()
{

    sleep(2);
    system("clear");
    printf("\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t MUB - Digital Player Music\n");
    printf("\t[1] Opcion uno\n");
    printf("\t[2] Opcion dos\n");
    printf("\t[3] Opcion tres\n");
    printf("\t[4] Opcion tres\n");
    printf("\t[0] Salir :(");
    printf("\n\n");
}

int Escoger_Opcion_Menu()
{
    int opcion;
    printf("Ingrese la opción que desea escoger : ");
    scanf("%d", &opcion);
    printf("\n\n");
    return opcion;
}