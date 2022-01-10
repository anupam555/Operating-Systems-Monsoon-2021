#include<stdio.h>
int main()
{
    int n;
    printf("enter the size of array:\n");
    scanf("%d", &n);
    unsigned int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int x;
    scanf("%d",&x);
    int temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int l=0;
    int r=n-1;
    int mid;
    int flag=0;
    while(l<=r)
    {   mid=(l+r)/2;
        if(arr[mid]>x)
        {
            r=mid-1;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element is found in the array");
    }
    else{
        printf("Not found.");
    }
    return 0;
}