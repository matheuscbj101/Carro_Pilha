#include "carro.h"
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct Pilha {
    Carro dados [MAX];
    int n;
} Pilha;

void create_pilha (Pilha *p);

void push (Pilha *p, Carro c);

Carro pop (Pilha *p);

void print_pilha (Pilha *p);

bool is_pilha_vazia (Pilha *p);