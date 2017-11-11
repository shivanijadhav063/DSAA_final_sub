#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MS 20
struct node
{
	char name[MS];
	struct node *next;
};
int stack()
{
	int ch;
	char n[MS];
	struct node *pnode,*top=NULL,*q;
	printf("\n............STACK.............\n");
	while(1)
	{
		printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pnode=malloc(sizeof(struct node));
				printf("\nEnter the name:\t");
				scanf("%s",&n);
				strcpy(pnode->name,n);
				pnode->next=top;
				top=pnode;
				break;
			case 2:
				if(top==NULL)
					printf("\nUNDERFLOW");
				else
				{
					printf("\nPoped element:");
					printf("\t%s",top->name);
					top=top->next;
				}
				break;
			case 3:
				q=top;
				if(q==NULL)
					printf("\nEmpty stack");
				else
				{
					printf("\nStack elements:");
					while(q!=NULL)
					{
						printf("\t%s",q->name);
						q=q->next;
					}
				}
				break;
			case 4:
				return(0);
			default:
				printf("\nWrong choice");
				break;
		}
	}
}
int queue()
{
	int ch;
	char n[MS];
	struct node *pnode,*front=NULL,*rear=NULL,*q;
	printf("\n............Queue.............");
	while(1)
	{
		printf("\n\t1.INSERTION\n\t2.DELETION\n\t3.DISPLAY\n\t4.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				pnode=malloc(sizeof(struct node));
				printf("\nEnter the name:\t");
				scanf("%s",&n);
				strcpy(pnode->name,n);
				pnode->next=NULL;
				if(front==NULL)
					front=rear=pnode;
				else
				{
					rear->next=pnode;
					rear=pnode;
				}
				break;
			case 2:
				q=front;
				if(front==NULL)
					printf("\nUNDERFLOW\n");
				else
				{
					printf("\nDeleted element::\t");
					printf("\t%s",front->name);
					front=front->next;
					free(q);
				}
				break;
			case 3:
				q=front;
				if(q==NULL)
					printf("\nEmpty Queue");
				else
				{
					printf("\nQueue elements::\t");
					while(q!=NULL)
					{
						printf("\t%s",q->name);
						q=q->next;
					}
				}
			       break;
			case 4:
				return(0);
			default:
				printf("\nWrong choice");
				break;
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n......................MAIN MENU.......................\n");
		printf("\n\t1.Stack\n\t2.Queue\n\t3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    stack();
			    break;
			case 2:
			    queue();
			    break;
			case 3:
			    exit(0);
			default:
			    printf("Invalid option");
			    break;
		}
	}
}

