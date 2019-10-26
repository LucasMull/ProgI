#include <stdio.h>
#include "tad_pilha.h"
#define MAX 100

int main() {
    tad_pilha p; 
    int i,x,t;
    
    inicializa_pilha(&p);
    printf("tamanho inicial da pilha eh: %d\n",tamanho_pilha(p));

    for (i=0; i<=MAX; i++)
        if (! empilha(i,&p)) {
            printf("%d nao inserido: pilha cheia\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }
        else {
            printf("%d empilhado\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }

    for (i=0; i<=MAX; i++) {
        x = topo(&t,p);
        if (! x)
            printf("pilha vazia, topo nao existe\n");
        else
            printf("topo eh: %d\n",t);

        x = desempilha(&t,&p);
        if (! x)
            printf("nao desempilhou: pilha vazia\n");
        else
            printf("%d desempilhado\n",t);
    }
    
    return 0;
}
