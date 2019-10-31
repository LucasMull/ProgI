#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cria_lista(t_lista *l)
{
	l->ini = NULL;
	l->tamanho = 0;
	
	return 1;	
}

int lista_vazia(t_lista *l)
{
	if ( l->tamanho == 0 )
		return 1;
	return 0;
}

void destroi_lista(t_lista *l)
{
	t_nodo *aux1, *aux2;

	if ( ! lista_vazia(l) )
	{
		aux1 = l->ini;
		
		while ( l->tamanho > 0 )
		{
			if ( aux1->prox != NULL )
			{
				aux2 = aux1->prox;
				aux1->prox = NULL;
				free(aux1);
				aux1 = aux2;
				l->tamanho--;
			}
		}
	}
	else
		printf("Nao destruida: lista vazia\n");
}

int insere_inicio_lista(int x, t_lista *l)
{
	t_nodo *new_nodo;
	
	new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
	if ( new_nodo == NULL )
		return 0;

	new_nodo->prox = l->ini;
	new_nodo->chave = x;
	l->ini = new_nodo;
	l->tamanho++;
	return 1;
}

int insere_fim_lista(int x, t_lista *l)
{
	t_nodo *new_nodo;
	t_nodo *aux;
	int i;

	new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
	if ( new_nodo == NULL )
		return 0;
	
	aux = l->ini;
	if ( l->tamanho > 0 )
	{
		while ( aux->prox != NULL )
			aux = aux->prox;
	
		aux->prox = new_nodo;
	}
	else
	  	l->ini = new_nodo;
	
	new_nodo->chave = x;
	new_nodo->prox = NULL;
	l->tamanho++;

	return 1;
}

int insere_ordenado_lista(int x, t_lista *l)
{
	t_nodo *new_nodo;
	t_nodo *aux1, *aux2;

	if ( lista_vazia(l) )
		return ( insere_inicio_lista(x,l) );
	
	if ( l->ini->prox == NULL )
	{
		if ( l->ini->chave > x )
			return ( insere_inicio_lista(x,l));
		else
			return ( insere_fim_lista(x,l));
	}
	
	if (l->ini->chave >= x )
		return ( insere_inicio_lista(x,l));

	aux1 = l->ini->prox;
	aux2 = l->ini;
	while ( aux1 != NULL && ( x >= aux1->chave ))
	{
		aux2 = aux1;
		aux1 = aux1->prox;
	}
	
	new_nodo = (t_nodo*) malloc(sizeof(t_nodo));
	if ( new_nodo == NULL )
		return 0;
	
	new_nodo->prox = aux1;
	new_nodo->chave = x;
	aux2->prox = new_nodo;
	l->tamanho++;
	
	return 1;	
}

void imprime_lista(t_lista *l)
{
	t_nodo *aux;
	int i;
	
	if ( ! lista_vazia(l) )
	{
		aux = l->ini;
		printf("tam: %d -> ", l->tamanho);
		for ( i=0; i < l->tamanho; i++)
		{
			printf("%d ", aux->chave);
			aux = aux->prox;
		}
		printf("\n");
	}
}

int remove_primeiro_lista(int *item, t_lista *l)
{
	t_nodo *aux;
	
	if ( lista_vazia(l) )
		return 0;

	aux = l->ini;
	l->ini = l->ini->prox;
	
	*item = aux->chave;
	free(aux);
	aux = NULL;
	l->tamanho--;
	
	return 1;
}

int remove_ultimo_lista(int *item, t_lista *l)
{
	t_nodo *aux;

	if ( lista_vazia(l) )
		return 0;

	if ( l->tamanho == 1 )
		return (remove_primeiro_lista(item, l));
	
	aux = l->ini;
	while ( aux->prox->prox != NULL )
		aux = aux->prox;

	*item = aux->chave;
	free(aux->prox);
	aux->prox = NULL;
	l->tamanho--;
	return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l)
{
	t_nodo *aux1, *aux2;

	if ( lista_vazia(l) )
		return 0;
	
	aux1 = l->ini->prox;
	aux2 = l->ini;
	if ( aux2->chave == chave )
		return (remove_primeiro_lista(item, l)) ;
	
	while ( aux1->prox != NULL )
	{
		aux2 = aux1;
		aux1 = aux1->prox;
		if ( chave == aux1->chave )
		{
			aux2->prox = aux1->prox;
			*item = aux1->chave;
			free(aux1);
			aux1 = NULL;
			l->tamanho--;
			return 1;
		}
	}
	printf("Nao removido: elemento nao encontrado.\n");	
	return 0;
}

int pertence_lista(int chave, t_lista *l)
{
	t_nodo *aux;

	if ( lista_vazia(l) == 1 )
		return 0;
	
	aux = l->ini;
	while ( aux->prox != NULL )
	{
		if ( chave == aux->chave )
			return 1;
		aux = aux->prox;
	}
	return 0;
}

int concatena_listas(t_lista *l, t_lista *m)
{
	t_nodo *aux;

	if (lista_vazia(l))
	{
		l->ini = m->ini; 
		m->ini = NULL;
	}

	aux = l->ini;
	while ( aux->prox != NULL )
		aux = aux->prox;
	
	aux->prox = m->ini;
	l->tamanho += m->tamanho;
	
	cria_lista(m);
	return 1;
}

int copia_lista(t_lista *l, t_lista *m)
{
	t_nodo *aux1, *aux2;
	int i;
	
	if ( lista_vazia(l) )
		return 0;
	
	cria_lista(m);

	aux1 = l->ini;
	aux2 = m->ini;
	for ( i=0; i < l->tamanho; i++)
	{
		insere_fim_lista(aux1->chave, m);
		aux1 = aux1->prox;
	}
	return 1;
}
