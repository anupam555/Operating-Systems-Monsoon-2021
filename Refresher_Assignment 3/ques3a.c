#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int val)
{
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left = ptr->right = NULL;
    return ptr;
}
struct node* FindMinVal(struct node* root)
{
    if(root==NULL)
    {   return NULL;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return FindMinVal(root->left);
    }
}
struct node* deleteinBST(struct node* root, int data)
{   
    if(root==NULL)
    {   return root;
    }
    else if(data < root->data)
    {
        root->left=deleteinBST(root->left,data);
    }
    else if(data > root->data)
    {
        root->right=deleteinBST(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp= root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            free(temp);
        }
        else if(root->left ==NULL && root->right == NULL)
        {
            free(root);
            root=NULL;
        }
        else{
            struct node *temp=FindMinVal(root->right);
            root->data=temp->data;
            root->right=deleteinBST(root->right, temp->data);
        }
    }
    return root;
}

struct node* insertnode(struct node* root, int val)
{
    if(root==NULL)
    {
        root=createnode(val);
        return root;
    }
    else if(val<=root->data)
    {
        root->left=insertnode(root->left,val);
    }
    else
    {
        root->right=insertnode(root->right, val);
    }
    return root;
}
void display(struct node *root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%d ->", root->data);
        display(root->left, level + 1);
        display(root->right, level + 1);
}
int main() 
{   
    struct node* root= NULL;
    root=insertnode(root,56);
    root=insertnode(root,47);
    root=insertnode(root,18);
    root=insertnode(root,67);
    display(root,0);
    return 0;
}