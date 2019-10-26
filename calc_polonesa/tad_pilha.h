#include <stdio.h>
#define MAX 100

typedef struct tad_pilha {
        int top;
        float v[MAX];
} tad_pilha ;

void inicializa_pilha(tad_pilha *p);

int pilha_vazia (tad_pilha p);

int tamanho_pilha (tad_pilha p);

int empilha (float x, tad_pilha *p);

int desempilha (float *t, tad_pilha *p);

int topo (float *t, tad_pilha p);
