#include<bits/stdc++.h>

using namespace std;


int main()
{

 
    int st = clock();
    
    int n,onec = 0,twoc = 0,sum = 0,pc = 0;

    cin >> n;

    for(int i = 0 ;i<n;i++)
    {
        int value;
        scanf("%d",&value);
        sum+=value;

        if(value == 1)
            onec++;
        else twoc++;
    }

    if(twoc) {
        cout << 2 <<" ";
        twoc--; 
        /* code */
    }
    if(onec)
    {
        cout << "1 ";
        onec--;
    }
    while(twoc--) {

        cout << 2 <<" ";
    }
     while(onec)
    {
        cout << "1 ";
        onec--;
    }
    cout << endl;
    //cout << sum << onec << twoc


       // cout <<" pc = " << pc << " " << pri[i]<< endl;
        int en = clock();
     //  cout << "Time : " << en-st/1000.0;
  
    return 0;
}


