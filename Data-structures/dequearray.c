#include<stdio.h>
#include<conio.h>
#define SIZE 150
typedef struct queue 
{  int a[SIZE];	
    int f,r,count;
}queue;
int isempty(const queue *p)
{	if(p->count==0)
	return 1;
     return 0;
}
int isfull(const queue *p)
{	if(p->count==SIZE)
	return 1;
     return 0;
}
int insertFirst(queue *p,int v)
{     if(isfull(p))
         return 0;
       p->f=(p->f+1)%SIZE;
       p->a[p->f]=v;
      p->count++; 
 	 return 1;
} 
int deleteFirst(queue*p)
{     
	    if(isempty(p))
	      return -1;
     if(p->f==-1)
        p->f=SIZE-1;	  
	  p->count--;
	 return p->a[p->f--];	  
}
int insertLast(queue *p,int v)
{      if(isfull(p))
         return 0;
      if(p->r==0) 
	   p->r=SIZE;
	 p->a[--p->r]=v;
	 p->count++;
	 return 1;
}
int deleteLast(queue*p)
{     int t;
    if(isempty(p))
	      return -1;
    if(p->r==SIZE)
	    p->r=0;
     t=p->a[p->r++];
       p->count--;
	 return t;         
}
void displayForward(const queue *p)
{    int i,n; 
    if(isempty(p))
     { printf("\nqueue is empty..");
        return ;
	 }
     n=p->count;  i=p->f;
	 while(n--)
	 {  if(i==-1) 
	      i=SIZE-1;
	    printf("%d\t",p->a[i--]);
	 }   
}
int main()
{  int i; 
   queue q={{0},-1,SIZE,0};
	insertLast(&q,10);
	insertLast(&q,20);
	insertFirst(&q,30);
	insertLast(&q,40);
	insertFirst(&q,50);
	insertLast(&q,60);
   /*while(q.count!=0)
    printf("%d\t",deleteLast(&q));
   */
     display(&q);
	 return 0;	
}                          
