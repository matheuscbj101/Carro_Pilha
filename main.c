#include <stdio.h>
#include "pilha_flexivel.h"

int main (void) {

    Pilha estacionamento;
    create_pilha(&estacionamento);
    int operacao, placa;

    do {
     scanf ("%d %d", &operacao, &placa);

     switch (operacao)
     {
     case 1:
     {
         Carro c;
         c.placa = placa;
         c.manobras = 0;
         push (&estacionamento, c);
         printf ("\nCarro inserido\n");
         print_pilha (&estacionamento);
     }
     break;
     case 2:
     {
         Pilha paux;
         create_pilha (&paux);
         
         while(!is_pilha_vazia(&estacionamento)) {
             Carro c = pop(&estacionamento);
             if (c.placa == placa) {
                 printf ("\nCarro encontrado!\n");
                 break;
             }
            push (&paux, c);
         }

         while (!is_pilha_vazia(&paux)) {
             Carro c = pop(&paux);
             c.manobras++;
             push (&estacionamento, c);
         }

         printf ("Carro removido!\n");
         print_pilha (&estacionamento);
     }
     break;
     default:
         printf ("\nOpcao Invalida!\n");
         break;
     }
    } while (operacao != 0);

    printf ("Programa finalizado\n");
    return 0;
}