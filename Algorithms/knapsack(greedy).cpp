//============================================================================
// Name        : knapsack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;

int main() {
  int p[]={10,23,7,4};
  int w[]={10,12,5,3};
  int capacity=18;
  pair<float,int> pr;
  vector< pair<float,int> > v;
  for(int i=0;i<4;i++)
  {   pr.first=(float)p[i]/w[i];
       pr.second=i;
	  v.push_back(pr);
  }
  sort(v.begin(),v.end());
 //knapsack 0/1
  bool selected[4]={false};
  float selected1[4]={0.0};
 for(vector< pair<float,int> >::reverse_iterator it=v.rbegin();it!=v.rend()&&capacity>0;it++){

	  if(w[it->second]<=capacity){
            selected[it->second]=true;
         capacity-=w[it->second];
         selected1[it->second]=1.0;
	  }
	  else{
            selected1[it->second]=((float)capacity/w[it->second]);
             capacity=0;
	  }
  }
  //knapsack fractional
 cout<<"knapsack 0/1:\n";
   for(int i=0;i<4;i++)
	   cout<<selected[i]<<"  ";
	cout<<"\nfractional knapsack:\n";
	  for(int i=0;i<4;i++)
		   cout<<selected1[i]<<"  ";
	return 0;
}

