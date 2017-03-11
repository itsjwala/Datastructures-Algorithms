/*
 ============================================================================
 Name        : j.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
    int prio;
}node;
typedef struct queue
{
  node *rear,*front;
}queue;
int isempty(const queue*p)
{   if(p->rear==NULL&&p->front==NULL)
	   return 1;
        return 0;
}/*
void enqueue(queue*p,int v)
{    node *new=(node*)malloc(sizeof(node));
	  if(new==NULL)
	   return ;
	  new->data=v;
	   new->next=NULL;
	   if(p->rear==NULL&&p->front==NULL)
             p->rear=p->front=new;
	   else
	   {
	       p->rear->next=new;
	         p->rear=new;
	   }
}*/
int dequeue(queue*p)
{     int t;   node*temp;
	 if(isempty(p))
	     return -1;
	 t=p->front->data;  temp=p->front;
	  p->front=p->front->next;
          if(p->front==NULL)
        	   p->rear=NULL;
        free(temp);
        return t;
}
void display(const queue*p)
{   node*temp;
   if(isempty(p))
    {
	   printf("\nqueue is empty");
       return ;
    }
    else
    {
    	for(temp=p->front;temp!=NULL;temp=temp->next)
    		printf("%d\t",temp->data);
    }
}
void ascprio(queue*p,int v,int prio)
{   node  *prev,*temp,*new=(node*)malloc(sizeof(node));
	if(new==NULL)
		return ;
	new->data=v;
	new->prio=prio;
	new->next=NULL;
    if(isempty(p))
     {
	     p->front=p->rear=new;
	       return ;
     }
	temp=p->front;
	prev=NULL;
	while(temp!=NULL)
	{   if(prio<temp->prio)
		   break;
	    else
		{  prev=temp;
		  temp=temp->next;
		}
	}
	if(prev==NULL)
	 {	new->next=p->front;
	     p->front=new;
	 }
	else
	{   new->next=prev->next;
		 prev->next=new;
	    if(new->next==NULL)
		  p->rear=p->rear->next;
	}
}
void descprio(queue*p,int v,int prio)
{   node  *prev,*temp,*new=(node*)malloc(sizeof(node));
	if(new==NULL)
		return ;
	new->data=v;
	new->prio=prio;
	new->next=NULL;
    if(isempty(p))
     {
	     p->front=p->rear=new;
	       return ;
     }
	temp=p->front;
	prev=NULL;
	while(temp!=NULL)
	{   if(prio>temp->prio)
		   break;
	    else
		{  prev=temp;
		  temp=temp->next;
		}
	}
	if(prev==NULL)
	 {	new->next=p->front;
	     p->front=new;
	 }
	else
	{   new->next=prev->next;
		 prev->next=new;
	    if(new->next==NULL)
		  p->rear=p->rear->next;
	}
}

int main(void)
{     queue q; q.rear=q.front=NULL;
      descprio(&q,10,5);
      descprio(&q,20,4);
      descprio(&q,30,3);
      descprio(&q,40,6);
      descprio(&q,50,1);
      descprio(&q,60,10);
     display(&q);
	 printf("\n");
	return EXIT_SUCCESS;
}
