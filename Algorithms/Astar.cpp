#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
  int V, E, s, u, v, w,dest;
  vector<vii> AdjList;


  // freopen("in_05.txt", "r", stdin);

  scanf("%d %d %d %d", &V, &E, &s,&dest);

  AdjList.assign(V, vii());
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    AdjList[u].push_back(ii(v, w));
  }
  int heu[V];
  for(int i=0 ; i<V ;i++)
    scanf("%d",&heu[i]);

  vi dist(V, INF); dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; 
  pq.push(ii(dist[s]+heu[s], s));

  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;

    if(u == dest)
      break;
    // if (d > dist[u]) continue;

    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first]+heu[v.first], v.first));
  } } }

 printf("shortest path from %d to % d  = %d",s,dest,dist[dest]);

  return 0;
}

/*
admissible and inconsistent
5 7 0 4
0 1 1
0 2 4
1 2 2
1 3 5
2 3 2
1 4 12
3 4 3
7 3 2 1 0

admissible but inconsistent heuristic
7 9 0 6
0 1 2
0 2 1
0 6 9
1 3 2
1 4 3
2 4 2
2 5 4
3 6 4
4 6 4
6 0 6 4 1 10 0

admissible but inconsistent heuristic
4 4 0 3
0 1 1
1 2 1
0 2 3
2 3 6
8 7 0 0


using inconsitent or Non monotonic heuristic will give sub optimal if we use visited array logic
because some node from visited array may get updated which leads to optimal path,
So conclusion dont use visited array if heuristic is inconsistent only issue would be visiting some nodes more than once (performance hit)
If want to use visited array(like in dijktra's) then make sure heuristic is consitent/ monotonic.

https://stackoverflow.com/a/51690332/9485283

*/
