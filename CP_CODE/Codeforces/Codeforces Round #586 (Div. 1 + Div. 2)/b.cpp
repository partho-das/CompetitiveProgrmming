#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
 
 
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
 
    int n;
    cin >> n;
    long long arr[2][n+5];
 
    for(int i = 0;i<2;i++)
        for(int j = 0; j < n;++j)
            cin >> arr[i][j];
 
        long long value = arr[0][1]*arr[0][2]/arr[1][2];
        value = sqrt(value);
        cout << value << " ";
        for(int i = 1;i<n;i++)
            cout << arr[0][i]/value << " ";
        cout << endl;
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
 
    return 0;
}
