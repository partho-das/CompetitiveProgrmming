#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3+6;

bool arr[maxn+10];
std::vector<int> prime;
void genarete(int n){   
    prime.push_back(2);
    for(int i = 3;i*i<=n;i+=2) 
        if(!arr[i]) 
            for(int j = i*i;j<=n;j+=i<<1) arr[j] = 1;

    for(int i = 3;i<=n;i+=2) if(!arr[i]) prime.push_back(i);
}

int sod[maxn+10];
vector<int> divisor[maxn+10];
void precalculate(){
    for(int i = 1;i<=maxn;i++){
        for(int j = i;j<=maxn;j+=i){
            divisor[j].push_back(i);
            sod[j] += i;
        }
    }
}



int main()
{
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    
    int q;
    scanf("%d",&q);
    precalculate();
    for(int i = 1;i<=q;i++){
        cout<<"Divisor OF "<<i<<" = ";
        for(auto &it : divisor[i]) cout<<it<<" ";
        cout<<endl;
    }
    for(int i = 1;i<=q;i++)d
    {
        
        cout<<sod[i]<<endl;
    }


       
    return 0;
}

 
#include<bits/stdc++.h>

using namespace std;
vector<int> v;
int f(int l,int r){
    if(is_sorted(v.begin()+l,v.begin()+r)) return r-l+1;
    return max(f(l,(l+r)/2), f(1+(l+r)/2,r));
}
int main()
{
    
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);


    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        int value;
        scanf("%d",&value);
        v.push_back(value);
    }
    

    cout << f(0,n-1) << endl;
    
   
    return 0;
}

 
