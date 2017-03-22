#include<bits/stdc++.h>
#define pb push_back
#define  mp make_pair
#define  f first
#define  s second
#define INF 10000
#define vit vector<pair<int,int>>::iterator
using namespace std;
void prim( vector<pair<int,int>> v[],int n){
	int dist[n],prev[n]={0};
  for(int i=0;i<n;i++)
     dist[i]=INF;
  bool selected[n]={0};
    int start=0;
    dist[start]=0;
    
  for(int count=1;count<=n;++count){
    selected[start]=1;
  for(vit it=v[start].begin();it!=v[start].end();++it)
  	 if(!selected[it->f]&&dist[it->f]>it->s){
  		dist[it->f]=it->s;
  		prev[it->f]=start;
	  }
	  	  
	 int m,min=INF; 
	for(int i=0;i<n;i++)
	  if(!selected[i]&&dist[i]<min)
	    {  m=i; min=dist[i];}  
      
	  start=m;    	
  }
  
  //MST array ->
   for(int i=0;i<n;i++)
     cout<<i<<":"<<prev[i]<<endl;  
     
}

int main(){
	
	cout<<"Enter number of nodes:";
	int n;
	cin>>n;
	vector<pair<int ,int>> v[n];
	cout<<"Enter number of edges:";
	int e;
	cin>>e;
	cout<<"Enter node1 node2 cost for all "<<e<<" edges"<<endl;
	while(e--){
	int a,b,c;	
		cin>>a>>b>>c;
		a--;b--;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	prim(v,n);
	
	return 0;
	
}		
