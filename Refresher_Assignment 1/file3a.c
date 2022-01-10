#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    int b[n];
    printf("Enter the elements of array a:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=0; j<n; j++)
    {
        b[n-j-1]=a[j];
    }
    printf("The reversed array\n ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",b[i]);
    }
}