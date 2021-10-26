#include "pilha_linear.h"
#include <stdio.h>
void create_pilha (Pilha *p) {
    p->n = 0;
}

void push (Pilha *p, Carro c) {
    if (p->n == MAX) {
        printf ("O estacionamento esta cheio\n");
    } else {
        p -> dados [p -> n] = c;
        p -> n++;
    }
}

Carro pop (Pilha *p) {
    if (p->n == 0) {
        printf ("O estacionamento esta vazio\n");
        Carro c = {-1, -1};
        return c; //carro invalido para retorno ("lixo")
    } else {
        p->n--;
        return p->dados[p -> n];
    }
}

void print_pilha (Pilha *p) {
    for (int i = 0; i<p->n*8+1; i++) {
        printf ("_");
    }
    printf ("\n|\n|");

    for (int i = 0; i<p->n; i++) {
        print_carro (p->dados[i]);
    }
    printf ("\n|");

    for (int i = 0; i<p->n*8; i++) {
        printf ("_");
    }
    printf ("\n");
}

bool is_pilha_vazia (Pilha *p) {
    return p->n == 0;
}

