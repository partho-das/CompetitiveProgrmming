#include<bits/stdc++.h>
 
using namespace std;
 
 
 
long long hc[200];
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	
 
    	int n,m,a[4000],b[4000],arr[404],brr[404];

        memset(a,0,sizeof a);
        memset(b,0,sizeof b);

        cin >> n;

        for(int i = 0;i<n;i++)
        {
            int value;
            cin >> value;

            a[value] = 1;

            arr[i] = value;


        }
        cin >> m;

        for(int i = 0;i<m;i++)
        {
            int value;
            cin >> value;

            b[value] = 1;
            brr[i] = value;

            
        }

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int x,y;

                x = arr[i];
                y = brr[j];

                int z = x+y;

                if(!a[z] && !b[z])
                {
                    cout << x <<" "<< y << endl;
                    return 0;
                }

            }
        }


 
 
 
  
 
    return 0;
 
}