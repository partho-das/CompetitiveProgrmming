#include<bits/stdc++.h>
using namespace std;

#define ll long long


struct all
{
    ll id,msub,mptime,fzsub,fzptime[100],fsum = 0;
    ll cnt = 0;
}team[100];
int rnk[100];


bool valid(int first,int second)
{
    if(team[first].msub+team[first].fzsub > team[second].msub+team[second].fzsub) return 1;
    else if(team[first].msub+team[first].fzsub == team[second].msub+team[second].fzsub)
    {
        if(team[first].mptime+team[first].fsum <= team[second].mptime+team[second].fsum)
            return 1;
    
    }
    return 0;
}
int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        
       int test;
       cin >> test;

       for(int c = 1;c<=test;c++)
       {
            int n,ck = 0;
            cin >> n;

            for(int i = 0;i<n;i++)//Input
            {
                int roll;
                cin >> roll;
                team[roll].id = roll;
                cin >> team[roll].msub >> team[roll].mptime >> team[roll].fzsub;
                team[roll].fsum = 0;
                for(int j = 0; j < team[roll].fzsub ; j++)
                {
                    cin >>team[roll].fzptime[j];
                        team[roll].fsum+=team[roll].fzptime[i];
                }
            }
            for(int i = 0;i<n;i++)
            {

                cin >> rnk[i];
                 // cout << rnk[i] << endl;
            }
          

            for(int i = 1;i<n;i++)
            {
                int first = rnk[i-1],second = rnk[i];

                cout << first <<" " << second<< endl;
                if(team[first].msub+team[first].fzsub > team[second].msub)
                { 
                    if(team[first].msub+team[first].fzsub > team[second].msub+team[second].fzsub)
                        continue;
                    else
                    {   cout << first <<" " << second<< endl;
                        while(!valid(first,second) &&  team[second].cnt<team[second].fzsub)
                        {  
                            team[second].fsum-=team[second].fzptime[team[second].cnt];
                            team[second].fzptime[team[second].cnt] = 0;
                            team[second].fzsub--;
                            team[second].cnt++;
                        }
                    }
                }
                else if(team[first].msub+team[first].fzsub == team[second].msub+team[second].fzsub)
                    {
                        if(!valid(first,second))
                        {
                            
                            ck = 1;
                        }
                    }
                else
                {
                    ck = 1;
                }

            }   

            printf("Case %d: ",c);
            if(ck == 1)
                printf("Say no to rumour >:\n");
            else printf("We respect our judges :)\n");


       }



    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
