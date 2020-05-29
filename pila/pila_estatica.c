#include "pila_estatica.h"



/*
                 libre┐        tipo de dato┐  ┌dato
    p->pila           │                    │  │                  MAX
          └> ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░███░███░███░███░███░███░███░███ <┘
                               │
                        p->tope┘

*/

void crear(tPila *p)
{
    p->tope = MAX;
}


int llena(const tPila *p, unsigned tamanio_dato)
{
    // se comprueba pasandole el tamaño de un dato que se le puede agregar y el tamaño donde se guardara el tipo de dato
    // p->tope es el espacio libre en la pila
    // si es 1, no hay lugar
    return p->tope < tamanio_dato + sizeof(unsigned);
}


int poner(tPila *p, void *dato, unsigned tamanio_dato)
{
    // comprobar si no esta lleno
    if(p->tope < tamanio_dato + sizeof(unsigned))
        return 0;


    // la pila se va llenando desde el final al principio
    // p->tope tiene la cantidad de lugar libre
    // entonces, se le resta el lugar que ocupara el dato a p->tope
    // y si p->tope estaba en 300 y el dato tiene un tamaño de 10, entonces p->tope valdra 290
    // en 290 se pone el dato (que obviamente ocupara hasta 300)
    p->tope-=tamanio_dato;
    memcpy(p->pila + p->tope, dato, tamanio_dato);

    // como se le puede poner cualquier dato, hay que saber que dato se guardo
    // enconces se reserva un unsigned int para poner el tipo de dato
    // para esto a p->tope se le resta 4, entonces, si estaba en 290, ahora estara en 286
    // en 286 se guara el tipo de dato que es el dato guardado de 290 a 300
    // p->tope vale 286
    p->tope-=sizeof(unsigned);
    memcpy(p->pila+p->tope, tamanio_dato, sizeof(unsigned));



    // p->pila guarda el lugar en memoria de la pila
    // p->pila + p->tope guardara el lugar en memoria donde se mete el dato y el tamaño del dato

    return 0;
}


int ver_tope(const tPila *p, void *dato, unsigned tamanio_dato)
{
    unsigned tamInfo;

    // la pila esta vacia
    if(p->tope == MAX)
        return 0;


    //se guarda el tipo de dato (o sea lo que esta ocupando el dato en la pila) en tamInfo
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));

    // se guarda en dato los bits que hay
    // desde la posicion en memoria de la pila + el ultimo lugar ocupado de la pila  + el tamaño del lugar donde se guarda el tipo de dato
    // hasta
    memcpy(&dato, p->pila + p->tope + sizeof(unsigned), minimo(tamanio_dato, tamInfo));
}
