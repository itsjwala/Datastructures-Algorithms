//============================================================================
// Name        : kmp.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int kmp(char x[],char y[]){
    //create failure table
    int yn=strlen(y);
	int T[yn-1];
	  T[0]=0;
    for(int i=0,j=1;j<yn;){
        if(y[i]==y[j])
        {	T[j]=i+1;  i++; j++;}
        else
        {   if(i)
        	 i=T[i-1];
           else
           { T[j]=0; j++;}
        }
    }
    int c=0;
    int xn=strlen(x);
    // matching
    int i,j;
    for(i=0,j=0;i<xn;)
    {
         if(x[i]==y[j])
         {  i++; j++;}
         else
         {     if(j)
        	     j=T[j-1];
              else
        	     i++;
         }

         if(j>=yn)
         { c=1;cout<<i-j<<endl;  j=0;}
    }
     if(!c)
	   return -1;
      return 0;
    /*
   only for first match
    int xn=strlen(x);
    // matching
    int i,j;
    for(i=0,j=0;i<xn&&j<yn;)
    {
         if(x[i]==y[j])
         {  i++; j++;}
         else
         {     if(j)
        	     j=T[j-1];
              else
        	     i++;
         }

    }
   if(j>=yn)
	    return i-j;
     if(i>=xn)
	   return -1;
*/
}
int main() {
    char x[]="AAABBABAABABCABABC";
    char y[]="ABABCABABC";
    if(kmp(x,y)==-1)
    	cout<<"no Match";


	return 0;
}
