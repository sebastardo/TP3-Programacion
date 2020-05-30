#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#include "../cabecera.h"

typedef struct
{
    char pila[MAX_RESULTADO];
    unsigned tope;
}tPila;

unsigned minimo(unsigned, unsigned);

void crear_pila(tPila *);
void vaciar_pila(tPila *);

int pila_llena(const tPila *, unsigned);
int pila_vacia(const tPila *);

int poner_en_pila(tPila *, void *, unsigned);
int sacar_de_pila(tPila *, void *, unsigned);

int ver_tope_de_pila(const tPila *, void *, unsigned);


#endif // PILA_ESTATICA_H_INCLUDED
