#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;


void enqueue()
{
	struct node *temp=head,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		printf("\n No space available");
		return;
	}
	
	newnode->link=NULL;
	printf("\nEnter the element to insert: ");
	scanf("%d",&newnode->data);
	
	if(head==NULL)
	{
		head=newnode;
	}
	
	else
		{
			while(temp->link!=NULL)
		{
			temp=temp->link;
		}
			temp->link=newnode;
		}
	printf("\n %d element inserted successfully",newnode->data);
}


void display()
{
	struct node *temp=head;
	
	if(head==NULL)
	{
		printf("\n No elements");
		return;
	}
	
	printf("\n elements in queue are: ");
	
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->link;
	}
}


void dequeue()
{
	struct node *temp=head;
	
	if(head==NULL)
	{
		printf("\n No elements");
		return;
	}
	
	printf("\n %d element deleted successfully",temp->data);
	head=temp->link;
	free(temp);
}

void search()
{
	struct node *temp=head;
	int pos=0,key,found=0;
	
	if(head==NULL)
	{
		printf("\n No elements");
		return;
	}
	
	printf("\n Enter the element to search\n");
	scanf("%d",&key);
	
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			printf("\n %d elements found at %d \n",temp->data,pos+1);
			found=1;
		}
		temp=temp->link;
		pos++;
	}
	
	if(!found)
	{
	printf("\n elements not found");
	}
}

void main()
{
	int choice;
	printf("\nQueue\n");
	do{
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n5.Exit\n");
	printf("\nEnter the choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:enqueue();
		break;
		case 2:dequeue();
		break;
		case 3:display();
		break;
		case 4:search();
		break;
		case 5:printf("Exit");
		break;
		
	}
	}
	
	while(choice!=5);
	
}
