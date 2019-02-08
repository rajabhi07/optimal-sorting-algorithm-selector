#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include"sorttime.h"

void bestofall(float arr[], int arr_size) 
{
	double time_taken[6], x;	
	clock_t start,end;
	char name[6][20];
	
	//MERGE SORT	
	start=clock();
	mergeSort(arr, 0, arr_size - 1);
	end=clock();
	time_taken[0]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[0],"MERGE SORT");	

	printf("\n Merge Sort: %f", time_taken[0]);

	//QUICK SORT
	start=clock();
	quickSort(arr, 0, arr_size - 1);
	end=clock();
	time_taken[1]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[1],"QUICK SORT");
	
	printf("\n Quick Sort: %f",time_taken[1]);


	//INSERTION SORT
	start=clock();
	insertionSort(arr, arr_size-1);
	end=clock();
	time_taken[2]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[2],"INSERTION SORT");

	printf("\n Insertion Sort: %f",time_taken[2]);


	//SELECTION SORT
	start=clock();
	selectionSort(arr, arr_size-1);
	end=clock();
	time_taken[3]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[3],"SELECTION SORT");

	printf("\n Selection Sort: %f",time_taken[3]);
	
	//BUBBLE SORT
	start=clock();
	bubbleSort(arr, arr_size-1);
	end=clock();
	time_taken[4]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[4],"BUBBLE SORT");

	printf("\n Bubble Sort: %f",time_taken[4]);

	//HEAP SORT
	start=clock();
	heapSort(arr, arr_size-1);
	end=clock();
	time_taken[5]=((double)end-start)/(CLOCKS_PER_SEC/1000);
	strcpy(name[5],"HEAP SORT");

	printf("\n Heap Sort: %f",time_taken[5]);

	printf("\n");

	x=time_taken[0];

	for(int i=0; i<6; i++)
	{
		if(time_taken[i] <= x)
			x = time_taken[i];
	}
	
	printf("\n Following are the sorting technique(s) optimal for the given input: \n");	

	for(int i=0; i<6; i++)
		if(x == time_taken[i])
			{
				printf(" >> %s \n",name[i]);
			}
	
	printf("\n");

}

int main()
{
	int n;
	printf("\n Enter number of elements: ");
	scanf("%d",&n);
	float ar[n];
	printf("\n Enter the data: ");
	for(int i=0; i<n; i++) 
	{
		scanf("%f",&ar[i]);
	}
	bestofall(ar,n);
	getchar();
	return 0;
}
