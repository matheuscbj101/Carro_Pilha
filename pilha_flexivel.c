#include "pilha_flexivel.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void create_pilha (Pilha *p) {
    p->topo = NULL;
    p->n = 0;
}

void push (Pilha *p, Carro c) {
    if (p->n == MAX) {
        printf ("O estacionamento esta cheio\n");
    } else {

        Celula *tmp = malloc (sizeof(Celula));
        tmp->dado = c;
        tmp->prox = p->topo;

        p->topo = tmp;
        p -> n++;
    }
}

Carro pop (Pilha *p) {
    if (p->n == 0) {
        printf ("O estacionamento esta vazio\n");
        Carro c = {-1, -1};
        return c; //carro invalido para retorno ("lixo")
    } else {
       Carro res = p->topo->dado;
       Celula *tmp = p->topo;
       p->topo = p->topo->prox;
       free (tmp);

       p->n--;
       return res;
    }
}

void print_pilha (Pilha *p) {
    for (int i = 0; i<p->n*8; i++) {
        printf ("_");
    }
    printf ("\n\n|");

    Carro *v = malloc(p->n*sizeof(Carro));
    int i = p->n-1;

    Celula *tmp = p->topo;
    while(tmp != NULL)  {
        v[i] = tmp->dado;
        i--;
        tmp = tmp->prox;
    }

    for (int i = 0; i<p->n; i++) {
        print_carro (v[i]);
    }
    printf (" \n|");

    for (int i = 0; i<p->n*8; i++) {
        printf ("_");
    }
    printf ("\n");
    free (v);
}

bool is_pilha_vazia (Pilha *p) {
    return p->n == 0;
}

