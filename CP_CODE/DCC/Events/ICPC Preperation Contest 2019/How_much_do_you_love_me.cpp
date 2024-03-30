//https://www.hackerrank.com/contests/icpc-preperation-contest/challenges/how-much-you-love-me
#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline int calculate(string &str)
{   int sum = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') sum+=str[i] - 'a' + 1;
        else if(str[i]>= 'A' && str[i] <= 'Z') sum+=str[i] - 'A' + 1;
    }

    return sum;
}
inline int onedigit(int n)
{
    int sum = 0;
    while(n){sum += n%10;n/=10;}
    if(sum/10 != 0) sum = onedigit(sum);
    return sum;
}

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    string str,str2;
    while(!cin.eof())
    {
        getline(cin,str);
        getline(cin,str2);

        int first = calculate(str);
        int second = calculate(str2);
        first = onedigit(first);
        second = onedigit(second);

     
        if(first<second)
        swap(first,second);

        double ratio = second/(double)first; 
        ratio *=100;

        printf("%.2f %%\n",ratio); 


    }    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
