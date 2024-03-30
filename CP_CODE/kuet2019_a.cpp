#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int t,a[100020],b[100020];
        stack<int> stk;

    	cin >> t;

    	for(int c = 1;c<=t;c++)
    	{
    		int ck = 0;
            int n;
            scanf("%d",&n);

            for(int i = 0;i<n;i++)
            {
             scanf("%d",&a[i]);
            // cout << a[i] << " " ;
            }
            //cout << endl;
            int x  = 0;
           for(int i = 0;i<n;i++)
           {
                scanf("%d",&b[i]);
           }
           for(int i = 0;i<n;i++)
           {
            
            if(a[i] == b[x])
            {
                   b[x] = -1;
                   x++;
                continue;
            }
            else
            {
                if(stk.empty())
                    stk.push(a[i]);
                else{
                    int top  = stk.top();
                    if(top == b[x])
                    {
                        stk.pop();
                        b[x] = -1;
                        x++;
                    }
                    else stk.push(a[i]);
                } 
            }
           
           }

       x = 0;
           while(!stk.empty() && x<n)
           {

            if(b[x] != -1)
            {
                if(stk.top() == b[x])
                {
                    x++;
                    stk.pop();

                }
                else{{
                    ck = 1;
                    break;
                }
                }
            }
            else x++;

           }
    		
            printf("Case %d: ",c);
    		if(ck == 0 &&  x>=n-1 && stk.empty())
            { 
    			printf("POSSIBLE\n");
            }
    		else printf("IMPOSSIBLE\n");
    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
