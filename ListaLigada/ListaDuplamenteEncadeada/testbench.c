/* 31/10/2019
 Arquivo que testa todas as funções do TAD Lista especificado em lib_lista.h e lib_lista_complementar.h
 Compare sua saída com o arquivo output_lista.txt
 Feito de aluno para aluno
Criador : Leonardo Lima Dionizio / UFPR 2019*/

#include <stdio.h>
#include <stdlib.h>
#include "lib_lista_complementar.h"

int testa_insercao_inicio(t_lista * l);
int testa_insercao_final(t_lista *l);
int testa_insere_ordenado(t_lista *l);
int testa_remove_inicio(t_lista *l);
int testa_remove_fim(t_lista *l);
int testa_destroi_lista(t_lista *l, t_lista *m, t_lista * o, t_lista * p);
int testa_remove_item(t_lista *l);
int testa_pertence(t_lista *l);

int main(){

	t_lista l;
	t_lista m;
	t_lista o;
	t_lista p;
	t_lista q;

	inicializa_lista(&l);
	inicializa_lista(&m);
	inicializa_lista(&o);
	inicializa_lista(&p);
	inicializa_lista(&q);
	printf("lista l é: \n");
	imprime_lista(&l);
	printf("Teste de insercao no inicio com lista l: \n");
	if (! testa_insercao_inicio(&l))
		printf("insercao no inicio falhou...\n");
	printf("lista l é: ");
	imprime_lista(&l);
	printf("Teste de insercao no fim com lista m: \n");
	if (! testa_insercao_final(&m))
		printf("insercao no fim falhou...\n");
	printf("lista m é: ");
	imprime_lista(&m);
	printf("Teste de copia de lista copiando m em p: \n");
	if (! copia_lista(&m, &p))
		printf("copia de lista falhou...\n");
	printf("lista p é: ");
	imprime_lista(&p);
	printf("Teste de insercao ordenada com lista o: \n");
	if (! testa_insere_ordenado(&o))
		printf("Insercao ordenada falhou...\n");
	printf("lista o é: ");
	imprime_lista(&o);
	printf("Testando ordenação com lista l: \n");
	if (! ordena_lista(&l))
		printf("Ordenacao falhou...");
	printf ("lista l é: ");
	imprime_lista(&l);
	printf("Testando intercalacao com lista o e p na lista q\n");
	if (! intercala_listas(&o, &p, &q))
		printf("intercalao falhou...");
	printf ("lista q é: ");
	imprime_lista(&q);
	printf("Teste de remocao no inicio com lista l: \n");
	if (! testa_remove_inicio(&l))
		printf("Remocao do inicio falhou...\n");
	printf("Teste de remocao no fim com lista m: \n");
	if (! testa_remove_fim(&m))
		printf("Remocao do fim falhou...\n");
	printf("Teste de remocao especifica com lista o: \n");
	if (! testa_remove_item(&o))
		printf("Remocao específica falhou...\n");
	printf("lista o é: ");
	imprime_lista(&o);
	printf("Teste de pertencer com lista o: \n");
	if (! testa_pertence(&o))
		printf("Pertence lista falhou...\n");
	printf("concatenando lista p na lista o\n");
	if (! concatena_listas(&o, &p))
		printf ("concatenacao falhou...\n");
	printf("lista o é: ");
	imprime_lista(&o);
	printf("Teste de destruicao das listas: \n");
	if (! testa_destroi_lista(&l, &m, &o, &q))
		printf("Destruicao falhou...\n");
	return 0;
}


int testa_insercao_inicio(t_lista * l){
	
	int i;

	for (i=0; i<=10; i+=2){
		if (! insere_inicio_lista(i, l))
			return 0;
	}
	return 1;

}

int testa_insercao_final(t_lista * l){
	
	int i;

	for (i=0; i<=10; i+=2){
		if (! insere_fim_lista(i, l))
			return 0;
	}
	return 1;

}

int testa_insere_ordenado(t_lista *l){

	int entradas[7]={4, -1, 3, 7, 11, 18, 0};

	int i;

	for (i = 0; i < 7; i++){
		if (! insere_ordenado_lista(entradas[i], l))
				return 0;
	}

	return 1;
}

int testa_remove_inicio(t_lista *l){
	
	int x;

	while (remove_inicio_lista(&x, l)){
		printf("Removeu %d\n", x);
		printf ("Lista l é: ");
		imprime_lista(l);
	}
	printf("\n");
	return (lista_vazia(l));
}
int testa_remove_fim(t_lista *l){
	
	int x;

	while (remove_fim_lista(&x, l)){
		printf("Removeu %d\n", x);
		printf ("Lista m é: ");
		imprime_lista(l);
	}
	printf("\n");
	return (lista_vazia(l));
}

int testa_destroi_lista(t_lista *l, t_lista *m, t_lista * o, t_lista * p){

	printf("Destruindo lista l...\n");
	destroi_lista(l);
	if (l->ini || l->fim || l->atual)
		return 0;
	printf("Destruindo lista m...\n");
	destroi_lista(m);
	if (m->ini || m->fim || m->atual)
		return 0;
	printf("Destruindo lista o...\n");
	destroi_lista(o);
	if (o->ini || o->fim || o->atual)
		return 0;
	printf("Destruindo lista q...\n");
	destroi_lista(p);
	if (p->ini || p->fim || p->atual)
		return 0;
	return 1;
}

int testa_remove_item(t_lista *l){

	int remocoes[3] = {11, -1, 20};
	int i;

	for (i=0; i < 3; i++){
		if (! remove_item_lista(remocoes[i], &remocoes[i], l ))
			printf ("Nao achou %d\n", remocoes[i]);
		else
			printf("Removeu %d\n", remocoes[i]);
	}
	return 1;
}

int testa_pertence(t_lista *l){
	
	int pertence[4] = {4, -1, 18, 30};
	int i;

	for(i=0; i < 4; i++){
		if (pertence_lista(pertence[i], l))
			printf("%d pertence a lista o\n", pertence[i]);
		else
			printf("%d não pertence a lista o\n", pertence[i]);
	}
	return 1;
}
