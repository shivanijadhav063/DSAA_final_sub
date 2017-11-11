#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0

struct node
{
    int data;
    struct node*left,*right;
};

struct node *pnode,*root;
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",pnode->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",pnode->data);
    }
}
void main()
{
    int ch,n;
    do
    {
        printf("*************MENU*********************\n");
        printf("1..PREORDER TRAVERSAL\n");
        printf("2..INORDER TRAVERSAL\n");
        printf("3..POSTORDER TRAVERSAL\n");
        printf("4..ENTER YOUR CHOICE\n\n\n");
        scanf("%d",ch);

    switch(ch)
    {
    case 1:
        printf("Enter the expression:\n");
        scanf("%d",&n);
        preorder(root);
        break;

    case 2:
        printf("Enter the expression:\n");
        scanf("%d",&n);
        inorder(root);
        break;

    case 3:
        printf("Enter the expression:\n");
        scanf("%d",&n);
        postorder(root);
        break;

    case 4:
        break;
    }
}

while(ch!=4);
}
