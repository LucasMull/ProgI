#include <stdio.h>

double fat(int n);

double pascal(int n, int i, int termo, int *termCounter, double *pivo);
double fatPascal(int n, int p, int *termCounter, int termo, double *pivo);

int buscaLinha(int termo, int i, int j, int n)
{
	if ( termo >= 0 && termo <= j )
		return j-i+1;
	
	return buscaLinha(termo, i+1*(n+1), j+1*(n+2), n+1);
}

int main()
{
	int n, termo, termCounter=0;
	double pivo;

	do
	{
	printf("n-esimo termo do Triangulo: ");
	scanf("%d", &termo);
	} while(termo <= 0);

	printf("\n");
	n = buscaLinha(termo-1, 0, 0, 0);
	pascal(n,0,termo, &termCounter, &pivo);

	printf("\n%d-ésimo termo: %.lf\n", termo, pivo);
	
	return 0;
}

double fat(int n)
{
	if (n == 0)
		return 1;
	
	return n*fat(n-1);
}

double pascal(int n, int i, int termo, int *termCounter, double *pivo)
{
	int p=0;

	if (i > n)
		return 1;
	
	fatPascal(i, p, termCounter, termo, pivo);	
	printf("\n");
		
	return pascal(n, i+1, termo, termCounter, pivo);
}

double fatPascal(int n, int p, int *termCounter, int termo, double *pivo)
{
	double x=0;

	if (p > n)
		return 1;
	
	x = fat(n)/(fat(p)*fat(n-p));
	*(termCounter)+=1;
	if (termo == *termCounter)
	{
		printf("#%.0lf ", x);
		*pivo = x;
	}
	else
		printf("%.0lf ", x);
	
	return fatPascal(n, p+1, termCounter, termo, pivo);
}
