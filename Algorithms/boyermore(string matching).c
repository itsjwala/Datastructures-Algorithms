/*
 ============================================================================
 Name        : BoreyMore.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 20
int min(int a, int b) {

	return a < b ? a : b;
}
int lastIndexOf(char x, char y[]) {
	int i;

	for (i = strlen(y) - 1; i >= 0 && y[i] != x; i--)
		;
	return i;

}

int boyerMore(char x[], char y[]) {
	int n = strlen(x);
	int i = strlen(y) - 1, j = i;
   int c=0;
	while (i < n) {

		while (j >= 0 && x[i] == y[j]) {
			i--;
			j--;
		}
		if (j == -1)
		{	 c=1;
			printf("%d\n",i+1);  //for multiple substring;
		    // return i+1; for first substring
		}if (x[i] != y[j]) {

			i = i + strlen(y) - min(j, (lastIndexOf(x[i], y) + 1));
			j = strlen(y) - 1;
		}
	}
	if(!c)
		puts("-1");


}
int main(void) {
	char x[] = "ABCXBCCABCDABC";
	char y[] = "ABC";

	//printf("%d", BoreyMore(x, y));
     boyerMore(x,y);
	return 0;
}
