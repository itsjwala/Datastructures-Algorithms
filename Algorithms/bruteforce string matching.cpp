//============================================================================
// Name        : bruteforce.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
int indexof(char x[], char y[]) {
	int n = strlen(x);
	int m = strlen(y);

	for (int i = 0, j = 0; i < n;) {

		while (j < m && (x[i++] == y[j++]));

		if (j == m && y[j - 1] == x[i - 1])
			return (i - m);
		else
			j = 0;
	}
	return -1;
}
int main() {
	char x[] = "abaaaabcabca";
	char y[] = "abz";
	cout << indexof(x, y);

	return 0;
}
