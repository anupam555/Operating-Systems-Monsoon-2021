#include<stdio.h>
#include<stdlib.h>
struct Node{
    int roll;
    int year;
    char program[40];
    char name[40];
    struct Node*next;
};

struct Node* push(int n)
{
    struct Node *top= NULL;
    struct Node *temp=NULL;
    struct Node *p= NULL;

    for(int i=0; i<n; i++)
    {   
        temp=(struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter the data of node %d",i+1);
        printf("\nEnter the name:");
        scanf("%s", temp->name);
        printf("\nEnter the roll number:");
        scanf("%d",&temp->roll);
        printf("\nEnter the joining year:");
        scanf("%d", &temp->year);
        temp->next=NULL;
        printf("\nEnter the academic program:");
        scanf("%s",temp->program);
     
    if (top == NULL) {
        top = temp;
        top->next = NULL;
    } 
    else 
    {   temp->next = top;
        top = temp;
        }
    }    
    return top;
}
void printStack(struct Node* top)
{
    struct Node*p= top;
    while(p !=NULL)
    {
        printf("\n Student name:%s",p->name);
        printf("\n Roll nO.:%d",p->roll);
        printf("\n Year: %d",p->year);
        printf("\n Academic Program:%s",p->program);
        printf("\n");
        p=p->next;
    }
}

int main()
{
    int n=0;
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    root=push(n);
    printStack(root);
    return 0;
}