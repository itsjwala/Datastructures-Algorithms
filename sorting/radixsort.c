
#include <stdio.h>
#include <stdlib.h>
int largest(int a[],int n)
{     int max=0,i;
	 for(i=0;i<n;i++)
	   if(a[i]>a[max])
	      max=i;
	 return a[max];
}
void radixsort(int *a,int n,int loop)
{     int i,b[10]={0},t,j,k=1,temp[10]={0};

      for(j=0;j<loop;j++)
       {  for(i=0;i<n;i++)
	       {     t=(a[i]/k)%10;
                 b[t]++;
           }
           for(i=1;i<10;i++)
             b[i]+=b[i-1];

          for(i=n-1;i>=0;i--)
            {    t=(a[i]/k)%10;
             	temp[--b[t]]=a[i];
            }
			for(i=0;i<n;i++)
				a[i]=temp[i];
			for(i=0;i<10;i++)
				b[i]=0;
			   k*=10;
		}
}
int main(void)
{         int i,a[10],n,max,loop=0;
			
			/*printf("enter number of elements:");
			scanf("%d",&n);
			printf("\nenter elements");
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);*/
             max=largest(a,n);
           while(max!=0)
           {   max/=10;
                loop++;
           }
        	   radixsort(a,n,loop);


        	   printf("\n sorted elements:");
               for(i=0;i<n;i++)
              	 printf("%d\t",a[i]);

	return EXIT_SUCCESS;
}
