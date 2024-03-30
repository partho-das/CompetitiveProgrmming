#include<bits/stdc++.h>

using namespace std;
 
int main()
{
   #ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    //int start_time = clock();
#endif
    int n, m, i, j, k, x, res, sur, test, arr[505][505];
    char str[508];
 
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
 
        x=1;
        for(j=0;j<n;j++)
        {
            scanf("%s", str);
            for(i=0;i<m;i++)
            {
                if(str[i]=='*')
                {
                    arr[j][i]=x;
                    x++;
                }
                else
                    arr[j][i]=0;
            }
        }
        res=0;
        for(j=0;j<n;j++)
        {
            for(i=0;i<m;i++)
            {
                if(arr[j][i]>0)
                {
                    res++;
                    sur=3;
                    for(k=1;k<n;k++)
                    {
                    	cout << j + k<< " " << i + k << endl; 
                        if(( j+k<n&&i+k<m&&i-k>=0 && arr[j+k][i+k]-arr[j+k][i-k])+1 == sur)
                        {
                            res++;
                            sur+=2;
                        }
                        else
                            break;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
 
    return 0;
}