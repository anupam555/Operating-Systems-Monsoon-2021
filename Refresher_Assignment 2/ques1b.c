#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randoms(int lower, int upper, int count)
{
    int num = (rand() %(upper - lower + 1)) + lower;
    return num;
}
int main()
{   int cols[6];
    int **mat = (int **)malloc(6 * sizeof(int));    
    for(int i=0; i<6; i++)
    {   printf("Specify the no of colums for row%d :",i);
        scanf("%d", &cols[i]);
    }
    for(int i = 0; i < 6; i++)
    {   *(mat+i) = (int *)malloc(cols[i] * sizeof(int));
        for(int j=0; j<cols[i]; j++)
        {   *(*(mat+i)+j)=randoms(1,10,1);
        }
    }
    for(int i=0; i<6; i++)
	{
	for(int j=0; j<cols[i]; j++)
	{   printf("%d ", *(*(mat+i)+j));
	}
        printf("\n");
	}
    return 0;
}