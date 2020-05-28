#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include "../cabecera.h"


typedef struct
{
    char dato[TAM];
    unsigned tope;
}tPila;

void crear(tPila *);


#endif // PILA_ESTATICA_H_INCLUDED
