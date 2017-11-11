#include<stdio.h>
#define NULL 0
struct node{
int data;
struct node *next;
};
struct node * first1,*first2;
void create(int flag)
{
    int i,n;
    struct node *pnode,*p;
    struct node *first=NULL;
    printf("enter no of nodes to crete\n");
    scanf("%d",&n);
    printf("Enter data value of each node\n");
    for(i=1;i<=n;i++)
    {
        pnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",pnode->data);
        pnode->next=NULL;
        if(p==first)
            first=p=pnode;
        else
        {
            p->next=pnode;
            p=pnode;
        }
    }
    if(flag==1)
        first1=first;
    if(flag==2)
        first2=first;
}

void traverse(struct node * first)
{
    struct node *p;
    if(first==NULL)
        printf("empty link list\n");
    else
        {
            printf("list list is as shown\n");
    p=first;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }}
}

void copy()
{
    struct node *p1,*p2,*pnode;
    if(first1==NULL)
        return;
    p1=first1;
    while(p1!=NULL)
    {
        pnode=(struct node *)malloc(sizeof(struct node));
        pnode->data=p1->data;
        pnode->next=NULL;
        if(first2==NULL)
            first2=p2=pnode;
        else
        {
            p2->next=pnode;
            p2=pnode;
        }
        p1=p1->next;
    }
}

void concat()
{
    struct node *p1;
    if(first1==NULL&&first2==NULL)
        return;
    else if(first1==NULL)
        first1=first2;
    else if(first2==NULL)
        return;
    else
    {
        p1=first1;
        while(p1->next!=NULL)
            p1=p1->next;
        p1->next=first2;
    }
}

void split()
{
    struct node *p1,*last;
    float n=0;int i;
    if(first1==NULL)
        return;
    p1=first1;
    while(p1!=NULL)
        {n++;
            p1=p1->next;}
    last=first1;
    for(i=1;i<ceil(n/2);i++)
        last=last->next;
       first2=last->next;
    last->next=NULL;
}

void main()
{
    int x,k,ch;
    do
    {
        printf("**********MENU***********\n");
        printf("1..Copy\n");
        printf("2..concat\n");
        printf("3..split\n");
        printf("4..exit\n");
        printf("enter ur choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            first1=first2=NULL;
            printf("create Original link list\n");
            create(1);
            copy();
            printf("original  link list is\n");
            traverse(first1);
            printf("copied link list is\n");
            traverse(first2);
            break;

        case 2:
            first1=first2=NULL;
            printf("create 1 link list\n");
            create(1);
            printf("create 1 link list\n");
            create(2);
            concat();
            printf("concatted link list is\n");
            traverse(first1);

            break;

        case 3:
            first1=first2=NULL;
            printf("create originl link list\n");
            create(1);
            split();
            printf(" 1 half link list\n");
            traverse(first1);
            printf(" 2 half link list\n");
            traverse(first2);
            break;

        case 4:
            break;

        }
    }
    while(ch!=4);
}
