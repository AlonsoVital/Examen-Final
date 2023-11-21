#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int busqueda_secuencial(int arr[], int n, int x)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i]==x)
		{
			return i;
		}
	}
	return -1;
}

int busqueda_binaria(int arr[], int n, int x)
{
	int inicio=0, fin=n-1;
	while(inicio<=fin)
	{
		int medio=inicio+(fin-inicio)/2;
		if(arr[medio]==x)
		{
			return medio;
		}
		if(arr[medio]<x)
		{
			inicio=medio+1;
		}
		else
		{
			fin=medio-1;
		}
	}
	return -1;
}

int main()
{
	int n=500000;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=i+1;
	}
	
	clock_t inicio, fin;
	double tiempo_promedio_secuencial=0, tiempo_promedio_binario=0; 
	int tiempo_minimo_secuencial=1000000000, tiempo_minimo_binario=1000000000;
	int tiempo_maximo_secuencial=0, tiempo_maximo_binario=0;
	
	for(int i=0; i<100; i++)
	{
		int x=rand()%n+1;
		
		inicio=clock();
		int resultado_secuencial=busqueda_secuencial(arr, n, x);
		fin=clock();
		double tiempo_secuencial=(double)(fin-inicio)/CLOCKS_PER_SEC*1000;
		
		inicio=clock();
		int resultado_binario=busqueda_binaria(arr, n, x);
		fin=clock();
		double tiempo_binario=(double)(fin-inicio)/CLOCKS_PER_SEC*1000;
		
		tiempo_promedio_secuencial+=tiempo_secuencial;
		tiempo_promedio_binario+=tiempo_binario;
		
		if(tiempo_secuencial<tiempo_minimo_secuencial)
		{
			tiempo_minimo_secuencial=tiempo_secuencial;
		}
		if(tiempo_secuencial>tiempo_maximo_secuencial)
		{
			tiempo_maximo_secuencial=tiempo_secuencial;
		}
		
		if(tiempo_binario<tiempo_minimo_binario)
		{
			tiempo_minimo_binario=tiempo_binario;
		}
		if(tiempo_binario>tiempo_maximo_binario)
		{
			tiempo_maximo_binario=tiempo_binario;
		}
	}
	
	tiempo_promedio_secuencial/=100;
	tiempo_promedio_binario/=100;
	
	printf("Tiempo promedio secuencial: %.3f ms\n", tiempo_promedio_secuencial);
	printf("Tiempo minimo secuencial: %d ms\n", tiempo_minimo_secuencial);
	printf("Tiempo maximo secuencial: %d ms\n", tiempo_maximo_secuencial);

	printf("Tiempo promedio binario: %.3f ms\n", tiempo_promedio_binario);
	printf("Tiempo minimo binario: %d ms\n", tiempo_minimo_binario);
	printf("Tiempo maximo binario: %d ms\n", tiempo_maximo_binario);
	
	//Probar varias veces con el valor puesto en n, porque va variando 
	
	return 0;
	
}
