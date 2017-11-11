#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * first=NULL,*last=NULL;

void create()
{
    int i,n;
    struct node* pnode,*p;
    printf("Enter no of nodes\n");
    scanf("%d",&n);
    printf("Enter data value of each node : \n");
    for(i=1;i<=n;i++)
    {
        pnode=(struct node*)malloc (sizeof(struct node));
        scanf("%d",& pnode->data);


        if(first==NULL)
            {pnode->next=pnode->prev=NULL;
            first=last=pnode;
            }
        else
        {
            pnode->next=NULL;
            pnode->prev=last;
            last->next=pnode;
            last=pnode;
        }
    }
}

void insertbef(int x,int k)
{
    struct node *pnode,*p,*follow;
    pnode=(struct node*)malloc (sizeof(struct node));
    p=first;
   // follow=NULL;
    while(p!=NULL)
    {
        if(p->data==k)
            break;
            //follow=p;
        p=p->next;
    }
    if(p==NULL)
        printf("node not found\n");
    else{
            pnode->data=x;
   if(p==first)
   {
       pnode->prev=NULL;
       pnode->next=first;
       first->prev=pnode;
       first=pnode;
   }
   else
   {
       pnode->prev=p->prev;
       pnode->next=p;
       p->prev->next=pnode;
       p->prev=pnode;
   }
}
}
void insertaft(int x,int k)
{
    struct node *pnode,*p;
            pnode=(struct node*)malloc (sizeof(struct node));
    p=first;
    while(p!=NULL)
    {
        if(p->data==k)
            break;
        p=p->next;
    }
    if(p==NULL)
        printf("node not found\n");
    else
    {
        pnode->data=x;
        if(p==last)
        {
            pnode->next=NULL;
            pnode->prev=last;
            last->next=pnode;
            last=pnode;
        }
        else
        {
        pnode->prev=p;
        pnode->next=p->next;
        p->next->prev=pnode;
        p->next=pnode;
    }}
}

void deletenode(int k)
{
    struct node *p,*follow;
    p=first;
    //follow=NULL;
    while(p!=NULL)
    {
        if(p->data==k)
            break;
        //follow=p;
        p=p->next;
    }
    if(p==NULL)
        printf("Node not found\n");
    else
        {
            if(p==first&&p==last)
                first=last=NULL;
           else if(p==first)
            {
                first=first->next;
                first->prev=NULL;
            }
           else if(p==last)
            {
                last=last->prev;
                last->next=NULL;
            }
          else
          {
              p->prev->next=p->next;
              p->next->prev=p->prev;
          }
          free(p);
        }
}

void insertbeginning(int x)
{
    struct node *p,*pnode;
    pnode=(struct node*)malloc (sizeof(struct node));
    pnode->data=x;
    pnode->prev=NULL;
    pnode->next=first;
    first->prev=pnode;
    first=pnode;
}

void insertend(int x)
{
    struct node *pnode,*follow,*p;
    pnode=(struct node*)malloc (sizeof(struct node));
    pnode->data=x;
    pnode->next=NULL;
    pnode->prev=last;
    last->next=pnode;
    last=pnode;
}

void search(int k)
{
   struct node *p;
   p=first;
   while(p!=NULL)
   {
       if(p->data==k)
        break;
       p=p->next;
   }
   if(p==NULL)
    printf("Node not found\n");
   else
    printf("Node is found at
address %X\n",p);
}
void traverseright()
{
    struct node *p;
    if(first==NULL)
        printf("Link list empty\n");
    else
    {
        printf("Link list is shown as \n");
        p=first;
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
        }
    }
}
void traverseleft()
{
    struct node *p;
    if(last==NULL)
        printf("Link list empty\n");
    else
    {
        printf("Link list is shown as \n");
        p=last;
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->prev;
        }
    }
}

void count()
{
    int n=0;
    struct node *p;
    p=first;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    printf("Number of node is %d\n",n);
}

void destroylist()
{
    struct node *temp,*p;
    p=first;
    while(p!=NULL)
    {
        temp=p;
        p=p->next;
        free(temp);
    }
    first=last=NULL;
}
/*void reverse()
{
    struct node *p,*follow,*ahead;
    p=first;
    while(p!=NULL)
    {
        ahead=p->next;
        p->next=follow;
        follow=p;
        p=ahead;
    }
    first=follow;
}
*/
void main()
{
    int x,k,ch;
    do
    {
printf("\n*******MENU***********\n");
printf("1.create\n");
printf("2.insert before\n");
printf("3.insert after\n");
printf("4.delete node\n");
printf("5.insert beginning\n");
printf("6.insert end\n");
printf("7.traverse right\n");
printf("8.search\n");
printf("9.count\n");
printf("10.traverse left\n");
printf("11.destroy list\n");
printf("12.exit\n");
printf("Enter ur choice\n");
scanf("%d",&ch);

switch(ch)
{
case 1:
    create();
    break;

case 2:
    printf("enter data value of new node\n");
    scanf("%d",&x);
    printf("enter data value of node after which new node to be inserted\n");
    scanf("%d",&k);
    insertbef(x,k);
    break;

case 3:
    printf("enter data value of new node\n");
    scanf("%d",&x);
    printf("enter data value of node after which new node to be inserted\n");
    scanf("%d",&k);
    insertaft(x,k);
    break;

case 4:
    //printf("enter data value of new node\n");
    //scanf("%d",&x);
    printf("enter data value of node to be deleted\n");
    scanf("%d",&k);
    deletenode(k);
    break;

case 5:
    printf("enter data value of new node\n");
    scanf("%d",&x);
   // printf("enter data value of node after which new node to be inserted\n");
    //scanf("%d",&k);
    insertbeginning(x);
    break;

case 6:
    printf("enter data value of new node\n");
    scanf("%d",&x);
   // printf("enter data value of node after which new node to be inserted\n");
    //scanf("%d",&k);
    insertend(x);
    break;

case 7:
    traverseright();
    break;

case 8:
  //  printf("enter data value of new node\n");
   // scanf("%d",&x);
    printf("enter data value of node to be searched\n");
    scanf("%d",&k);
    search(k);
    break;

case 9:
    count();
    break;

case 10:
    traverseleft();
    break;

case 11:
    destroylist();
    break;

case 12:
    break;

}}
while(ch!=12);
    }



