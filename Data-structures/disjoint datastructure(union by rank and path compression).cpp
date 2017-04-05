#include <bits/stdc++.h>
#define N 10
using namespace std;
int parent[N + 5], rank[N + 5];
void init() {
	//initially all are members of group that contains themselves only (therefore 1)
	memset(rank, 1, N + 5);

	//iniitially all are parent of themselves
	for (int i = 0; i < N; i++)
		parent[i] = i;

}
//find parent of 'n' upto the root
int find(int n) {
	int x = n;
	while (n != parent[n])
		n = parent[n];

	parent[x] = n; //union by path compression
	return n;
}
void merge(int x, int y) {
	int _x = find(x);   //traverse upwards and find root of x;
	int _y = find(y);   //same with y

	//if dont belong to same union merge
	if (_x != _y) {

		if (rank[_x] > rank[_y]) 
			parent[_y] = _x;
		 else 
			parent[_x] = _y;
		if(rank[_x] == rank[_y])
                        rank[_y]++; 
	}

}
int main() {
	init();
	merge(1, 2);
	merge(1, 5);
	merge(1, 6);
	merge(6, 5);
	merge(3, 4);
	merge(3, 7);
	merge(7, 4);
	//merge(7, 1);
	if (find(2) != find(3))
		cout << "parents are different or different community";
	else
		cout << "parents are same or same community";

	return 0;
}
