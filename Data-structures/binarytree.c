/*
 ============================================================================
 Name        : binarytree.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{   int data;
	struct node*left,*right;
}tnode;
void insertbt(tnode**p,int v)
{   tnode *new=(tnode*)malloc(sizeof(tnode));
    tnode *temp,*prev;  int ch;
  	 new->data=v;  new->left=new->right=NULL;
	  if((*p)==NULL)
	    *p=new;
	    else
	    {    temp=(*p);
	          while(temp!=NULL)
	          {      prev=temp;
	        	     printf("\nenter 1.left   2.right of %d:",temp->data);
	        	      scanf("%d",&ch);
	        	      if(ch==1)
	        	    	  temp=temp->left;
	        	      else
	        	    	  temp=temp->right;
	          }
	          if(ch==1)
	        	  prev->left=new;
	          else
	        	  prev->right=new;
	    }
}
int inorder(tnode*p)
{    if(p==NULL)
     {
	   return 0;
     }
		else
		 {   int x=inorder(p->left);
			  printf("%d\t",p->data);
			 int y=inorder(p->right);
			 return(x+y+1);
		}
}
int  search(tnode*p,int v)
{  	 int x,y=0;
     if(p==NULL)
    	 return 0;
	if(p->data==v)
	     return 1;
      else
      {    x=search(p->left,v);
    	  if(x==0)
    	  y=search(p->right,v);
     	  else
    	    return 1;
    	   if(y==0)
    		   return 0;
    	   else
    		   return 1;
      }
}
int main(void)
{ tnode *root=NULL;//int count;
	insertbt(&root,10);
	insertbt(&root,5);
	insertbt(&root,6);
	 insertbt(&root,15);
	 insertbt(&root,45);
	 insertbt(&root,70);
	 insertbt(&root,50);
     inorder(root);
	 printf("\n%d",search(root,6));
	return EXIT_SUCCESS;
}
