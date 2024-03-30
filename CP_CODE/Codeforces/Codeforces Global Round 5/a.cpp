
#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
  
  	int arr[50000],n;


  	cin >> n;

  	int x = 0,value,sum = 0;
  	for(int i = 0;i<n;i++)
  	{
  		cin >> value;
  		arr[i] = value;
  		if(value%2==0)
  		{
  			sum += value/2;
  		}
  		else
  		{
  			x++;
  			sum += value/2;
  		}
  	}

  		for(int i = 0;i<n;i++)
  		{
  			if(arr[i]%2==0)
	  		{
	  			arr[i]/=2;
	  		}
	  		else
	  		{
	  			if(sum<0)
	  			{
	  				if(arr[i]>0)
	  				{
	  					arr[i] = (arr[i]+1)/2;
	  					sum++;
	  				}
	  				else
	  				{
	  					arr[i] = (arr[i])/2;

	  				}
	  			}
	  			else if(sum>0)
	  			{
	  				if(arr[i]<0)
	  				{
	  					arr[i] = (arr[i]-1)/2;
	  					sum--;
	  				}
	  				else
	  				arr[i] = (arr[i])/2;

	  			}
	  			else
	  				arr[i] = (arr[i])/2;
	  		}

  		}


  		for(int i = 0;i<n;i++)
  		{
  			cout << arr[i] << endl;
  		}
  

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
