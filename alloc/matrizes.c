#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, j, k;
	
	int **M1, **M2, **res; /*matrizes*/
	int ln1, ln2, col1, col2;
	
	printf("Escolha a qtd de linhas e colunas da Matriz 1: ");
	scanf("%d%*c%d", &ln1, &col1);
	printf("Escolha a qtd de linhas e colunas da Matriz 2: ");
	scanf("%d%*c%d", &ln2, &col2);
	
	M1= (int**) malloc(ln1 * sizeof(int*));
	for(i=0; i<ln1; i++)
		*(M1+i)= (int*)malloc(col1*sizeof(int));
	M2= (int**) malloc(ln2 * sizeof(int*));
	for(i=0; i<ln2; i++)
		*(M2+i)= (int*)malloc(col2*sizeof(int));
	printf("\nMATRIZ 1:\n");
	for(i=0; i<ln1; i++)
	{
		for (j=0; j<col1; j++)
			printf("[%d] ", M1[i][j]= rand()%10);
		printf("\n");
	}		
	printf("\nMATRIZ 2:\n");
	for(i=0; i<ln2; i++)
	{
		for (j=0; j<col2; j++)
			printf("[%d] ", M2[i][j]= rand()%10);
		printf("\n");
	}			
	
	if (col1 == ln2)
	{
		res= (int**) malloc(ln1 * sizeof(int*));
		for(i=0; i<ln1; i++)
			*(res+i)= (int*)malloc(col2*sizeof(int));
		
		printf("\nMATRIZ 1 X MATRIX 2:\n");
		for(i=0; i<ln1; i++)
		{
			for(j=0; j<col2; j++)
			{
				res[i][j]=0;
				for(k=0; k<ln2; k++)
					res[i][j] += M1[i][k]*M2[k][j];
				printf("[%d] ", res[i][j]);	
			}
			printf("\n");
		}
	}
	else
		printf("\nNÃO É POSSÍVEL MULTIPLICAR\n");
	return 0;
}
