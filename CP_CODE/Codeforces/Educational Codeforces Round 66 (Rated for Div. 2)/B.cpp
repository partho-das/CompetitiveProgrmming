#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long value  = pow(2,32),have = 0,n,xpo = 1;
	value--;
	//cout << value;
    stack<long long> sq,xh;

    int l;

    cin >> l;
    while(l--)
    {

        string cmd;
        cin >> cmd ;
        if(cmd == "for")
        {
            cin >> n;
            sq.push(n);
            if(xpo<=value/n)
            xpo*=n;
            else
            {
                xh.push(n);
            }

        }
        else if(cmd == "add")
        {
            if(xh.empty())
            have+=xpo;
            else
            {
                 cout << "OVERFLOW!!!" << endl;
                    return 0;
            }
        }
        else if(cmd == "end")
        {
            if(!sq.empty())
            {
                int top = sq.top();
                sq.pop();
             if(!xh.empty())
                xh.pop();
             else
            xpo/=top;


            }

        }
        if(have>value)
        {

            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
        cout << "xq " << xh.size() << " xpo " << xpo << " have " << have << endl;

    }
    cout << have << endl;

	return 0;
}
