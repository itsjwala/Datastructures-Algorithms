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
#define SIZE 10
typedef struct heap
{    int a[SIZE];
     int index;
}heap;
void insert(heap *p,int v)
{   int i;
	if(p->index==SIZE-1)
	    return ;
    for(i=++p->index;i>0&&(p->a[(i-1)/2]>v);i=(i-1)/2)
            p->a[i]=p->a[(i-1)/2];
      p->a[i]=v;
}
int delete(heap*p)
{   int v,t,i;
	if(p->index==-1)
         return -1;
    v=p->a[0];
    t=p->a[p->index--];
    for(i=1;i<=p->index;i=2*i+1)
    {  if((i+1)<=p->index&&p->a[i]>p->a[i+1])
    	   i++;
      if(p->a[i]<t)
    	 p->a[(i-1)/2]=p->a[i];
      else
    	  break;
    }
    p->a[(i-1)/2]=t;
    return v;
}
int main(void)
{  heap s;  int v;
	s.index=-1;
	insert(&s,10);
	insert(&s,7);
	insert(&s,30);
	insert(&s,20);
	insert(&s,5);
   while(s.index!=-1)
   {
	    v=delete(&s);
	    printf("%d\t",v);
   }
	return EXIT_SUCCESS;
}
