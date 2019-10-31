#include <stdio.h>
#include <stdlib.h>
#include "lib_lista.h"

int inicializa_lista(t_lista *l)
{
 l->ini = NULL;
 l->atual = NULL;
 l->fim = NULL;

 return 1;
}

int lista_vazia(t_lista *l)
{
 if ( ! l->tamanho )
	 return 1;
 return 0;
}

int destroi_lista(t_lista *l)
{

}

int insere_inicio_lista(int item, t_lista *l)
{
 t_nodo *new_node;

 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( ! new_nodo )
	 return 0;

 new_nodo->chave = item;
 new_nodo->prox = l->ini;
 l->ini->prev = new_nodo;
 l->ini = new_nodo;
 l->ini->prev = NULL;
 l->tamanho++;

 return 1;
}

int tamanho_lista(int *tam, t_lista *l)
{
 if ( *tam = l->tamanho )
	 return 1;
 return 0;
}

int insere_fim_lista(int item, t_lista *l)
{
 t_nodo *new_nodo;
 
 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( ! new_nodo )
	 return 0;

 if ( l->tamanho )
 {
	l->atual = l->fim->prev;
	l->fim = new_nodo;
	new_nodo->prev = l->atual;
	l->atual->prox = new_nodo;
 }
 else
	l->ini = l->fim = new_nodo;

 new_nodo->chave = item;
 new_nodo->prox = NULL;
 l->tamanho++;

 return 1;
}

int insere_ordenado_lista(int item, t_lista *l)
{
 

}

int remove_inicio_lista(int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 l->atual = l->ini;
 l->ini = l->ini->prox;

 *item = l->atual->chave;
 free(l->atual);
 l->atual = NULL;
 l->tamanho--;

 return 1;
}

int remove_fim_lista(int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;
 

 if ( l->tamanho == 1 )
	 return ( remove_inicio_lista(item, l) );


 l->atual = l->fim;
 l->fim = l->fim->prev;

 *item = l->atual->chave;
 free(l->atual);
 l->atual = NULL;
 l->tamanho--;

 return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 l->atual = l->ini;
 if ( l->atual->chave == chave )
	 return ( remove_inicio_lista(item, l) );

 while ( l->atual != l->fim )
 {
	 if ( l->atual == chave )
	 {
		*item = l->atual->chave;
		l->atual->prev->prox = l->atual->prox;
		l->atual->prox->prev = l->atual->prev;
		free(l->atual);
		l->atual = NULL;
		l->tamanho--;
		return 1;	
	 }
	 l->atual = l->atual->prox;
 }
 
 return 0;
}

int pertence_lista(int chave, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;

 l->atual = l->ini;
 while ( l->atual != l->fim )
 {
 	if ( chave == l->atual->chave )
		return 1;
	l->atual = l->atual->prox;
 } 
 
 return 0;
}

int inicializa_atual_fim(t_lista *l)
{
 if ( lista_vazia(l) )
	return 0; 
	
 l->atual = l->fim;
 
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

}

int remove_item_atual(int *item, t_lista *l)
{
 if ( lista_vazia(l) )
	 return 0;
 
 if ( l->atual != l->ini )
 	l->atual->prev->prox = l->atual->prox;
 else
	 l->ini = l->atual->prox;

 if ( l->atual != l->fim )
 	l->atual->prox->prev = l->atual->prev;
 else
	 l->fim = l->atual->prev;

 return 1;
}
