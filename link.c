#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert_frunt(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
        //printf("\t%d\n",newnode->next);
    } 
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void delete()
{
    struct node *temp,*temp1;
    if (head==NULL)
    {
        printf("empty\n");
    } 
    else
    {
        temp=head;  
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;            
        }
        temp1->next=NULL;
        free(temp);
    }
}
void f_delete()
{
    struct node *temp,*temp1;
    if (head==NULL)
    {
        printf("empty\n");
    } 
    else
    {
        temp=head;  
      /*   while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;            
        }*/
        head=head->next;
        
        //temp1->next=NULL;
        free(temp);
    }
}

void print()
{
    struct node *h=head;
    if(h==NULL)
    {
        printf("list is already empty\n");
    }
    else
    {
        while(h!=NULL)
        {
            printf("%d\t",h->data);
            h=h->next;
        }
        printf("\n");
    }
}

int main()
{
    insert_frunt(1);
    insert_frunt(2);
    insert_frunt(3);
    insert_frunt(4);
    insert_frunt(5);
    print();
    f_delete();
    print();
    return 0;
}