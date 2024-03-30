#include<bits/stdc++.h>

using namespace std;

int ubound(int n,int *arr,int value)
{
	int start = 0,stop = n-1;
    int mid ;
	 while(start<=stop)
    {

    	mid = (stop+start)/2;
    	// cout << start<<" " <<stop <<" " << mid <<" " <<arr[mid] <<" " << endl;
    	if(arr[mid]<=value)
    	{
    		start = mid+1;
    	}
    	else
    	{
    		stop = mid-1;

    	}

    }
    // cout << start<<" " <<stop <<" " << mid <<" " <<arr[mid] <<" " << endl;
    return start;
}
int lbound(int n,int *arr,int value)
{
	int start = 0,stop = n-1,mid;
	 while(start<=stop)
    {

    	mid = (stop+start)/2;
    	// cout << start<<" " <<stop <<" " << mid <<" " <<arr[mid] <<" " << endl;
    	if(arr[mid]<value)
    	{
    		start = mid+1;
    	}
    	else
    	{
    		stop = mid-1;

    	}

    }
    return start;
}


int main()
{
    //freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    //freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);


    int arr[10000];
    int n;
    cin >> n;

    for(int i = 0;i<n;i++)
    	scanf("%d",&arr[i]);

    sort(arr,arr+n);

    for(int value = 0; value < 30; value++){
		cout << lbound(n,arr,value) <<  " " << ubound(n,arr,value) << endl;
		cout << lower_bound(arr,arr+n,value)-arr << " " << upper_bound(arr,arr+n,value)-arr << endl;
		puts("_________________");
	}


    return 0;
}

