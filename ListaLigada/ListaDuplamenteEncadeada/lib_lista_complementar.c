#include <stdio.h>
#include <stdlib.h>
#include "lib_lista_complementar.h"

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
