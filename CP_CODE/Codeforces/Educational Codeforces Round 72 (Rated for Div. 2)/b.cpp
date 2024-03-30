
#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int> a,pair<int,int> b)
{
    return (a.first-a.second)>(b.first-b.second);
}


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   
    
    	int t;
    	cin >> t;

    	while(t--)
    	{
            int ck = 0,mx =-1,mxdh = -1e9;
    		int n,arr[200],x,h[200];
            std::vector<pair<int,int> > def;

            cin >> n >>x;
            for(int i = 0;i<n;i++)
            {

                cin >> arr[i] >> h[i];
                mx =max(arr[i],mx);
                mxdh = max(arr[i]-h[i] ,mxdh);

            }


            int res = 1;

            x-=mx;
            if(x>0)
            {
                if(mxdh<=0) res = -1;
                else res+= (x+mxdh-1)/mxdh;

            }
            cout << res << endl;

           
            



    	}
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
