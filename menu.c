#include "menu.h"

size_t opcion()
{
    size_t opcion = -1;
    printf("Ingrese la el numero de ejercicio a ejecutar (0 a 21): ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

size_t menu(size_t opcion)
{
    switch(opcion)
    {
        case 1:
            /// Ejericicio 1
            titulo("Ejercicio 1");
            break;


        case 0:
            printf("\n\t\t-----Chau!-----\n");
            break;
        default:
            printf("Es del 1 al 21, ingrese nuevamente.\n");
    }
    return opcion;
}


void titulo(char *s)
{
    char tope[] = {201,205,205,205,205,205,205,205,205,205,205,205,205,187,'\0'};
    char piso[] = {200,205,205,205,205,205,205,205,205,205,205,205,205,188,'\0'};

    printf("\n%s\n", tope);
    if(strlen(s) == 11)
        printf("%c%s%c%c\n", 186,s,' ',186);
    else
        printf("%c%s%c\n", 186,s,186);
    printf("%s\n", piso);
}
