#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void swap(struct node *p,struct node *q)
{
    int temp;
    temp=p->data;
    p->data=q->data;
    q->data=temp;
}

void front(int val)
{
    count++;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }    
}

void last(int val)
{
    count++;
    struct node *newnode=(struct node*)malloc(sizeof(struct node)),*temp;
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        //head=newnode;
    }    
}

void reverse()
{
    int i=0,j=count-1,k;
    struct node *p,*q;
    p=q=head;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->next;
            k++;
        }
        swap(p,q);
        i++;j--;
        p=p->next;
        q=head;
    }
}

void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("empty\n");
    }
    else
    {
        printf("\n\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

void key_funtion(int key,int val)//,int limit)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node)),*temp,*temp1;
    //struct node *temp=(struct node*)malloc(sizeof(struct node)),*temp1=NULL;
    newnode->data=val;
    newnode->next=NULL;
    temp=head;
    //if(key>limit)
    
    if(key==0)
    {
        front(val);
    }
    else
    {
        while(temp->data!=key||temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->data==key)
        {
            temp1=temp->next;
            temp->next=newnode;
            newnode->next=temp1; 
        }
        else if(temp->next==NULL)
        {
            {
                printf("\nKey is not found\n");
            }
        }
    }
}

int main()
{
    int a,ele,ch,key_word,d;
    printf("enter the length of list\n");
    scanf("%d",&a);
    printf("1.frunt\n2.last\nenter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("enter an element\n");
            for(int i=0;i<a;i++)
            {
                scanf("%d",&ele);
                front(ele);
            }break;
    case 2:
            printf("enter an element\n");
            for(int i=0;i<a;i++)
            {
                scanf("%d",&ele);
                last(ele);
            }break;
    }
    display();
    //reverse();
    //display();
    printf("enter key and data\n");
    scanf("%d%d",&key_word,&d);
    key_funtion(key_word,d);//,a);
    display();
    return 0;
}
