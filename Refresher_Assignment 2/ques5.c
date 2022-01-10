#include<stdio.h>
int main()
{   
    int n,x;
    printf("Enter the array size :\n");
    scanf("%d",&x);
    int arr[x];
    for(int i=0; i<x; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter your choice: \n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    scanf("%d",&n);
    if(n==1)
    {   int small,pos,temp;
        for(int i=0; i<x; i++) 
        {   small=arr[i];
            pos=i;
            for(int j=i+1; j<x; j++)
            {   if (arr[j]<small)
                {   small=arr[j];
                    pos=j;
                }
            }
        if(pos!=i)
        {   temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
     }   
        for(int i=0; i<x; i++)
        {   printf("%d\t",arr[i]);
        }
    }
    else if(n==2)
    {
    int temp;
    for(int i=0;i<x;i++)
    {  for(int j=0; j<x-1-i; j++)
        { 
            if(arr[j]>arr[j+1])
            {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    printf("Final Sorted Array:\n");
    for(int i=0; i<x; i++)
    {   printf("%d\t",arr[i]);
        }
    }
    else
    {   printf("Invalid input.");
    }
    return 0;
}