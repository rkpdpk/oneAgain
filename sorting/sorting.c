#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)  
{  
    int t =*a;  
    *a = *b;  
    *b = t;  
}

void selection(int arr[],int n)
{
    int i,j,m;
    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[m]<arr[j])
                m=j;
            swap(&arr[m],&arr[j]);
        }
    }
}

void bubble(int arr[], int n) 
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

void insertion(int arr[],int n)
{
    int i,p,j;
    for(i=1;i<5;i++)
    {
        arr[i]=p;
        for(j=i-1;j<)
    }
}

int main()
{
    int arr1[5]={3,1,5,4,2},i,j;
    //selection(arr1,5);
    //bubble(arr1,5);
    insertion(arr1,5);
    for(i=0;i<5;i++)
    {
        printf("%d ",arr1[i]);
    }
    return 0;
}