#include <stdio.h>
#include <stdlib.h>


int binaria(int *array, int n, int MAX, int MIN);

int main()
{
	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //ARRAY JA ESPECIFICADO PARA TESTE
	int count = -1;
	int number;
	int MAIOR, min = 0;

	for ( int i=0; i<10; i++,count++ ); //CASO O TAMANHO DO ARRAY SEJA DESCONHECIDO
	
	printf("ESCOLHA UM VALOR: ");scanf("%d", &number);
		
	MAIOR=binaria(v, number, count, min);
	printf("ENCONTRADO ELEMENTO: %d\n", MAIOR);
	
	return 0;
}

int binaria(int *array, int n, int MAX, int MIN)
{
	(MAX+MIN)/2;
	
	if (  array[(MAX+MIN)/2] == n )
		return (MAX+MIN)/2;

	if ( *(array+MIN) >= *(array+MAX) )
		return -1;
	else if ( n > array[(MAX+MIN)/2] )
		return binaria( array, n, MAX, ((MAX+MIN)/2)+1 );
	else
		return binaria( array, n, ((MAX+MIN)/2)-1, MIN );
}
