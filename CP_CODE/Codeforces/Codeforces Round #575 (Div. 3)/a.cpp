#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+200;



int main()
{

	
		#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    	#endif

    	
    	long long arr[5],value,q,a,b,due;

        cin >> q;


        while(q--)
        {

            cin >> arr[0]>> arr[1] >> arr[2];



            sort(arr,arr+3);
            // cout << arr[0] << " "<< arr[1] << " "<< arr[2] << endl;

            a = arr[0];
            b = arr[1];

            due = (b-a);
            //cout << due << endl;

            arr[2] -= due;

            a+=due;

            due = arr[2]>>1;

            a+=due;


            cout << a << endl;


        }

   			




		#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    	#endif
 
	
 
	return 0;
}