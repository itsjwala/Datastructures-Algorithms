#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
using namespace std;
struct job
{	
	int id,arrival,burst,end,waiting,remaining;	
};

bool comparator (const job &i,const job & j) 
{ return (i.arrival<j.arrival); 
}


//could use binary search coz. jobs are sorted according to arrival time
void searchArrival(const vector<job>& jobs ,const int &upto,int &low,int &high){
 
low=high+1;
for(int idx=low; idx<jobs.size() ; idx++){
    if(jobs[idx].arrival>upto){
  	 high=idx-1;
  	 return ;
  }
}
 high=jobs.size()-1;

}

int main()
{
int n,TQ;
cout<<"Enter number of processes : ";
cin>>n;
cout<<"Enter Time Quantum : ";
cin>>TQ;
vector<job> jobs(n);
cout<<"Enter arrival and burst time for "<<n<<" processes"<<endl;
for(int i=0;i<n;i++){
cout<<"job "<<i+1<<" : ";
cin>>jobs[i].arrival>>jobs[i].burst;
jobs[i].remaining=jobs[i].burst;
jobs[i].id=i;
}
sort(jobs.begin(),jobs.end(),comparator);


queue<job> q;

q.push(jobs[0]);
int timer=0;
int low=0,high=0;

//round robin queue
while(!q.empty()){

   job picked=q.front();

  q.pop();
  bool lessThanTQ=false;
   if(picked.remaining<=TQ){
   	 timer+=picked.remaining;
   	 picked.remaining=0;
   	 jobs[picked.id].end=timer;
     lessThanTQ=true;
   }
 	
   if(!lessThanTQ){
	picked.remaining-=TQ;
	timer+=TQ;
	}
       searchArrival(jobs,timer,low,high);

       // cout<<"low : "<<low <<" high : "<<high<<endl;
       
       /**when picked job is executing some jobs may have arrived so insert in queue first*/
        // [low,high] including 
       for(int i=low;i<=high;i++)
        	 q.push(jobs[i]);
        
        //then push picked process;
       if(!lessThanTQ)
       q.push(picked);

  // cout<<" job "<<picked.id+1<<" at : "<<timer<<" remaining : "<<picked.remaining<<endl;
}

int tat=0; int awt=0;

for(int i=0;i<jobs.size();i++){
 int turnAround=jobs[i].end-jobs[i].arrival;
 jobs[i].waiting=turnAround-jobs[i].burst;
 tat+=turnAround;
 awt+=jobs[i].waiting;
}
/*************/
cout<<"Job \t |AT\t|BT\t |ET\t |WT\n";
for(int i=0;i<n;i++)
cout<<i+1<<"\t |"<<jobs[i].arrival<<"\t |"<<jobs[i].burst<<"\t |"<<jobs[i].end<<"\t |"<<jobs[i].waiting<<endl;

cout<<"Turn arround time : "<<(double)tat/n<<" Average waiting time : "<<(double)awt/n;

	return 0;
}