#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tad_pilha.h"


int transformaDigito(char ch[], char digit[], int startOfdigit, int i, tad_pilha *p);
float transformaOperador (char *ch, float op, float t);

int main()
{
	tad_pilha p;
	int i, j, startOfdigit; /*contadores*/
	float op=0, t; /*realiza operação durante desempilha*/
	int FIM=0; /*condição para saída do laço; !FIM permanece no laço*/
	char ch[MAX], digit[MAX]; /*leitura do input do usuário; armazenamento dos digitos do input*/

	inicializa_pilha(&p);

	printf("CALCULADORA POLONESA\n");
	do
	{
		printf(">> ");
		fgets(ch, MAX-1, stdin);
		startOfdigit = 0;
				
		for ( i=0; ch[i]!='\0'; i++)
		{	
			if ( ! isdigit(ch[i]) )
			{
				switch (ch[i])
				{
					case ' ':	
						startOfdigit= transformaDigito(ch,digit,startOfdigit,i,&p); /* inclui função empilha dentro da fç transformaDigito */
						break;
					case '+':
					case '-':
					case '*':
					case '/':
						if ( topo(&t,p)>=0 && tamanho_pilha(p)>1 )
						{
							op = t;
							printf("\tTopo da pilha:: %.2f\n", t);
							
							for ( j=0; j<1; j++)
								if (! desempilha(&t, &p))
									printf("\tNÃO DESEMPILHOU: PILHA VAZIA\n");
								else
								{
									printf("\t\t%.2f DESEMPILHADO\n", t);
									topo(&t,p);
									printf("\tTopo da pilha: %.2f\n", t);
									desempilha(&t, &p);
									printf("\t\t%.2f DESEMPILHADO\n", t);
									
									printf("\t%.2f", op);
									printf("%c%.2f: %.2f\n", ch[i], t, op= transformaOperador(ch+i,op,t) );
								}
							empilha(op, &p);
							topo(&t, p);
							printf("\tTopo da pilha: %.2f\n", t);
							printf("\tTamanho da pilha: %d\n\n",tamanho_pilha(p));
							
						}
						break;
					case 'q':
						ch[i]='\0';
						FIM = 1;
						topo(&t, p);
						printf("\tRESULTADO FINAL:\n\tTopo da pilha: %.2f\n", t);
						printf("\tTamanho da pilha: %d\n\n",tamanho_pilha(p));
						
						break;
					case '\n':
						break;
					default:
						printf("\tERRO!! CARACTERE INVÁLIDO: %c\n\tSerá ignorado junto de seus sucessores.\n\n", ch[i]);  
						ch[i]='\0';
						break;	
				}
			}
		}
		startOfdigit= transformaDigito(ch,digit,startOfdigit,i,&p);
	}
	while ( ! FIM );	
	return 0;
}

int transformaDigito(char ch[], char digit[], int startOfdigit, int i, tad_pilha *p)
{
	float val;
	int j, k=0;

	if ( isdigit(ch[startOfdigit]) != 0 )
	{
		for ( j=startOfdigit, k=0; j<=i; j++, k++ )
			digit[k]=ch[j];
		digit[j]='\0';

		val = atof(digit);
		
		empilha(val, p);
		printf("\tEMPILHADO: %.2f\n", val);
	}
	return i+1;
}

float transformaOperador (char *ch, float op, float t)
{

	switch (*ch) /**CRIAR FUNÇÃO QUE ASSOCIA ASCII COM OPERACAO AUTOMATICAMENTE**/
	{
		case '+':
			return op + t;
		case '-':
			return op - t;
		case '*':
			return op * t;
		case '/':
			if (t == 0)
				return op;
			
			return op/t;
		default:
			return 0;
	}
	return 1;
}
