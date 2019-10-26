#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

#define MAX 50000

void printArray(int arr[], int n);
int sortMachine(const char leitura[]);

int main()
{
	system("ls -1Sr ./entradas/ordenadas/* > entries.txt"); //lista de arqvs para ordenar
	const char arq[] = "./entries.txt";
	
	char c[256]; //aponta qual arquivo deverá ser lido para ordenação
	FILE *leitura;
	
	if ((leitura = fopen(arq, "r")) == NULL) //se a lista ñ existir cancela operação
	{
		printf("Erro ao tentar abrir arquivo entries.txt\n");
		exit(1);
	}
	
	printf("tam bolha selecao insercao\n");	
	while (!feof (leitura)) //rodar laço até o final da lista de ponteiros
	{	
		fscanf(leitura,"%s", c); //ao final de cada \n guarda o valor do ponteiro
		sortMachine(c); //utiliza os algoritmos de ordenação no ponteiro atual
	}
	fclose(leitura);
	return 0;
}

int sortMachine(const char leitura[])
{
	FILE *arq; //recebe ponteiro de arquivo do int main()
	int i=0,n=0;
	int arr[MAX], v0[MAX], v1[MAX], v2[MAX];

	arq=fopen(leitura, "r"); //abrir arquivo do ponteiro para leitura
	
	fscanf (arq, "%d", &i); //vasculha arquivo por inteiros
	while (!feof (arq)) //continua no laço até chegar no fim do arquivo
	{
		arr[n]=i; //preenche o vetor com os inteiros
		fscanf (arq, "%d", &i);
		n++; //atualiza total de linhas
	}
	fclose(arq);
	
	//DUPLICATAS DO ARRAY ORIGINAL (pra garantir que o array entre desordenado em todos algoritmos)	
	memcpy(v0, arr, n*sizeof(int));
	memcpy(v1, arr, n*sizeof(int));
	memcpy(v2, arr, n*sizeof(int));

	//CALCULAR TEMPO GASTO NA CPU POR PROCESSO
	clock_t begin1 = clock();
	bubbleSort(v0, n);
	clock_t end1 = clock();
	printf("%d %.2f", n-1 ,(double)(end1-begin1)/CLOCKS_PER_SEC);
	clock_t begin2 = clock();
        selectionSort(v1, n);
        clock_t end2 = clock();
        printf(" %.2f", (double)(end2-begin2)/CLOCKS_PER_SEC);
	clock_t begin3 = clock();
        insertionSort(v2, n);
        clock_t end3 = clock();
        printf(" %.2f\n", (double)(end3-begin3)/CLOCKS_PER_SEC);
	
	memcpy(v1, arr, n*sizeof(int)); //duplicata do array original
	//printArray(temp, n); //conferir se a ordenação está funcionando

	return 0;
}

void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int V[], int n){
        int i=0, chave=0, j=0;
        for (i = 1; i < n; i++){
                chave = V[i];
                j = i-1;
                while (j >= 0 && V[j] > chave){
                        V[j+1] = V[j];
                        j--;
                }
                V[j+1]=chave;
        }
}

void selectionSort(int arr[], int n) {
  int i, j, min, chave;
  for (i = 0; i < (n-1); i++)
  {
     min = i;
     for (j = (i+1); j < n; j++) {
       if(arr[j] < arr[min])
         min = j;
     }
     if (arr[i] != arr[min]) {
       chave = arr[i];
       arr[i] = arr[min];
       arr[min] = chave;
     }
  }
}

void bubbleSort(int arr[], int n)
{
        int c, d, swap;

        for (c = 0 ; c < n - 1; c++)
        {
                for (d = 0 ; d < n - c - 1; d++)
                {
                        if (arr[d] > arr[d+1]) // para ordem decrescente
                        {
                                swap = arr[d];
                                arr[d] = arr[d+1];
                                arr[d+1] = swap;
                        }
                }
        }
}
