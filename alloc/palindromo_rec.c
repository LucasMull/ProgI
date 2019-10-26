#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo (char *ch, int i, int k)
{
	if ( *(ch+k)==' ' || *(ch+k)=='\0')
		return palindromo(ch, i, k-1);

	if ( k<=i )
		return 1;
	
	if ( *(ch+i) == *(ch+k) )
		return palindromo(ch, i+1, k-1);
	return 0; 
}

int main ()
{
	char *ch;
	int i=0, k;

	printf("Digite o total de chars para o string: ");
	scanf("%d", &k);
	
	ch = (char *)malloc(k*sizeof(char));
	printf("Escreve uma palavra: ");	
	scanf("%s", ch);
	
	if (! palindromo(ch, i, k-1))
		printf("Nao e palindromo\n");
	else
		printf("Eh palindromo\n");
	free(ch);

	return 0;
}
