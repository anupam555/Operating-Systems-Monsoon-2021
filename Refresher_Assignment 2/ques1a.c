#include<stdio.h>
#include<stdlib.h>
int main()
{   int **ptr=(int**)malloc(6*sizeof(int*));
    int col[]={7,4,6,3,7,2};
	for(int i=0; i<6; i++)
	{    *(ptr+i)=(int*)malloc(col[i]*sizeof(int*));
	}
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<col[i]; j++)
		{
			printf("%d ", *(*(ptr+i)+j));
		}
		printf("\n");
	}
	return 0;
}