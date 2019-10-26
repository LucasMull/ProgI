#include <stdio.h>
#define MAX 10

typedef struct 
{
int v[MAX]; /** calorias gasta por exercício **/
int n; /** tamanho de v **/
int u[MAX]; /** tempo gasto por exercício **/
int m; /** tamanho de u **/
}fitness;

int routine (fitness *rotina, int salva[MAX][MAX], int i)
{
	printf("\n");
	if (i < rotina->n)
	{
		printf("EXERCICIO %d\nCalorias Gasta: ", i+1);
		scanf("%d", &rotina->v[i]);
		printf("Tempo Gasto: ");
		scanf("%d", &rotina->u[i]);
		return routine(rotina, salva, i+1);
	}
	return 1;
}

int otimizarTempo(fitness *rotina, int salva[MAX][MAX], int n, int *tempoTotal, int *calTotal, int t) /**Considerando que o vetor caloria já está ordenado**/
{ 
	if (n<0)
		return 0;

	if ( *tempoTotal + rotina->u[n] <= t )
	{
		*tempoTotal += rotina->u[n];
		*calTotal += rotina->v[n];
		return otimizarTempo(rotina, salva, n-1, tempoTotal, calTotal, t);
	}
	else
		return otimizarTempo(rotina, salva, n-1, tempoTotal, calTotal, t);
}

int ordenarVetores(fitness *rotina, int i, int n, int pivoCal, int pivoTempo, int salva[MAX][MAX])
{
	if (i<n)
	{
		if ( pivoCal < rotina->v[i] )
		{
			pivoCal = rotina->v[i];
			pivoTempo = rotina->u[i];
			return ordenarVetores(rotina, i+1, n, pivoCal, pivoTempo, salva);
		}
		else
		{
			rotina->v[i-1]=rotina->v[i];
			rotina->v[i]=pivoCal;

			rotina->u[i-1]=rotina->u[i];
			rotina->u[i]=pivoTempo;

			return ordenarVetores(rotina, i+1, n, pivoCal, pivoTempo, salva);
		}	
		
	}
	if (n>1)
	{
		return ordenarVetores(rotina, 1, n-1, rotina->v[0], rotina->u[0], salva);
	}
	else
		return 0;
}

int main ()
{
	fitness jaque;
	int exercicio[MAX][MAX];
	int t, tempoTotal=0, calTotal=0;

	printf("Quantidade de exercícios: ");
	scanf("%d", &jaque.n);
	jaque.m=jaque.n;
	
	routine(&jaque, exercicio, 0);

	printf("Tempo disponível para treino em minutos: ");
	scanf("%d", &t);
	
	ordenarVetores(&jaque, 1, jaque.n, jaque.v[0], jaque.u[0], exercicio);
	otimizarTempo(&jaque, exercicio, (jaque.n)-1, &tempoTotal, &calTotal, t);
	printf("\ntempoTotal: %d\ncalTotal: %d\n", tempoTotal, calTotal);

return 0;
}
