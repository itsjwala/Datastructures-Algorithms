#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
struct job
{	
	int arrival,burst,end,waiting;	
};

bool comparator (const job &i,const job & j) 
{ return (i.arrival<j.arrival); 
}

int main()
{
int n;
cout<<"Enter number of processes :";
cin>>n;
vector<job> jobs(n);
cout<<"Enter arrival and burst time for "<<n<<" processes";
for(int i=0;i<n;i++){
cout<<"job "<<i+1<<" : ";
cin>>jobs[i].arrival>>jobs[i].burst;
}
sort(jobs.begin(),jobs.end(),comparator);

jobs[0].end=jobs[0].arrival+jobs[0].burst; jobs[0].waiting=0;

int tat=0; int awt=0;
tat+=(jobs[0].waiting+jobs[0].burst);

for(int i=1;i<n;i++){
	jobs[i].end=jobs[i-1].end+jobs[i].burst;
	jobs[i].waiting=jobs[i].end-jobs[i].arrival-jobs[i].burst;
tat+=(jobs[i].waiting+jobs[i].burst);
awt+=jobs[i].waiting;
}
cout<<"Job \t |AT\t|BT\t |ET\t |WT\n";
for(int i=0;i<n;i++)
cout<<i+1<<"\t |"<<jobs[i].arrival<<"\t |"<<jobs[i].burst<<"\t |"<<jobs[i].end<<"\t |"<<jobs[i].waiting<<endl;

cout<<"Turn arround time : "<<(double)tat/n<<" Average waiting time : "<<(double)awt/n;



	return 0;
}
