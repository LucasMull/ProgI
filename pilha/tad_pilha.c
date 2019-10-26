#include <stdio.h>
#define MAX 5

/* aqui vao as declaracoes iniciais e os codigos das funcoes */
/* inicio das suas modificacoes nesta parte                  */
typedef struct tad_pilha {
        int top;
        int v[MAX];
} tad_pilha ;

/* fim das suas modificacoes desta parte                     */
void inicializa_pilha(tad_pilha *p){
	p -> top = -1;
}

int pilha_vazia (tad_pilha p) {
	if (p.top == -1)
		return 1;
	return 0;
}

int tamanho_pilha (tad_pilha p) {
	return p.top+1;
}

int empilha (int x, tad_pilha *p){
	if ((*p).top+1 >= MAX)
		return 0;
	p -> v[++p -> top] = x;
		return 1;
}

int desempilha (int *t, tad_pilha *p){
	if(pilha_vazia(*p))
		return 0;
	*t = p -> v[p -> top--];
		return 1;
}

int topo (int *t, tad_pilha p){
	if(pilha_vazia(p))
		return 0;
	*t = p.v[p.top];
		return 1;
}
/* O codigo abaixo so pode ser modificado para resolver o    */
/* problema da passagem de endereços como parâmetros!        */
/* Deixe o restante do programa inalterado!!!                */

int main() {
    tad_pilha p; 
    int i,x,t;
    
    inicializa_pilha(&p);
    printf("tamanho inicial da pilha eh: %d\n",tamanho_pilha(p));

    for (i = 0; i <= MAX; i++)
        if (! empilha(i,&p)) {
            printf("%d nao inserido: pilha cheia\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }
        else {
            printf("%d empilhado\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }

    for (i = 0; i <= MAX; i++) {
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
