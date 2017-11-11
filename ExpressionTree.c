#include<stdio.h>
#include<stdlib.h>
#define NULL 0
#define STACKSIZE 50

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct stack
{
    int top;
    struct node *items[STACKSIZE];
};

void createtree(char e[]);
int isoperand(char c);
struct node *pop(struct stack *ps);
void push(struct stack *ps,struct node *x);
void inorder(struct node *root);

void main()
{
    char e[20];
    printf("Enter expression in postfix form\n");
    gets(e);
    createtree(e);

    printf("Expression in prefix\n");
    preorder(root);
    printf("\n");

    printf("Expression in infix form\n");
    inorder(root);
    printf("\n");
}

void createtree(char e[])
{
    int i;
    struct node *pnode,*op1,*op2;
    struct stack s;
    s.top=-1;
    for(i=0;e[i]!='\0';i++)
        if(isoperand(e[i]))
            {
                pnode=(struct node*)malloc(sizeof(struct node));
                pnode->data=e[i];
                pnode->left=pnode->right=NULL;
                push(&s,pnode);
            }
        else
            {
                op2=pop(&s);
                op1=pop(&s);
                pnode=(struct node*)malloc(sizeof(struct node));
                pnode->data=e[i];
                pnode->left=op1;
                pnode->right=op2;
                push(&s,pnode);
            }
    root=pop(&s);
}

int isoperand(char c)
{
    if(c>='0'&&c<='9'||c>='A'&&c<='Z'||c>='a'&&c<='z')
        return 1;
    else
        return 0;
}

struct node *pop(struct stack *ps)
{
    return(ps->items[ps->top--]);
}

void push(struct stack *ps,struct node *x)
{
    ps->items[++(ps->top)]=x;
}

void preorder(struct node *root)
{
    if(root!=NULL)
        {
            printf("%c",root->data);
            preorder(root->left);
            preorder(root->right);
        }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}
