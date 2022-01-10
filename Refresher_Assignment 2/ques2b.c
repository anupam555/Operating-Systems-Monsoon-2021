#include<stdio.h>
#include<stdlib.h>

struct Node{
    int roll;
    int year;
    char program[40];
    char name[40];

    struct Node*prev;
    struct Node*next;
};

struct Node* createLinkedList(int n);
void displayList(struct Node* head);

int main()
{
    int n=0;
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    root=createLinkedList(n);
    displayList(root);
    return 0;
}

struct Node* createLinkedList(int n)
{
    struct Node *head= NULL;
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
        temp->prev=NULL;
        printf("\nEnter the academic program:");
        scanf("%s",temp->program);

        if(head==NULL)
        {   head=temp;
        }
        else
        {   p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            temp->prev=p;
        }
    }    
    return head;
}
void displayList(struct Node* head)
{
    struct Node*p= head;
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
