#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

//Auxiliar del quickSort
int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=(low-1);
	for(int j=low; j<=high-1; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp= arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	
	return (i+1);
}

void quickSort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi= partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void bubbleSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


int main()
{
	int n=10000;
	int repeticiones=100;
	
	int *arr=(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
		arr[i]=rand()%n;
	}
	
	//Mide tiempos
	for(int r=0; r<repeticiones; r++)
	{
		
		//Insertion Sort
		clock_t start = clock();
		insertionSort(arr, n);
		clock_t end = clock();
		double time_spent=1000.0*(double)(end-start)/CLOCKS_PER_SEC;
		printf("Insertion Sort - Ejecucion %d: %lf milisegundos\n", r+1, time_spent);
		
		//QuickSort
		start = clock();
		quickSort(arr, 0, n-1);
		end=clock();
		time_spent=1000.0*(double)(end-start)/CLOCKS_PER_SEC;
		printf("QuickSort - Ejecucion %d: %lf milisegundos\n", r+1, time_spent);
		
		//BubleSort
		start = clock();
		bubbleSort(arr, n);
		end=clock();
		time_spent=1000.0*(double)(end-start)/CLOCKS_PER_SEC;
		printf("BubbleSort - Ejecucion %d: %lf milisegundos\n", r+1, time_spent);
	}
	
	return 0;
}
