#include <bits/stdc++.h>
using namespace std;

void print(int a[], int x[], int n) {

	for (int i = 0; i < n; i++)
		cout << a[i] << " : " << x[i] << endl;
	cout << endl;

}
/*
//fixed tuple backtracking
void sumofsubset(int a[], int x[], int sum, int r, int n) {

	for (int i = 1; i >= 0; i--) {
		x[r] = i;
		int t = sum;
		t -= (i == 1) ? a[r] : 0;

		if (t >= 0) {

			if (t == 0) {
				print(a, x, n);
				continue;
			} else if (r + 1 < n)
				sumofsubset(a, x, t, r + 1, n);

		}

	}
}
*/

//variable tuple
void sumofsubset(int a[], int x[], int sum, int r, int n) {

	for (int i = r; i < n; i++) {

		x[i] = 1;
		int t = sum;  //*
		t -= a[i];

		if (t >= 0) {

			if (t == 0) {
				print(a, x, n);
				x[i] = 0;
				continue;   //if sum found than dont expand the tree
			}

			else if (r + 1 < n)
				sumofsubset(a, x, t, i + 1, n);  //** i+1 //i is array index and r is current level 
		}

		x[i] = 0;  //undo to previous config

	}

}
int main() {
	int n = 5;
	int a[] = { 8, 5, 7, 10, 3 };
	// sort(a,a+n);  sort to reduce growth of tree
	int x[n] = { 0 };
	int sum = 15;
	sumofsubset(a, x, sum, 0, n);

	return 0;
}
