#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void llenarMatriz(int matriz[30][30])
{
	for(int i=0; i<30; i++)
	{
		for(int j=0; j<30; j++)
		{
			matriz[i][j]=rand()%9+1;
		}
	}
}

void ImprimirMatriz(int matriz[30][30])
{
	for(int i=0; i<30; i++)
	{
		for(int j=0; j<30; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void Multiplicacion(int matriz1[30][30], int matriz2[30][30], int result[30][30])
{
	//int result[30][30];
	for(int i=0; i<30; i++)
	{
		for(int j=0; j<30; j++)
		{
			result[i][j]=0;
			for(int k=0; k<30; k++)
			{
				result[i][j]+=matriz1[i][k]*matriz2[k][j];
			}
		}
	}
}

int main()
{
	clock_t tic=clock();
	
	srand(time(NULL));
	
	int matriz1[30][30];
	int matriz2[30][30];
	int result[30][30];
	
	llenarMatriz(matriz1);
	llenarMatriz(matriz2);
	
	printf("Matriz 1: \n");
	ImprimirMatriz(matriz1);
	
	printf("\n");
	
	printf("Matriz 2: \n");
	ImprimirMatriz(matriz2);
	
	printf("Resultado de la multiplicacion: \n");
	Multiplicacion(matriz1, matriz2, result);
	ImprimirMatriz(result);
	
	printf("\n");
	
	clock_t toc=clock();
	printf("Elapsed: %f seconds\n", (double)(toc-tic)/CLOCKS_PER_SEC);
	
	return 0;
}
