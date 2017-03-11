/*
 ============================================================================
 Name        : SentinalSearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sentinalSearch(int a[],int n,int k){
	int i=0;
	a[n] = k;
	while(a[i]!=k)
		i++;
	if(i<n)
		return i;
	else
		return -1;
}

int main(void) {
	int a[20],i,n,k;
		printf("Enter the number of elements\n");
		scanf("%d",&n);
		printf("Enter the elements\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("Enter the element to be searched\n");
		scanf("%d",&k);
		int j = sentinalSearch(a,n,k);
		if(j==-1)
			printf("Element not found\n");
		else
			printf("Element found at position %d",j+1);
	return EXIT_SUCCESS;
}
