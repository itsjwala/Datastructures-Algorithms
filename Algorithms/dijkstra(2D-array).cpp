#include <bits/stdc++.h>
#define INF 10000
#define N 20
using namespace std;
void dijkstra(int a[][N], int source, int destination, int n) {
	int dist[n], prev[n];
	bool selected[n] = { 0 };
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	int s = source;
	dist[s] = 0;
	for (int count = 1; count <= n; count++) {
		selected[s] = 1;
		for (int i = 0; i < n; i++) {
			int d = dist[s] + a[s][i];
			if (a[s][i]) {
				if (!selected[i] && d < dist[i]) {
					dist[i] = d;
					prev[i] = s;
				}
			}
		}
		int minSource = s;
		int min = INF;
		for (int i = 0; i < n; i++) {
			if (!selected[i] && dist[i] < min) {
				minSource = i;
				min = dist[i];
			}

		}
		s = minSource;

	}
	cout << "Shortest path between " << source + 1 << " and " << destination + 1
			<< " is:";

	vector<int> path;
	path.push_back(destination);
	for (int sd; destination != source; destination = sd) {
		sd = prev[destination];
		path.push_back(sd);
	}
	for (int i = path.size() - 1; i > 0; i--)
		cout << path[i] + 1 << "->";
	cout << path[0] + 1;

}
int main() {

	int a[N][N] = { 0 };
	int n;
	cout << "Enter number of node:";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "Distance between " << i + 1 << " and " << j + 1 << ":";
			cin >> a[i][j];
		}
	cout << "Adjacency matrix is:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	int s, d;
	cout << "Enter source and destination node:";
	cin >> s;
	cin >> d;
	--s;
	--d;
	dijkstra(a, s, d, n);
	return 0;
}
