#include <bits/stdc++.h>
using namespace std;


#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)

void excolor(int n,int m,int *color,int *step,int x)
{   int sum = 0;
    for(int i = x;i<=m;i++)
    {
      sum+=step[i];
    }
    cout << sum << endl;
   
    stack <int> process;
    int  last = 1000000;
    int cnt = sum;
    for(int i = n;i>=1;i--,cnt--)
    {   

        if(cnt == 0)
        {
          cnt = i;
          cout << cnt << endl;
          break;
        }

       if(color[i])
       { 
          if(last!=color[i])
          { //cout << color[i] << endl;
            step[color[i]] = 1;
            last = color[i];
            process.push(color[i]);
          }else
          {
            step[color[i]]++;
           // cout << step[color[i]] << endl;
          } 
       }
       
    }

   // cout << cnt << endl;
    for(int i = cnt ;i<=n;i++)
    {   
         int value;
        if(!process.empty())
        {
            value = process.top();
            cout << value << endl;
          process.pop();
        }
       
        else break;

        value = step[i];
        while(value--)
        {
            color[i++] = value;
        }
        cnt  =  i;
    }

    for(int i = cnt+1 ;i<=n;i++)
    {
        int value = step[x++];
        while(value--)
        {
           color[i++] = value;
        }
    }


    for(int i = 1 ;i<=n;i++)
      cout << color[i] << " ";
    cout << endl;
}

int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif
    

    int n,m,d;
    int step[1020];
    int color[1020];
    memset(color,0,sizeof color);
    cin >> n >> m >> d;
   
   for(int i = 1;i<=m;i++)
   {
      cin >>  step[i];
   }
    
    step[m+1] = 0;
   int now = 0,x = 1;
    d = max(d,1);
   while(x<=m && now<=n)
   {
         now = now+d;
          if(x<=m)
          {
            int value = step[x];
            for(int i = now;value && i<=n;i++,value--)
              color[i] = x;
             cout <<" value = "<< value << endl;
             now  += step[x++]-1;
            if(value)
            {
                x--;
                value = step[x] - value;
              for(int i = n;value && i>=0;i--,value--)
              color[i] = 0;
              break;
              
            } 
          }
       cout << now << endl;
    
   }
    for(int i = 1;i<=n;i++)cout << color[i] << " ";
      cout << endl;
     cout << now << endl;
     int ck = 0;
    if(now>n)
        ck = 1;
      else
      {
         now = now+d;
         if(now>n) ck = 1;
          else  ck = 0;
      } 
      cout << ck << endl;
      if(ck)
      {
          if(x<=m)
          {
            printf("hi\n");
            excolor(n,m,color,step,x);
          }
      }
      else puts("NO");


   #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
   #endif
    return 0;
}
