#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int top=-1;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int is_empty()
{
    if(top==-1)
        return 0;
    return 1;
}
int is_full()
{
    if(top==SIZE-1)
        return 1;
    return 0;
}
void push(int val)
{
    top++;
    //printf("%d\n\n",top);
    struct node *new_node=(struct node*)malloc(sizeof(struct node)),*temp;
    new_node->data=val;
    new_node->next=NULL;
    if(is_full())
    {
        printf("\noverflow\n");
    }
    else
    {
        
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
            temp=new_node;
        }
    }
}

void pop()
{
    struct node *temp;
    if(is_empty())
    {
        return;
    }
    else
    {
        if(head==NULL)
        {
            temp=head;
            top--;
            free(temp);
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            top--;
            free(temp);
        }
    }
}

void display()
{
    struct node *temp;
    if(top==-1)
    {
        printf("\nunderflow\n");
    }
    else
    {
        temp=head;
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int ch,n,ele;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.peek\nexit\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1  :   printf("\nEnter number of element to pushed\n");
                        scanf("%d",&n);
                        printf("enter your elements\n");
                        for(int i=0;i<n;i++)
                        {
                            scanf("%d",&ele);
                            push(ele);
                        }
                        break;
            case 2  :   pop();
                        break;
            case 3  :   display();
                        break;
            //case 4  :   peek();
                       // break;
            case 5  :   exit(0);
                        break;
            default :   printf("\nenter vailed choice\n");
        }
    }
    return 0;
}