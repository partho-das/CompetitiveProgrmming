#include<bits/stdc++.h>

using namespace std;


bool arr[1000000];
vector<int> prime;

void genarete(int n){   
    prime.push_back(2);
    for(int i = 3;i*i<=n;i+=2) 
        if(!arr[i]) 
            for(int j = i*i;j<=n;j+=i<<1) arr[j] = 1;

    for(int i = 3;i<=n;i+=2) if(!arr[i]) prime.push_back(i);
}
std::vector<int> primediv[100000];
void dv(int n)
{
    for(int i = 0;i<prime.size();i++)
    {
        for(int j = prime[i]*2; j<=n ;j+=prime[i])
        {
            primediv[j].push_back(prime[i]);
           // printf("2\n");
        }
        
    }

}


int main()
{


    int n;
    cin >> n;
    int cnt = 0;
    //cout << n;
    genarete(n);
    dv(n);
    // for(int i = 0;i<primediv[10].size();i++)
    //     cout<<primediv[10][i]<<" ";
    for(int i = 1;i<=n;i++)
    {
       
        if(primediv[i].size()==3)
        {  
           // cout<<i<<" "; 
            printf("Yes\n");
           // cout<<primediv[i][0]<<" "<<primediv[i][1]<<endl;
        } 
        printf("NO\n");
    }
    cout <<cnt<<endl;

 

    return 0;
}

 
#include<bits/stdc++.h>

using namespace std;

int maxn = 10e2+7;

long long power(int n,int base)
{
    //cout<<n<<" "<<base<<endl;
    if(base==0)
        return 1;
    if(base&1)
    {   long long value = n*power(n,base-1)%maxn;
        //cout<<"value = "<<value<<endl;
        return value%maxn;
    }
    else {
        long long temp = power(n,base/2)%maxn;
       // cout<<"temp = "<<(temp*temp)%maxn<<endl;
        return (temp*temp)%maxn;
    }


}

namespace Bigmod {
    // template<class T> T bigMod(T base, T p, T MOD){
    //     if(!p) return 1;

    //     T h = bigMod(base, p>>1, MOD);
    //     h = h*h%MOD;
    //     if(p&1)  h = h*base%MOD;

    //     return h;
    // }

    template<class T> T bigMod(T base, T p, T MOD){
        if(!p)  return 1;
        if(p&1) return bigMod(base,p-1,MOD)*base%MOD;
        else{
            T h = bigMod(base, p>>1, MOD);
            return h*h%MOD;
        }
    }

    template<class T> T gcd(T a, T b){
        if(!a) return b;
        return gcd(a%b, a);
    }
}



int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout); 
    
    int n,base; 
    long long value;

    
    while(scanf("%d%d%d",&base,&n,&maxn) == 3)
    {
         value = bigMod(base,n,maxn);
         cout<<value<<endl;
    }
   
       
    return 0;
}
#include <stdio.h>
int checkPrime(int n);
int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);  

    int n, i, flag = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for(i = 2; i <= n/2; ++i)
    {
        // condition for i to be a prime number
        if (checkPrime(i) == 1)
        {
            // condition for n-i to be a prime number
            if (checkPrime(n-i) == 1)
            {
                // n = primeNumber1 + primeNumber2
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }

        }
    }

    if (flag == 0)
        printf("%d cannot be expressed as the sum of two prime numbers.", n);

    return 0;
}

// Function to check prime number
int checkPrime(int n)
{
    int i, isPrime = 1;

    for(i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            isPrime = 0;
            break;
        }  
    }

    return isPrime;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);

    char str[1000]="DCC Programming Club\0";

    int len = strlen(str);
    int i = 0;
    while(len)
        {
            len--;
            printf("%s\n", str+len);



        }

    i = 0;
    while(str[i]) printf("%s\n", str+i), i++;

    string s(str);



    i = 0;
    while(i < s.size()) cout << s.substr(i++,2) << endl; 


    
    return 0;
}