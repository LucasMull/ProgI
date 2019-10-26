#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo (char *ch, int k)
{
	int i;
	
	while (1)
		if ( *(ch+k)==' ' || *(ch+k)=='\0')
			k--;
		else
			break;
	*(ch+(k+1))='\0';
	
	for ( i=0; i<=k; i++, k--)
	{
		printf("ch[%d]:%c, ch[%d]:%c\n",i,*(ch+i),k,*(ch+k));
		if ( *(ch+i) != *(ch+k) )
			return 0;
	}
	return 1;
}

int main ()
{
        char *ch;
        int k;

        printf("Digite o total de chars para o string: ");
        scanf("%d", &k);
	k--;

        ch = (char *)malloc(k*sizeof(char));
        printf("Escreva uma palavra: ");
        scanf("%s", ch);

        if (! palindromo(ch, k))
                printf("Nao e palindromo\n");
        else
                printf("Eh palindromo\n");
        free(ch);

        return 0;
}
