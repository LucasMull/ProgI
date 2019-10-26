#include <stdio.h>
#include "tad_pilha.h"
#define MAX_CH 25

int main(){
	tad_pilha p;
	int i, k=0;
	char ch[MAX_CH];
	
	inicializa_pilha(&p);
	printf("Insira sequencia de parenteses (0 no fim): ");
	do
	{
		scanf(" %c", &ch[k]);
			
		if (ch[k]=='0')
		{
			k--;
			break;
		}

		if (! empilha(ch[k],&p)) 
		{
	    		printf("%d nao inserido: pilha cheia\n",k);
		    	printf("tamanho da pilha: %d\n",tamanho_pilha(p));
		}
		else 
		{
			printf("%c empilhado\n",ch[k]);
			printf("tamanho da pilha: %d\n",tamanho_pilha(p));
		}
		k++;
	}
	while (k<MAX_CH);
  
	for (i=0; i<k; i++,k--)
	{
		switch (p.v[i])
		{
			case 40:
				if (p.v[k]!=41)
				{
					printf("NÃO %c %c\n", p.v[i], p.v[k]);
					return 0;
				}	
			break;
			
			case 91:
				if (p.v[k]!=93)
				{
					printf("NÃO %c %c\n", p.v[i], p.v[k]);
                                        return 0;
				}
			break;
						
			case 123:
				if (p.v[k]!=125)
				{
					printf("NÃO %c %c\n", p.v[i], p.v[k]);
                                        return 0;
				}
			break;

			default:
				printf("Não é caractere desejado\n");
				return 0;
		}
	}
	printf("SIM\n");

return 0;
}
