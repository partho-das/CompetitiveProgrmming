#include<bits/stdc++.h>

using namespace std;

bool isPrime[1000010];

void primeSieve(int n)
{
    memset(isPrime,0,sizeof(isPrime));
    for(int i=2;i<=n;i++)
    {
        if(!isPrime[i])
        {
            for(int j=i+i;j<=n;j+=i)
            {
                isPrime[j] = 1;
            }
        }
    }
    // for(int i=2;i<=n;i++)
    // {
    //     if(!isPrime[i]) printf("%d ",i);
    // }
    //puts(""); 
    return;
}

int main()
{
  
    
    primeSieve(1000000);
    int n;
    while(scanf("%d",&n) !=EOF)
    {

       //int n;
       string str;
       stringstream ss;
      // cin >> n;
       //cout << n;
       if(!isPrime[n])
       {
        ss << n;
        ss >> str;
        int cpy  = 0;
        int value = 1;
      reverse(str.begin(),str.end() );
        ss << str;
       // /cout << str << endl;
       for(int i  = str.size()-1;i>=0;i--)
       {
        cpy +=(str[i]-'0' )*value;
        value*=10;

       }
        //cout << cpy << endl;

        if(!isPrime[cpy] && n!=cpy)
        {
            printf("%d is emirp.\n",n);

        }
        else printf("%d is prime.\n",n);

       }
       else 
       {
        printf("%d is not prime.\n",n);
       }


    }
      

    
    return 0;
}
