#include <stdio.h>
#include <string.h>
#define MAX 150

int palindromo (char ch[], int i, int k)
{
	if (i==k)
		return 1;
	
	if (ch[i] == ch[k])
		return palindromo(ch, i+1, k-1);
	return 0; 
}

int contaChar(char ch[], int i)
{
	if (ch[i]=='\0')
		return i-1;
	return contaChar(ch, i+1);
}

int main ()
{
	char ch[MAX];
	int i=0, k;

	printf("Escreve uma palavra: ");	
	scanf("%s", ch);
	k=contaChar(ch, i);

	if (! palindromo(ch, i, k))
		printf("Nao e palindromo\n");
	else
		printf("Eh palindromo\n");
	return 0;
}
