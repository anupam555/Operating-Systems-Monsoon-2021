#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{   
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("Values after swapping: %d %d", *x, *y);
}

int main()
{   int a, b;
    printf("Enter variables: \n");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    return 0;
}
