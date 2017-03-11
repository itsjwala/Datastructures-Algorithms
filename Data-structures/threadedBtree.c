/*
 ============================================================================
 Name        : threadedBtree.c
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
	  int data,leftf,rightf;
	  struct node *left,*right;
}node;
void insertBtree(node**p,int v)
{    node *new=(node*)malloc(sizeof(node)); node *temp;
	 new->leftf=new->rightf=0;  new->data=v;
	 if(*p==NULL)
	 {    *p=new;
		  new->left=new->right=NULL;
	 }
	 else
	 {     temp=(*p);
	       while(1)
		    { //temp=temp;
			   if(temp->data<v&&temp->rightf)
		       temp=temp->right;
		       else if(temp->data>v&&temp->leftf)
		           temp=temp->left;
		       else
		    	   break;
		    }
	       if(temp->data<v)
	       {    new->right=temp->right;
	    	    temp->right=new;
	    	   temp->rightf=1;
	    	   new->left=temp;
	       }
	       else
	       {     new->left=temp->left;
	    	     temp->left=new;
	    	    temp->leftf=1;
	    	     new->right=temp;
	       }
	 }
}
void inorder(node*p)
{
	if(p==NULL)
	      return ;
	while(1)
	{	while(p->leftf)
		   p=p->left;
      printf("%d\t",p->data);
       while(!p->rightf)
       {    p=p->right;
            if(p==NULL)
        	  return ;
    	     printf("%d\t",p->data);
       }
       p=p->right;
	}
}
int main(void)
{  node*root=NULL;
	 insertBtree(&root,15);
	 insertBtree(&root,10);
	insertBtree(&root,20);
	insertBtree(&root,18);
	insertBtree(&root,9);
	insertBtree(&root,5);
    inorder(root);
    return EXIT_SUCCESS;
}
