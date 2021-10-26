#include <stdbool.h>
#include <stdio.h>
#include "carro.h"
#define MAX 5

typedef struct Celula {
    Carro dado;
    struct Celula *prox;
} Celula;

typedef struct Pilha {
    Celula *topo;
    int n;
} Pilha;

void create_pilha (Pilha *p);

void push (Pilha *p, Carro c);

Carro pop (Pilha *p);

void print_pilha (Pilha *p);

bool is_pilha_vazia (Pilha *p);