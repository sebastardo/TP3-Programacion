#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include "../cabecera.h"


typedef struct
{
    char dato[TAM];
    unsigned tope;
}tPila;

void crear(tPila *);
int poner(tPila *, void *, unsigned);

#endif // PILA_ESTATICA_H_INCLUDED
