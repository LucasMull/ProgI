#include "tad_pilha.h"
#define MAX 100

void inicializa_pilha(tad_pilha *p){
	p->top=-1;
}

int pilha_vazia (tad_pilha p) {
	if (p.top == -1)
		return 1;
	return 0;
}

int tamanho_pilha (tad_pilha p) {
	return p.top+1;
}

int empilha (float x, tad_pilha *p){
	if ((*p).top+1 >= MAX)
		return 0;
	p->v[++p->top] = x;
		return 1;
}

int desempilha (float *t, tad_pilha *p){
	if(pilha_vazia(*p))
		return 0;
	*t = p->v[p->top--];
		return 1;
}

int topo (float *t, tad_pilha p){
	if(pilha_vazia(p))
		return 0;
	*t = p.v[p.top];
		return 1;
}
