#include<bits/stdc++.h>

using namespace std;

   void Sort(int *arr,int L,int M,int R)
{
     for(int i = L;i<=R;i++)
        cout<< arr[i]<<" ";
    cout<<endl;

    int s1 = M-L+1;
    int s2 = R-M;

    int v1[s1],v2[s2];

    for(int i=0;i<s1;i++)
    {
        v1[i] = arr[L+i];
    }
    for(int i=0;i<s2;i++)
    {
        v2[i] = arr[M+1+i];
    }
    int i,j,k;
    i = j = 0;
    k = L;

    while(i<(s1) && j<(s2))
    {
        if(v1[i]<=v2[j])
        {
            arr[k++] = v1[i];
            i++;
        }
        else
        {
            arr[k++] = v2[j];
            j++;
        }
    }
    while(i<s1)
    {
        arr[k++] = v1[i++];
    }
    while(j<s2)
    {
        arr[k++] = v2[j++];
    }
}

void MergeSort(int *arr,int L,int R)
{
    cout<<"L"<<" "<<"R"<<endl;
    cout<<L<<" "<<R<<endl;
     for(int i = L;i<=R;i++)
        cout<< arr[i]<<" ";
    cout<<endl;
    
    if(L<R)
    {
        int M = L+(R-L)/2;
         cout<<"_____L_____"<<endl;
        MergeSort(arr,L,M);
        cout<<"_____R______"<<endl;
        MergeSort(arr,M+1,R);
         cout<<"_____M______"<<endl;
        Sort(arr,L,M,R);
    }
}
  

int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
 

    int arr[1000];

    int n;

    cin>> n;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr,0,n-1);
    
    for(int i = 0;i<n;i++)
        cout<< arr[i]<<" ";

    return 0;
}