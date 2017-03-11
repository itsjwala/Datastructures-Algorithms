#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{    int data;
    struct node*left,*right; 	 
}tnode;
int c=0;
void insert(tnode**p,int v)
{   if(*p==NULL)
   {  tnode*new=(tnode*)malloc(sizeof(tnode));
           new->data=v;  
            new->left=NULL; new->right=NULL;
            *p=new;   
   }
   else if((*p)->data>v)
       insert(&(*p)->left,v);
   else if((*p)->data<v)
	  insert(&(*p)->right,v);
}
int count(tnode*p)
{    if(p==NULL)
        return 0;
   	 else
   	 {  return (count(p->left)+count(p->right)+1);
     }
}
int deletebst(tnode**p,int v)
{
	 tnode *prev,*temp,*sucs;
  	   if(*p==NULL)
  		   return -1;
  	    temp=(*p);  prev=NULL;
       while(temp!=NULL)
  	   {
  		   if(temp->data==v)
  		         break;
  		     prev=temp;
  		   if(temp->data>v)
  			   temp=temp->left;
  		   else
  			   temp=temp->right;
  	   }
       if(temp==NULL)
    	   return 0;
       /*finding successor and replacing it with found data*/
        if(temp->left!=NULL&&temp->right!=NULL)
        {   prev=temp;    sucs=temp->right;
        	  while(sucs->left!=NULL)
        	 {     prev=sucs;
        		 sucs=sucs->left;
        	 }
              temp->data=sucs->data;
               temp=sucs;
        }/*for only one child or if root has only one child */
        else if((*p)==temp)
          {    if((*p)->left!=NULL)
                	   *p=(*p)->left;
                else
                    	*p=(*p)->right;
             free(temp);
              return 1;
          }
        /*deleting the succesor now*/
        if(temp->left==NULL&&temp->right==NULL)
        {   if(prev->left==temp)
        	     prev->left=NULL;
            else
              prev->right=NULL;
        }
        else if(temp->right==NULL&&temp->left!=NULL)
        {   if(prev->left==temp)
   	        prev->left=temp->left;
            else
            prev->right=temp->left;
        }
        else if(temp->left==NULL&&temp->right!=NULL)
        {    if(prev->left==temp)
        	    prev->left=temp->right;
             else
            	  prev->right=temp->right;
        }
        free(temp);
        return 1;
}
/*returns -1 if root is NULL otherwise returns max element*/
/*time complexity O(n)*/
int max_element(tnode*p)
{   if(p==NULL)
	  return -1;
	 while(p->right!=NULL)
	   p=p->right;
	   return p->data;
}
/*returns pointer to the node where element is found otherwise returns NULL*/
tnode*search(tnode*p,int v)
{     if(p==NULL||p->data==v)
           return p;     
	 else
	 {    tnode*x=search(p->left,v);
	          if(x!=NULL)
	   	    return x;
		     tnode*y= search(p->right,v);
	        if(y!=NULL)
	          return y;
	        return NULL;
	  }
}
void inorder(tnode*p)
{  
	if(p==NULL)
	return ;
	else
	{     inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
	}
}
int count_leaf(tnode*p)
{   
     if(p==NULL)
         return 0; 
     if(p->left==NULL&&p->right==NULL)
	           return 1;
	 else
	 return (count_leaf(p->left)+count_leaf(p->right));
}
int height(tnode*p)
{    
      if(p==NULL)
         return 0; 
      if(p->left==NULL&&p->right==NULL)
	        return 0;	
	  else
	  return (height(p->left)+height(p->right)+1);
     
}
/*returns 1 if complete b-tree otherwise 0*/
int iscomplete(tnode*p)
{   
	int h=height(p);
	int n=count(p);
	int i=0;
	while(n/=2)   //to calculate floor(log(n))
       i++;
	   if(i==h)
         return 1;
 	   return 0;   
}
int main()
{   tnode*root=NULL; int v,opt;
     while(1)
     {   printf("\n1.insert 2.height 3.leaf nodes 4.maximum  5.iscomplete B-tree  6.inorder 7.delete  8.exit:");
     	 scanf("%d",&opt);
     	 switch(opt)
     	 {  case 1:printf("\nenter value:");
     	           scanf("%d",&v);
		             insert(&root,v);
		             break;
		    case 2: printf("\nheigth=%d",height(root));
		            break;
		    case 3: printf("\nleaf nodes=%d",count_leaf(root));
		              break;
		    case 4: printf("\nmaximum=%d",max_element(root));
		             break;
		    case 5: if(iscomplete(root))
			         printf("\nYES");
					 else 
					 printf("\nNO");
					 break;
		   case 6:  inorder(root);
                     break;    		   
		   case 7:   printf("\nenter value to delete:");
		              scanf("%d",&v); 
		              if(!deletebst(&root,v))
		               printf("\nNo value found..");
		               else
		               printf("\ndeleted..");
		               break;
		   case 8:   break;
		   default : printf("\nInvalid choice..");          		        
		 }
     	if(opt==8)
     	  break;
	 }
	return 0;
}
