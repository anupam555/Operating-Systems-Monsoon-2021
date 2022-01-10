#include<stdio.h>
#include<stdlib.h>

struct Node{
    int roll;
    int year;
    char program[40];
    char name[40];
    struct Node*next;
};

struct Node* insert(int n);
void displayList(struct Node* front);

int main()
{
    int n=0;
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    root=insert(n);
    displayList(root);
    return 0;
}

struct Node* insert(int n)
{
    struct Node *front= NULL;
    struct Node *rear= NULL;
    struct Node*temp;
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
        printf("\nEnter the academic program:");
        scanf("%s",temp->program);
        temp->next=NULL;

    if(front==NULL)     
    {   front=temp;
        rear=temp;
    }
    else
    {   temp->next=front;
        front=temp;
    }   
    } 
    return front;
}
void displayList(struct Node* front)
{
    struct Node*p= front;
    while(p!=NULL)
    {
        printf("\n Student name:%s",p->name);
        printf("\n Roll nO.:%d",p->roll);
        printf("\n Year: %d",p->year);
        printf("\n Academic Program:%s",p->program);
        printf("\n");
        p=p->next;
    }
}