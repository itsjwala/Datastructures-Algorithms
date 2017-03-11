/*
 ============================================================================
 Name        : queuearray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef struct queue
{
	 int a[SIZE];
	 int front,rear;
}queue;
int isempty(queue *p)
{   if(p->front==p->rear)
	return 1;
    else
      return 0;
}
void insert(queue *p,int val)
{     if((p->rear+1)%SIZE==p->front)
	      return ;
	 else
	 {  p->rear=(p->rear+1)%SIZE;
		 p->a[p->rear]=val;
	 }
}
int delete(queue*p)
{
	  if(isempty(p))
		  return -1;
	  else
		  {   p->front=(p->front+1)%SIZE;
		    return p->a[p->front];
		  }
}
void display(queue *p)
{      int i;
	for( i=(p->front+1);i!=(p->rear+1);i=(i+1)%SIZE)
           printf("%d\t",p->a[i]);
}
int main(void)
{   queue q;
  q.front=q.rear=0;
  insert(&q,10);
  insert(&q,20);
  insert(&q,30);
  printf("\n");
  display(&q);
  printf("%d\t",delete(&q));
  printf("%d\t",delete(&q));
  //printf("%d\t",delete(&q));
  printf("\n");
  insert(&q,40);
  insert(&q,50);
  insert(&q,60);
  insert(&q,70);
  printf("%d\t",delete(&q));
  printf("%d\t",delete(&q));
  printf("%d\t",delete(&q));
  printf("%d\t",delete(&q));
  printf("%d\t",delete(&q));
  printf("\n");
 	return EXIT_SUCCESS;
}
