#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printList(int *v, int tam);
void troca(int *a, int *b);

/* ALGORITMOS DIVIDE-AND-CONQUER */
int partition(int *v, int ini, int fim)
{
  int pivot; /*pivô é o último elemento*/
  int i, j; /*índice do menor elemento*/
  
  pivot=v[fim];
  i = ini-1;
  for ( j=ini; j<=fim-1; j++ )
	  if ( v[j] < pivot )
	  {
		i++; /*o i é a 'barreira', ele identifica os elementos menores que o pivo*/
		troca( &v[j], &v[i] );
	  }
  troca( &v[i+1], &v[fim] ); /*coloca o pivô no se lugar depois da barreira, agora os elementos antes dele são menores e depois maiores*/
  return (i+1);
}
void quickSort(int *v, int ini, int fim)
{
  int partIndex;

  if (ini<fim)
  {
	  partIndex = partition(v, ini, fim); /*o partition centraliza o pivô (q neste caso é o último elemento) para q os elementos menores fiquem à esquerda e os maiores à esquerda */
	  quickSort(v, ini, partIndex-1); /*ch.recursiva com todos os elementos menores q o pivô atual, e cujo novo pivô é o último elemento desta lista*/
	  quickSort(v, partIndex+1, fim); /*ch.recursiva com todos os elementos maiores q o pivô atual, e cujo novo pivô é o último elemento desta lista*/
  }
}

int main ()
{
  int *v1, *v2;
  int tam;
  int i;

  srand ( time(NULL) );
  printf("Teste de algoritmos Divide-and-Conquer\nEscolha um tamanho pra lista de vetor: ");

  scanf("%d", &tam);
  v1 = v2 = (int*)malloc( sizeof(int)*tam );
  
  for ( i=0; i<tam; printf("%d ", v1[i]),i++ )
  	v1[i] = v2[i] = rand() % tam;
  printf("\n");

  quickSort(v1, 0, tam-1);
  printList(v1, tam);
  
  return 0;
}

void printList(int *v, int tam)
{
  int i;

  for ( i=0; i<tam; i++ )
	printf("%d ", v[i]);
  printf("\n");
}

void troca(int *a, int *b)
{
  int aux;

  aux = *a;
  *a = *b;
  *b = aux;
}

