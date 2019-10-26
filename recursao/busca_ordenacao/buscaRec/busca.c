#include <stdio.h>
#include <stdlib.h>


int busca (int *MIN, int *MAX, int MAIOR);


int main()
{
	int v[5] = {2312, 432, 23423, 2, 1}; //ARRAY JA ESPECIFICADO PARA TESTE
	int count = -1;
	int MAIOR = 0;
	
	for ( int i=0; i<5; i++, count++ ); //CASO O TAMANHO DO ARRAY SEJA DESCONHECIDO
	
	MAIOR = busca(v, v+count, MAIOR);		
	printf("MAIOR ELEMENTO: %d\n", MAIOR);
	
	
	return 0;
}

int busca (int *MIN, int *MAX, int MAIOR)
{
	if ( MAIOR < *MAX )
		MAIOR = *MAX;
	else if ( MAX == MIN-1 )
	  	return MAIOR;

	busca(MIN, MAX-1, MAIOR);
}
