#include <stdio.h>
#include <stdlib.h>
#include "lib_lista.h"

int inicializa_lista(t_lista *l)
{
 t_nodo *first, *last;
 first = (t_nodo*) malloc(sizeof(t_nodo));
 last = (t_nodo*) malloc(sizeof(t_nodo));
 if ( first == NULL || last == NULL )
 {
	 free(first);
	 return 0;
 }

 l->ini = first;
 first->prox = last;
 first->prev = NULL;
 l->fim = last;
 l->atual = NULL;
 last->prox = NULL;
 last->prev = first;
 
 l->tamanho = 0;

 return 1;
}

int lista_vazia(t_lista *l)
{
 if ( ! l->tamanho )
	 return 1;
 return 0;
}

void destroi_lista(t_lista *l){
	t_nodo *aux;

	if(l->tamanho > 0){
		l->atual = l->ini->prox;
		while(l->atual->prox != NULL){
			aux = l->atual->prox;
			aux->prev->prev = NULL;
			aux->prev->prox = NULL;
			free(l->atual);
			l->atual = aux;
		}
		aux = NULL;
	}

	l->ini->prox = NULL;
	l->fim->prev = NULL;
	free(l->fim);
	free(l->ini);
	l->ini = NULL;
	l->atual = NULL;
	l->fim = NULL;
	l->tamanho = 0;
}

int insere_inicio_lista(int item, t_lista *l)
{
 t_nodo *new_nodo;

 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( new_nodo == NULL )
	 return 0;

 new_nodo->chave = item;
 new_nodo->prox = l->ini->prox;
 new_nodo->prev = l->ini;
 new_nodo->prox->prev = new_nodo;
 l->ini->prox = new_nodo;
 l->tamanho++;

 return 1;
}

int tamanho_lista(int *tam, t_lista *l)
{
 if ( (*tam = l->tamanho) )
	 return 1;
 return 0;
}

int insere_fim_lista(int item, t_lista *l)
{
 t_nodo *new_nodo;
 
 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( new_nodo == NULL )
	 return 0;

 new_nodo->prox = l->fim;
 new_nodo->prev = l->fim->prev;
 l->fim->prev->prox = new_nodo;
 l->fim->prev = new_nodo;

 new_nodo->chave = item;
 l->tamanho++;

 return 1;
}

int insere_ordenado_lista(int item, t_lista *l)
{
 t_nodo *new_nodo;
 
 if ( lista_vazia(l) )
	return (insere_inicio_lista(item, l));
 
 l->fim->chave = item; /*sentinela*/
 inicializa_atual_inicio(l);
 while ( l->atual->chave < item )
	incrementa_atual(l);

 if ( l->atual == l->fim )
	 return ( insere_fim_lista(item, l) );

 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( new_nodo == NULL )
 	return 0;

 new_nodo->chave = item;
 new_nodo->prox = l->atual;
 new_nodo->prev = l->atual->prev;
 new_nodo->prev->prox = new_nodo;
 new_nodo->prox->prev = new_nodo;
 
 l->tamanho++;

 return 1;
}

int remove_inicio_lista(int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 inicializa_atual_inicio(l);
 *item = l->atual->chave;
 l->ini->prox = l->atual->prox;

 free(l->atual->prev);
 l->atual->prev = NULL;
 l->tamanho--;

 return 1;
}

int remove_fim_lista(int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 inicializa_atual_fim(l);
 *item = l->atual->chave;
 l->fim->prev = l->atual->prev;

 free(l->atual->prox);
 l->atual->prox = NULL;
 l->tamanho--;

 return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 inicializa_atual_inicio(l);
 if ( l->atual->chave == chave )
	 return ( remove_inicio_lista(item, l) );

 while ( l->atual != l->fim )
 {
	 if ( l->atual->chave == chave )
	 {
		*item = l->atual->chave;
		l->atual->prev->prox = l->atual->prox;
		l->atual->prox->prev = l->atual->prev;
		
		free(l->atual);
		l->atual = NULL;

		l->tamanho--;
		return 1;	
	 }
	 incrementa_atual(l);
 }
 
 return 0;
}

int pertence_lista(int chave, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 inicializa_atual_inicio(l);
 while ( l->atual != l->fim )
 {
 	if ( chave == l->atual->chave )
		return 1;

 	incrementa_atual(l);
 } 
 
 return 0;
}

int inicializa_atual_fim(t_lista *l)
{
 if ( lista_vazia(l) )
	return 0; 
	
 l->atual = l->fim->prev;
 
 return 1;
}

int inicializa_atual_inicio(t_lista *l)
{
 if ( lista_vazia(l) )
	return 0; 
	
 l->atual = l->ini->prox;
 
 return 1;
}

void incrementa_atual(t_lista *l)
{
 if ( ( l->atual != l->fim ) &&  ( l->atual ) )
 	l->atual = l->atual->prox;
 else
	 l->atual = NULL;
}

void decrementa_atual(t_lista *l)
{
 if ( ( l->atual != l->ini ) && ( l->atual ) )
	 l->atual = l->atual->prev;
 else
	 l->atual = NULL;
}

int consulta_item_atual(int *item, t_lista *atual)
{
 if ( atual->atual == NULL )
	 return 0;

 *item = atual->atual->chave;
 return 1;
}

int remove_item_atual(int *item, t_lista *l)
{
 if ( lista_vazia(l) || l->atual == NULL )
	 return 0;
 
 l->atual->prev->prox = l->atual->prox;
 l->atual->prox->prev = l->atual->prev;

 free(l->atual);
 l->atual = NULL;
 l->tamanho--;

 return 1;
}
