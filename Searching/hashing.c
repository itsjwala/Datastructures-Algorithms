/*
 ============================================================================
 Name        : hashing.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
int hash(int v)
{
     return v%SIZE;
}
int search(int a[],int v)
{  int i=hash(v);
  //int j=i,k=1;
   int j=v%(SIZE-1)+1;
while(a[i]!=v&&a[i]!=0)
		{
			 //i=(j+k*k)%SIZE;
	    i=(i+j)%SIZE;
			 //k++;
		}
	if(a[i]==v)
		return i;
	return -1;

}
void add(int a[],int v)
{   int i=hash(v); int j,k=1;
  //j=i;
j=v%(SIZE-1)+1;  //double hashfunction
   while(a[i]!=0)
	{
		 //i=(j+k*k)%SIZE;
	   i=(i+j)%SIZE;
		 //k++;
	}
   a[i]=v;
}
int main(void) {
	int a[SIZE]={0};
	add(a,85);
	add(a,25);
	add(a,45);
	add(a,27);
	add(a,35);
	add(a,15);
	add(a,11);
	add(a,55);
	add(a,28);
	printf("\nfound at:%d",search(a,55));
	return EXIT_SUCCESS;
}
