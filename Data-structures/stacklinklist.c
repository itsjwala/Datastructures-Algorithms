/*
 ============================================================================
 Name        : stacklinklist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{    char ch;
	  struct  stack *next;

}stack;
void push(stack**p,char ch)
{    stack *new,*temp;
	   new=(stack*)malloc(sizeof(stack));
	    if(new==NULL)
	    	return ;
	    new->ch=ch;
         new->next=*p;
	           *p=new;

}
int isempty(stack *p)
{   if(p==NULL)
      return 1;
   else
	   return 0;
}
void pop(stack**p)
{    stack* temp=*p;
	   (*p)=(*p)->next;
	  free(temp);
}
int main(void)
{    stack *top=NULL;
	char ch;  int flag=1;
	 while((ch=getchar())!='\n')
	 {
		 if(ch=='(')
            push(&top,ch);
		 else if(ch==')')
		 {	 if(!isempty(top))
	      	 	   pop(&top);
		    else
		    { flag=0;
		       break;
		    }
		 }
	 }
	 if(isempty(top)&&flag)
           printf("balanced");
	 else
		 printf("unbalanced");
	return EXIT_SUCCESS;
}
