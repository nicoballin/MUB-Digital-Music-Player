#include "algoritmos.h"
#include "codes_mub.h"
#include <stdio.h>

#define RUNNING 1

int main()
{
    
    while(RUNNING)
    {
        Print_Menu_Inicial(); //Mostramos Menu
        int opcion_menu = Escoger_Opcion_Menu();
        if (opcion_menu == 0) return 0;

        switch (opcion_menu)
        {
        case 1:
            printf("\tEstas en la opcion 1 \n");
            printf("\tEstas en la opcion 1 \n");
            printf("\tEstas en la opcion 1 \n");
            printf("\tEstas en la opcion 1 \n");
            break;
        
        case 2:
            printf("\tEstas en la opcion 2 \n");
            printf("\tEstas en la opcion 2 \n");
            printf("\tEstas en la opcion 2 \n");
            printf("\tEstas en la opcion 2 \n");
            break;

        case 3:
            printf("\tEstas en la opcion 3 \n");
            printf("\tEstas en la opcion 3 \n");
            printf("\tEstas en la opcion 3 \n");
            printf("\tEstas en la opcion 3 \n");
            break;
        
        case 4:
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            printf("\tEstas en la opcion 4 \n");
            break;

        default:
            printf("\tIngrese una opción Valida!\n");
            break;
        }
    }

    return 0;
}