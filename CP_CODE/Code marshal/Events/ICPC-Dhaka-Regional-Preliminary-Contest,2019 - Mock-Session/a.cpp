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
        
        int arr[5];


        for(int i = 0;i<3;i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+3);

        if(arr[0]==arr[1] && arr[1] == arr[2])
            cout <<  "Equilateral Triangle" << endl;
        else if(arr[0]== arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
            cout << "Isosceles Triangle" << endl;
        


    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
