#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;
int arr[100],a[100],b[100];

void marge(int l,int mid,int r)
{   
    int i;
    for( i = l;i<=mid;i++)
        a[i] = arr[i];
        a[i] = maxn;
    for(i = mid+1;i<=r;i++)
        b[i] = arr[i];
        b[i] = maxn;
    int j = l,k = mid+1;
    i = l;
    while(j<=mid || k<=r && i <= r)
    {
        if(a[j]<=b[k])
            arr[i++] = a[j++];
        else arr[i++] = b[k++];
      
    }

    return;
}

int split(int l,int r)
{
    int mid = l + (r - l)/2;

   //cout << mid << " " << l << " " << r << endl;
    if(l>=r)
        return 0;
    //cout << mid << " " << l << " " << r << endl;
    split(l,mid);
    split(mid+1,r);

    marge(l,mid,r);
    return 0;
}
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
    int n ;
    cin >> n;
    //cout << n;
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    split(0,n-1);


    for(int i = 0;i<n;i++)
        cout << arr[i] <<" ";
    cout << endl;
    
  

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
