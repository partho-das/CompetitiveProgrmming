#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){ ///greatest common divisor
    if(!a) return b;
    return gcd(b%a,a);
}


bool arr[10000000];

void isprmie(int n)
{  
     memset(arr,0,sizeof(arr));
    for(int i = 3;i*i<=n;i+=2)
    {   
        if(!arr[i])
        { 
             for(int j = i*i;j<=n;j+=i)
             {
                arr[j] = 1;
             }
        }
       
    }
    printf("2\n");

    for(int i = 3;i<=n;i+=2)
        if (!arr[i])
        {
            printf("%d\n", i);
        }
    return;

}

vector < int > divisor[10000000];

void divse(int n)
{

    for(int i = 1;i*i<=n;i++)
    {
        for(int j = i;j<=n;j+=i)
        {
            divisor[j].push_back(i);
        }
    }

    for(int i = 1; i<=n ;i++)
    {
        int sum = 0;
        for(auto  it : divisor[i] )
        {
            sum+=it;
           // cout<<it<<" ";
        }
        cout<<i<<" : "<<sum<<endl;
    }
}
int sod[1000010];///some of divisor
void sodSieve(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            sod[j]+=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d : %d\n",i,sod[i]);
    }
    //puts("");
    return;
}






int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);






    int test ;

    cin>>test;
    int x = 0;

    //divse(test);
   isprmie(100);

    
    
    return 0;
}
