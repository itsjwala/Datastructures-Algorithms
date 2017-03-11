/*
 ============================================================================
 Name        : LinearOrderSearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int LinearOrderSearch(int a[] , int n,int k)	{
	int i=0;
	while(i<n && a[i]<k)
		i++;
	if(i<n && a[i]==k)
		return i;
	else
		return -1;
}

int main(void) {
	int a[20],i,n,k;
			printf("Enter the number of elements\n");
			scanf("%d",&n);
			printf("Enter the elements in sorted order\n");
			for(i=0;i<n;i++)	{
				scanf("%d",&a[i]);
			}
			printf("Enter the element to be searched\n");
			scanf("%d",&k);
			int j = LinearOrderSearch(a,n,k);
			if(j==-1)
				printf("Element not found\n");
			else
				printf("Element found at position %d",j+1);
	return EXIT_SUCCESS;
}
