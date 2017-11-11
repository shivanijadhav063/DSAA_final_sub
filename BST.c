#include<stdio.h>
#include<conio.h>
#define NULL 0

struct node
{
    int data;
    struct node *left,*right;
};
struct node *root=NULL,*pnode;
int ncount,lcount;

void create()
{
    int x,n,i;
    printf("Enter number of nodes required :\n");
    scanf("%d",&n);
    printf("Enter data value of node:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        insert(x);
    }
}
void insert(int x)
{
    struct node *pnode,*p,*follow;
    pnode=(struct node*)malloc(sizeof (struct node));
    pnode->data=x;
    pnode->left=pnode->right=NULL;
    if(root==NULL)
        root=pnode;
    else
    {
        p=root;
        follow=NULL;
        if(pnode->data<p->data)
            p=p->left;
        else
            p=p->right;
        if(pnode->data=follow->data)
            follow->left=pnode;
        else
            follow->right=pnode;
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
        {
            printf("%d",pnode->data);
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

void search(int k)
{
    struct node *p;
    p=root;
    while(p!=NULL)
    {
        if(p->data==k)
            break;
        if(k<p->data)
            p=p->left;
        else
            p=p->right;
    }
      if(p==NULL)
            printf("Required node not found..\n");
      else
            printf("Node found at %X..\n",p);
}

void nodecount(struct node *root)
{
    if(root!=NULL)
    {
        nodecount(root->left);
        ++ncount;
        nodecount(root->right);
    }
}

void leafcount(struct node *root)
{
    if(root!=NULL)
    {
        leafcount(root->left);
        if(root->left=root->right=NULL)
        {
            ++lcount;
            printf("%d",root->data);
        }
        leafcount(root->right);
    }
}

void findmin()
{
    struct node *p;
    if(root==NULL)
        printf("Empty tree..\n");
    else
        {
            p=root;
            while(p->left!=NULL)
                p=p->left;
            printf("Smallest node data value is %d",p->data);
        }
}

void findmax()
{
    struct node *p;
    if(root=NULL)
        printf("Empty tree...\n");
    else
    {
        p=root;
        while(p->right!=NULL)
            p=p->right;
        printf("Largest data value is %d",p->data);
    }
}

void main()
{
    int x,k,ch;
    do
    {
        printf("***********MENU**********\n");
        printf("1..CREATE\n");
        printf("2..INSERT\n");
        printf("3..PREORDER\n");
        printf("4..POSTORDER\n");
        printf("5..INORDER\n");
        printf("6..SEARCH\n");
        printf("7..NODE COUNT\n");
        printf("8..LEAF COUNT\n");
        printf("9..FIND SMALLEST\n");
        printf("10..FIND LARGEST\n");
        printf("11..EXIT\n\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data value of new node:");
                scanf("%d",&x);
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter data value of node to be searched");
                scanf("%d",&k);
                search(k);
                break;

            case 7:
                ncount=0;
                nodecount(root);
                printf("No of nodes present are %d\n",ncount);
                break;

            case 8:
                lcount=0;
                leafcount(root);
                printf("Leaf node on tree are %d\n",lcount);
                break;

            case 9:
                findmin();
                break;

            case 10:
                findmax();
                break;
        }
    }
    while(ch!=10);
}
