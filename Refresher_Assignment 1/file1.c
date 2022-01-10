#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fptr1, *fptr2;
    char f1[100], c;
    char f2[100];
  
    fptr1 = fopen(argv[1], "rb");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", f1);
        exit(0);
    }
  
    fptr2 = fopen(argv[2], "wb");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", f2);
        exit(0);
    }

    while(fread(&c, 1, 1, fptr1) == 1)
    {
    fwrite(&c, 1, 1, fptr2);
    }

    printf("\nContents copied to %s", f2);
  
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}