#include <bits/stdc++.h>
using namespace std;
 
int count(string &str)
{
    int onecnt = 0;

    for(int i = 0;i<str.size();i++)
        if(str[i] == '1')
            {
                onecnt++;
            }
    return onecnt;
}
string convert(string &str)
{
     //cout << str << endl;
    for(int i = 0;i<str.size();i++)
        if(str[i] == '1')
        {
            str[i] = '7';
        }
        else str[i] = '4';
       // cout << str << endl;     
        return str;
}
set<string> sstr[11];
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
        int n;

        n = 10;

        long long value = 1 << n; 
        std::vector<long long> v;
        std::vector<string> vstr;

        // cout << value << endl;
        for(int i = 0;i<value;i++)
        {  
                std::string binary = std::bitset<10>(i).to_string();
                vstr.push_back(binary);
        }
       for(int i = 2;i<=10;i+=2)
       {
            string cpy;
            for(int j = 0;j<vstr.size();j++)
            {
                cpy.assign(vstr[j],10-i,i);
                //cout << vstr[j] << endl;
                int onecnt = count(cpy),zerocnt = 0;
                zerocnt = i - onecnt;
                if(onecnt==zerocnt)
                {
                      //cout << cpy << endl;
                    cpy = convert(cpy);
                    sstr[i].insert(cpy);
                    //cout << cpy << endl;
                }
                //cout << cpy << endl;
            }
       }

       for(int i = 2;i<=10;i+=2)
       {    
       
            for(auto it : sstr[i])
            {
                 stringstream ss;
                 long long value;
                 ss << it;
                 ss >> value;
                 v.push_back(value);
            }
        }
   
       
       sort(v.begin(), v.end());

        long long inp;
        cin >> inp;
       for(int i = 0;i<v.size();i++)
       {
        if(v[i]>=inp)
        {
            inp = v[i];
            break;
        }
       }
        cout << inp << endl;




    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
