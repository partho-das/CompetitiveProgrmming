#include<bits/stdc++.h>

using namespace std;
const int maxn = 300000;
 int y[maxn],x[maxn];
#define fio  freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin), freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout)


int main()
{
    fio;
   
    int n,m,a,b,xc = 1,yc = 1;
    cin >> n >> m;
   
    memset(x,0,sizeof x);
    memset(y,0,sizeof y);


    int x1,x2;

    for(int i = 0;i<m;i++)
    {
        cin >> a >> b;

        if(i==0)
        {
            x1 = a;
            x2 = b;
        }
        else
        {
            if(x1 != a &&  x1 !=b)
            {
                x[a]++;
                x[b]++;
            }
            else xc++;
            if(x2 != a &&  x2 !=b)
            {
                y[a]++;
                y[b]++;
            }
        else yc++;

        }
    }

   for(int i = 1;i<=n;i++)
   {
    if(xc+x[i] == m)
    {
        printf("YES\n");
        return 0;
    }
    if(yc+y[i] == m)
    {
        printf("YES\n");
        return 0;
    }
   }
   printf("NO\n");
    return 0;
}