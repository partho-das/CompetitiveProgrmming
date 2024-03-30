#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n = 10;
int taken[12];
int output[12];
int value = 1,ck = 0;

std::vector<pair<string,string>> stor[100];
void BT(int pos = 0)
{
    int a = 0,b = 0,agent = 10000;
    if(pos>=n)
     {
        for(int i = 0;i<n;i++,agent/=10)
        {
            if(i==5)
                agent = 10000;
            if(i<5)
            a +=output[i]*agent;
            else b+=output[i]*agent;
            // cout << output[i] << " ";
        }
        int rat = b/a;
        string up,down;
        if(rat==b/(float)a)
        {   
             // if(rat == value)
             // {
             //     ck = 1;
             //     if(output[0]==0)
             //    cout <<b<<" / "<<0<<a<<" = "<<rat << endl;
             //    else cout <<b<<" / "<<a<<" = "<<rat << endl;
             // }

            for(int i = 0;i<=4;i++)
            {
                down.push_back(output[i]+'0');
            }
            for(int i = 5;i<10;i++)
            {
                up.push_back(output[i]+'0');
            }

            stor[rat].push_back({up,down});
            
        }
        return;
    }
    for(int i = 0;i<n;i++)
    {
       
        if(pos==0 && i >5)
            break;
        if(!taken[i])
        {
            taken[i] = 1;
            output[pos] = i;
            BT(pos+1);
            taken[i] = 0;
        }
    }

    return;
}


int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        int f = 0;
         BT();
    while(value)
    {
        ck = 0;
        cin >> value;
        if(f && value)
            puts("");
        if(!value)
            break;

         if(!stor[value].size())
            printf("There are no solutions for %d.\n",value);
        else{
            for(int i = 0;i<stor[value].size();i++)
                cout << stor[value][i].first << " / " <<  stor[value][i].second << " = " << value << endl;
        }

        f = 1;
    }
   

            
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
