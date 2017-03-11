/*
 ============================================================================
 Name        : graphs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define STACK_SIZE
typedef struct node
{   char data;
	struct node*next;
}node;/*
void createGraph(node**p,int direc)
{  int ch;  node*temp,*new;
	char x,y;
	do
	{  new=(node*)malloc(sizeof(node)*SIZE);
		printf("\nEnter edges:");
	   scanf("%c",&x);scanf("%c",&y);
	   x=toupper(x);  y=toupper(y);
	   new->data=y;  new->next=NULL;
	    	temp=p[x];
	    while(temp->next)
	    	 temp=temp->next;
	    temp->next=new;
	    if(!direc)
	    {
	    	//


	    }
	    printf("\n1.Continue  2.Exit:");
	    scanf("%d",&ch);
	}while(ch==1);
}*/
void createGraph(int a[][SIZE],int directed)
{   int ch;  char x,y;

    do
    {  	printf("\nEnter edges:");
	   scanf(" %c",&x);scanf(" %c",&y);
	   x=toupper(x);  y=toupper(y);
	   a[x-65][y-65]=1;
	   if(!directed)
	     a[y-65][x-65]=1;
	   printf("\n1.Continue  2.Exit:");
	  	    scanf("%d",&ch);
    }while(ch==1);
}
void dfs(int a[][SIZE],int visited[],int start)
{   int st[STACK_SIZE][2]={{0}}; int top=-1;
	 int i;
	 printf("%c\t",start+65);
	 visited[start]=1;
	 st[++top][0]=start;
	 st[top][1]=0;
	while(top!=-1)
	{	 start=st[top][0];
	  for(i=st[top][1];i<SIZE;i++)
		{
			 if(a[start][i]&&!visited[i])
			 {   st[top][1]=i;
				 st[++top][0]=i;
				  st[top][1]=0;
				 visited[i]=1;
				 printf("%c\t",i+65);
				 break;
			 }

		}
	     if(i==SIZE)
	    	 top--;
	 }
}
void bfs(int a[][SIZE],int start)
{     int Q[SIZE]={0},rear=-1,front=-1;
   int visited[SIZE]={0},i;
     printf("%c\t",start+65);
     visited[start]=1;
     Q[++rear]=start;
     while(rear!=front)
     {     start=Q[++front];
    	    for(i=0;i<SIZE;i++)
    	    {   if(a[start][i]&&!visited[i])
    	    	  { Q[++rear]=i;
    	           visited[i]=1;
    	           printf("%c\t",i+65);

    	    	  }

    	    }
      }
}
int main(void)
{   int visited[SIZE]={0};
int a[SIZE][SIZE]={{0}};
    createGraph(a,1);
   dfs(a,visited,0);
   bfs(a,0);
   return EXIT_SUCCESS;
}
