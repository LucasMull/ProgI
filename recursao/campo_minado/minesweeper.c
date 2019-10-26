#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 26

/** CHARS DA TABELA ASCII UTILIZADOS:
 * 48 a 57 = '0 a 9'
 * 254 = Minas
 * 65 a 90 = 'A a Z'
**/

void clean_stdin(void) /** função que limpa buffer de entrada **/
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int grid(int *A, int *B);
int montaCampo(int campo[MAX][MAX], int A, int B, int col, int linha, int updateX, int updateY);
int gerarMinas(int campo[MAX][MAX],int A, int B, int a, int b, int DIFICULDADE);
int jogada(int campo[MAX][MAX], int X, int Y, int A, int B, int updateX);

int main()
{
	unsigned int A, B; /** A,B: Linhas e Colunas totais no campo **/
	char X; int Y; /** X,Y: Coordenadas para efetuar jogada; **/
	char TURN=1; char LEAVE=0; /** TURN=1:GameOn; TURN=0: GameOver; !LEAVE: Repete jogada **/
	int DIFICULDADE=0; /** DIFICULDADE DE 1 a 3 AUMENTA QUANTIDADE DE MINAS **/
	int campo[MAX][MAX]; /**Matriz do campo com posição das minas**/ 
	time_t t; /**para inicializar srand e definir pos aleatória das minas**/
	
	printf("Escolha a grid do tabuleiro de 1 até 25(Escreva como AxB):\n");
	grid(&A, &B);
	
	printf("NIVEL DE DIFICULDADE\n1: facil\n2: medio\n3: dificil\n");
	do
	{
		printf("NIVEL: ");
		scanf("%d", &DIFICULDADE);

		switch (DIFICULDADE)
		{
			case 1:
				printf("\nDIFICULDADE: FACIL ...");
				break;
			case 2:
				printf("\nDIFICULDADE: MEDIO ...");
				break;
			case 3:
				printf("\nDIFICULDADE: DIFICIL ...");
				break;
			default:
				DIFICULDADE = 0;
				printf("\nInvalido, por favor repita novamente ...\n");
				clean_stdin();
		}

	}
	while (DIFICULDADE == 0);
	printf("\n\n");

	A--;
	B--;
	montaCampo(campo, A, B, 0, -1, -1, -1);
	srand((unsigned) time(&t)); /**inicializa pra gerar valor random**/
	gerarMinas(campo, A, B, 0, 0, DIFICULDADE);
	printf("\n\n");
	
	while (TURN != 0) /** CRIAR RESTRIÇÕES DE JOGADAS INVÁLIDAS **/
	{
		printf("Escolha coordenada para ativar (EX: A13):\n");
		LEAVE=0;
		do
		{	
			clean_stdin();
			scanf("%c%d", &X,&Y);
			if ( ( X>=65 )&&( X<=65+A )&&( Y>=1 )&&( Y<=B+1 ) )
				LEAVE=1;
			else
				printf("Jogada inválida ...\nTente novamente\n");
		}
		while (LEAVE==0); 
		TURN=jogada(campo, Y-1, X-65, A, B, 0);
		montaCampo(campo, A, B, 0, -1, X, Y);			
		
		if (! TURN)
		{
			printf("\n");
			montaCampo(campo, A, B, 0, -1, -2, -2);
			printf("\n\nVOCÊ PERDEU!!\n\n");
		}
		else if ( jogada(campo, 0, 0, A, B, -1) == 3 )
		{
			printf("\n");
			montaCampo(campo, A, B, 0, -1, -2, -2);
			printf("\n\nVOCÊ VENCEU!!\n\n");
			TURN=0;
		}
	}
	return 0;
}

int grid(int *A, int *B)
{
	scanf("%d%*c%d",A,B);
	if ( *A<=MAX && *A>=1 && *B<=MAX && *B>=1 )
		return 1;
	printf("Inválido, tente novamente ...\n");
	clean_stdin();
	return grid(A,B);
}

int montaCampo(int campo[MAX][MAX], int A, int B, int col, int linha, int updateX, int updateY)
{
	/**A,B: recebe total de linhas e colunas
	 * linha, col: percorre linhas e colunas
	 * 	obs: linha começa no -1 para poder formatar as coordenadas do topo do campo
	 * updateX, updateY: efetua jogadas graficamente
	 * 
	 * updateX: também serve para checar a parte da função a ser interpretada
	 * 	updateX = -1 : Inicia o jogo, monta campo e inicia a matriz
	 * 	updateX = -2: FIM DE JOGO, monta campo com todas as minas à mostra
	 * 	updateX = default: Atualiza o campo e mostra a alteração dos tiles após a jogada
	 **/

	if (linha > A+1)
		return 0;
		
	if (linha == -1)
		if (col<=B)
		{
			if (col == 0)
			{
				system("clear");
				printf("    ");	
			}
			printf("%c ", 65+col);
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
		else if ( col > B )
		{
			printf("\n");	
			return montaCampo(campo,A,B,0,0,updateX,updateY);
		}
	if (col == 0)
		if (linha <= A)
			printf("%2d| ", linha+1);
		else if (linha > A)
			printf("    ");
	
	if (col > B)
	{
		if (linha<=A)
			printf("|%d\n", linha+1);
		else
			printf("\n");
		return montaCampo(campo,A,B,0,linha+1,updateX,updateY);
	}

	if (updateX == -1) /** INICIA MATRIZ DO CAMPO **/
	{
		if (linha<=A)
		{
			campo[linha][col]='#';
			printf("%c ", campo[linha][col]);	
			return montaCampo(campo,A,B,col+1,linha,-1,-1);
		}
		else
		{
			printf("%c ", 65+col);
			return montaCampo(campo,A,B,col+1,linha,-1,-1);
		}
	}
	else if (updateX == -2) /** FIM DE JOGO **/
	{
		if (linha<=A)
		{
			
			if (campo[linha][col] == '#')
			{
				jogada(campo, linha, col, A, B, -2); /** imprime o campo com todas as tiles numeradas **/
				printf("%c ", campo[linha][col]);
				return montaCampo(campo,A,B,col+1,linha,-2,-2);
			}
			printf("%c ", campo[linha][col]);
			return montaCampo(campo,A,B,col+1,linha,-2,-2);
		}
		else
		{
			printf("%c ", 65+col);
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
		
	}
	else /** ATUALIZA CAMPO DURANTE JOGADAS **/
	{
		if ( (linha == updateX)&&(col == updateY) )
		{
			printf("%c ", campo[linha][col]);
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
		else if ( (linha <= A)&&( ( (campo[linha][col]>=48)&&(campo[linha][col]<=56) )||(campo[linha][col]==' ')) )
		{
			printf("%c ",campo[linha][col]);
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
		else if (linha <= A)
		{
			printf("# ");
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
		else
		{
			printf("%c ", 65+col);
			return montaCampo(campo,A,B,col+1,linha,updateX,updateY);
		}
	}
}

int gerarMinas(int campo[MAX][MAX],int A, int B, int a, int b, int DIFICULDADE)
{
	/** 
	 *  A,B: recebe total de linhas e colunas
	 *  a,b: percorre linhas e colunas
	 *  DIFICULDADE: definido pelo usuário, determina a quantidade de minas no campo
	 *  randomA, randomB: gera um valor random entre 0 até a A e 0 até B, e associa uma mina a essa coordenada
	 **/  
	
	int randomA, randomB;
	
	if(a<=((A+B)/2)*DIFICULDADE) /** qtd de minas == media de linhas e colunas * nível de dificuldade **/
	{	
		randomA=rand()%(A+1);
		randomB=rand()%(B+1);

		if(campo[randomA][randomB]==254) /**se já tiver mina no tile, tente novamente**/
			return gerarMinas(campo, A, B, a, b, DIFICULDADE);	
		
		campo[randomA][randomB]=254;	
		return gerarMinas(campo, A, B, a+1, b+1, DIFICULDADE);
	}	
	return 0;	
}

int jogada(int campo[MAX][MAX], int X, int Y, int A, int B, int updateX)
{
	/**
	 *  X,Y: coordenada da linha e coluna escolhida pelo usuário para a jogada
	 *  A,B: recebe total de linhas e colunas
	 *  tilesNum: conta a quantidade de minas ao redor do tile escolhido pelo usuário, assim como os tiles que surgirem recursivamente
	 *  updateX == 0: GameOn, updateX == -2: GameOver, updateX == -1: checar se atinge condições para vitória
	 **/ 
	if (updateX == -1)
	{
		if ( campo[X][Y] == '#' )
			return 2; /** Ainda não satisfaz condições de vitória **/
		if ( X<=A )
			return jogada(campo, X+1, Y, A, B, -1);
		else if ( Y <= B)
			return jogada(campo, 0, Y+1, A, B, -1);
		
		return 3; /** Satisfaz condições de vitória **/
	}

	char tilesNum=0;
	if (campo[X][Y] == 254) 
		return 0;

	/**CONTAR MINAS AO REDOR DO TILE**/	
	if (campo[X][Y-1] == 254)
		tilesNum++;
	if (campo[X][Y+1] == 254)
		tilesNum++;
	if (campo[X-1][Y-1] == 254)
		tilesNum++;
	if (campo[X-1][Y] == 254)
		tilesNum++;
	if (campo[X-1][Y+1] == 254)
		tilesNum++;
	if (campo[X+1][Y-1] == 254)
		tilesNum++;
	if (campo[X+1][Y] == 254)
		tilesNum++;
	if (campo[X+1][Y+1] == 254)
		tilesNum++;
	
	if (tilesNum!=0) /**Imprime número de minas ao redor do tile escolhido**/
		campo[X][Y] = tilesNum+48; /**48 representa o 0 na tabela ASCII**/
	else campo[X][Y] = ' ';
	
	if (tilesNum == 0 && updateX == 0) /**Se não tiver minas ao redor do tile, então há chamada recursiva, até que se encontre uma mina próxima ou o limite do campo**/
	{
		if ( (Y>0)&&(campo[X][Y-1]=='#') )
			jogada(campo,X,Y-1,A,B,0);
		if ( (Y<=B)&&(campo[X][Y+1]=='#') ) 
			jogada(campo,X,Y+1,A,B,0);
		if ( (Y>0)&&(X>0)&&(campo[X-1][Y-1]=='#') )
			jogada(campo,X-1,Y-1,A,B,0);
		if ( (X>0)&&(campo[X-1][Y]=='#') )
			jogada(campo,X-1,Y,A,B,0);
		if ( (X>0)&&(Y<=B)&&(campo[X-1][Y+1]=='#') )
			jogada(campo,X-1,Y+1,A,B,0);
		if ( (X<=A)&&(Y>0)&&(campo[X+1][Y-1]=='#') )
			jogada(campo,X+1,Y-1,A,B,0);
		if ( (X<=A)&&(campo[X+1][Y]=='#') )
			jogada(campo,X+1,Y,A,B,0);
		if ( (X<=A)&&(Y<=B)&&(campo[X+1][Y+1]=='#') )
			jogada(campo,X+1,Y+1,A,B,0);
	}
	return 1;
}
