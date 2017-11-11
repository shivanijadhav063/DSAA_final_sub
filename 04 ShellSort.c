// Shell SORT

#include<stdio.h>
#include<conio.h>

void shellSort(int *, int, int *, int);

int main()
{
	int n,arr[100];
	int i;
	int incrementsArray [ ] = {1,2,4};
	int countOfIncrements = 3;


	printf("\n\nHOW MANY NUMBERS ARE THERE : \t");
	scanf("%d",&n);

	printf("\n\nENTER NUMBERS ONE BY ONE ....");
	for(i=0;i<n;i++)
	{
		printf("\nENTER NUMBER %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	shellSort(arr,n,incrementsArray,countOfIncrements);

	printf("\n\nTHE SORTED ARRAY IS.... ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",arr[i]);
	}
	return 0;
}

void shellSort(int x[], int n, int incrementsArray[], int countOfIncrements)
{
	int i, j, k, span, temp;
	for(i = countOfIncrements - 1; i >= 0; i--)
    {
		span = incrementsArray[i]; 		/* span is gap */
		for(j=span; j<n; j++)
        {
            //insert element x[j] into its proper position within its subsets
			temp = x[ j ];
			for(k=j-span; k>=0 && temp<x[k]; k=k-span)
				x[ k + span] = x[k];
			x[ k + span] = temp;
		}
	}
}
