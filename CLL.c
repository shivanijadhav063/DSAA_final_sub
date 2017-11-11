#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct node
{
    int data;
    struct node * next;
};
struct node * first=NULL;
struct node *last=NULL;

void create()
{
    struct node * pnode;
    int i,n;
    printf("enter no of nodes required\n");
    scanf("%d",&n);
    printf("Enter data value of each node\n");
    for(i=1;i<=n;i++)
    {
        pnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",pnode->data);
        if(first==NULL)
        first=last=pnode;
        else
            {
                last->next=pnode;
                last=pnode;
            }
    last->next=first;
    }
}

void deletenode(int k)
{
    struct node *p,*follow;
    p=first;
    follow=NULL;
    while(follow!=last)
    {
        if(p->data==k)
            break;
        follow=p;
        p=p->next;
    }
    if(follow==last)
        printf("Required node not found\n");
    else
        {
            if(p==first&&p==last)
            first=last=NULL;
    else if(p==first)
    {
        first=first->next;
        last->next=first;
    }
    else if(p==last)
    {
        last=follow;
        last->next=first;
    }
       else
            follow->next=p->next;
       free(p);
        }
}

void traverse()
{
    struct node * p,*follow;
    if(first==NULL)
        printf("Circular link list empty\n");
    else
        {
            printf("Circular link list is ::\n");
            p=first;
    follow=NULL;
    while(follow!=NULL)
    {
        printf("%d",p->data);
        follow=p;
        p=p->next;
    }}
}
void main()
{
    int x,k,ch;
    do
    {
        printf("**********MENU***********\n");
        printf("1..Create\n");
        printf("2..dealet\n");
        printf("3..traverse\n");
        printf("4..exit\n");
        printf("enter ur choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            printf("Enter value of node to be deleted\n");
            scanf("%d",&k);
            deletenode(k);
            break;

        case 3:
            traverse();
            break;

        case 4:
            break;

        }
    }
    while(ch!=4);
}
