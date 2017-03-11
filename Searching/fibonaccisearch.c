#include<stdio.h>

int fibSearch(int a[],int n,int v)
{   int i,f,s,t,mid,prev,temp;  
    prev=-1; f=0; s=1;  t=1;
	 n--;  
   	while(t<n)
   	 {  prev=f;  	 
		f=s;
   	 	 s=t;
	    t=f+s;
	 }  
	 if(t==n)
	    mid=s;  
	 else 
	    { mid=f;  temp=prev;  prev=f-prev; f=temp;}   
     while(f>=0)	   
     {   if(mid<=n&&a[mid]==v)
           return mid;
     	 else if(mid>n||a[mid]>v)
      	    mid-=f;
     	  else  
			  mid+=f;
       temp=prev; 			  
	   	prev=f-prev; 
	    f=temp;	   
	 }
	 return -1;
	
}
int main()
{   //int a[20]={5,7,10,47,55,57,66,74,86,94};
   int a[20]={5,10,15,25,45,56,67,78,89};
	 printf("found at:%d",fibSearch(a,9,89));
	return 0;
}
