#include "pila_estatica.h"



/*
                 libre┐           tipo de dato┐      ┌dato
    p->pila           │                       │      │             MAX
          └> ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░████░████░████░████░████░████░████ <┘
                               │
                        p->tope┘

*/

///auxiliar
unsigned minimo(unsigned tamanio_dato, unsigned tamInfo)
{
    // esta funcion se la considera una proteccion
    // usa el mas pequeño entre tamanio_dato y tamInfo
    // Sin en la pila estuviese guardado un dato 5 bytes y se pasa tamanio_dato = 6, romperia
    // si se le paso el dato, que se joda por pasar mal el dato, pero la pila da lo que tiene
    // no le veo sentido igual porque no se modifica nada en la funcion ver_tope, pero no molesta

    return (tamanio_dato<tamInfo?tamanio_dato:tamInfo);
}

void crear_pila(tPila *p)
{
    p->tope = MAX_RESULTADO;
}


void vaciar_pila(tPila *p)
{
    p->tope = MAX_RESULTADO;
}


int pila_llena(const tPila *p, unsigned tipo_dato)
{
    // se comprueba pasandole el tamaño de un dato que se le puede agregar y el tamaño donde se guardara el tipo de dato
    // p->tope es el espacio libre en la pila
    // si es 1, no hay lugar
    return p->tope < tipo_dato+sizeof(unsigned);
}

int pila_vacia(const tPila *p)
{
    // si tope es igual a MAX, es porque no tiene nada
    return p->tope == MAX_RESULTADO;
}


int poner_en_pila(tPila *p, void *dato, unsigned tipo_dato)
{
    // comprobar si no esta lleno
    if(p->tope < tipo_dato + sizeof(unsigned))
        return 0;


    // la pila se va llenando desde el final al principio
    // p->tope tiene la cantidad de lugar libre
    // entonces, se le resta el lugar que ocupara el dato a p->tope
    // y si p->tope estaba en 300 y el dato tiene un tamaño de 10, entonces p->tope valdra 290
    // en 290 se pone el dato (que obviamente ocupara hasta 300)
    p->tope -= tipo_dato;
    memcpy(p->pila+p->tope, dato, tipo_dato);


    // como se le puede poner cualquier dato, hay que saber que dato se guardo
    // enconces se reserva un unsigned int para poner el tipo de dato
    // para esto a p->tope se le resta 4, entonces, si estaba en 290, ahora estara en 286
    // en 286 se guara el tipo de dato que es el dato guardado de 290 a 300
    // p->tope vale 286
    p->tope-=sizeof(unsigned);
    memcpy(p->pila + p->tope, &tipo_dato, sizeof(unsigned));

    // p->pila guarda el lugar en memoria de la pila
    // p->pila + p->tope guardara el lugar en memoria donde se mete el dato y el tamaño del dato

    return 1;
}




int sacar_de_pila(tPila *p, void *dato, unsigned tamanio_dato)
{
    unsigned tamInfo;

   //comprobar que no este vacio
    if(p->tope == MAX_RESULTADO)
        return 0;

    // guardar el tamaño del dato
    memcpy(&tamInfo, p->pila+p->tope, sizeof(unsigned));

    // mover el puntero hasta donde empieza el dato en la pila
    p->tope+=sizeof(unsigned);

    // copiar en dato lo que hay en memoria desde la posicion de memoria que hay en p->pila sumada a la "posicion" en memoria de p->tope
    // minimo es metodo de seguridad para no romper los datos en pila que no se deberian tocar
    memcpy(dato, p->pila+p->tope, minimo(tamInfo, tamanio_dato));

    // se posiona p->tope donde termina el dato que sacamos, asi queda libre esa parte
    p->tope += tamInfo;

    return 1;
}


int ver_tope_de_pila(const tPila *p, void *dato, unsigned tamanio_dato)
{
    unsigned tamInfo;
   // la pila esta vacia
    if(p->tope == MAX_RESULTADO)
        return 0;

    //se guarda el tipo de dato (o sea lo que esta ocupando el dato en la pila) en tamInfo
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));

    // se guarda en dato los bits que hay
    // desde la posicion en memoria de la pila + el ultimo lugar ocupado de la pila  + el tamaño del lugar donde se guarda el tipo de dato
    // hasta
    memcpy(&dato, p->pila + p->tope + sizeof(unsigned), minimo(tamanio_dato, tamInfo));

    return 1;
}
