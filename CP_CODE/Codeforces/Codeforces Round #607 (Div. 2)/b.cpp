#include <bits/stdc++.h>
using namespace std;


//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
//____________________________________________________________________________________________________________________________________


int main()
{

#ifdef PARTHO
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int start_time = clock();
#endif

    int test;

    cin >> test;

    while(test--)
    {
        string str,cstr;

        cin >> str >> cstr;
        int ck = -1;

        if(str<cstr)
            ck = 2;
        char cchar;


        int n = min(str.size(),cstr.size());

        if(ck != 2)
        {

            for(int i = 0; i<n; i++)
            {
                if(str[i]>cstr[i])
                {
                    for(int j = i; j<str.size(); j++)
                    {

                        if(str[j]<cstr[i])
                        {
                            swap(str[j],str[i]);
                            ck = 2;
                            break;
                        }
                    }
                    break;

                }
            }
        }

        if(ck!=2)
            {

                for(int i = 0; i<n; i++)
                {
                    if(str[i]>=cstr[i])
                    {
                        for(int j = i; j<str.size(); j++)
                        {

                            if(str[j]<cstr[i])
                            {
                                swap(str[j],str[i]);
                                ck = 2;
                                break;
                            }
                        }
                        break;
                    }
                }

            }

            if(ck != 2)
            {
                 if(ck!=2)
            {

                for(int i = 0; i<n; i++)
                {
                    if(str[i]>cstr[i])
                    {
                        for(int j = i; j<str.size(); j++)
                        {

                            if(str[j]<=cstr[i])
                            {
                                swap(str[j],str[i]);
                                ck = 2;
                                break;
                            }
                        }
                        break;

                    }
                }

            }

            }



            if(ck != 2)
            {
                 if(ck!=2)
            {

                for(int i = 0; i<n; i++)
                {
                    if(str[i]>=cstr[i])
                    {
                        for(int j = i; j<str.size(); j++)
                        {

                            if(str[j]<=cstr[i])
                            {
                                swap(str[j],str[i]);
                                ck = 2;
                                break;
                            }
                        }
                        break;

                    }
                }

            }

            }




    if(cstr>str)
        cout << str << endl;
    else cout << "---" << endl;




    }

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
    return 0;
}

