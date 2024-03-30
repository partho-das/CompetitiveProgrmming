#include<bits/stdc++.h>
 
using namespace std;
 
int ubound(int n,int *arr,int value)
{Tech49
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
     freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
     freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int test;
    cin>>test;
    for(int j = 1;j<=test;j++)
    {
        printf("Case %d:\n",j);
         int arr[100500];
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
 
        sort(arr,arr+n);
        while(q--)
        {
            int a,b;
 
            scanf("%d%d",&a,&b);
 
            int range = ubound(n,arr,b);
            cout<<lbound(n,arr,a)<<endl;
            printf("%d\n", range);
        }
 
 
 
    }
 
   
 
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void binarysearch(int n,int *arr,int value)
{
    int start = 0;
    int stop = n;

    while(start<=stop)
    {
        int mid = (start+stop)/2;

        if(arr[mid] == value)
        {
            printf("Found in %d\n",mid);
            return;
        }
        else if(arr[mid]<value)
            start = mid+1;
        else if(arr[mid]>mid)
            stop = mid-1;
    }

    printf("NOT Found\n");
    return;

}


int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int arr[1000000],n;

    scanf("%d",&n);

    for(int i  = 0;i<n;i++)
        scanf("%d",&arr[i]);

    int value;
    scanf("%d",&value); 
    binarysearch(n,arr,value);


     long long value = 1,mv = 0,n,mxv = 0 ; 
    scanf("%lld",&n);
    mv = n;
    int cnt = 0;
    for(int i = 1;i<1000;i++)
    {
        n  = mv;
        while(n%10)
        {
            cnt++;
          value*=n%10;
            n=n/10; 
        }
        
        value = 1;
        mv--;
        if(mv<0)
            break;
    }
    value = 1;
    for(int i= 1;i<cnt;i++)
        value*=9;
    if(value>mxv)
        mxv = value;

    cout<<mxv<<endl;



   

    return 0;
}
