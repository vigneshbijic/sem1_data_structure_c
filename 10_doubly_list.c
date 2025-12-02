#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *head=NULL;
void insertfirst()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n No Space available");
        return;
    }
    newnode->llink=NULL;
    newnode->rlink=NULL;
    printf("\nEnter the value to insert to front: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
    printf("\nElement inserted %d",newnode->data);
}


void insertlast()
{
    struct node *newnode,*temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n No Space available");
        return;
    }
    newnode->llink=NULL;
    newnode->rlink=NULL;
    printf("\nEnter the value to insert to last: ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
        newnode->llink=temp;
        temp->rlink=newnode;
    }
    printf("\nElement inserted  successfully %d",newnode->data);
}



void insertlocation()
{
    int key;
    struct node *newnode,*temp=head,*next;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n No Space available");
        return;
    }
    if(head==NULL)
    {
        printf("\nlist is empty");
    }
    else{
        printf("Enter the key where after you want to add element: ");
        scanf("%d",&key);
        while(temp->data!=key && temp!=NULL)
        {
            temp=temp->rlink;
        }
    }
    if(temp==NULL)
    {
        printf("\nvalue not exist");
    }
    else{
        printf("\nEnter the element to inserted: ");
        scanf("%d",&newnode->data);
        if(temp->rlink==NULL)
        {
            newnode->llink=temp;
            newnode->rlink=NULL;
            temp->rlink=newnode;
        }
        else{
            next=temp->rlink;
            newnode->llink=temp;
            newnode->rlink=next;
            temp->rlink=newnode;
            next->llink=newnode;
        }
        printf("\nvalue inserted successfullt %d", newnode->data);
    }
}



void deletefirst()
{
    struct node *temp=head,*next;
    if(head==NULL)
    {
        printf("\nlist Empty");
        return;
    }
    printf("\nValue deleted %d\n",temp->data);
    if(temp->rlink==NULL)
    {
        head=NULL;
    }
    else{
        next=temp->rlink;
        head=next;
        next->llink=NULL;
    }
    free(temp);
}



void deletelast()
{
    if(head==NULL)
    {
        printf("\nlist Empty");
        return;
    }
    struct node *temp=head,*next;
    if(temp->rlink==NULL)
    {
        printf("\n Value %d deleted ",temp->data);
        head=NULL;
    }
    else
    {
        while(temp->rlink!=NULL){
            temp=temp->rlink;
        }
        printf("value %d deleted",temp->data);
        next=temp->llink;
        next->rlink=NULL;
    }
    free(temp);
}




void deletelocation()
{
    int key;
    struct node *temp=head, *next,*prev;
    if(head==NULL)
    {
        printf("\nlist Empty");
        return;
    }
    printf("\nEnter the key which you want to delete element: ");
    scanf("%d",&key);
    while(temp!=NULL &&temp->data!=key)
    {
        temp=temp->rlink;
    }
    if(temp==NULL)
    {
        printf("\nValue not Exsist\n");
        return;
    }
    if(temp->llink==NULL)
    {
        head=temp->rlink;
        if(head!=NULL){
            head->llink=NULL;
        }
    }
    else if(temp->rlink==NULL)
    {
        temp->llink->rlink=NULL;
    }
    else{
        prev=temp->llink;
        next=temp->rlink;
        prev->rlink=next;
        next->llink=prev;
    }
    printf("value %d is deleted",temp->data);
    free(temp);
}


void search()
{
    struct node *temp=head;
    int pos=0,found=0,val;
    if(head==NULL)
    {
        printf("\nlist Empty");
        return;
    }
    printf("\nEnter the value to search: ");
    scanf("%d",&val);
    while(temp!=NULL){
        if(temp->data==val)
        {
            printf("\n%d value found at %d location\n",temp->data,pos+1);
            found=1;
        }
        pos++;
        temp=temp->rlink;
    }
    if(!found)
    {
        printf("value %d not Exsist",val);
    }
}



void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\n Empty list");
        return;
    }
    else{
        printf("\nElements in the list\n");
        while(temp!=NULL)
        {
            printf(" %d ",temp->data);
            temp=temp->rlink;
        }
    }
}

void main()
{
    int choice;
    printf("\nDoubly linked list\n");
    do{
        printf("\n1.InsertFirst\n2.InsertLast\n3.InsertLocation\n4.DeleteFirst\n5.DeleteLast\n6.DeleteLocation \n7.Display\n8.Search\n9.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertfirst();
            break;
            case 2:insertlast();
            break;
            case 3:insertlocation();
            break;
            case 4:deletefirst();
            break;
            case 5:deletelast();
            break;
            case 6:deletelocation();
            break;
            case 7:display();
            break;
            case 8:search();
            break;
            case 9:printf("\nExiting");
            exit(0);
            default:printf("\n Invalid Choice");
            break;
        }
    }while(choice!=9);
}
