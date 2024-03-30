#include<bits/stdc++.h>
using namespace std;

int main()
{

    string command,now,cpy;
    int test,cnt = 1;
    stack<string> bak,fow;
    cin>>test;
    while(test--)
    {
         while(!(fow.empty()))

                    fow.pop();
        while(!(bak.empty()))
                    bak.pop();
        now = "http://www.lightoj.com/";
                    bak.push(now);

        printf("Case %d:\n",cnt++);

        while(1)
        {
            cin>>command;
            if(command=="QUIT")
            {
             break;
            }
            if(command=="VISIT")
            {
                cin>>now;
                bak.push(now);
                while(!(fow.empty()))
                    fow.pop();
                cout<<now<<endl;

            }
            else if(command=="BACK")
            {

                cpy = bak.top();
               // cout<<"ext "<<cpy<<endl;
                bak.pop();
                if((bak.empty()))
                {
                    bak.push(cpy);
                cout<<"Ignored"<<endl;
                }
                else
                {
                fow.push(cpy);
                now = bak.top();
                cout<<now<<endl;
                }
            }
            else if(command=="FORWARD")
            {
                if((fow.empty()))
                    cout<<"Ignored"<<endl;
                else{
                //cpy = fow.top();
                 now = fow.top();
                fow.pop();
                bak.push(now);
                cout<<now<<endl;
                }
            }

        }
    }



    return 0;
}
