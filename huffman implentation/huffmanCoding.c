#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define HEAP_SIZE 20
#define STACK_SIZE 50
#define STRING_SIZE 50
#define FREQMAPSIZE (int)130
char str[127][127]={{0}};
/*tree node*/
typedef struct tnode
{   char l;
  unsigned	int freq;
	struct tnode*left,*right;
}tnode;
/*priority queue using array/ minheap*/
typedef struct heap
{    tnode *a[HEAP_SIZE];
     int index;  //indication number of nodes in minheap <SIZE
}heap;
/*stack of tnode pointers*/
typedef struct stack
{    tnode*a[STACK_SIZE];
	  int top;
}stack;
tnode* newNode(char data, unsigned freq)
{
     tnode* new =
          (tnode*) malloc(sizeof( tnode));
    new->left = new->right = NULL;
    new->l = data;
    new->freq = freq;
    return new;
}
/*convert string into frequecy map */
void toFreqMap(const char *in,char *map)
{  int i;
	   for(i=0;in[i];i++)           
	     map[in[i]]++;
}
/*creating minheap of available single characters from input string*/
void createMinHeap(heap*p,char *map)
{    int i;  
    for(i=1;i<FREQMAPSIZE;i++)  /*******JAVA CHARCTERS 2 bytes(check)******/
      {   if(map[i]==0)
      	     continue;
      	     printf("%c-%d\n",i,map[i]);
      	  minHeapInsert(p,newNode(i,map[i]));
	  }
}
/*insertion in priority queue based on frequency*/
int minHeapInsert(heap*p,tnode*t)
{   int i;
	 if(p->index==HEAP_SIZE-1)
	     return 0;
	 for(i=++p->index;i>0&&(p->a[(i-1)/2]->freq>t->freq);i=(i-1)/2)
		    p->a[i]=p->a[(i-1)/2];
	  p->a[i]=t;
      return 1;
}
/*dequeuing minimum frequency node from priority queue*/
tnode* minHeapDelete(heap*p)
{   int i;  tnode*t,*min;
	if(p->index==-1)
         return NULL;
    min=p->a[0];
    t=p->a[p->index--];  p->a[p->index+1]=NULL;
    for(i=1;i<=p->index;i=2*i+1)
    {  if((i+1)<=p->index&&(p->a[i]->freq)>(p->a[i+1]->freq))
    	   i++;
      if(p->a[i]->freq<t->freq)
    	 p->a[(i-1)/2]=p->a[i];
      else
    	  break;
    }
    p->a[(i-1)/2]=t;
    return min;
}
tnode* createHuffmanTree(const char *in)
{      tnode*root,*left,*right;  char map[FREQMAPSIZE]={0};    /*******JAVA CHARCTERS 2 bytes(check)******/
       heap s={{NULL},-1};
	    //*****conversion of input string into frequency map, function call goes here,!!******
	    toFreqMap(in,map);
		createMinHeap(&s,map);  //see definition
	    if(s.index==0)
	      return  s.a[s.index];  //if in input string only 1 character th'out
		   //root=NULL;
	  /*loop until there's only one node in heap and build huffman tree*/
	   while(s.index>0)
	   {      left=minHeapDelete(&s);  //dequeue in priority queue
                right=minHeapDelete(&s);      	   	 
 	   	  root=newNode('`',left->freq+right->freq); //internal nodes chararter is '`' and leaf nodes are corresponding chararcter
			  root->left=left;  root->right=right;
	         minHeapInsert(&s,root);  //enqueue  in priority queue
	   }
	   return root;  //returns root of huffman tree
}
void charToCode(tnode*p,char*t,int top)
{    if(p->left)
     {    t[top]='0';
     	 charToCode(p->left,t,top+1);
	 }
	if(p->right)
     {    t[top]='1';
     	 charToCode(p->right,t,top+1);
	 }
	else
	{     t[top]=0;
            printf("\n%c-%s",p->l,t); 
	}
	
}
int main(void)
{     char string[STRING_SIZE]={0};    
char temp[FREQMAPSIZE]={0};//for storing bitsequence
   FILE *fp=fopen("test.txt","r");
      //printf("Enter a string:");
    //scanf("%[^\n]s",string);
	 fgets(string,STRING_SIZE-1,fp);
	 printf("string is:%s\n",string);
     //string[strlen(string)-1]=0;
	 charToCode(createHuffmanTree(string),temp,0);
  fclose(fp);
return EXIT_SUCCESS;
}
