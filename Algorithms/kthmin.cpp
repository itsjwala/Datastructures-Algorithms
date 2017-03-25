//============================================================================
// Name        : kthmin.cpp
// Author      : vru
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
int kthmin(int a[],int low ,int high,int k){
    if(low>high)
      return -1;
    if((low==high)&&(low==k))
    	return a[low];
    int pivot=low;
    int l=low+1;
    int r=high;
     while(1){
       while(a[pivot]>=a[l]&&l<high)
    	     l++;
       while(a[pivot]<a[r])
    	    r--;
        if(l<r)
        	swap(a[l],a[r]);
        else
          break;
     }
      swap(a[pivot],a[r]);
      if(r==k)
    	  return a[r];
      if(k<r)
  return     kthmin(a,low,r-1,k);
      else
      return kthmin(a,r+1,high,k);
}
int main() {
  int a[]={2,8,0,3,5};

    cout<<kthmin(a,0,5-1,3-1);
     return 0;
}
