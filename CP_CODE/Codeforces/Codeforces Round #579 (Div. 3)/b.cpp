#include<bits/stdc++.h>



using namespace std;

const int maxn = 2e4;

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int q,n,arr[1000],cpy[1000],ck = 0;
        long long area = 1;

        cin >> q;

        while(q--)
        {
            ck = 0;
            cin >> n;
            int value;
            for(int i = 0;i<(4*n);i++)
            {
                cin >> arr[i];
            }

            sort(arr,arr+(4*n));
            int m = 0;
            for(int i = 0;i<(4*n);i+=2)
            {
              if(arr[i]==arr[i+1])
                cpy[m++] = arr[i];
            else
            {
                    ck = 1;
                     printf("NO\n");
                     break;

            }

                //cout << cpy[m-1] <<" ";
            }
            //cout << endl;
            if(ck==0)
             value = cpy[0]*cpy[2*n-1];
             if(ck==0)
             for(int i = 0;i<m;i++)
             {

                if(value == (cpy[i]*cpy[m-1-i]))
                    continue;
                else
                {
                    ck = 1;
                     printf("NO\n");
                     break;

                } 
             }
             if(ck==0)
             printf("YES\n");
            

        }


	return 0;
}