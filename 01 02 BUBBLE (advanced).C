// BUBBLE SORT

#include<stdio.h>
#include<conio.h>

void bubbleSort(int *,int);

int main()
{
	int n,arr[100];
	int i;

	printf("\n\nHOW MANY NUMBERS ARE THERE : \t");
	scanf("%d",&n);

	printf("\n\nENTER NUMBERS ONE BY ONE ....");
	for(i=0;i<n;i++)
	{
		printf("\nENTER NUMBER %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	bubbleSort(arr,n);

	printf("\n\nTHE SORTED ARRAY IS.... ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",arr[i]);
	}
	return 0;
}
	// 34	22	27	24	29
	// above numbers provide need for enhanced bubble sort
void bubbleSort(int arr[],int n)
{
	int i,j,temp;
	int exchanged = 1;
	for(i=0;i<n-1 && exchanged;i++)
	{
		exchanged = 0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				exchanged = 1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
