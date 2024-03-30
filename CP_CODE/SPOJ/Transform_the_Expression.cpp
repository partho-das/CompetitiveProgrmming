#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> oper;
    char top;
    string operand;
    int tst;

    cin>>tst;
    while(tst--)
    {
        cin>>operand;
       for(int i = 0;i<operand.size();i++)
       {
           if(operand[i]>='a'&&operand[i]<='z')
            cout<<operand[i];
           else if(operand[i]==')')
           {
               top  = oper.top();
               oper.pop();
               cout<<top;
           }
           else if(operand[i] == '+'||
                   operand[i] == '-'||
                   operand[i] == '*'||
                   operand[i] == '/'||
                   operand[i] == '^')
           {
               top  =  operand[i];
               oper.push(top);
           }
       }
       cout<<endl;

    }
    return 0;
}
