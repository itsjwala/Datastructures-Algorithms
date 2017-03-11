#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
typedef struct  brace
{     char brack;
	struct node*next;
}brace;
int isempty(brace *p)
{     if(p==NULL)
	      return 1;
      else
	      return 0;
}
void push(brace **p,char b)
{     brace *new;
       new=(brace *)malloc(sizeof(brace));
       if(new==NULL)
    	   return ;
       new->brack=b;
       new->next=(*p);   (*p)=new;
}
void pop(brace**p)
{     brace *temp;
	   temp=(*p);
	   (*p)=(*p)->next;
	  free(temp);
}
int check_equation(brace **stack,char *a)
{   int i;
     for(i=0;a[i];i++)
     {      if(a[i]=='{'||a[i]=='['||a[i]=='(')
    	        push(stack,a[i]);
             if(a[i]=='}'||a[i]==']'||a[i]==')')
             {      if(isempty(*stack))
            	         return 0;
                    else




             }
     }
}
void freespace(brace**p)
{   brace*temp;
	   while(*p!=NULL)
	   {   temp=*p;
		   *p=(*p)->next;
		   free(temp);
	   }
}
void main()
{    char eq[SIZE];  brace *last=NULL;
         printf("enter a equation:");
         gets(eq);
         if(check_equation(&last,eq))
            	printf("\nequation is balanced");
         else
        	 printf("\nequation is not balanced");

}
