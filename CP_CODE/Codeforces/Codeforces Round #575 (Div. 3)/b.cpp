#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+200;

bool arr[maxn];



int main()
{

	
		#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    	#endif

    	
        int q,n,k,odd = 0,even = 0,ck = 0,st = 0,en = 0,s = 0,c;


        cin >> q;

        while( q--)
        {
          
            odd = 0,even = 0,ck = 0,st = 0,en = 0;
            std::vector<int> seg;
             cin >> n >> k;
             c = k;

            for(int i = 0;i<n;i++)
            {
                int value;
                cin >> value;
                arr[i] = value&1;

                if(arr[i])
                    odd++;
                else even++;
            }


            if(odd<k)
            {

                cout << "NO" << endl;
              
            }
            else
            {
                

                for(int i = 0;i<n;i++)
                {

                    if(arr[i])
                    {
                        s++;
                      k--;
                      odd--;
                     
                      if(k==0 && odd != 0)
                      {
                        k++;

                      }
                      else
                      {
                        if(s&1)
                        {
                            s = 0;
                            if(k==0)
                            {
                                seg.push_back(n);
                            }
                            else
                            {
                               
                                seg.push_back(i+1);
                               

                            }
                            

                           // cout << i << endl;
                        }
                      }

                    }
                    
                  
                }

                if(seg.size() !=c)
                    cout << "NO"  << endl;
                else
                {
                    cout << "YES" << endl;

                    for(int i = 0;i<c;i++)
                    {
                         cout << seg[i];
                         if(i<c-1)
                            cout <<" ";
                    }
                   
                    puts("");
                } 


                
               
        }
    }


   			




		#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    	#endif
 
	
 
	return 0;
}