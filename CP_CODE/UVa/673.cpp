
#include<bits/stdc++.h>
using namespace std;

int main()
{

    char str[200],now;
    int test,ck = 0;
    stack<char> stq;
    cin>>test;
    getchar();

    while(test--){
        gets(str);
        ck  = 0;
        while(!(stq.empty()))
            stq.pop();
        if(!(strlen(str))) cout<<"Yes"<<endl;
        else{
            for(int i = 0;i<strlen(str);i++){
                if(str[i]=='('||str[i]=='[') stq.push(str[i]);
                else{
                    if(str[i]==']'){
                        if(!(stq.empty())){
                            now = stq.top();
                            stq.pop();
                            if(now=='[')
                                ck = 0;
                            else{
                                ck = 1;
                                break;
                            }

                        }
                        else{
                            ck = 1;
                            break;
                        }

                    }
                    else if(str[i]==')'){
                         if(!(stq.empty())){
                            now = stq.top();
                            stq.pop();
                            if(now=='(')
                                ck = 0;
                            else{
                                ck = 1;
                                break;
                            }

                        }
                        else{
                            ck = 1;
                            break;

                    }


                }
                else{
                    ck = 1;
                    break;
                }
            }
        }
        if(ck==0&&(stq.empty()))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        }

    }

    return 0;
}
