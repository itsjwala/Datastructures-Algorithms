#include<stdio.h>
void swap(int *x,int *y)
{   int temp=(*x);
    *x=*y;
	 *y=temp;
}
int partition(int a[],int low,int high)
{    int pivot=low,l=low+1,r=high;
	     while(1)
		 {
		   while(l<=high&&a[l]<=a[pivot])
	         l++;
	        while(a[r]>a[pivot])
	         r--;
	         if(l<r)
	          swap(&a[l],&a[r]);
	         else
			    break; 
	     }
	     swap(&a[pivot],&a[r]);
	  return r; 
}
void quicksort(int a[],int low,int high)
{    int pivot,stack[50]={0},top=-1; 
	if(low>=high)
	  return;
	  stack[++top]=high; stack[++top]=low;
	   while(top>-1)  
		{ low=stack[top--];
		 high=stack[top--];
		if(low<high)
		pivot=partition(a,low,high);
	    else
	     continue;
		 stack[++top]=high;
	     stack[++top]=pivot+1;
	     stack[++top]=pivot-1;
	     stack[++top]=low;
	    }
}
int main()
{    int a[]={6,15,23,1,85,58,63,24,35,15,10,10,10,10},i;
	 quicksort(a,0,14-1);
	
	for(i=0;i<14;i++)
	 printf("%d\t",a[i]);
	
	return 0;
}
