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

void destroi_lista(t_lista *l)
{
 int tam;
 int i, temp;

 tamanho_lista(&tam, l);
 for ( i=0; i<tam; i++ )
	remove_fim_lista(&temp, l);
 
 free(l->ini);
 free(l->atual);
 free(l->fim);
 l->ini = NULL; 
 l->atual = NULL; 
 l->fim = NULL; 
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
	return ( insere_inicio_lista(item, l) );

 inicializa_atual_inicio(l);
 if ( l->atual->chave >= item )
	 return ( insere_inicio_lista(item, l) );

 while (( l->atual != l->fim ) && ( l->atual->chave <= item ))
	incrementa_atual(l);

 if ( l->atual == l->fim )
	 return ( insere_fim_lista(item, l) );

 new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
 if ( new_nodo == NULL )
 	return 0;

 new_nodo->prox = l->atual->prev->prox;
 new_nodo->prev = l->atual->prev;
 l->atual->prev->prox = new_nodo;
 l->atual->prox->prev = new_nodo;
 
 new_nodo->chave = item;
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
 if ( ! atual )
	 return 0;

 *item = atual->atual->chave;
 return 1;
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
 
 l->tamanho--;

 return 1;
}

void imprime_lista(t_lista *l)
{
 if ( ! lista_vazia (l) )
 {
	l->atual = l->ini->prox;
	printf("tam: %d -> ", l->tamanho);
	while ( l->atual->prox != NULL )
	{
		printf("%d ", l->atual->chave);
		incrementa_atual(l);
	}
	printf("\n");
 }
}

int copia_lista(t_lista *l, t_lista *c)
{
 int item;
	
 if ( lista_vazia(l) )
	 return 0;

 inicializa_lista(c);
 inicializa_atual_inicio(l);
 inicializa_atual_inicio(c);
 while ( l->atual != l->fim )
 {
	consulta_item_atual(&item, l);
	insere_fim_lista(item, c);
	incrementa_atual(l);
 }

 return 1;
}

int concatena_listas(t_lista *l, t_lista *m)
{
 if ( lista_vazia(l) )
	 return 0;
 
 inicializa_atual_fim(l);
 inicializa_atual_inicio(m);

 l->atual->prox = m->atual;
 l->fim = m->fim;
 l->tamanho += m->tamanho;

 free(m->ini);
 free(m->fim);
 m->fim = NULL;
 m->ini = NULL;

 return 1;
}

int ordena_lista(t_lista *l)
{
 int *ordena;
 int i, chave, j;

 if ( lista_vazia(l) )
	 return 0;
 
 ordena = (int*)malloc(sizeof(int)*(l->tamanho));
 l->atual = l->ini;
 for ( i=0; i < l->tamanho; i++ )
 {
	ordena[i] = l->atual->chave;
	incrementa_atual(l);
 }
 
 for (i = 1; i < l->tamanho; i++)
 {
	 chave = ordena[i];
	 j = i-1;
	 
	 while (j >= 0 && ordena[j] > chave)
	 {
		 ordena[j+1] = ordena[j];
		 j--;
	 }
	 ordena[j+1]=chave;
 }
 
 l->atual = l->ini;
 for ( i=0; i < l->tamanho; i++ )
 {
	l->atual->chave = ordena[i];
	incrementa_atual(l);	
 }
 free(ordena);
 ordena = NULL;

 return 1;
}

int intercala_listas(t_lista *l, t_lista *m, t_lista *i)
{
 int j, tam_l, tam_m, tam_i;
  
 inicializa_lista(i);
 if ( lista_vazia(l) && lista_vazia(m) )
	 return 0;
 else if ( lista_vazia(l) )
	return copia_lista(m, i);
 else if ( lista_vazia(m) )
	return copia_lista(l, i);

 inicializa_atual_inicio(i);
 inicializa_atual_inicio(l);
 inicializa_atual_inicio(m);

 tamanho_lista(&tam_l, l);
 tamanho_lista(&tam_m, m);
 tam_i = tam_l + tam_m;
 for ( j=0; j < tam_i; j++ )
 {
	if (( j%2==0 ) && ( l->atual != l->fim))
	{
		insere_fim_lista(l->atual->chave, i);
		incrementa_atual(l);
	}
	else if ( m->atual != m->fim )
	{
		insere_fim_lista(m->atual->chave, i);
		incrementa_atual(m);
	}
 }

 return 1;
}
