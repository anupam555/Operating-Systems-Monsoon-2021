#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter string without any spaces: \n");
    scanf("%s",str);

    int cnt=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        cnt++;
    }
    char temp;
    for(int i=0; i<cnt/2; i++)
    {   
        temp=str[i];
        str[i]=str[cnt-i-1];
        str[cnt-i-1]=temp;
    }
    printf("Reversed string %s", str);
    return 0;
}