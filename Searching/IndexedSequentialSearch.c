/*
 ============================================================================
 Name        : IndexedSequentialSearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int IndexedUsing2DArray(int a[] , int n, int k){
	int i=0,m = n/5,j=0;
	int t[5][2];
	while(i<n){
		t[j][0] = i;
		t[j][1] = a[i];
		j++;
		i+=m;
	}//not required
	if(n%m != 0)	{
		t[j][0] = n-1;
		t[j][0] = a[n-1];
	}
	while(i<=j && t[i][0]<k)
		i++;
	if(i>0)
		i = t[i-1][0];
	while(i<n && a[i]<k)
		i++;
	if(i<n && a[i]==k)
		return i;
	else
		return -1;
}

int IndexedSequential(int a[] , int n , int v, int g)	{
	int i;
	for(i=0;i<n&&a[i]<v;i+=g);
	if(i>0)
	 i-=g;
	 for(;i<n&&a[i]<v;i++);
	 if(a[i]==v)
	   return i;
	   return -1;
}

int main(void) {
	int a[20],i,n,l,k;
				printf("Enter the number of elements\n");
				scanf("%d",&n);
				printf("Enter the elements in sorted order\n");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				printf("Enter the element to be searched\n");
				scanf("%d",&k);
				printf("Enter the jump\n");
				scanf("%d",&l);
				int j = IndexedSequential(a,n,k,l);
				if(j==-1)
					printf("Element not found\n");
				else
					printf("Element found at position %d",j+1);
	return EXIT_SUCCESS;
}
