#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void add(int a, int b)
{
     printf("%d",a+b);
}
void sub(int a, int b)
{
    printf("%d",a-b);
}
void mul(int a, int b)
{
     printf("%d",a*b);
}
void division(int a, int b)
{    float c=(float)a/b;
     printf("%f",c);
}
void exponent(int a, int b)
{
    printf("%d",(int)pow(a,b));
}
void (*type[])(int,int)={add, sub, mul,division,exponent};
int main()
{   
    printf("Choose the required operation: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    int n;
    scanf("%d",&n);
    int x,y;
    printf("Enter the operands:");
    scanf("%d %d", &x, &y);
    type[n-1](x,y);
    return 0;
}