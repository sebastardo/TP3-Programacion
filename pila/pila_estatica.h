#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include "../cabecera.h"


typedef struct
{
    char dato[TAM];
    unsigned tope;
}tPila;

// auxiliar para seguridad, no es parte de la pila
unsigned minimo(unsigned, unsigned);

// primitivas
void crear(tPila *);
void vaciar(tPila *);

int llena(const tPila *, unsigned);
int vacia(const tPila *);

int poner(tPila *, void *, unsigned);
int sacar(tPila *, void *, unsigned);

int ver_tope(const tPila *, void *, unsigned);

#endif // PILA_ESTATICA_H_INCLUDED
