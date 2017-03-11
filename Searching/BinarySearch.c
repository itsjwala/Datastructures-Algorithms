/*
 ============================================================================
 Name        : BinarySearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int BinaryRecursive(int a[] , int low , int high, int k)	{
	if(low>high)
		return -1;
	int mid = (low + high)/2;
	if(a[mid]==k)
		return mid;
	else if(a[mid]<k)
		return BinaryRecursive(a,mid+1,high,k);
	else
		return BinaryRecursive(a,low,mid-1,k);
}

int BinaryIterative(int a[], int n , int k)	{
	int low = 0,high = n-1,mid = (low+high)/2;
	while(low<=high && a[mid]!=k)	{
		if(a[mid]<k)
			low = mid+1;
		else
			high = mid-1;
		mid = (low+high)/2;
	}
	if(low>high)
		return -1;
	else
		return mid;
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
				int j = BinaryIterative(a,n,k);
				if(j==-1)
					printf("Element not found\n");
				else
					printf("Element found at position %d",j+1);
	return EXIT_SUCCESS;
}
