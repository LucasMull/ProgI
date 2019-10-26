#include <stdio.h>
#include <stdlib.h>

int crescente(int x);
int decrescente(int z);

int main()
{
	int y;
	printf("Escolha um valor: ");scanf("%d", &y);

	printf("Crescente: ");
	crescente(y);
	printf("\n");

	printf("Decrescente: ");
	decrescente(y);
	printf("\n");
	
	return 0;
}

int crescente(int x)
{
	if ( x > 1 )
		crescente(x-1);
	printf("%d ", x);
	return 0;
}

int decrescente(int z)
{
	printf("%d ", z);
	if ( z > 1 )
		decrescente(z-1);
	return 0;
}
