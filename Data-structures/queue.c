/*
 ============================================================================
 Name        : queue.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{    int data;
	struct node *next;
}node;
typedef struct queue
{
	node *front ,*rear;
}queue;
int isempty(queue*p)
{    if(p->front==NULL)
	   return 1;
     else
	  return 0;
}
void insert(queue*p,int val)
{   node*new;
    new=(node*)malloc(sizeof(node));
   if(new==NULL)
	   return ;
    new->data=val;   new->next=NULL;
    if(p->rear==NULL)
    {
    	p->front=p->rear=new;
    }
    else
    {  p->rear->next=new;
       p->rear=new;
    }
}
int delete(queue*p)
{   int t;  node*temp;
	if(isempty(p))
	    return -1;
     t=p->front->data;
     temp=p->front;
     p->front=temp->next;
     if(p->front==NULL)
    	 p->rear=NULL;
     free(temp);
     return t;
}
int main(void)
{    queue q;
  q.front=NULL;   q.rear=NULL;
		insert(&q,5);
		insert(&q,20);
		insert(&q,30);
		insert(&q,40);
		insert(&q,50);
		while(q.front!=NULL)
	    printf("%d\t",delete(&q));
	return EXIT_SUCCESS;
}
