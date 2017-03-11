/*
 ============================================================================
 Name        : treestack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef  struct node
{
	int data;
	 struct node *left,*right;
}tnode;
typedef struct stack
{     tnode*a[SIZE];
	int top;
}stack;
void insertbst(tnode **p,int v)
{   if(*p==NULL)
    {
	    tnode *node=(tnode*)malloc(sizeof(tnode));
	   node->data=v;
	    node->left=NULL;
	    node->right=NULL;
	    *p=node;
    }
  else  if((*p)->data<v)
    insertbst(&(*p)->right,v);
  else
	  insertbst(&(*p)->left,v);
}
int preorder(tnode*p)
{     stack s={{NULL},-1};
	  if(p==NULL)
		  return 0;
      while(1)
      {       while(p!=NULL)
           {     printf("%d\t",p->data);
               s.a[++s.top]=p;
               p=p->left;
           }
            if(s.top!=-1)
            {   p=s.a[s.top--];
            	p=p->right;
            }
            else
            	break;
      }
}
int main(void) {

	return EXIT_SUCCESS;
}
