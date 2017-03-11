/*
 ============================================================================
 Name        : musical.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include<conio.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
	 char name[10];
	   struct node *next;
}node;
/*add new player*/
/*time complexity O(n)*/
void add(node**p,char *a)
{       node*new;
	  new=(node*)malloc(sizeof(node));
	  strcpy(new->name,a);   new->next=NULL;
      if(*p==NULL)
      {     *p=new;   new->next=new;  }
      else
      {
     	  new->next=(*p)->next;
    	  (*p)->next=new;
    	  *p=new;
      }
}
/*select random player */
/*returns pointer to the node of the player*/
/*time complexity O(rand())*/
node* random_select(node*temp)
{     int i,n=rand();
      for(i=0;i<=n;i++)
	      temp=temp->next;

      return temp;
}
/*deletes the player */
/*time complexity O(n)*/
void delete(node**p,node*out)
{      node*prev=out;
	  while(prev->next!=out)
	     prev=prev->next;
	   prev->next=out->next;
	   if(out==*p)
		   *p=prev;
	   free(out);
}
/* for increasing time of game*/
void delay(void)
{        int i;
	 for(i=1;i<=1000000000;i++);
}
int main(void)
{   node*last=NULL,*out=NULL;    char name[10];  int n,i;
      do
      {  printf("\nenter number of players:");
       scanf("%d",&n);
       if(n<=1)
       printf("\nenter atleast 2 players\n");
      }while(n<=1);
       printf("\nenter name of %d players\n",n);
        for(i=1;i<=n;i++)
         {   printf("\nplayer %d:",i);
              scanf("%s",name);
        	  add(&last,name);
         }
        printf("beginning the game..\n");
         for(i=1;i<n;i++)
         {    delay();
        	  out=random_select(last);
        	 printf("\n%s  out of the game..\n",out->name);
        	      delete(&last,out);
         }

         printf("\nwinner:%s",last->name);
              free(last);
              getch();
     	return EXIT_SUCCESS;
}
