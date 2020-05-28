#include "menu.h"


///  esto no se hace, hay que definir un nuevo .C y un .h, pero soy vago
void titulo_main()
{
    // lo podria haber hecho mejor... que desastre
    char tope[] = {201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,'\0'};
    char piso[] = {200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188,'\0'};

    printf("%s\n", tope);
    printf("%c%s%c\n", 186,"\tTRABAJO PARACTICO 3\t",186);
    printf("%s\n", piso);
}


int main()
{
    titulo_main();
    while(menu(opcion()));
    return 0;
}



