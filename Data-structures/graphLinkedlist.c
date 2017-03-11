/****requires graphLinkedlist-adjlist.txt &  graphLinkedlist-source_destination.txt  **********/
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
typedef struct station
{    char name[SIZE];
	 struct node *adjlist;
}station;
typedef struct node
{    int vertexnum;
    struct node *next;
}node;
int findIndex(const station*v,const char *c,int n)
{     int i;
	for(i=0;i<n;i++)
	     if(strcmpi(v[i].name,c)==0)
		    return i;
	return -1;
}
void addEdge(station *v,const char *a,const char *b,int n)//,int directedflag)
{    int i,j;  node *new;
   i=findIndex(v,a,n);
	j=findIndex(v,b,n);
	if(i==-1||j==-1)
	  return;
	new=(node*)malloc(sizeof(node));
	new->vertexnum=j; new->next=NULL;
	if(v[i].adjlist==NULL)
	 v[i].adjlist=new;
	 else
	 {  node*temp=v[i].adjlist,*prev=NULL;
	    while(temp!=NULL&&temp->vertexnum<j)
	      {  prev=temp;
		temp=temp->next;
	       }
	       if(prev==NULL)
		  {   new->next=v[i].adjlist;
		    v[i].adjlist=new;
		  }
		 else
		  {  new->next=prev->next;
		     prev->next=new;
		  }
	 }
}
station *createGraph(int *n)
{   int i;  station *v;
 char temp[SIZE],temp1[SIZE],ch;
 FILE *fp=fopen("graphLinkedlist-adjlist","r");
  if(fp==NULL)
  {
    printf("\nUnable to list file..");
    exit(-1);
  }
  //printf("\nenter number of stations:");
      fscanf(fp,"%d",n);
   v=(station*)malloc(sizeof(station)*(*n));
     //printf("\nEnter Station names..");
     for(i=0;i<(*n);i++)
      {  //printf("\nStation %d)",i+1);
	   fscanf(fp,"%s",temp);
	 strcpy(v[i].name,temp);
	  v[i].adjlist=NULL;
      }
	  while(!feof(fp))
	   { //printf("\nEnter 2 station separated by space(" ")");
	     fscanf(fp,"%s%s",temp,temp1);
	    // printf("\nadded %s and %s",temp,temp1);
	    addEdge(v,temp,temp1,(*n));
	     //printf("\nAdd more Edge [Y/n]:");
	     //scanf(" %c",&ch);
	  }//while(ch=='Y'||ch=='y');
	  fclose(fp);
	  return v;
}
int dfs(const station *v,int s,int d,int visited[],int *path)
{  int flag=0;
  visited[s]=1;  *path=s;
    if(s!=d)
	{   node*temp=v[s].adjlist;
		while(temp!=NULL)
		   {   if(!visited[temp->vertexnum])
		        flag=dfs(v,temp->vertexnum,d,visited,path+1); 
			  temp=temp->next;
		   }

     }
     else if(s==d)
      return 1;
    if(!flag)
	  *path=-1; 
      return flag;
}
void findPath(station*v,const char *sou,const char *dest,int n)
{  int *visited,*path,s,d,i;
    s=findIndex(v,sou,n);
    d=findIndex(v,dest,n);
    if(s==-1||d==-1)
      return;
  visited=(int*)calloc(n,sizeof(int));
  path=(int *)malloc(sizeof(int)*2*n);
    for(i=0;i<2*n;i++)
       path[i]=-1;
	 dfs(v,s,d,visited,path);
      free(visited);
	printf("\nPATH:\n");
	 for(i=0;i<2*n&&path[i]!=d&&path[i]!=-1;i++)
	  {  printf("%s->",v[path[i]].name);
	  }
	  if(path[0]!=-1)
	  printf("%s",v[d].name);
	  else
	   printf("\nNo path found");
	 free(path);
}
void freespace(station*v,int n)
{     node*temp;  int i;
	for(i=0;i<n;i++)
	   while(v[i].adjlist!=NULL)
	     { temp=v[i].adjlist;
		  v[i].adjlist=v[i].adjlist->next;
		  free(temp);
	      }
	free(v);
}
int main()
{    station *v; char source[SIZE],destination[SIZE];
   int n;  FILE*fp;
  // clrscr();
     v=createGraph(&n);
     fp=fopen("graphLinkedlist-source_destination.txt","r");
     if(fp==NULL)
      {   printf("\nUnable to open source and destination file..");
      	   freespace(v,n);
      	    exit(-1);
	  }
     
	 //printf("\nEnter source:");
      // fflush(stdin);
       fscanf(fp,"%s",source);
       //printf("\nEnter destination:");
       fscanf(fp,"%s",destination);
       fclose(fp);
     findPath(v,source,destination,n);
	  freespace(v,n);
	 // getch();
	return 0;
}
