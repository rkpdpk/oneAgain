#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;

void frunt(int val)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node)),*temp;
    new_node->data=val;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;
        head=new_node;
        new_node->next=temp;
        temp->prev=new_node;
    }
}

void last(int val)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node)),*temp,*temp1;
    new_node->data=val;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
} 

void delete()
{
    struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp=temp->prev;
        temp->next=NULL;
    }
}

void display()
{
    struct node *temp,*temp1;
    temp=head;
    if(head==NULL)
    {
        printf("\nempty\n");
    }
    else
    {
        printf("\ndoubly link_list in forward\n");
        while(temp!=NULL)
        {
            temp1=temp;
            printf("%d\t->\t",temp1->data);
            temp=temp->next;
        }
        printf("null\n\ndoubly link_list in backward\n");
        while(temp1!=NULL)
        {
            printf("%d\t->\t",temp1->data);
            temp1=temp1->prev;
        }
        printf("null\n");
    }
}

int main()
{
    int a,ele;
    printf("enter the length of list\n");
    scanf("%d",&a);
    printf("enter an element\n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ele);
        last(ele);
    }
    display();
    delete();
    display();
    return 0;
}