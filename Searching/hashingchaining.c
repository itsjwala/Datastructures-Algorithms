/*
 ============================================================================
 Name        : hashingchaining.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node
{
	  int data;
	 struct node*next;
}node;
int hash(int v)
{
     return v%SIZE;
}
void insertOrder(node**p,int v)
{    node *new=(node*)malloc(sizeof(node));
  new->data=v;  new->next=NULL;
    if(*p==NULL)
    	*p=new;
    else
    {  node*temp=(*p),*prev=NULL;
       while(temp!=NULL&&temp->data<v)
    	   {  prev=temp;
    	    temp=temp->next;
    	   }
       if(temp==(*p))
       {   new->next=(*p);
    	   *p=new;
       }
       else
       {    new->next=prev->next;
          prev->next=new;
	   }
    }
}
void add(node**a,int v)
{   int i=hash(v);
   insertOrder(&a[i],v);
}
int search(node*a[],int v)
{     int i=hash(v);
    node*temp=a[i];
     while(temp!=NULL&&v>temp->data)
        temp=temp->next;
     if(temp!=NULL&&temp->data==v)
    	 return 1;
     return 0;
}
int main(void)
{  node *a[SIZE]={NULL};
    add(a,85);
	add(a,25);
	add(a,45);
	add(a,27);
	add(a,35);
	add(a,15);
	add(a,11);
	add(a,55);
	add(a,28);
printf("\nfound :%d",search(a,28));
	return EXIT_SUCCESS;
}
