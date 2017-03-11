#include<stdio.h>
#include<stdlib.h>
int merge(int a[],int lbeg,int lend,int rbeg,int rend)
{    int *temp=calloc(rend-lbeg+1,sizeof(int)),i;
	  int mid=rbeg,invcount=0;
	  for(i=0;;)
	  {
	  	  if(a[lbeg]<=a[rbeg])
	  	   temp[i++]=a[lbeg++];
	  	   else
	  	     {  temp[i++]=a[rbeg++];
	  	         invcount+=(mid-lbeg);
			  }
		if(lbeg>lend||rbeg>rend)
			   break; 
	  }	
	  while(lbeg<=lend)
	   temp[i++]=a[lbeg++];
	   while(rbeg<=rend)
	    temp[i++]=a[rbeg++];
	   for(i--;i>=0;)
	     a[rend--]=temp[i--];
	     	free(temp);
    return invcount;
}
int mergesort(int a[],int low ,int high)
{  int mid,inv=0;
  if(low>=high)
    return 0;
	mid=(low+high)/2;
	 inv=mergesort(a,low,mid);
	 inv+=mergesort(a,mid+1,high);
	 inv+=merge(a,low,mid,mid+1,high);
   return inv;	
}
int main()
{    int a[]={1,20,6,4,5},i;
	int  inv=mergesort(a,0,5-1);
	for(i=0;i<5;i++)
	 printf("%d\t",a[i]);
	printf("\ninversion count=%d",inv);
	return 0;
}
